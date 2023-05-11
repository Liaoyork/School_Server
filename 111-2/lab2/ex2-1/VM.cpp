#include "VM.h"

#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool owner = true;

VM::VM() {
}
VM::~VM() {
}

void VM::start() {
    string password;
    password = set_password();
st:

    int cmd = 0;
    cout << "Enter 1 for owner mode, 2 for customer mode: ";
    cin >> cmd;
    if (cmd >= 3) {
        cout << "Invalid input!" << endl;
        goto st;
    }
    if (cmd == 1) {
        string password_in;
        while (password != password_in) {
            cout << "Please enter your password: ";
            cin >> password_in;
            if (password != password_in) {
                cout << "Wrong password!" << endl;
                cout << "Enter 1 for type again, 2 for going back to last step: ";
                cin >> cmd;
                if (cmd == 1) {
                    continue;
                } else if (cmd == 2) {
                    goto st;
                }
            }
        }
        owner = true;
        print_optionList();
        goto st;
    }
    if (cmd == 2) {
        owner = false;
        print_optionList();
        goto st;
    }
}

void VM::add_item() {
    item items;
    int I;
    string Na;
    int Pri;
    cout << "Please enter the information of the item." << endl;
    cout << "ID: ";
    cin >> items.id;
    cout << "Name: ";
    cin >> items.name;
    cout << "Price: ";
    cin >> items.price;
    item_vec.push_back(items);
}

void VM::remove_item() {
    bool find = false;
    string na;
    cout << "The name of the item you want to remove: ";
    cin >> na;
    for (int i = 0; i < item_vec.size(); i++) {
        if (item_vec[i].name == na) {
            item_vec.erase(item_vec.begin() + i);
            find = true;
            continue;
        }
    }
    if (!find) {
        cout << "No item found!" << endl;
    }
}

void VM::find_change(item item_a, int one, int five, int ten, int fifty) {
    int total = one + five * 5 + ten * 10 + fifty * 50;
    int coin[4] = {0};
    if (total == item_a.price) {
        cout << "No change should be given." << endl;
    } else {
        cout << "Your change" << endl;
        int remain = total - item_a.price;
        cout << "remain = " << remain << endl;
        if (remain >= 50) {
            coin[3] = remain / 50;
            remain = remain - coin[3] * 50;
        }
        if (remain >= 10) {
            coin[2] = remain / 10;
            remain = remain - coin[2] * 10;
        }
        if (remain >= 5) {
            coin[1] = remain / 5;
            remain = remain - coin[1] * 5;
        }
        if (remain > 0) {
            coin[0] = remain;
        }
        cout << "One dollar: " << coin[0] << endl;
        cout << "Five dollar: " << coin[1] << endl;
        cout << "Ten dollar: " << coin[2] << endl;
        cout << "Fifty dollar: " << coin[3] << endl;
    }
    for (int i = 0; i < item_vec.size(); i++) {
        if (item_vec[i].id == item_a.id) {
            item_vec.erase(item_vec.begin() + i);
            continue;
        }
    }
    cout << "Thank you for your purchase!" << endl;
}

void VM::purchase_item() {
    bool get = false;
    string it;
    cin >> it;
    for (int i = 0; i < item_vec.size(); i++) {
        if (item_vec[i].name == it) {
            get = true;
            cout << "The price is " << item_vec[i].price << " dollars" << endl;
            cout << "Please insert coins." << endl;
            int one = 0, five = 0, ten = 0, fifty = 0;
            cout << "One dollar: ";
            cin >> one;
            cout << "Five dollar: ";
            cin >> five;
            cout << "Ten dollar: ";
            cin >> ten;
            cout << "Fifty dollar: ";
            cin >> fifty;
            find_change(item_vec[i], one, five, ten, fifty);
            continue;
        }
    }
    if (!get) {
        cout << "Out of stock!" << endl;
    }
}

void VM::print_itemList() {
    for (int i = 0; i < item_vec.size(); i++) {
        for (int j = 0; j < item_vec.size(); j++) {
            if (item_vec[i].id < item_vec[j].id) {
                swap(item_vec[i], item_vec[j]);
            }
        }
    }

    if (item_vec.size() != 0) {
        cout << "ID\tName\tPrice" << endl;
        for (int i = 0; i < item_vec.size(); i++) {
            cout << item_vec[i].id << "\t"
                 << item_vec[i].name << "\t"
                 << item_vec[i].price << endl;
        }
    } else {
        cout << "There is no item right now!!!" << endl;
    }
}

void VM::print_optionList() {
    int cmd = 0;
    if (owner) {
        cout << "Welcome to owner mode!" << endl;
        cout << "1. Add item" << endl;
        cout << "2. Remove item" << endl;
        cout << "3. Print item list" << endl;
        cin >> cmd;
        switch (cmd) {
            case 1:
                add_item();
                break;
            case 2:
                remove_item();
                break;
            case 3:
                print_itemList();
                break;
        }
    } else {
        if (item_vec.size() == 0) {
            cout << "Sorry! There is no item right now." << endl;
        } else {
            cout << "Welcome! Here is the item list." << endl;
            print_itemList();
            cout << "Which item do you want to buy?" << endl;
            purchase_item();
        }
    }
}

string VM::set_password() {
    string password = "1", password_c = "0";
    while (password != password_c) {
        cout << "Enter a password for your vending machine: ";
        cin >> password;
        cout << "Enter your password again: ";
        cin >> password_c;
        if (password != password_c) {
            cout << "It's different from the first password! Please set the password again!" << endl;
        }
    }
    return password;
}
