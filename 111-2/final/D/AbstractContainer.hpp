#ifndef A_
#define A_

#include <bits/stdc++.h>

using namespace std;

template<class T>
class AbstractContainer{
    protected:
        int len;
        T *arr;
    public:
        AbstractContainer(T*a,int l){
            len = l;
            arr = a;
        }
        void insert(T t,int pos){

        }
        void erase(T t){

        }
        int size(){

        }
        bool empty(){

        }
        void clear(){

        }
        T& begin(){

        }
        T& end(){

        }
        void display(){

        }
};
#endif
