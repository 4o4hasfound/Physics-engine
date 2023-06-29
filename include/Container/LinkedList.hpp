#ifndef PULSAR_LINKED_LIST_INCLUDED
#define PULSAR_LINKED_LIST_INCLUDED

#include "setup.hpp"

namespace Pulsar {
	// Class for a simple LinkedList
	template<class T>
	class LinkedList {
		// Structures
	private:

		// Struct for a Node
		struct Node {
			Node* next = nullptr;

			T element;
		};
	public:
		// Iterator Class
		class Iterator {
		public:
			// iterator traits

			using difference_type = std::ptrdiff_t;
			using value_type = T;
			using pointer = T*;
			using const_pointer = T const*;
			using reference = T&;
			using const_reference = const T&;
			using iterator_category = std::forward_iterator_tag;

			// Constructor
			Iterator(Node* _node) : node(_node) {}

			// Pre increment (++it)
			Iterator& operator++() {
				node = node->next;
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
				return node->element;
			}

			// Const Deferencable
			LinkedList<T> operator*() const {
				return node->element;
			}

			// Deferencable
			pointer operator->() {
				return &node->element;
			}

			// Const Deferencable
			const_pointer operator->() const {
				return &node->element;
			}

			// Boolean operations

			bool operator==(Iterator other) {
				return node == other.node;
			}

			bool operator!=(Iterator other) {
				return node != other.node;
			}

		private:
			Node* node;
		};
	public:

		// Create a new LinkedList. 
		LinkedList();

		// Destruct a LinkedList.
		~LinkedList();

		// Insert an element to the LinkedList and return an Iterator to it.
		Iterator insert(const T& element);

		// Add an element to the free list by constructing it directly into the list,
		// and returns an index to it.
		template<class ... Ts>
		Iterator emplace(Ts&& ... args);

		// Clear the entire LinkedList
		void clear();

		// Return the Iterator at the start of the list
		Iterator begin();

		// Return the Iterator at the end of the list
		Iterator end();
	private:
		Node* _head = nullptr, * _tail = nullptr;

	};
}


#endif