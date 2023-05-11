#include <iostream>
#include "HashTable-1.h"
using namespace std;
HashTable(int tableSize){
     this->tableSize = tableSize;
     tablePtr = new node[tableSize];
}
~HashTable();

void operator += (node n); //Insert data to hash table  
void printTable(){
    cout << "Home Addr\t" << "Prime Area\t" << "Overflow List" <<endl;
    for (int i = 0 ; i < tableSize ; i++){
        cout << i << "\t\t" << 
    }

}
void searchTable() {
    int key;
    cout << endl << "Please enter the item number: "; cin >> key;

}
void analyzeTable();

static int moduloDivision(int key, int tableSize); //Hashing function

