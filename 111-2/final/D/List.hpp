#ifndef L_
#define L_

#include <bits/stdc++.h>

#include "AbstractContainer.hpp"
#include "Node.h"
using namespace std;
template <class T>
class List : public virtual AbstractContainer<T> {
   public:
    List(T *a, int l) : AbstractContainer<T>(a, l) {
        Node<T> *n = new Node<T>;
        head = n;
        tail = n;
        n->data = -1;
        // n->data = a[0];
        for (int i = 0; i < l; i++) {
            Node<T> *ptr = new Node<T>;
            ptr->data = a[i];
            tail->next = ptr;
            ptr->pre = tail;
            tail = ptr;
            tail->next = nullptr;
        }
        n = new Node<T>;
        tail->next = n;
        n->pre = tail;
        n->next = nullptr;
        n->data = -1;
        tail = n;
    }
    void insert(int pos, T t) {
        this->len++;
        bool flag = false;
        Node<T> *add = new Node<T>;
        add->data = t;
        Node<T> *it = head;
        Node<T> *nn;
        for (int i = 0; i < pos; i++) {
            it = it->next;
            if (it->next == nullptr) {
                flag = true;
                break;
            }
        }
        if (flag) {
            it->next = add;
            add->pre = it;
            add->next = nullptr;
            tail = add;
        } else {
            nn = it->next;
            it->next = add;
            add->pre = it;
            add->next = nn;
            nn->pre = add;
        }
    }
    void erase(int pos) {
        if (pos == 0) {
            Node<T> *it = head->next;
            head->next = it->next;
            it->next->pre = head;
            delete it;
            this->len--;
            return;
        } else if (pos == this->len - 1) {
            Node<T> *it = tail->pre;
            tail->pre = it->pre;
            it->pre->next = tail;
            delete it;
            this->len--;
            return;
        } else {
            Node<T> *it = head;
            for (int i = 0; i < pos; i++) {
                it = it->next;
                if (it->next == nullptr) break;
            }
            Node<T> *nn = it->next->next;
            delete it->next;
            it->next = nn;
            nn->pre = it;
            this->len--;
            return;
        }
    }
    int size() {
        return this->len;
    }
    bool empty() {
        if (this->len == 0) return true;
        return false;
    }
    void clear() {
        for (int i = 0; i < this->len; i++) {
            erase(i);
        }
    }
    int begin() {
        return 0;
    }
    int end() {
        return this->len - 1;
    }
    void display() {
        cout << "nullptr <-> ";
        Node<T> *ptr = head->next;
        while (ptr->next) {
            cout << ptr->data << " <-> ";
            ptr = ptr->next;
        }
        cout << "nullptr" << endl;
    }
    ~List() {
        Node<T> *del = head;
        delete del;
        del = tail;
        delete del;
    }

   protected:
    Node<T> *head;
    Node<T> *tail;
};

#endif
