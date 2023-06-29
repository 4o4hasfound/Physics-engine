#include "Physics/QuadTree.hpp"

namespace Pulsar{
	QuadTree::QuadTree() {
		nodes = new QuadNode(AABB(vec4(100, 100, 800, 800)));
	}

	QuadTree::~QuadTree() {
		nodes->clear();
	}

	void QuadTree::Insert(const int32_t& id, const AABB& _AABB) {
		int ind = elements.emplace(id, _AABB);
		idToElementIndex.insert(std::pair<int, int>(id, ind));
		nodes->insert(ind, _AABB, 1, elements);
	}

	void QuadTree::Cleanup() {
		// Call the cleanup function of the root node if only it is not a leaf.
		if (!nodes->isLeaf()) {
			nodes->cleanup();
		}
	}

	void QuadTree::Clear() {
		elements.clear();
		nodes->eltNode.clear();
		idToElementIndex.clear();
		for (int i = 0; i < 4; i++) {
			if (nodes->child[i] != nullptr) {
				nodes->child[i]->clear();
				delete nodes->child[i];
				nodes->child[i] = nullptr;
			}
		}
	}

	void QuadTree::Remove(int32_t id) {
		//_STARTTIME
		if (idToElementIndex.count(id)) {
			int32_t index = idToElementIndex[id];
			nodes->remove(index, elements[index].aabb);
			elements.remove(index);
		}
		//_ENDTIME("Time for removal:    ")
	}

	void QuadTree::Update(int32_t id, const AABB& _AABB) {
		if (idToElementIndex.count(id)) {
			int32_t index = idToElementIndex[id];
			if (elements[index].aabb != _AABB) {
				nodes->update(index, elements[index].aabb, _AABB, 1, elements);
				elements.remove(index);
				elements.emplace(id, _AABB);
			}
		}
	}

	std::vector<QuadTree::QuadNode*> QuadTree::GetLeaves() {
		std::vector<QuadNode*> ret;
		nodes->getLeaves(ret);
		return ret;
	}

	std::vector<int32_t> QuadTree::Query(const AABB& _AABB) {
		std::unordered_set<int32_t> indexes_set;
		nodes->query(indexes_set, _AABB);
		std::vector<int32_t> indexes(indexes_set.size());
		indexes.assign(indexes_set.begin(), indexes_set.end());
		for (int i = 0; i < indexes.size(); i++) {
			indexes[i] = elements[indexes[i]].id;
		}
		return indexes;
	}

	QuadTree::QuadNode::QuadNode(const AABB& _AABB) : aabb(_AABB) {
		eltNode.reserve(5);
	}

	QuadTree::QuadNode::~QuadNode() {
		for (int i = 0; i < 4; i++) {
			if (child[i] != nullptr) {
				delete child[i];
				child[i] = nullptr;
			}
		}
	}

	void QuadTree::QuadNode::insert(const int32_t& id, const AABB& _AABB, const int32_t& depth, FreeList<QuadElt>& elementList) {
		// If the current node is leaf (All the child is null), then we can start inserting the element into eltNode.
		if (isLeaf()) {
			if (eltNode.size() < 5 || depth >= 3) {
				eltNode.insert(id);
			}
			else {
				// Insert the _AABB.
				add(id, _AABB, depth, elementList);

				// Insert every other value in the eltNode.
				for (const auto& value : eltNode) {
					add(value, elementList[value].aabb, depth, elementList);
				}

				// Clear linked list and count
				eltNode.clear();
			}
		}
		else {
			// Insert the _AABB.
			add(id, _AABB, depth, elementList);
		}
	}

	void QuadTree::QuadNode::add(const int32_t& id, const AABB& _AABB, const int32_t& depth, FreeList<QuadElt>& elementList) {
		for (int i = 0; i < 4; i++) {
			if (child[i] == nullptr) {
				// Construct the child only if it has intersect with the AABB.
				AABB _aabb(vec4(aabb.getPointAfterSplit(i), aabb.getWidth() / 2, aabb.getHeight() / 2));
				if (_aabb.intersect(_AABB)) {
					child[i] = new QuadNode(_aabb);
					child[i]->insert(id, _AABB, depth + 1, elementList);
				}
			}
			else {
				if (child[i]->aabb.intersect(_AABB)) {
					child[i]->insert(id, _AABB, depth + 1, elementList);
				}
			}
		}
	}

