#ifndef SQUARE_H
#define SQUARE_H

#include "Rect.h"
class Square : public Rect {
   private:
    vector<Point> points;

   public:
    /* any member functions if necessary */
    Square(int, int, int, int);
    void ComputePoints();
    void ComputePerimeter();
    void ComputeArea();
    vector<Point> getPoints();
};

#endif

