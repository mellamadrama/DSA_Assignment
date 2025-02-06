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
    ValueType* search(KeyType key);

    // Remove a key-value pair from the hash table
    void remove(KeyType key);

    // Display the hash table
    void display() const;
};

// Constructor
template <typename ValueType>
HashTable<ValueType>::HashTable(int max_size) : max_size(max_size), size(0) {
    table = new Node * [max_size]();  // Initialize all pointers to nullptr
}

// Destructor
template <typename ValueType>
HashTable<ValueType>::~HashTable() {
    cout << "Destructor called" << endl;
    for (int i = 0; i < max_size; ++i) {
        Node* current = table[i];
        while (current) {
            Node* temp = current;
            current = current->next;
            delete temp;
        }
    }
    delete[] table;
}

// Insert a key-value pair
template <typename ValueType>
void HashTable<ValueType>::insert(KeyType key, const ValueType& value) {
    int index = hashFunction(key);
    std::cout << "[DEBUG] Inserting key: " << key
        << " at index: " << index
        << " with value: " << value << std::endl;  // Assuming ValueType has getName()

    // Allocate new Node if table[index] is null
    if (table[index] == nullptr) {
        table[index] = new Node(key, value);
        std::cout << "[DEBUG] Inserted as new node at index " << index
            << " (no collision)" << std::endl;
    }
    else {
        Node* current = table[index];
        std::cout << "[DEBUG] Collision detected at index " << index
            << ", traversing linked list..." << std::endl;

        // Traverse the linked list to handle collisions
        while (current != nullptr) {
            std::cout << "[DEBUG] Checking node with key: " << current->key << std::endl;

            // Update value if key already exists
            if (current->key == key) {
                std::cout << "[DEBUG] Key " << key
                    << " already exists, updating value to "
                    << value << std::endl;
                current->value = value;
                return;
            }

            // Move to the next node
            if (current->next == nullptr) break;
            current = current->next;
        }

        // Add new node at the end of the linked list
        current->next = new Node(key, value);
        std::cout << "[DEBUG] Appended new node with key: " << key
            << " at index: " << index << std::endl;
    }

    size++;
    std::cout << "[DEBUG] Hash table size is now: " << size << std::endl;
}

// Search a value by key
template <typename ValueType>
ValueType* HashTable<ValueType>::search(KeyType key) {
    int index = hashFunction(key);
    Node* current = table[index];
	cout << "Searching for key " << key << " at index " << index << endl;
    while (current != nullptr) {
        return &current->value;
        current = current->next;
    }
    return nullptr;
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