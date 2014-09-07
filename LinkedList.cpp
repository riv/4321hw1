#include <iostream>
#include <sstream>
#include "LinkedList.h"

LinkedList::LinkedList() {
	_first = NULL;
	_size = 0;
}

LinkedList::LinkedList(const LinkedList& original) {
	if (original._size == 0) {
		_first = NULL;
		_size = 0;
	} else {
		_first = new Node(original._first->getValue()); 
		Node* originalTraverser = original._first;
		Node* copyTraverser = _first; 
		for (unsigned int i = 0; i < original._size - 1; i++) {
			originalTraverser = originalTraverser->getNext();
			copyTraverser->setNext(new Node(originalTraverser->getValue()));
			copyTraverser = copyTraverser->getNext();
		} // end for
		_size = original._size;
	} // end else
} // end copy

LinkedList::~LinkedList() {
	
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
	Node* toBeInserted = new Node(value);
	Node* traverser = _first;
	if (offset == 0) {
		toBeInserted->setNext(traverser);
		_size = _size + 1;
		return true;
	} else if (offset <= _size && offset > 0) {
		// loop to one before offset
		for (int i = 0; i < offset - 1; i++) {
			traverser = traverser->getNext();
		}
		// if there is a next value
		if(offset < _size) {
			toBeInserted->setNext(traverser->getNext());
		}
		traverser->setNext(toBeInserted);
		_size = _size + 1;
		return true;
	} else {
		// invalid offset
		return false;
	} // end else
}

bool LinkedList::erase(int value) {
	//Node* traverser = _first;
	//Node* next = _first->_next;
	//for (int i = 0; i < _size;i++) {
	//	if (traverser->_value == value) {
	//		
	//	}
	//}
	return false;
}

int LinkedList::size() const {
	return _size;
}

void LinkedList::sort() {
	// TODO: Fill this in
	std::cerr << "LinkedList::sort() is not yet implemented" << std::endl;
	exit(1);
}
