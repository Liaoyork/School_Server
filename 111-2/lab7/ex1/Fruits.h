#ifndef FRUITS_H
#define FRUITS_H
#include "Stocks.h"

class Fruits : public Stocks {
   private:
    int *expired_month;
    int *expired_date;

   public:
    /* any member functions if necessary */
    Fruits(int,int,int);
    ~Fruits();
    void operator=(Stocks&);
    void Display();
};

#endif
