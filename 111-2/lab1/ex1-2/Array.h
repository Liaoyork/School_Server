#ifndef ARRAY_H
#define ARRAY_H
#include <iostream>
using namespace std;
class Array{
private:
    int *num_arr;
    int length;
public:
    Array(int *,int);
    ~Array();
    void showArray();
    void add_num();
    int count_n();
};
#endif
