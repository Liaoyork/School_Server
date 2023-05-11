#include <iostream>

using namespace std;

#include "Array.h"

Array::Array(int *arr, int len){
    length = len;
    num_arr = arr;
}
Array::~Array(){
    ;
}

void Array::showArray(){
    cout << "The number in num_arr is ";
    for (int i = 0 ; i < length ; i++){
        cout << num_arr[i] << " ";
    }
    cout << endl;
}

void Array::add_num(){
    cout << "please enter a new number: ";
    int nu;
    cin >> nu;
    int *temp = new int[length];
    for (int i = 0 ; i < length ; i++){
        temp[i] = num_arr[i];
    }
    length++;
    delete [] num_arr;
    num_arr = new int[length];
    for (int i = 0 ; i < length - 1;i++){
        num_arr[i] = temp[i];
    }
    num_arr[length - 1] = nu;
}

int Array::count_n(){
    int tar;
    int cou = 0;
    cout << "please enter a counting number: ";
    cin >> tar;
    for (int i = 0 ; i < length ; i++){
        if (num_arr[i] == tar){
            cou++;
        }
    }
    cout << "The counting number appears "<< cou << " times in the num_arr" << endl;
    return cou;
}
