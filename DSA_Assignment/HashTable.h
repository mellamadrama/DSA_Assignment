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

        Node(KeyType k, ValueType v) : key(k), value(v), next(nullptr) {}
    };

    Node** table;
    int max_size;
    int size;

    int hashFunction(KeyType key) const {
        return key % max_size;
    }

public:
    HashTable(int max_size);
    ~HashTable();

    void insert(KeyType key, const ValueType& value);
    ValueType* find(KeyType key);
    void remove(KeyType key);
    void display() const;
};