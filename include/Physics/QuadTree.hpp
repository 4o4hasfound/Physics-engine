#ifndef PULSAR_QUADTREE_INCLUDED
#define PULSAR_QUADTREE_INCLUDED

#include "setup.hpp"
#include "Container/FreeList.inl"
#include "Physics/AABB.hpp"

#include <unordered_map>
#include <unordered_set>

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

namespace Pulsar {
	// Represents a quadtree
	class QuadTree {
	public:
		struct QuadNode;
		struct QuadElt;

	public:

		// Construcct a new QuadTree
		QuadTree();

		// Destruct a QuadTree
		~QuadTree();

		// Insert an element into the tree
		void Insert(const int32_t& id, const AABB& _AABB);

		// Delete empty leaves.
		void Cleanup();

		// Clear the tree.
		void Clear();

		// Remove an element.
		void Remove(int32_t id);

		// Traverse with the purpose of removing and inserting an element at the same time.
		void Update(int32_t id, const AABB& _AABB);

		// Return a list of the leaves in the tree
		std::vector<QuadNode*> GetLeaves();

		// Return all the element index that the _AABB could collide into.
		std::vector<int32_t> Query(const AABB& _AABB);

		int32_t getInd(int32_t id) {
			return elements[id].id;
		}

		// Debug
		void DebugDraw(sf::RenderTarget& target) {
			nodes->DebugDraw(target);
		}
	private:
		// Stores all the elements in the quadtree.
		FreeList<QuadElt> elements;

		// Use a unordered_map to stort a { id( index outside of the class ) to ind( index inside of the class) }
		std::unordered_map<int, int> idToElementIndex;

		// Stores all the nodes in the quadtree.
		QuadNode* nodes;



		// Structures
	private:
		struct QuadNode {
			// The nodes.
			QuadNode* child[4] = { nullptr, nullptr, nullptr, nullptr };

			// The AABB for the node
			AABB aabb;

			// Store the id of the element
			FreeList<int32_t> eltNode;

			// Default Constructor
			QuadNode() {};

			// Construct a QuadNode
			QuadNode(const AABB& _AABB);

			// Destruct a QuadNode
			~QuadNode();

			// Insert an element into the tree using recursion.
			void insert(const int32_t& id, const AABB& _AABB, const int32_t& depth, FreeList<QuadElt>& elementList);

			// Check if the four child has intersect with the AABB, construct the child if needed, and insert the element into the child.
			void add(const int32_t& id, const AABB& _AABB, const int32_t& depth, FreeList<QuadElt>& elementList);

			// Delete empty leaves.
			void cleanup();

			// Clear the tree.
			void clear();

			// Remove an element.
			void remove(int32_t id);

			// Remove an element using an AABB.
			void remove(int32_t id, const AABB& _AABB);

			// Push_back all the element index that the _AABB could collide into the indexes.
			void query(std::unordered_set<int32_t>& indexes, const AABB& _AABB);

			// Traverse with the purpose of removing and inserting an element at the same time.
			// befAABB: the AABB before the update. aftAABB: the AABB after the update. 
			void update(const int32_t& id, const AABB& befAABB, const AABB& aftAABB, const int32_t& depth, FreeList<QuadElt>& elementList);

			void getLeaves(std::vector<QuadNode*>& vec);

			// Check if is leaf.
			bool isLeaf() const {
				for (int i = 0; i < 4; i++) if (child[i] != nullptr) return false;
				return true;
			}

			// Debug
			void DebugDraw(sf::RenderTarget& target) {
				//std::cout << count << "\n";
				//std::cout << aabb.getMinX() << " " << aabb.getMinY() << "\n";
				sf::RectangleShape rect;
				rect.setPosition(aabb.getMinX(), aabb.getMinY());
				rect.setSize(sf::Vector2f(aabb.getWidth(), aabb.getHeight()));
				rect.setFillColor(sf::Color::Transparent);
				rect.setOutlineThickness(1);
				rect.setOutlineColor(sf::Color::White);
				target.draw(rect);

				for (int i = 0; i < 4; i++) {
					if (child[i] != nullptr) child[i]->DebugDraw(target);
				}
			}
		};

		// Represents an element in the quadtree.
		struct QuadElt {
			// Stores the id for the element (can be used to 
			// refer to external data).
			int32_t id;

			// Stores the rectangle for the element.
			AABB aabb;

			// Default Constructor
			QuadElt() = default;

			// Constructor
			QuadElt(const int32_t& _id, const AABB& _aabb);

			// Constructor for searching ID.
			QuadElt(const int32_t& _id);
		};

		//// Represents an element node in the quadtree.
		//struct QuadEltNode {
		//	// Store the element index.
		//	int32_t element;
		//};
	};
}


#endif