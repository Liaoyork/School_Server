#include "Electronics.h"
#include <iostream>

using namespace std;

Electronics::Electronics(int length, int width){
    this->length = length;
    this->width = width;
    usage = false;
    charging = false;
}
bool Electronics::get_usage(){
    return usage;
}
void Electronics::set_usage(bool flag){
    usage = flag;
}
bool Electronics::get_charging(){
    return charging;
}
void Electronics::set_charging(bool flag){
    charging = flag;
}
void Electronics::charge(){
    charging = true;
}
void Electronics::poweron(){
    usage = true;
}
void Electronics::poweroff(){
    usage = false;
}
void Electronics::run(){
    for (int i = 0 ; i < length; i++){
        if (i == 0 || i == length - 1){
            cout << " ";
        } else {
            cout << "|";
        }
        if (i == 0 || i == length - 1){
            for (int j = 0; j < width; j++){
                cout << "-";
            }
        } else {
            if (usage){
                for (int j = 0 ; j < width; j++){
                    cout << "*";
                }
            } else {
                for (int j = 0; j < width; j++){
                    cout << " ";
                }
            }
        }
        if (i == 0 || i == length - 1){
            cout << " ";
        } else {
            cout << "|";
        }
        cout << endl;
    }
    charging = false;
}

int Electronics::getLen(){
    return length;
}

int Electronics::getWid(){
    return width;
}
