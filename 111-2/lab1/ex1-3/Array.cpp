#include <iostream>

using namespace std;

#include "Array.h"


void Array::showArray(Arr &a){
    cout << "The number in num_arr is ";
    for (int i = 0 ; i < a.length ; i++){
        cout << a.num_arr[i] << " ";
    }
    cout << endl;
}

void Array::add_num(Arr &a){
    cout << "please enter a new number: ";
    int nu;
    cin >> nu;
    int *temp = new int[a.length];
    for (int i = 0 ; i < a.length ; i++){
        temp[i] = a.num_arr[i];
    }
    a.length++;
    delete [] a.num_arr;
    a.num_arr = new int[a.length];
    for (int i = 0 ; i < a.length - 1;i++){
        a.num_arr[i] = temp[i];
    }
    a.num_arr[a.length - 1] = nu;
}

int Array::count_n(Arr &a){
    int tar;
    int cou = 0;
    cout << "please enter a counting number: ";
    cin >> tar;
    for (int i = 0 ; i < a.length ; i++){
        if (a.num_arr[i] == tar){
            cou++;
        }
    }
    cout << "The counting number appears "<< cou << " times in the num_arr" << endl;
    return cou;
}
