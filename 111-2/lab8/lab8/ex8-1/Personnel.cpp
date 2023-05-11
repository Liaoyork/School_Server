#include "Personnel.h"

#include <iostream>

using namespace std;

Personnel::Personnel() {
    ;
}
Personnel::Personnel(string id, string name, string email, string password) {
    this->id = id;
    this->name = name;
    this->email = email;
    this->password = password;
}

void Personnel::printInfo() {
    cout << "id: " << id << "\t"
         << "name: " << name << "\t"
         << "email: " << email << "\t";
}
string Personnel::getId() {
    return id;
}
