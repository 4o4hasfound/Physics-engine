#include "Container/LinkedList.hpp"

namespace Pulsar {
	template<class T>
	LinkedList<T>::LinkedList() {

	}

	template<class T>
	LinkedList<T>::~LinkedList() {
		Node* n = _head;
		while (n != nullptr) {
			Node* temp = n->next;
			delete n;
			n = temp;
		}
	}

	template<class T>
	LinkedList<T>::template Iterator LinkedList<T>::insert(const T& element) {
		if (_head) {
			_tail->next = new Node;
			_tail = _tail->next;
			_tail->element = element;
		}
		else {
			_head = _tail = new Node;
			_head->element = _tail->element = element;
		}
		return Iterator(_tail);
	}

	template<class T>
	template<class ...Ts>
	LinkedList<T>::template Iterator LinkedList<T>::emplace(Ts && ...args) {
		if (_head) {
			_tail->next = new Node;
			_tail = _tail->next;
			_tail->element = std::move(T(std::forward<Ts>(args)...));;
		}
		else {
			_head = _tail = new Node;
			_head->element = _tail->element = std::move(T(std::forward<Ts>(args)...));
		}
		return Iterator(_tail);
	}

	template<class T>
	void LinkedList<T>::clear() {
		Node* n = _head;
		while (n != nullptr) {
			Node* temp = n->next;
			delete n;
			n = temp;
		}
		_head = _tail = nullptr;
	}

	template<class T>
	LinkedList<T>::template Iterator LinkedList<T>::begin() {
		return Iterator(_head);
	}

	template<class T>
	LinkedList<T>::template Iterator LinkedList<T>::end() {
		return Iterator(nullptr);
	}
}