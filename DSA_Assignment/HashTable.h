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
        // pre : none
        // post: a node is initialized with given key and value, next is set to nullptr
        Node(KeyType k, ValueType v) : key(k), value(v), next(nullptr) {}
    };

    Node** table;
    int max_size;
    int size;

    // Hash function to compute the index for a key
    // pre : key is a valid integer
    // post: returns the index in the table for the given key
    int hashFunction(KeyType key) const {
        return key % max_size;
    }

public:
    // Constructor
    HashTable(int max_size);

    // Destructor
    ~HashTable();

    // Insert a key-value pair into the hash table
    // pre : key is unique, value is valid
    // post: key-value pair is added; if key exists, the value is updated
    void insert(KeyType key, const ValueType& value);

    // Search a value by key
    // pre : key is a valid integer
    // post: returns a pointer to the value if found, nullptr otherwise
    ValueType* search(ValueType value);

    // Remove a key-value pair from the hash table
    // pre : key is a valid integer
    // post: key-value pair is removed if found; size is decreased
    void remove(KeyType key);

    // Display the hash table
    // pre : none
    // post: all key-value pairs are printed to the console
    void display() const;
};

// Constructor
template <typename ValueType>
HashTable<ValueType>::HashTable(int max_size) : max_size(max_size), size(0) {
    table = new Node * [max_size];
    for (int i = 0; i < max_size; ++i) {
        table[i] = nullptr;
    }
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
    delete[] table;
}

// Insert a key-value pair
template <typename ValueType>
void HashTable<ValueType>::insert(KeyType key, const ValueType& value) {
    int index = hashFunction(key);
    Node* newNode = new Node(key, value);

    if (!table[index]) {
        table[index] = newNode;
    }
    else {
        Node* current = table[index];
        while (current->next) {
            if (current->key == key) {
                current->value = value;
                delete newNode;
                return;
            }
            current = current->next;
        }
        current->next = newNode;
    }
    size++;
}

// Search a value by value
template <typename ValueType>
ValueType* HashTable<ValueType>::search(ValueType value) {
    for (int i = 0; i < max_size; i++) {
        Node* entry = table[i];
        while (entry) {
            if (entry->value == value) {
                return &entry->value;     
            }
            entry = entry->next;
        }
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
    cout << "Key not found!" << endl;
}

// Display the hash table
template <typename ValueType>
void HashTable<ValueType>::display() const {
    for (int i = 0; i < max_size; ++i) {
        cout << "Bucket " << i << ": ";
        Node* current = table[i];
        while (current) {
            cout << "[" << current->key << "] -> ";
            current->value.display();
            current = current->next;
        }
        cout << "NULL" << endl;
    }
}
