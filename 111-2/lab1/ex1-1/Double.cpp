#include <iostream>

#include "Double.h"
using namespace std;
Double::Double(double inNum){
    num = inNum;
}

Double::~Double(){
    ;
}
double Double::Round(){
    int temp = 0;
    temp  = num * 10;
    if (temp % 10 >= 5){
        temp = int(num+1);
    }
    else {
        temp = int(num);
    }
    return double(temp);
}

double Double::Ceil(){
    int temp = int(num + 1);
    return double(temp);
}

double Double::Floor(){
    int temp = int(num);
    return double(temp);
}

void Double::showResult(){
     cout << "the beginning of the function" << endl;
     cout << "Round("<< num <<") = " << Round()<<endl;
     cout << "Ceil("<< num <<") = " << Ceil() << endl;
     cout << "Floor("<< num <<") = " << Floor() << endl;
     cout << "the end of of the function";
}

