#ifndef HEALTHY_H_
#define HEALTHY_H_
#include "Commodity.h"
using namespace std;
class Healthy : public Commodity {
   private:
    string* name_arr;
    int* value_arr;
    int arr_length;

   public:
    Healthy(string*, int*, int, string, int);
    ~Healthy();
    void cal_score();
    void show_spec();
};
#endif  // HEALTHY_H_
