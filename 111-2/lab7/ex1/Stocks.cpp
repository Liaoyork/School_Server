#include <iostream>
#include <string>
#include "Stocks.h"
#include "Fruits.h"
using namespace std;

Stocks::Stocks(int n){
    //type = NULL;
    type = new int;
    *type = n;
    //itemList = NULL;
    itemList = new string [n];
}

Stocks::~Stocks(){
    if (type) delete type;
    type = NULL;
    if (itemList) delete [] itemList;
    itemList = NULL;
}

void Stocks::Initialize(){
    cout << "Initialize" << endl;
    for (int i = 0 ; i < *type; i++){
        cout << "Item " << i + 1 << ": "; cin >> itemList[i];
    }
}

void Stocks::Display(){
    cout << "Item List: ";
    for (int i = 0; i < *type; i++){
        cout << itemList[i] << " ";
    }
    cout << endl;
}

void Stocks::setType(int n){
    if (type) delete type;
    type = NULL;
    type = new int;
    *type = n;
}


int *Stocks::getType(){
    return type;
}

string *Stocks::getitemList(){
    return itemList;
}

void Stocks::setitemList(string *p){
    itemList = new string [*type];
    itemList = p;
}

void Stocks::operator=(Fruits &o1){
    *this->type = *o1.type;
    if (itemList) delete [] itemList;
    itemList = new string [*type];
    for (int i = 0 ; i < *type; i++){
        itemList[i] = o1.getitemList()[i];
    }
}

void Stocks::operator=(Stocks &o1){
    *type = *o1.type;
    if (itemList) delete [] itemList;
    itemList = new string [*type];
    for (int i = 0 ; i < *type; i++){
        itemList[i] = o1.itemList[i];
    }
}
