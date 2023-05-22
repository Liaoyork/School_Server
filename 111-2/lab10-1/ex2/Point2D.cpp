#include "Point2D.h"
#include "Vector.h"

void Point2D::operator = (const Point2D &o1){
    x = o1.x;
    y = o1.y;
}
void Point2D::set_x(int a){
    x = a;
}
void Point2D::set_y(int b){
    y = b;
}
int Point2D::get_x(){
    return x;
}
int Point2D::get_y(){
    return y;
}

ostream & operator << (ostream &out,const Point2D o1){
    cout << "(" << o1.x << ", " << o1.y << ") ";
    return out;
}

Point2D Point2D::operator*(const Point2D &o1){
    this->x = this->x * o1.x;
    this->y = this->y * o1.y;
    return *this;
}

Point2D Point2D::operator+=(const Point2D &o1){
    this->x = this->x + o1.x;
    this->y = this->y + o1.y;
    return *this;
}
