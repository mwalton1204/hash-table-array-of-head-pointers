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

    tmpId = 3;
    tmpString = "Hello";
    table.addEntry(tmpId, &tmpString);
    cout << "COUNT: " << table.getCount() << "\n\n";

    tmpId = 5;
    tmpString = "Hello";
    table.addEntry(tmpId, &tmpString);
    cout << "COUNT: " << table.getCount() << "\n\n";

    table.removeEntry(1);

    cout << "COUNT: " << table.getCount() << "\n\n";

    table.removeEntry(5);

    cout << "COUNT: " << table.getCount() << "\n\n";

    table.removeEntry(7);

    cout << "COUNT: " << table.getCount() << "\n\n";

    table.removeEntry(3);

    cout << "COUNT: " << table.getCount() << "\n\n";

    table.removeEntry(1);

    cout << "COUNT: " << table.getCount() << "\n\n";

    return 0;
}