#include <algorithm>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

#include "Commodity.h"
#include "Food.h"
#include "Healthy.h"

using namespace std;
bool sortScore(Commodity *a, Commodity *b) {
    return (a->name < b->name);
}
int main(int argc, char* argv[]) {
    vector<Commodity *> somethings;
    ifstream in(argv[1]);
    string ss;
    string *Mname = NULL;
    int *Min = NULL;
    int count = 0;
    while (in >> ss) {
        string name;
        int price;

        string *Mname = NULL;
        int *Min = NULL;
        if (ss[0] == 'H') {
            in >> ss;
            name = ss;
            in >> ss;
            price = stoi(ss);
            in >> ss;
            count = stoi(ss);
            Mname = new string[count];
            Min = new int[count];
            for (int i = 0; i < count; i++) {
                in >> ss;
                Mname[i] = ss;
                in >> ss;
                Min[i] = stoi(ss);
            }
            Healthy *p = new Healthy(Mname, Min, count, name, price);
            somethings.push_back(p);
        }
        int *c, *p, *f;
        if (ss[0] == 'F') {
            in >> ss;
            name = ss;
            in >> ss;
            price = stoi(ss);
            in >> ss;
            c = new int(stoi(ss));
            in >> ss;
            p = new int(stoi(ss));
            in >> ss;
            f = new int(stoi(ss));
            Food *m = new Food(c, p, f, name, price);
            somethings.push_back(m);
        }
    }

    sort(somethings.begin(), somethings.end(), sortScore);
    for (int i = 0; i < (int)somethings.size(); i++) {
        somethings[i]->show_spec();
        delete somethings[i];
    }
    cout << "=======================================" << endl;
}
