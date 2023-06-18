#ifndef A_
#define A_

#include <bits/stdc++.h>

#include "Node.h"
using namespace std;

template <class T>
class AbstractContainer {
   protected:
    int len;
    T* arr;

   public:
    AbstractContainer(T a, int l) {
        len = l;
        arr = new T[l];
        for (int i = 0 ; i < l; i++){
            arr[i] = a;
        }
    }
    virtual ~AbstractContainer() = default;
    virtual void insert(int pos, T t) {
    }
    virtual void erase(T t) {
    }
    virtual int size() {
        return len;
    }
    virtual bool empty() {
        return true;
    }
    virtual void clear() {
    }
    virtual int begin() {
        return 0;
    }
    virtual int end() {
        return len - 1;
    }
    virtual void display() {
    }
};
#endif
