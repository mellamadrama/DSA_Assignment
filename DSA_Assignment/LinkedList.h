/*
* Name: Hervin Sie(S10262115C), Charlotte Lee(s10258027k)
* Group: 6
*/

#pragma once
#include <iostream>
#include "HashTable.h"
using namespace std;

template <typename T>
extern HashTable<T>* hashTable;


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

	//Helper functions
	Node* mergeSort(Node* head, bool (*compare)(T, T));
	Node* merge(Node* left, Node* right, bool (*compare)(T, T));
	Node* split(Node* head);

public:
	LinkedList();			// constructor

    ~LinkedList();		// destructor

	// sort the linked list
	void sort(bool (*compare)(T, T));

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

	// check if the list contains an item
	// pre : none
	// post: none
	// return true if the list contains the item; otherwise returns false
	bool contains(T& item);

	// remove an item at a specified position in the list
	// pre : 0 <= index < size
	// post: item is removed the specified position in the list
	//       items after the position are shifted forward by 1 position
	//       size of list is decreased by 1

	// get an item at a specified position of the list (retrieve)
	// pre : 0 <= index < size
	// post: none
	// return the item in the specified index of the list
	T get(int index);

	// get an item by id
	// pre : none
	// post: none
	// return the item with the specified id
	T getById(int id);

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
};

template <typename T>
LinkedList<T>::LinkedList() {
	firstNode = NULL;
	backNode = NULL;
	size = 0;
}

template <typename T>
LinkedList<T>::~LinkedList() {
}

// Merge two sorted linked lists
template <typename T>
typename LinkedList<T>::Node* LinkedList<T>::merge(Node* left, Node* right, bool (*compare)(T, T)) {
	Node dummy;            // Dummy node to simplify edge cases
	Node* tail = &dummy;   // Pointer to track the merged list

	while (left && right) {
		if (compare(left->item, right->item)) {
			tail->next = left;
			left = left->next;
		}
		else {
			tail->next = right;
			right = right->next;
		}
		tail = tail->next;
	}

	// Attach the remaining nodes
	tail->next = (left) ? left : right;

	return dummy.next;  // Return the merged list, skipping the dummy node
}

// Find the middle node of the linked list
template <typename T>
typename LinkedList<T>::Node* LinkedList<T>::split(Node* head) {
	if (!head) return head;

	Node* slow = head;
	Node* fast = head->next;

	while (fast && fast->next) {
		slow = slow->next;
		fast = fast->next->next;
	}
	return slow;
}

// Merge sort implementation
template <typename T>
typename LinkedList<T>::Node* LinkedList<T>::mergeSort(Node* head, bool (*compare)(T, T)) {
	if (!head || !head->next) return head;

	Node* middle = split(head);
	Node* nextToMiddle = middle->next;
	middle->next = nullptr;

	Node* left = mergeSort(head, compare);
	Node* right = mergeSort(nextToMiddle, compare);

	return merge(left, right, compare);
}

// Merge sort function
template <typename T>
void LinkedList<T>::sort(bool (*compare)(T, T)) {
	firstNode = mergeSort(firstNode, compare);
}

template <typename T>
bool LinkedList<T>::add(T item) {
	Node* node = new Node;
	node->item = item;
	node->next = nullptr;

	if (size == 0) {
		firstNode = node;
	}
	else {
		Node* current = firstNode;
		while (current->next != nullptr) {
			current = current->next;
		}
		current->next = node;
	}
	size++;
	hashTable<T>->insert(size, item);
	return true;
}

template <typename T>
bool LinkedList<T>::add(int index, T item) {
	if (index < 0 || index > size) {
		return false;
	}

	Node* newNode = new Node;
	newNode->item = item;
	newNode->next = nullptr;

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
	}

	size++;  
	hashTable<T>->insert(size, item); 
	return true;
}

template <typename T>
bool LinkedList<T>::contains(T& item)  {
	Node* current = firstNode;
	while (current != nullptr) {
		if (current->item == item) {
			return true;
		}
		current = current->next;
	}
	return false;
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
T LinkedList<T>::getById(int id) {
	Node* current = firstNode;
	while (current != nullptr) {
		if (current->item->getId() == id) {
			return current->item;
		}
		current = current->next;
	}
	return T();
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