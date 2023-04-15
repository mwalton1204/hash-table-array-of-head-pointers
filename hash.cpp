/*********************
Name: Michael Walton
COSC-2436-004
Purpose:
 - Design Hash Table ADT with Array of Head Pointers
**********************/

#include "hash.h"

HashTable::HashTable() {
    for(int i = 0; i < HASHTABLESIZE; i++) {
        hashTable[i] = NULL;
    }
    count = 0;
}

HashTable::~HashTable() {}

bool HashTable::addEntry(int id, string* data) {
    bool added = false;
    int position = hash(id);

    Node *newNode = new Node{{id, *data}, NULL};

    if (!hashTable[position]) {
        hashTable[position] = newNode;
        count++;
        added = true;
    } else{
        Node *current = hashTable[position];
        while(current->next) {
            current = current->next;
        }
        current->next = newNode;
        count++;
        added = true;
    }

    return added;
}

bool HashTable::removeEntry(int) {
    return true;
}

string HashTable::getEntry(int) {
    return 0;
}

int HashTable::getCount() {
    return count;
}

void HashTable::displayTable() {}

int HashTable::hash(int id) {
    return id % HASHTABLESIZE;
}