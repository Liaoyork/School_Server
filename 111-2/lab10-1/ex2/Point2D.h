#ifndef _P_
#define _P_
#include <iostream>
using namespace std;
class Point2D
{
private:
    int x;
    int y;
public:
    //Add constructor by yourself
    Point2D() :x(1), y(1){
        ;
    }
    Point2D(int , Point2D());
    Point2D(int a,int b){
        x = a;
        y = b;
    }
    void operator = (const Point2D &);
    void set_x(int);
    void set_y(int);
    int get_x();
    int get_y();
    friend ostream &operator<<(ostream &os, const Point2D);
    Point2D operator*(const Point2D &);
    Point2D operator+=(const Point2D &);
};
#endif
