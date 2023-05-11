#include <iostream>
using namespace std;

int main (){
    int *p;
    &p=3;
    int *q,*r,*t;
    r=q=t=p;
    cout << r; 
    cout << q;
    cout << t;
    cout << p;
}
