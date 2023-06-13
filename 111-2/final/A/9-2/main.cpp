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
            vector<int> k;
            vector<string> s_k;
            int time = 1;
            string ss_i;

            in >> ss;
            s_k.push_back(ss);
            in >> ss;
            k.push_back(stoi(ss));
            
            while(time != count){
                in >> ss;
                for (int i = 0; i < (int)s_k.size(); i++){
                    if (ss == s_k[i]){
                        in >> ss_i;
                        k[i] = k[i] + stoi(ss_i);
                        break;
                    } else if (i == (int)s_k.size() - 1 && ss != s_k[i]){
                        in >> ss_i;
                        k.push_back(stoi(ss_i));
                        s_k.push_back(ss);
                        break;
                    }
                }
                time++;
            }
            for (int i = 0 ;i < (int)k.size(); i++){
                for (int j = 0 ; j < (int)k.size(); j++){
                    if (s_k[i] < s_k[j]){
                        swap(s_k[i],s_k[j]);
                        swap(k[i],k[j]);
                    }
                }
            }
            Mname = new string[s_k.size()];
            Min = new int [k.size()];
            
            for (int i =0 ; i < (int)k.size(); i++){
                Mname[i] = s_k[i];
                Min[i] = k[i];
            }
            
            Healthy *p = new Healthy(Mname, Min, (int)s_k.size(), name, price);
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
