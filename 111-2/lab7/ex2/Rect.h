#ifndef RECT_H
#define RECT_H

#include "Shape.h"

class Rect : public Shape {
   private:
    int W;
    vector<Point> points;

   public:
    Rect(int, int, int, int, int can);
    Rect(int, int, int, int);
    // ~Rect();
    /* any member functions if necessary */
    void ComputePoints();
    void ComputePerimeter();
    void ComputeArea();
    vector<Point> getPoints();
};

#endif

