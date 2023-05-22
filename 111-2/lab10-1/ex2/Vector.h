#ifndef _V_
#define _V_
#include <iostream>
#include "Point2D.h"
using namespace std;
// Vector.h
template <class T>
class Vector
{
private:
    int len;
    T* vec;
    friend Point2D dot (const Vector<Point2D> &o1, const Vector<Point2D> &o2);
public:
    // add any member if necessary
    void display(){
        for (int i = 0 ; i < len; i++){
            cout << vec[i] << " ";
        }
        cout << endl;
    }
    Vector(int a, T *k){
        len = a;
        vec = new T [len];
        for (int i = 0; i < len; i++){
            vec[i] = k[i];
        }
    }
    Vector(int a, T k){
        len = a;
        vec = new T [a];
        for (int i = 0 ; i < len; i++){
            vec[i] = k;
        }
    }
    Vector<T> &operator+= (const Vector<T> &rhs){
        for (int i = 0 ; i < len; i++){
            vec[i] += rhs.vec[i];
        }
        return *this;
    }
    template<class S>
    friend S dot (const Vector<S> &o1, const Vector<S> &o2);
    int getLen() const {
        return len;
    }
};
#endif
