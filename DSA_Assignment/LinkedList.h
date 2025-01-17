#pragma once
#include <iostream>
using namespace std;

template <typename T>

class LinkedList{
private:
	struct Node
	{
		ItemType item;	// data item
		Node* next;	// pointer pointing to next item
	};

	Node* firstNode;	// point to the first item
	Node* backNode;     // point to the last item
	int  size;			// number of items in the list

public:
	List();			// constructor

    ~List();		// destructor


};

