#include <iostream>
#include "Array.h"

using namespace std;

int main (){
    int le;
    cout << "please enter the initial length: ";
    cin >> le;
    cout << "please enter "<< le <<" integer numbers: ";
    int *arr = new int[le];
    for (int i = 0 ; i < le ; i++){
        cin >> arr[i];
    }
    Array a(arr, le);
    a.showArray();
    a.count_n();
    for (int i = 0 ; i < 2 ; i++){
        a.add_num();
        a.showArray();
        a.count_n();
    }
}
