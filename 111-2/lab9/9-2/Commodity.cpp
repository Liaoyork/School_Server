#include "Commodity.h"

#include <iostream>
#include <string>
using namespace std;

Commodity::Commodity(string name, int price) {
    this->name = name;
    this->price = new int (price);
}
Commodity::~Commodity() {
}
