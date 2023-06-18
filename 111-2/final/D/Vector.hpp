#ifndef V_
#define V_
#include "AbstractContainer.hpp"
#include <bits/stdc++.h>

using namespace std;
template <class T>
class Vector : virtual public AbstractContainer<T>{
    public:
        Vector(int l, T b) :AbstractContainer<T>(b,l){
            capa = l;
        }
        int capacity(){
            return this->capa;
        }
        void display(){
            for (int i = 0; i < this->len; i++){
                cout << this->arr[i] << " ";
            }
            cout << endl;
        }
        void insert(int pos, T t){
            this->len++;
            T* ans = new T [this->len];
            for (int i = 0 ; i < pos; i++){
                ans[i] = this->arr[i];
            }
            ans[pos] = t;
            for (int i = pos + 1; i < this->len; i++){
                ans[i] = this->arr[i - 1];
            }
            delete [] this->arr;
            if (this->len >= capa) capa *= 2;
            this->arr = ans;
        }
        void push_back(T t){
            this->len++;
            T* ans = new T [this->len];
            for (int i = 0 ; i < this->len - 1; i++){
                ans[i] = this->arr[i];
            }
            ans[this->len - 1] = t;
            delete [] this->arr;
            this->arr = ans;
        }
        void pop_back(){
            this->len--;
            T *ans = new T [this->len];
            for (int i = 0; i < this->len; i++){
                ans[i] = this->arr[i];
            }
            delete [] this->arr;
            this->arr = ans;
        }
        T operator[] (int index){
            return this->arr[index];
        }
        void erase (int pos){
            this->len--;
            T* ans = new T [this->len];
            for (int i = 0; i < pos; i++){
                ans[i] =  this->arr[i];
            }
            for (int i = pos; i < this->len; i++){
                ans[i] = this->arr[i + 1];
            }
            delete [] this->arr;
            this->arr = ans;
        }
        bool empty(){
            if (this->len > 0) return false;
            return true;
        }
        int size(){
            return this->len;
        }
        void clear(){
            delete [] this->arr;
            this->len = 0;
        }
    protected:
        int capa;
};

#endif
