#include <string>

using namespace std;

class DNode {
public:
	DNode(int value) {
		_value = value;
		_previous = NULL;
		_next = NULL;
	}
	
	int getValue() const {
		return _value;
	}
	void setValue(int value) {
		_value = value;
	}
	DNode* getPrevious() const {
		return _previous;
	}
	void setPrevious(DNode* previous) {
		_previous = previous;
	}
	DNode* getNext() const {
		return _next;
	}
	void setNext(DNode* next) {
		_next = next;
	}

private: 
	int _value;
	DNode *_previous;
	DNode *_next;
};

// Implementation of a doubly linked list.
class DLinkedList {
public:
	// Create a new empty linked list
	DLinkedList();
	
	// Create a new linked list whose elements are copies of those in the
	// list "original". Insertions or deletions to the original list should
	// not affect the copied list, and insertions or deletions to the copied
	// list should not affect the original list.
	DLinkedList(const DLinkedList& original);

	// List destructor. Free the memory that's used by DNodes in the list.
	~DLinkedList();

	// Generate a string containing human-readable versions ofthe elements of
	// the list, with a space between adjacent elements in the list.
	// For instance, if the list contains the elements [1, 2, 3] then the
	// output of this function should be "1 2 3" (without the quotes).
	string toString() const;

	// Create a new list whose elements are the same as those in the original
	// list, but which appear in the opposite order. For instance, if the
	// original list l contains the elements [1, 2, 3] then l.getReverse()
	// will return a new list which contains the elements [3, 2, 1].
	DLinkedList* getReverse() const;

	// Insert a new DNode into the list. That DNode should have the value "value"
	// and should be located at position "offset". For instance, if offset = 0
	// then the DNode should be inserted into the list at the very beginning
	// of the list. If offset = 1 then the DNode should be inserted just after
	// what was previously the first element of the list. And so on.
	//
	// This function should return true if the insertion was successful, or
	// false otherwise. (This can happen if "offset" is greater than the
	// length of the list.)
	bool insert(int value, int offset);

	// Remove from the list every DNode whose value is equal to "value". If no
	// such DNodes exist, the contents of the list will not be changed by this
	// function.
	bool erase(int value);

	// Get the number of elements in the list.
	int size() const;

	// Sort the elements in the list in ascending order
	void sort();

	//Sets the _first DNode of the list
	void setFirst(DNode* first) {
		_first = first;
	}

	//Sets the size of the list
	void setSize(unsigned int size) {
		_size = size;
	}

private:
	DNode *_first;
	unsigned int _size;
};
