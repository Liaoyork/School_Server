#include "Stocks.h"
#include "Fruits.h"
#include <iostream>

using namespace std;

Fruits::Fruits(int ty,int mo = 0, int da = 0) : Stocks(ty){
    expired_month = new int; 
    *expired_month = mo;
    expired_date = new int;
    *expired_date = da;
}


Fruits::~Fruits(){
    if (expired_date) delete expired_date;
    expired_date = NULL;
    if (expired_month) delete expired_month;
    expired_month = NULL;
}

void Fruits::operator=(Stocks &o1){
    /* 
    if (this->getitemList()) delete [] this->getitemList();
    this->setType(*(o1.getType()));
    string *p = new string [*getType()];
    this->setitemList(p);
    for (int i = 0 ; i < *getType() ; i++){
        p[i] = o1.getitemList()[i];
    }
    
    *this->getType() = *o1.getType();
    if (this->getitemList()) delete [] this->getitemList();
     
    string *p = new string [*getType()];
    this->setitemList(p);
    for (int i = 0 ; i < *getType() ; i++){
        p[i] = o1.getitemList()[i];
    }
    p = NULL;
    delete [] p;
    *this->getType() = *o1.getType();
    */
    Stocks::operator=(o1);
    *this->expired_month = 0;
    *this->expired_date = 0;
}

void Fruits::Display(){
    Stocks::Display();
    if (*expired_month == 0) cout << "No Expiration Date" << endl;
    else {
        cout << "Expired at " << *expired_month << "/" << *expired_date << endl;
    }
}
