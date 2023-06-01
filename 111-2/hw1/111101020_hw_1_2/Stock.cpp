#include "Stock.h"

#include <iostream>
#include <string>

using namespace std;

const double Stock::init_price = 57.88;
const double Stock::limit_ratio = 0.1;
double Stock::cur_price = init_price;
bool Stock::trade_available = true;

Stock::Stock() {
    ;
}
Stock::Stock(double av, int ti){
    avg_buy_price = av;
    ticket_num = ti;
}
Stock::Stock(string name) : owner_name(name) {
    ticket_num = 0;
    avg_buy_price = 0;
}
Stock::Stock(string name, int n1) {
}
// Stock(string name, double total1);
void Stock::operator+(const Stock &o1) {
    this->avg_buy_price = (this->avg_buy_price) * (this->ticket_num) + o1.avg_buy_price * o1.ticket_num;
    this->ticket_num = this->ticket_num + o1.ticket_num;
    this->avg_buy_price = this->avg_buy_price / this->ticket_num;
}
void Stock::operator-(const Stock &o1) {
    this->avg_buy_price = (this->avg_buy_price) * (this->ticket_num) - o1.avg_buy_price * o1.ticket_num;
    this->ticket_num = this->ticket_num - o1.ticket_num;
    this->avg_buy_price = this->avg_buy_price / this->ticket_num;
}
void Stock::buy() {
    Stock xx(this->avg_buy_price, this->ticket_num);
    if (!trade_available) {
        cout << "The trade is not available today." << endl;
        return;
    }
    cout << "How many tickets do you want to buy: ";
    int temp = 0;
    cin >> temp;
    Stock yy(cur_price,temp);
    *(this) + yy;
}
void Stock::sell() {
    if (!trade_available) {
        cout << "The trade is not available today." << endl;
        return;
    }
    cout << "How many tickets do you want to sell: ";
    int temp = 0;
    cin >> temp;
    if (ticket_num < temp) {
        cout << "you don't have enough stock ticket" << endl;
        return;
    }
    Stock yy(cur_price, temp);
    *(this) - yy;
}
void Stock::show_stock() {
    cout << owner_name << ", you have " << ticket_num << " stocks and the average price is " << avg_buy_price << endl;
}

string Stock::get_owner_name() const {
    return owner_name;
}

void Stock::show_current_price() {
    cout << "------------------------------------------" << endl;
    cout << "current price of the stock: " << cur_price << endl;
}
void Stock::check_trade_is_available() {
    double limit = init_price * limit_ratio;
    if (init_price - cur_price > limit) {
        trade_available = false;
        cout << "trade is not available anymore" << endl;
    }
}
void Stock::refresh_current_price() {
    cur_price = cur_price + double(rand() % 500) / 100 - 2.5;
    show_current_price();
}
