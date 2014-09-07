//#include <iostream>
//#include <sstream>
//#include "DLinkedList.h"
//
//DLinkedList::DLinkedList() {
//	_first = NULL;
//	_size = 0;
//}
//
//DLinkedList::DLinkedList(const DLinkedList& original) {
//	// TODO: Fill this in
//	std::cerr << "LinkedList::LinkedList(const LinkedList& original) is not yet ";
//	std::cerr << "implemented" << std::endl;
//	exit(1);
//}
//
//DLinkedList::~DLinkedList() {
//	// TODO: Fill this in
//	std::cerr << "LinkedList::~LinkedList() is not yet implemented" << std::endl;
//	exit(1);
//}
//
//std::string DLinkedList::toString() const {
//	std::ostringstream result;
//	Node* traverser = _first;
//
//	while (traverser != NULL) {
//		result << traverser->getValue();
//		
//		if (traverser->getNext() != NULL) {
//			result << " ";
//		}
//		traverser = traverser->getNext();
//	}
//
//	return result.str();
//}
//
//DLinkedList* DLinkedList::getReverse() const {
//	// TODO: Fill this in
//	std::cerr << "LinkedList::getReverse() is not yet implemented" << std::endl;
//	exit(1);
//}
//
//bool DLinkedList::insert(int value, int offset) {
//	// TODO: Fill this in
//	std::cerr << "LinkedList::insert(value, offset) is not yet implemented" << std::endl;
//	exit(1);
//}
//
//bool DLinkedList::erase(int value) {
//	// TODO: Fill this in
//	std::cerr << "LinkedList::erase(value) is not yet implemented" << std::endl;
//	exit(1);
//}
//
//int DLinkedList::size() const {
//	return _size;
//}
//
//void DLinkedList::sort() {
//	// TODO: Fill this in
//	std::cerr << "LinkedList::sort() is not yet implemented" << std::endl;
//	exit(1);
//}
