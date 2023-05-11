#include <iostream>
#include <string>
#include "test.h"

using namespace std;

int main (){
   double pri = 0; 
   string na = "";
   cout << "enter name: ";
   cin >> na;
   cout << "enter price: ";
   cin >> pri;
   airticket Ticket(na,pri);
   Ticket.takeprice();
   for (int i = 0 ; i < 2 ; i ++){
       Ticket.resetName();
       Ticket.resetPrice();
       Ticket.takeprice();
   }
   return 0;
}   
