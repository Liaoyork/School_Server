#include <iostream>
#include "Array.h"

using namespace std;
using namespace Array;
int main (){
    int le;
    cout << "please enter the initial length: ";
    cin >> le;
    cout << "please enter "<< le <<" integer numbers: ";
    int *arr = new int[le];
    for (int i = 0 ; i < le ; i++){
        cin >> arr[i];
    }
    Arr a;
    a.num_arr = arr;
    a.length = le;
    showArray(a);
    count_n(a);
    for (int i = 0 ; i < 3 ; i++){
        add_num(a);
        showArray(a);
        count_n(a);
    }
}
