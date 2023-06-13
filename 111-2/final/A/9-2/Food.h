#ifndef FOOD_H_
#define FOOD_H_
#include <bits/stdc++.h>
#include "Commodity.h"
using namespace std;
class Food : public Commodity {
   private:
    vector<int*> ptr_vec;
   public:
    Food(int*, int*, int*, string, int);
    ~Food();
    void cal_score();
    void show_spec();
};
#endif  // FOOD_H_
