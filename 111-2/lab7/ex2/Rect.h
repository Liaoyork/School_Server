#ifndef RECT_H
#define RECT_H

#include "Shape.h"

class Rect : public Shape {
   private:
    int W;

   public:
    Rect(int,int,int,int);
    ~Rect();
    /* any member functions if necessary */
};

#endif