	void QuadTree::QuadNode::cleanup() {
		for (int i = 0; i < 4; i++) {
			if (child[i] != nullptr) {
				if (child[i]->isLeaf() && child[i]->eltNode.size() == 0) {
					delete child[i];
					child[i] = nullptr;
				}
				else {
					child[i]->cleanup();
				}
			}
		}
	}

	void QuadTree::QuadNode::clear() {
		eltNode.clear();
		for (int i = 0; i < 4; i++) {
			if (child[i] != nullptr) {
				child[i]->clear();
				delete child[i];
				child[i] = nullptr;
			}
		}
	}

	void QuadTree::QuadNode::remove(int32_t id) {
		if (isLeaf()) {
			size_t ind = eltNode.find(id);
			if (ind != -1) {
				eltNode.remove(ind);
			}
		}
		else {
			for (int i = 0; i < 4; i++) {
				if (child[i] != nullptr) {
					child[i]->remove(id);
				}
			}
		}
	}

	void QuadTree::QuadNode::remove(int32_t id, const AABB& _AABB) {
		if (isLeaf()) {
			size_t ind = eltNode.find(id);
			if (ind != -1) {
				eltNode.remove(ind);
			}
		}
		else {
			for (int i = 0; i < 4; i++) {
				if (child[i] != nullptr && child[i]->aabb.intersect(_AABB)) {
					child[i]->remove(id, _AABB);
				}
			}
		}
	}

	void QuadTree::QuadNode::query(std::unordered_set<int32_t>& indexes, const AABB& _AABB) {
		if (aabb.intersect(_AABB)) {
			for (const int32_t& i : eltNode) {
				indexes.insert(i);
			}
			for (int i = 0; i < 4; i++) {
				if (child[i] != nullptr) {
					child[i]->query(indexes, _AABB);
				}
			}
		}
	}

	void QuadTree::QuadNode::update(const int32_t& id, const AABB& befAABB, const AABB& aftAABB, const int32_t& depth, FreeList<QuadElt>& elementList) {
		if (!isLeaf()) {
			for (int i = 0; i < 4; i++) {
				if (child[i] != nullptr) {
					if (child[i]->aabb.intersect(befAABB)) {
						if (child[i]->aabb.intersect(aftAABB)) {
							// Intersect with both aabb at the same time, call update of the child.
							child[i]->update(id, befAABB, aftAABB, depth + 1, elementList);
						}
						else {
							// Only intersect with the aabb before, call remove of the child.
							child[i]->remove(id, befAABB);
						}
					}
					else {
						if (child[i]->aabb.intersect(aftAABB)) {
							// Only intersect with the aabb after, call insert of the child.
							child[i]->insert(id, aftAABB, depth + 1, elementList);
						}
					}
				}
				else {
					// Construct the child only if it has intersect with the AABB.
					AABB _aabb(vec4(aabb.getPointAfterSplit(i), aabb.getWidth() / 2, aabb.getHeight() / 2));
					if (_aabb.intersect(aftAABB)) {
						child[i] = new QuadNode(_aabb);
						child[i]->insert(id, aftAABB, depth + 1, elementList);
					}
				}
			}
		}
	}

	void QuadTree::QuadNode::getLeaves(std::vector<QuadNode*>& vec) {
		if (isLeaf()) {
			vec.push_back(this);
			return;
		}
		for (int i = 0; i < 4; i++) {
			if (child[i] != nullptr) {
				child[i]->getLeaves(vec);
			}
		}
	}

	QuadTree::QuadElt::QuadElt(const int32_t& _id, const AABB& _aabb) : id(_id), aabb(_aabb) {

	}

	QuadTree::QuadElt::QuadElt(const int32_t& _id) : id(_id) {
	}
}