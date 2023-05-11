#ifndef CIRCLE_H
#define CIRCLE_H

#include "Shape.h"
#define PI 3.14

class Circle : public Shape {
   private:
       int L;
       int pos_x;
       int pos_y;
       int canvas_size;
       vector<Point> points;
   public:
    Circle(int, int ,int ,int);
    Circle(int, int ,int);
    void ComputeArea();
    void ComputePerimeter();
    void ComputePoints();
    void draw();
    /* any member functions if necessary */
};
#endif
