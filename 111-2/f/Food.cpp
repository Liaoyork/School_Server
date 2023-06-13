#include "Food.h"

#include <iostream>
#include <string>

#include "Commodity.h"
using namespace std;
Food::Food(int* car, int* pro, int* fat, string name, int price) : Commodity(name, price) {
    cout << "";
    this->car_value = car;
    this->pro_value = pro;
    this->fat_value = fat;
    cal_score();
}

Food::~Food(){
    delete pro_value;
    delete fat_value;
    delete car_value;
    delete score;
    delete price;
}
void Food::cal_score() {
    score = new double(*pro_value / (double)*price);
}
void Food::show_spec() {
    cout << "=======================================" << endl;
    cout << "Name: " << Commodity::name << endl;
    cout << "price: " << *Commodity::price << endl;
    cout << "car: " << *car_value << endl;
    cout << "pro: " << *pro_value << endl;
    cout << "fat: " << *fat_value << endl;
    cout << "score: " << *Commodity::score << endl;
}
