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
    ValueType* search(KeyType key);

    // Remove a key-value pair from the hash table
    // pre : key is a valid integer
    // post: key-value pair is removed if found; size is decreased
    void remove(KeyType key);

    // Display the hash table
    // pre : none
    // post: all key-value pairs are printed to the console
    void display() const;
};