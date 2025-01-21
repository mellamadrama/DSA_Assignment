#pragma once
#include <iostream>
using namespace std;

template <typename T>

class LinkedList{
private:
	struct Node
	{
		T item;	// data item
		Node* next;	// pointer pointing to next item
	};

	Node* firstNode;	// point to the first item
	Node* backNode;     // point to the last item
	int  size;			// number of items in the list

public:
	LinkedList();			// constructor

    ~LinkedList();		// destructor

	// add an item to the back of the list (append)
	// pre : size < MAX_SIZE
	// post: item is added to the back of the list
	// size of list is increased by 1
	bool add(T item);

	// add an item at a specified position in the list (insert)
	// pre : 0 <= index <= size
	// post: item is added to the specified position in the list
	//       items after the position are shifted back by 1 position
	//       size of list is increased by 1
	bool add(int index, T item);

	// remove an item at a specified position in the list
	// pre : 0 <= index < size
	// post: item is removed the specified position in the list
	//       items after the position are shifted forward by 1 position
	//       size of list is decreased by 1
	void remove(int index);

	// get an item at a specified position of the list (retrieve)
	// pre : 0 <= index < size
	// post: none
	// return the item in the specified index of the list
	T get(int index);

	// check if the list is empty
	// pre : none
	// post: none
	// return true if the list is empty; otherwise returns false
	bool isEmpty();

	// check the size of the list
	// pre : none
	// post: none
	// return the number of items in the list
	int getLength();

	// display the items in the list
	void print();

	// void replace(int index, ItemType item);
	// int search(ItemType item);
};

template <typename T>
LinkedList<T>::LinkedList() {
	firstNode = NULL;
	size = 0;
}

template <typename T>
LinkedList<T>::~LinkedList() {
	while (!isEmpty()) {
		remove(0);
	}
}

template <typename T>
bool LinkedList<T>::add(T item) {
	Node* node = new Node;
	node->item = item;
	node->next = NULL;

	if (size == 0)
	{
		firstNode = node;
	}
	else {
		Node* current = firstNode;
		while (current->next != NULL)
		{
			current = current->next;
		}
		current->next = node;
	}
	size++;
	return true;
}

template <typename T>
bool LinkedList<T>::add(int index, T item) {
	if (index < 0 || index > size) {
		return false;
	}
	Node* newNode = new Node;
	newNode->item = item;
	newNode->next = NULL;

	if (index == 0) {
		newNode->next = firstNode;
		firstNode = newNode;
	}
	else {
		Node* current = firstNode;
		for (int i = 0; i < index - 1; i++) {
			current = current->next;
		}
		newNode->next = current->next;
		current->next = newNode;
		size++;
		return true;
	}
	return false;
}

template <typename T>
void LinkedList<T>::remove(int index) {
	if (index < 0 || index >= size) {
		return;
	}

	Node* toDelete = NULL;

	if (index == 0) {
		toDelete = firstNode;
		firstNode = firstNode->next;
	}
	else {
		Node* current = firstNode;
		for (int i = 0; i < index - 1; i++) {
			current = current->next;
		}
		toDelete = current->next;
		current->next = toDelete->next;
	}

	delete toDelete;
	size--;
}

template <typename T>
T LinkedList<T>::get(int index) {
	if (index < 0 || index >= size) {
		return T();
	}
	Node* current = firstNode;
	for (int i = 0; i < index; i++) {
		current = current->next;
	}
	return current->item;
}

template <typename T>
bool LinkedList<T>::isEmpty() {
	if (size == 0) {
		return true;
	}
	return false;
}

template <typename T>
int LinkedList<T>::getLength() {
	return size;
}

template <typename T>
void LinkedList<T>::print() {
	Node* current = firstNode;
	while (current != NULL) {
		cout << current->item << " ";
		current = current->next;
	}
	cout << endl;
}
