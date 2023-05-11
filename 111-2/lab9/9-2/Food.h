#ifndef FOOD_H_
#define FOOD_H_
#include "Commodity.h"
using namespace std;
class Food : public Commodity {
   private:
    int* car_value;
    int* pro_value;
    int* fat_value;

   public:
    Food(int*, int*, int*, string, int);
    ~Food();
    void cal_score();
    void show_spec();
};
#endif  // FOOD_H_
