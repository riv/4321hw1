#include <iostream>
#include <sstream>
#include "LinkedList.h"

LinkedList::LinkedList() {
	_first = NULL;
	_size = 0;
}

LinkedList::LinkedList(const LinkedList& original) {
	LinkedList copy = LinkedList.LinkedList();
	if (original._size = 0) {
		return copy;
	} 
	else {
		Node* const _current = original._first;
		copy._first = original._first;
		for (int len = 0; len < original._size;len++) {
			Node x = Node(original._first->getValue());

		}
	}
}

LinkedList::~LinkedList() {
	// TODO: Fill this in
	std::cerr << "LinkedList::~LinkedList() is not yet implemented" << std::endl;
	exit(1);
}

std::string LinkedList::toString() const {
	std::ostringstream result;
	Node* traverser = _first;

	while (traverser != NULL) {
		result << traverser->getValue();
		
		if (traverser->getNext() != NULL) {
			result << " ";
		}
		traverser = traverser->getNext();
	}

	return result.str();
}

LinkedList* LinkedList::getReverse() const {
	// TODO: Fill this in
	std::cerr << "LinkedList::getReverse() is not yet implemented" << std::endl;
	exit(1);
}

bool LinkedList::insert(int value, int offset) {
	Node tobeInserted = Node(value);
	Node* traverser = _first;
	if (offset == 0) {
		tobeInserted._next = traverser;
		return true;
	}
	for (int i = 0; i < offset-1;i++) {
		traverser = traverser ->getNext();
	}
	tobeInserted._next = traverser->_next;
	traverser->_next = &tobeInserted;
}

bool LinkedList::erase(int value) {
	Node* traverser = _first;
	Node* next = _first->_next;
	for (int i = 0; i < _size;i++) {
		if (traverser->_value == value) {
			
		}
	}
}

int LinkedList::size() const {
	return _size;
}

void LinkedList::sort() {
	// TODO: Fill this in
	std::cerr << "LinkedList::sort() is not yet implemented" << std::endl;
	exit(1);
}
