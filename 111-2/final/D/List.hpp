#ifndef L_
#define L_

#include <bits/stdc++.h>
#include "AbstractContainer.hpp"
#include "Node.h"
using namespace std;

template<class T>
class List : virtual public AbstractContainer<T>{
    public:
        List(T *a,int l) :AbstractContainer<T>(a, l){
            this->len = l;
            first = true;
            Node<T> *n = new Node<T> [l]; 
            head = n;
            tail = n;
            for (int i = 0 ; i < l; i++){
                if (first) {
                    n->data = a[i];
                    first = false; 
                    continue;
                }
                else {
                    Node<T> * ptr = new Node<T>;
                    ptr->data = a[i];
                    head->next = ptr;
                    ptr->pre = tail;
                    tail = ptr;
                    tail->next = nullptr;
                }
            }
        }
        void insert(T t,int pos){
            Node<T> *add = new Node<T>;
            add->data = t;
            Node<T> *it = head;
            Node<T> *nn = head;
            for (int i = 0; i < pos; i++){
                it = it->next;
                nn = nn->next;
            }
            nn = nn->next;
            add->pre = it;
            it->next = add;
            add->next = nn;
            nn->pre = add;
            this->len++;
        }
        void erase(int pos){
            this->len--;
            Node<T> *it = head;
            Node<T> *nn = head;
            for (int i = 0; i < pos; i++){
                it = it->next;
                nn = nn->next;
            }
            Node<T> *del;
            del = nn->next;
            nn = nn->next->next;
            nn->pre = it;
            it->next = nn;
            delete del;
            this->len--;
        }
        int size(){
            return this->len;
        }
        bool empty(){
            if (this->len == 0) return true;
            return false;
        }
        void clear(){
            delete [] this->arr;
        }
        T& begin(){
            return &head;
        }
        T& end(){
            return &tail;
        }
        void display(){
            cout << "nullptr <-> ";
            Node<T> *ptr = head;
            while(ptr->next){
                cout << ptr->data << " <-> ";
                ptr = ptr->next;
            }
        }
    protected:
        bool first;
        Node<T> *head;
        Node<T> *tail;
};

#endif
