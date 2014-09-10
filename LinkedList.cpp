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
		int originalSize = original.size();
		for (unsigned int i = 0; i < originalSize - 1; i++) {
			originalTraverser = originalTraverser->getNext();
			copyTraverser->setNext(new Node(originalTraverser->getValue()));
			copyTraverser = copyTraverser->getNext();
		} // end for
		_size = originalSize;
	} // end else
} // end copy

LinkedList::~LinkedList() {
	Node* traverser = _first;
	int currentSize = size();
	// loop through and delete all nodes
	for(int i = 0; i < currentSize; i++) {
		Node* currentNode = traverser;
		if(i < currentSize - 1) {
			traverser = traverser->getNext();
		} // end if
		delete currentNode;
	} // end for
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
	LinkedList* revList = new LinkedList();
	Node* traverser = _first;
	int currentsize = _size;
	// fill the new linked list with references to the nodes in the list
	for(int i = 0; i < currentsize; i++) {
		revList->insert(traverser->getValue(), 0);
		if(i < currentsize - 1) { 
			traverser = traverser->getNext();
		} // end if
	} // end for 
	return revList;
}

bool LinkedList::insert(int value, int offset) {
	Node* toBeInserted = new Node(value);
	Node* traverser = _first;
	if (offset == 0) {
		toBeInserted->setNext(traverser);
		setFirst(toBeInserted);
		setSize(size() + 1);
		return true;
	} else if (offset <= size() && offset > 0) {
		// loop to one before offset
		for (int i = 0; i < offset - 1; i++) {
			traverser = traverser->getNext();
		}
		// if there is a next value
		if(offset < size()) {
			toBeInserted->setNext(traverser->getNext());
		}
		traverser->setNext(toBeInserted);
		setSize(size() + 1);
		return true;
	} else {
		// invalid offset
		delete toBeInserted;
		return false;
	} // end else
}

bool LinkedList::erase(int value) {
	Node* traverser = _first;
	Node* previous = NULL;
	Node* next;
	bool flag = false;
	int size = this->size();
	// If list has only one element then check if it equals value and delete it if it does
	if (size == 1) {
		if (_first->getValue() == value) {
			delete _first;
			_first = NULL;
			_size = 0;
			return true;
		} // end if
		return false;
	} else if (size > 1) {
		// sets initial next reference
		next = _first->getNext();
		// iterate through linked list
		for (int i = 0; i < size; i++) {
			if (traverser->getValue() == value) {
				delete traverser;
				flag = true;
				_size--;
				// if this is the first element or there are no elements before it
				if(i == 0 || previous == NULL) {
					_first = next;
				} else if(i == size - 1) {
					previous->setNext(NULL);
				} else {
					previous->setNext(next);
				} // end else
			} else {
				// if traverser was not deleted, set previous to it (after the iteration)
				previous = traverser;
			} // end else
			traverser = next;
			if(i < size - 1) {
				next = next->getNext();
			} // end if
		} // end for
		return flag;
	} // end else if
	return false;
}

int LinkedList::size() const {
	return _size;
}


void LinkedList::sort() {
	Node* outerTraverser = _first;
	int currentSize = size();
	if (currentSize <= 1) {
		return;
	}
	//for each node, iterate through the rest of the list and find the lowest value
	for (int i = 0; i < currentSize; i++) {
		Node* innerTraverser = outerTraverser;
		Node* lowestNode = outerTraverser;
		//iterates through the rest of list to get lowest value node
		for (int j = i; j < currentSize; j++) {
			if (innerTraverser->getValue() < lowestNode->getValue()) {
				lowestNode = innerTraverser;
			} // end if
			innerTraverser = innerTraverser->getNext();
		} // end for
		//swap the two nodes values
		int lowestNodeValue = lowestNode->getValue();
		lowestNode->setValue(outerTraverser->getValue());
		outerTraverser->setValue(lowestNodeValue);
		outerTraverser = outerTraverser->getNext();
	} // end for
}