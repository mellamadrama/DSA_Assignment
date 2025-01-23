#pragma once
#include "LinkedList.h"

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
