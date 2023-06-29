#include "Container/FreeList.hpp"

namespace Pulsar {
	template<class T>
	int FreeList<T>::insert(const T& element) {
		count++;
		if (first_free != -1) {
			const int index = first_free;
			first_free = data[first_free].next;
			data[index].element = element;
			data[index].removed = false;
			return index;
		}
		else {
			FreeElement fe;
			fe.element = element;
			data.push_back(std::move(fe));
			return static_cast<int>(data.size() - 1);
		}
	}

	template<class T>
	template<class ...Ts>
	int FreeList<T>::emplace(Ts && ...args) {
		count++;
		if (first_free != -1) {
			const int index = first_free;
			first_free = data[first_free].next;
			data[index].element = T(std::forward<Ts>(args)...);
			data[index].removed = false;
			return index;
		}
		else {
			FreeElement fe;
			fe.element = T(std::forward<Ts>(args)...);
			data.push_back(std::move(fe));
			return static_cast<int>(data.size() - 1);
		}
	}

	template<class T>
	void FreeList<T>::remove(int n) {
		count--;
		data[n].next = first_free;
		data[n].removed = true;
		first_free = n;
	}

	template<class T>
	void FreeList<T>::remove(const Iterator& itr) {
		count--;
		data[itr.ind].next = first_free;
		data[itr.ind].removed = true;
		first_free = itr.ind;
	}

	template<class T>
	void FreeList<T>::clear() {
		count = 0;
		data.clear();
		first_free = -1;
	}

	template<class T>
	length_t FreeList<T>::range() const {
		return count ? data.size() : 0;
	}

	template<class T>
	length_t FreeList<T>::find(const T& element) {
		Iterator itr = begin();
		for (; itr != end(); ++itr) {
			if (element == (*itr)) {
				return itr.ind;
			}
		}
		return -1;
	}

	template<class T>
	length_t FreeList<T>::find(const T&& element, bool(*comp)(T, T&)) {
		Iterator itr = begin();
		for (; itr != end(); ++itr) {
			if ((*comp)(element, (*itr))) {
				return itr.ind;
			}
		}
		return -1;
	}

	template<class T>
	void FreeList<T>::invert() {
		std::reverse(data.begin(), data.end());
	}

	template<class T>
	void FreeList<T>::reserve(int n) {
		data.reserve(n);
	}

	template<class T>
	length_t FreeList<T>::size() const {
		return count;
	}

	template<class T>
	T& FreeList<T>::operator[](int n) {
		return data[n].element;
	}

	template<class T>
	const T& FreeList<T>::operator[](int n) const {
		return data[n].element;
	}

	template<class T>
	FreeList<T>::template Iterator FreeList<T>::begin() {
		Iterator itr(this, 0);
		while (itr.ind < data.size() && data[itr.ind].removed) {
			++itr;
		}
		return itr;
	}

	template<class T>
	FreeList<T>::template Iterator FreeList<T>::end() {
		return Iterator(this, data.size());
	}

	template<class T>
	std::vector<T> FreeList<T>::Data() {
		std::vector<T> ret;
		for (auto itr = begin(), e = end(); itr != e; ++itr) ret.push_back(*itr);
		return ret;
	}
}