#include "Food.h"

#include <iostream>
#include <string>

#include "Commodity.h"
using namespace std;
Food::Food(int* car, int* pro, int* fat, string name, int price) : Commodity(name, price) {
    cout << "";
    ptr_vec.push_back(car);
    ptr_vec.push_back(pro);
    ptr_vec.push_back(fat);
    cal_score();
}

Food::~Food(){
    for (auto p : ptr_vec){
        delete p;
    }
    delete score;
    delete price;
}
void Food::cal_score() {
    int a = 0;
    score = new double((double)*ptr_vec[1] / (double)*price);
}
void Food::show_spec() {
    cout << "=======================================" << endl;
    cout << "Name: " << Commodity::name << endl;
    cout << "price: " << *Commodity::price << endl;
    cout << "car: " << *ptr_vec[0] << endl;
    cout << "pro: " << *ptr_vec[1] << endl;
    cout << "fat: " << *ptr_vec[2] << endl;
    cout << "score: " << *Commodity::score << endl;
}
