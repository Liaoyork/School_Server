#include "TV.h"
#include <iostream>

using namespace std;

TV::TV(int len, int wid) : Electronics(len,wid){
    ;
}

void TV::run(){
    cout << "TV: ";
    if (get_charging()){
        cout << "(charging) " << endl;
    } else {
        cout << "(not charging) " << endl;
        set_usage(false);
    }
    for (int i = 0 ; i < getLen(); i++){
        if (i == 0 || i == getLen() - 1){
            cout << " ";
        } else {
            cout << "|";
        }
        if (i == 0 || i == getLen() - 1){
            for (int j = 0; j < getWid(); j++){
                cout << "-";
            }
        } else {
            if (get_charging() && get_usage()){
                for (int j = 0 ; j < getWid(); j++){
                    cout << "*";
                }
            } else {
                for (int j = 0; j < getWid(); j++){
                    cout << " ";
                }
            }
        }
        if (i == 0 || i == getLen() - 1){
            cout << " ";
        } else {
            cout << "|";
        }
        cout << endl;
    }
}

void TV::charge(){
    if (get_charging()) set_charging(false);
    else set_charging(true);
}
