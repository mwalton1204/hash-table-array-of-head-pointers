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
    string tmpString = "One";
    table.addEntry(tmpId, &tmpString);
    cout << "COUNT: " << table.getCount() << "\n\n";

    tmpId = 3;
    tmpString = "Three";
    table.addEntry(tmpId, &tmpString);
    cout << "COUNT: " << table.getCount() << "\n\n";

    tmpId = 5;
    tmpString = "Five";
    table.addEntry(tmpId, &tmpString);
    cout << "COUNT: " << table.getCount() << "\n\n";

    tmpId = 35;
    tmpString = "Five";
    table.addEntry(tmpId, &tmpString);
    cout << "COUNT: " << table.getCount() << "\n\n";

tmpId = 95;
    tmpString = "Five";
    table.addEntry(tmpId, &tmpString);
    cout << "COUNT: " << table.getCount() << "\n\n";

    table.displayTable();

    cout << table.getEntry(1) << "\n\n";
    cout << table.getEntry(3) << "\n\n";
    cout << table.getEntry(5) << "\n\n";
    cout << table.getEntry(7) << "\n\n";

    table.removeEntry(1);

    cout << "COUNT: " << table.getCount() << "\n\n";

    cout << table.getEntry(1) << "\n\n";

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