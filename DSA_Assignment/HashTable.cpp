#include "HashTable.h"

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
                // Update existing value
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

// Search a value by key
template <typename ValueType>
ValueType* HashTable<ValueType>::search(KeyType key) {
    int index = hashFunction(key);
    Node* current = table[index];

    while (current) {
        if (current->key == key) {
            return &current->value;
        }
        current = current->next;
    }
    return nullptr; // Key not found
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
