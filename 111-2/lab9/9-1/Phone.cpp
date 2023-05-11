#include "Phone.h"
#include <iostream>
#include <string>

using namespace std;


Phone::Phone(int in_rate,int out_rate,int len,int wid) : Electronics(len, wid){
    this->in_rate = in_rate;
    this->out_rate = out_rate;
    set_usage(false);
    set_charging(false);
}


void Phone::charge(){
    if (get_charging()) {
        set_charging(false);
    } else {
        set_charging(true);
    }
}

void Phone::poweron(){
    set_usage(true);
}

void Phone::poweroff(){
    set_usage(false);
}
void Phone::run(){
    if (get_charging()) current_power += in_rate;
    if (get_usage()) current_power -= out_rate;

    if (current_power > 100) current_power = 100;
    if (current_power < 0) current_power = 0;

    cout << "Phone: ";
    if (current_power == 0) set_usage(false);
    if (get_charging()){
        cout << "(charging) " << current_power << "%" << endl;
    } else {
        cout << "(not charging) " << current_power << "%" <<endl;
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
            if (get_usage() && current_power > 0){
                for (int j = 0 ; j < getWid(); j++){
                    cout << "*";
                }
            } else{
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
