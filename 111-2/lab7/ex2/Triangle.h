#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "Shape.h"
class Triangle : public Shape {
   private:
    int L;
    int pos_x;
    int pos_y;
    int canvas_size;
    vector<Point> points;

   public:
    /* any member functions if necessary */
    Triangle(int, int, int, int);
    Triangle(int, int, int);
    // ~Triangle();
    void ComputePoints();
    void ComputePerimeter();
    void ComputeArea();
    vector<Point> getPoints();
};

#endif

