#ifndef PULSAR_FREELIST_INCLUDED
#define PULSAR_FREELIST_INCLUDED

#include "setup.hpp"

#include <vector>
#include <iterator>
#include <iostream>

namespace Pulsar {
	// Provides an index free list with constant-time removals from anywhere
	// in the list without invalidating indices. T must be trivially constructible
	// and destructible.
	template<class T>
	class FreeList {
		// Structures
	public:

		// Iterator class
		class Iterator {
			friend class FreeList<T>;
		public:
			// iterator traits 

			using difference_type = std::ptrdiff_t;
			using value_type = T;
			using pointer = T*;
			using const_pointer = T const*;
			using reference = T&;
			using const_reference = const T&;
			using iterator_category = std::forward_iterator_tag;

			// Constructor with a pointer to the Freelist
			Iterator(FreeList<T>* _list, int _ind) : list(_list), ind(_ind) {  }

			// Return the index of an iterator.
			length_t getIndex() { return ind; }

			// Pre increment (++it)
			Iterator& operator++() {
				do {
					ind++;
				} while (ind < list->data.size() && list->data[ind].removed); // Skip the removed elements
				return *this;
			}

			// Post increment (it++)
			Iterator operator++(int) {
				Iterator retval = *this;
				++(*this);
				return retval;
			}

			// Deferencable
			reference operator*() {
				return list->data[ind].element;
			}

			// Const Deferencable
			const_reference operator*() const {
				return list->data[ind].element;
			}

			// Deferencable
			pointer operator->() {
				return &list->data[ind].element;
			}

			// Const Deferencable
			const_pointer operator->() const {
				return &list->data[ind].element;
			}

			// Iterator distance.
			int operator-(Iterator other) const {
				return std::abs(other.ind - ind);
			}

			// Boolean operations

			bool operator<(Iterator other) {
				return ind < other.ind;
			}

			bool operator<=(Iterator other) {
				return ind <= other.ind;
			}

			bool operator>(Iterator other) {
				return ind < other.ind;
			}

			bool operator>=(Iterator other) {
				return ind <= other.ind;
			}

			bool operator==(Iterator other) {
				return ind == other.ind;
			}

			bool operator!=(Iterator other) {
				return ind != other.ind;
			}

		private:
			int ind;

			FreeList<T>* list;
		};

		// Class representing an element
		class FreeElement {
		public:
			FreeElement() {}
			FreeElement(const FreeElement& other) {
				element = other.element;
				next = other.next;
				removed = other.removed;
			}
			union { T element; int32_t next = -1; };
			bool removed = false;
		};
	public:
		// Create a new free list.
		FreeList() :first_free(-1) {

		};

		// Destruct a free list.
		~FreeList() {};

		// Inserts an element to the free list and returns an index to it.
		int insert(const T& element);

		// Add an element to the free list by constructing it directly into the list,
		// and returns an index to it.
		template<class ... Ts>
		int emplace(Ts&&... args);

		// Removes the nth index element from the free list.
		void remove(int n);

		// Removes an element from an Iterator.
		void remove(const Iterator& itr);

		// Removes all elements from the free list.
		void clear();

		// Returns the range of valid indices.
		length_t range() const;

		// Try to find a given item in the list and returns an Iterator to 
		// that element if it exist. Otherwise, returns the end() Iterator.
		length_t find(const T& element);

		// Try to find a given item in the list using custom comparator function
		// and returns an Iterator to that element if it exist. 
		// Otherwise, returns the end() Iterator.
		length_t find(const T&& element, bool (*comp)(T, T&));

		// Invert the whole vector.
		void invert();

		// Reserve a certain amount of memory for the FreeList.
		void reserve(int n);

		// Return the size of valid elements.
		length_t size() const;

		// Returns the nth element.
		T& operator[](int n);

		// Returns the nth element.
		const T& operator[](int n) const;

		// Return the Iterator at the start of the list
		Iterator begin();

		// Return the Iterator at the end of the list
		Iterator end();

		std::vector<T> Data();

	private:
		std::vector<FreeElement> data;
		int first_free = -1;
		length_t count = 0;
	};
}

#endif