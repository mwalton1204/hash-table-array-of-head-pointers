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

HashTable::~HashTable() {
    for (int i = 0; i < HASHTABLESIZE; i++) {
        Node *current = hashTable[i];
        while(current) {
            Node *tmpNode = current;
            current = current->next;
            delete tmpNode;
        }
        hashTable[i] = NULL;
    }
}

bool HashTable::addEntry(int id, string* data) {
    bool added = false;
    int position = hash(id);

    Node *newNode = new Node{{id, *data}, NULL};

    if (!hashTable[position]) {
        hashTable[position] = newNode;
        count++;
        added = true;
    } else if (hashTable[position]) {
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

bool HashTable::removeEntry(int id) {
    bool removed = false;
    int position = hash(id);

    if(hashTable[position]) {
        if(hashTable[position]->data.id == id) {
            Node* tmpNode = hashTable[position];
            hashTable[position] = tmpNode->next;
            delete tmpNode;
            count--;
            removed = true;
        } else {
            Node *current = hashTable[position];
            while(current->next && current->next->data.id != id) {
                current = current->next;
            }
            if(current->next && current->next->data.id == id) {
                Node* tmpNode = current->next;
                current->next = tmpNode->next;
                delete tmpNode;
                count--;
                removed = true;
            }
        }
    }

    return removed;
}

string HashTable::getEntry(int id) {
    int position = hash(id);
    Data tmpData{id, "ERROR: ID NOT FOUND"};

    if(hashTable[position]) {
        if(hashTable[position]->data.id == id) {
            tmpData.data = hashTable[position]->data.data;
        } else {
            Node *current = hashTable[position];
            while(current->next && current->next->data.id != id) {
                current = current->next;
            }
            if(current->next && current->next->data.id == id) {
                tmpData.data = current->data.data;
            }
        }
    }

    return tmpData.data;
}

int HashTable::getCount() {
    return count;
}

void HashTable::displayTable() {
    for(int i = 0; i < HASHTABLESIZE; i++) {
        Node *current = hashTable[i];
        cout << "Entry " << i + 1 << ": ";
        while(current) {
            cout << current->data.id;
            if (current->next) {
                cout << " -> ";
            }
            current = current ->next;
        }
        cout << "\n";
    }
}

int HashTable::hash(int id) {
    return id % HASHTABLESIZE;
}