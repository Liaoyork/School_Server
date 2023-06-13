#include "Healthy.h"

#include <iostream>

#include "Commodity.h"
using namespace std;
Healthy::Healthy(string* Mn, int* Mi, int arr, string na, int pr) : Commodity(na, pr) {
    this->name_arr = Mn;
    this->value_arr = Mi;
    arr_length = arr;
    cal_score();
}
Healthy::~Healthy(){
    delete [] name_arr;
    delete [] value_arr;
    delete score;
    delete price;
}
void Healthy::cal_score() {
    double k = 0;
    for (int i = 0; i < arr_length; i++) {
        k += value_arr[i];
    }
    score = new double((k / *price));
}
void Healthy::show_spec() {
    cout << "=======================================" << endl;
    cout << "Name: " << Commodity::name << endl;
    cout << "price: " << *Commodity::price << endl;
    for (int i = 0; i < arr_length; i++) {
        cout << name_arr[i] << ": " << value_arr[i] << endl;
    }
    cout << "score: " << *Commodity::score << endl;
}
