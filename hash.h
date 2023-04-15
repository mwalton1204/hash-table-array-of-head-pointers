/*********************
Name: Michael Walton
COSC-2436-004
Purpose:
 - Design Hash Table ADT with Array of Head Pointers
**********************/

#ifndef HASH_H
#define HASH_H

#define HASHTABLESIZE 15

#include <string>
#include <iostream>

using std::string;
using std::cout;

//Standard Data Struct
struct Data {
    int id;
    string data;
};

//Standard Node Struct
struct Node {
    Data data;
    Node *next;
};

class HashTable {

public:

    HashTable();
    ~HashTable();

    bool addEntry(int, string*);
    bool removeEntry(int);
    string getEntry(int);
    int getCount();
    void displayTable();

private:

    int hash(int);

    int count;
    Node *hashTable[HASHTABLESIZE];

};

#endif //HASH_H