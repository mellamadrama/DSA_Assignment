/*
* Name: Hervin Sie(S10262115C), Charlotte Lee(s10258027k)
* Group: 6
*/

#pragma once
#include <iostream>
using namespace std;

typedef int KeyType;
template <typename ValueType>

class HashTable {
private:
    struct Node {
        KeyType key;
        ValueType value;
        Node* next;

        // Node constructor
        Node(KeyType k, ValueType v) : key(k), value(v), next(nullptr) {}
    };

    int max_size;
    int size;
    Node** table;

    // Hash function to compute the index for a key
    int hashFunction(KeyType key) const {
        return key % max_size;
    }

public:
    // Constructor
    HashTable(int max_size);

    // Destructor
    ~HashTable();

    // Insert a key-value pair into the hash table
    void insert(KeyType key, const ValueType& value);

    // Search a value by key
    ValueType& search(KeyType key);

    // Search a value by id
    ValueType* searchById(int id);

    // Remove a key-value pair from the hash table
    void remove(KeyType key);
};

// Constructor
template <typename ValueType>
HashTable<ValueType>::HashTable(int size) {
    table = new Node * [size];
    for (int i = 0; i < size; ++i) {
        table[i] = nullptr;
    }
    max_size = size;
    this->size = 0;
}

// Destructor
template <typename ValueType>
HashTable<ValueType>::~HashTable() {
    for (int i = 0; i < max_size; ++i) {
        Node* current = table[i];
        while (current) {
            Node* temp = current;
            current = current->next;
            delete temp;
        }
    }
}

// Insert a key-value pair
template <typename ValueType>
void HashTable<ValueType>::insert(KeyType key, const ValueType& value) {
    int index = hashFunction(key);
    // Allocate new Node if table[index] is null
    if (table[index] == nullptr) {
        table[index] = new Node(key, value);
    }
    else {
        Node* current = table[index];

        // Traverse the linked list to handle collisions
        while (current->next != nullptr) {
            // Update value if key already exists
            if (current->key == key) {
                current->value = value;
                return;
            }
            current = current->next;
        }

        // Add new node at the end of the linked list
        current->next = new Node(key, value);
    }
    size++;

}

// Search a value by key
template <typename ValueType>
ValueType& HashTable<ValueType>::search(KeyType key) {
    int index = hashFunction(key);
    Node* current = table[index];

    while (current != nullptr) {
		if (current->key == key) {
			return current->value;
		}
		current = current->next;
    }
    throw std::runtime_error("Key not found in the hash table.");
}

// Remove a key-value pair
template <typename ValueType>
void HashTable<ValueType>::remove(KeyType key) {
    int index = hashFunction(key);
    Node* current = table[index];
    Node* prev = nullptr;

    while (current) {
        if (current->key == key) {
            if (prev) {
                prev->next = current->next;
            }
            else {
                table[index] = current->next;
            }
            delete current;
            size--;
            return;
        }
        prev = current;
        current = current->next;
    }
}