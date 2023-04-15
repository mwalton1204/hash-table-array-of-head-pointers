/*********************
Name: Michael Walton
COSC-2436-004
Purpose:
 - Design Hash Table ADT with Array of Head Pointers
**********************/

#include "main.h"

int main() {
    HashTable table;

    cout << "COUNT: " << table.getCount() << "\n\n";

    int tmpId = 1;
    string tmpString = "Hello";

    table.addEntry(tmpId, &tmpString);

    cout << "COUNT: " << table.getCount() << "\n\n";

    table.addEntry(tmpId, &tmpString);

    cout << "COUNT: " << table.getCount() << "\n\n";

    table.addEntry(tmpId, &tmpString);

    cout << "COUNT: " << table.getCount() << "\n\n";


    return 0;
}