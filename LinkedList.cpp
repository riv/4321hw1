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
	LinkedList revList(*this);
	Node* traverser = revList._first;
	int currentSize = revList.size();
	Node* nodeArray[currentSize];
	// create an array with references to the nodes in the list
	for(int i = 0; i < currentSize; i++) {
		nodeArray[i] = traverser;
		if(i < currentSize - 1) { 
			traverser = traverser->getNext();
		} // end if
	} // end for 
	// go through the array in reverse to create a new reversed list
	if(currentSize >= 1) {
		revList._first = nodeArray[currentSize - 1];
		for(int i = currentSize - 1; i >= 0; i--) {
			if(i > 0) {
				nodeArray[i]->setNext(nodeArray[i - 1]);
			} else {
				nodeArray[i]->setNext(NULL);
			} // end else
		} // end for
	} // end if
	delete[] nodeArray;
	return &revList;
}

bool LinkedList::insert(int value, int offset) {
	Node* toBeInserted = new Node(value);
	Node* traverser = _first;
	if (offset == 0) {
		toBeInserted->setNext(traverser);
		setSize(2);
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
		setSize(2);
		return true;
	} else {
		// invalid offset
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
	Node* traverser = _first;
	int currentSize = this->size();
	Node* nodeArray[currentSize];
	// create an array with references to the nodes in the list
	for(int i = 0; i < currentSize; i++) {
		nodeArray[i] = traverser;
		if(i < currentSize - 1) { 
			traverser = traverser->getNext();
		} // end if
	} // end for
	// O(n^2) sort
	for(int i = 0; i < currentSize; i++) {
		Node* lowest = nodeArray[i];
		int lowestIndex = i;
		// find the lowest each time
		for (int j = i; j < currentSize; j++) {
			if(lowest->getValue() > nodeArray[j]->getValue()) {
				lowest = nodeArray[j];
				lowestIndex = j;
			} // end if
		} // end for
		// swap the lowest and the current one
		Node* temp = nodeArray[i];
		nodeArray[i] = lowest;
		nodeArray[lowestIndex] = temp;
	} // end for
	// convert array back to LinkedList
	Node* currentNode = _first;
	for(int i = 0; i < currentSize; i++) {
		currentNode = nodeArray[i];
		if(i < currentSize - 1) { 
			currentNode->setNext(nodeArray[i+1]);
		} else {
			currentNode->setNext(NULL);
		} // end else
	} // end for

	delete[] nodeArray;
}


