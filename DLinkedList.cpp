#include <iostream>
#include <sstream>
#include "DLinkedList.h"

DLinkedList::DLinkedList() {
	_first = NULL;
	_size = 0;
}

DLinkedList::DLinkedList(const DLinkedList& original) {
	_size = 0;
	_first = original._first;
	DNode* traverser = _first;
	for (int i = 0; i < original._size; i++) {
		insert(traverser->getValue(), i);
		traverser = traverser->getNext();
	}
}

DLinkedList::~DLinkedList() {
	DNode* traverser = _first;
	int currentSize = size();
	// loop through and delete all DNodes
	for(int i = 0; i < currentSize; i++) {
		DNode* currentDNode = traverser;
		if(i < currentSize - 1) {
			traverser = traverser->getNext();
		} // end if
		delete currentDNode;
	} // end for
}

std::string DLinkedList::toString() const {
	std::ostringstream result;
	DNode* traverser = _first;

	while (traverser != NULL) {
		result << traverser->getValue();
		
		if (traverser->getNext() != NULL) {
			result << " ";
		}
		traverser = traverser->getNext();
	}

	return result.str();
}

DLinkedList* DLinkedList::getReverse() const {
	DLinkedList* revList = new DLinkedList();
	DNode* traverser = _first;
	int currentsize = _size;
	// fill the new linked list with references to the DNodes in the list
	for(int i = 0; i < currentsize; i++) {
		revList->insert(traverser->getValue(), 0);
		if(i < currentsize - 1) { 
			traverser = traverser->getNext();
		} // end if
	} // end for 
	return revList;
}

bool DLinkedList::insert(int value, int offset) {
	DNode* toBeInserted = new DNode(value);
	DNode* traverser = _first;
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
			DNode* traverserNextDNode = traverser->getNext();
			toBeInserted->setNext(traverserNextDNode);
			traverserNextDNode->setPrevious(toBeInserted);
		}
		toBeInserted->setPrevious(traverser);
		traverser->setNext(toBeInserted);
		setSize(size() + 1);
		return true;
	} else {
		// invalid offset
		delete toBeInserted;
		return false;
	} // end else
}

bool DLinkedList::erase(int value) {
	DNode* traverser = _first;
	DNode* next;
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
				DNode* previous = traverser->getPrevious();
				delete traverser;
				flag = true;
				_size--;
				// if this is the first element or there are no elements before it
				if(i == 0 || previous == NULL) {
					_first = next;
					_first->setPrevious(NULL);
				} else if(i == size - 1) {
					previous->setNext(NULL);
				} else {
					previous->setNext(next);
					next->setPrevious(previous);
				} // end else
			}
			traverser = next;
			if(i < size - 1) {
				next = next->getNext();
			} // end if
		} // end for
		return flag;
	} // end else if
	return false;
}

int DLinkedList::size() const {
	return _size;
}

void DLinkedList::sort() {
	DNode* outerTraverser = _first;
	int currentSize = size();
	if (currentSize <= 1) {
		return;
	}
	//for each DNode, iterate through the rest of the list and find the lowest value
	for (int i = 0; i < currentSize; i++) {
		DNode* innerTraverser = outerTraverser;
		DNode* lowestDNode = outerTraverser;
		//iterates through the rest of list to get lowest value DNode
		for (int j = i; j < currentSize; j++) {
			if (innerTraverser->getValue() < lowestDNode->getValue()) {
				lowestDNode = innerTraverser;
			} // end if
			innerTraverser = innerTraverser->getNext();
		} // end for
		//swap the two DNodes values
		int lowestDNodeValue = lowestDNode->getValue();
		lowestDNode->setValue(outerTraverser->getValue());
		outerTraverser->setValue(lowestDNodeValue);
		outerTraverser = outerTraverser->getNext();
	} // end for
}
