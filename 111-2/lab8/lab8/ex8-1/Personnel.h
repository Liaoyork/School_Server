#pragma once
#include <string>

using namespace std;

class Personnel {
   private:
    string id;
    string name;
    string email;
    string password;

   public:
    Personnel();
    Personnel(string id, string name, string email, string password);

    virtual ~Personnel() = default;
    void printInfo();
    string getId();
    string getName() {
        return name;
    }
    string getMail() {
        return email;
    }
};
