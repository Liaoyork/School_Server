#include <iostream>
#include <string>
#include "test.h"

using namespace std;

airticket::airticket(string na, double pri){
    price = pri;
    name = na;
}

airticket::~airticket(){
    ;
}

void airticket::resetName(){
    string na = "";
    cout << "Please enter the new name";
    cin >> na;
    name = na;
}

void airticket::resetPrice(){
    double pri = 0;
    cout << "Please enter new ticket price";
    cin >> pri;
    price = pri;
}

void airticket::takeprice(){
    double newPri = 0;
    if (price > 10000){
        newPri = price * 0.9;
    }
    else {
        newPri = price * 0.95;
    }
    cout << "your name is " << name << " and "
         <<"your ticket costs you $" << newPri << " dollars." << endl;
}
