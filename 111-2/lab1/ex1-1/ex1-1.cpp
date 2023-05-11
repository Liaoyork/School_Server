#include <iostream>
#include "Double.h"

using namespace std;
int main (){
    double dou;
    cout << "Please enter the number: ";
    cin >> dou;
    Double x(dou);
    x.showResult();
    return 0; 
}
