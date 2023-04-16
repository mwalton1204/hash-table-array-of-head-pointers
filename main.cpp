/*********************
Name: Michael Walton
COSC-2436-004
Purpose:
 - Design Hash Table ADT with Array of Head Pointers
**********************/

#include "main.h"

int main() {
    srand(time(NULL));
    HashTable table;
    int testIds[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26};
    string testData[] = {"A","B", "C", "D", "E", "F", "G", "H", "I", "J", "K", "L", "M", "N", "O", "P", "Q", "R", "S", "T", "U", "V", "W", "X", "Y", "Z"};

    cout << "-------------------\tTESTING INITIALIZED HASH TABLE\t-------------------\n\n";

    cout << "PRINTING HASH TABLE: " << "\n";
    table.displayTable();
    cout << "\n";
    cout << "TOTAL ENTRIES: " <<  table.getCount();
    cout << "\n\n";

    cout << "-------------------\tTESTING FILLING HASH TABLE WITH TEST DATA\t-------------------\n\n";

    int qtyEntries = (rand() % MAXENTRIES) + 1;

    for(int i = 0; i < qtyEntries; i++) {
        int randIndex = (rand() % 25) + 1;
        int newId = testIds[randIndex];
        string newData = testData[randIndex];

        cout << "ATTEMPTING TO ADD ENTRY [ID: " << newId << " STR: " << newData << "]";

        if(table.addEntry(newId, &newData)) {
            cout << " ... ADDED\n";
        } else {
            cout << " ... NOT ADDED\n";
        }
    }

    cout << "\nPRINTING HASH TABLE: " << "\n";
    table.displayTable();
    cout << "\n";
    cout << "TOTAL ENTRIES: " <<  table.getCount();
    cout << "\n\n";

    cout << "-------------------\tTESTING GETTING STR DATA FROM HASH TABLE\t-------------------\n\n";

    int qtyGets = (rand() % qtyEntries) + 1;

    for (int i = 0; i < qtyGets; i++) {
        int idToGet = (rand() % 25) + 1;

        cout << "ATTEMPTING TO RETRIEVE STR DATA FROM [ID : " << idToGet << "]";
        cout << "... RETRIEVED [STR: " << table.getEntry(idToGet) << "]\n";
    }

    cout << "\nPRINTING HASH TABLE: " << "\n";
    table.displayTable();
    cout << "\n";
    cout << "TOTAL ENTRIES: " <<  table.getCount();
    cout << "\n\n";

    cout << "-------------------\tTESTING REMOVING SOME ENTRIES FROM HASH TABLE\t-------------------\n\n";

    for (int i = 0; i < TESTDATASIZE; i++) {
        cout << "ATTEMPTING TO REMOVE ENTRY [ID: " << testIds[i] << " STR: " << testData[i] << "]";

        if(table.removeEntry(testIds[i])) {
            cout << " ... REMOVED\n";
        } else {
            cout << " ... NOT REMOVED\n";
        }
    }

    cout << "\nPRINTING HASH TABLE: " << "\n";
    table.displayTable();
    cout << "\n";
    cout << "TOTAL ENTRIES: " <<  table.getCount();
    cout << "\n\n";

    cout << "-------------------\tTESTING EMPTYING HASH TABLE\t-------------------\n\n";

    for(int i = 0; i < HASHTABLESIZE; i++) {
        while(table.getCount() != 0) {
            for(int i = 0; i < TESTDATASIZE; i++) {
                table.removeEntry(testIds[i]);
            }
        }
    }

    cout << "\nPRINTING HASH TABLE: " << "\n";
    table.displayTable();
    cout << "\n";
    cout << "TOTAL ENTRIES: " <<  table.getCount();
    cout << "\n\n";

    return 0;
}