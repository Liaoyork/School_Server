#ifndef STOCKS_H
#define STOCKS_H
#include <iostream>
#include <string>
using namespace std;
class Fruits;
class Stocks {
   private:
    int* type;         // number of stock types
    string* itemList;  // store all stock name

   public:
    /* any member functions if necessary */
    Stocks(int);
    ~Stocks();
    void Initialize();
    void Display();
    void setType(int);
    int *getType();
    string *getitemList();
    void setitemList(string *);
    void operator=(Fruits &);
    void operator=(Stocks &);
};

#endif
