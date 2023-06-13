#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *next;
};

void InsertionSort(int *a, int n) {
    for (int i = 1; i < n; i++) {
        int j = i - 1;
        int key = a[i];
        while (j >= 0 && a[j] > key) {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = key;
    }
}

int main() {
    //need pass the valgrind
    srand(0);
    int *a;
    a = new int[5];
    for (int i = 0; i < 5; i++) {
        a[i] = rand() % 100;
    }
    int *b;
    b = new int[7];
    for (int i = 0; i < 7; i++) {
        b[i] = rand() % 100;
    }
    // sort
    InsertionSort(a, 5);
    InsertionSort(b, 7);
    //create list
    Node *head1 = new Node;
    head1->data = a[0];
    head1->next = NULL;
    Node *head2 = new Node;
    head2->data = b[0];
    head2->next = NULL;
    Node *p = head1;
    for (int i = 1; i < 5; i++) {
        Node *tmp = new Node;
        tmp->data = a[i];
        tmp->next = NULL;
        p->next = tmp;
        p = p->next;
    }
    p = head2;
    for (int i = 1; i < 7; i++) {
        Node *tmp = new Node;
        tmp->data = b[i];
        tmp->next = NULL;
        p->next = tmp;
        p = p->next;
    }
    //merge
    Node *head = new Node;
    head->next = NULL;
    p = head;
    Node *p1 = head1;
    Node *p2 = head2;
    while (p1 != NULL && p2 != NULL) {
        if (p1->data < p2->data) {
            Node *tmp = new Node;
            tmp->data = p1->data;
            tmp->next = NULL;
            p->next = tmp;
            p = p->next;
            p1 = p1->next;
        } else {
            Node *tmp = new Node;
            tmp->data = p2->data;
            tmp->next = NULL;
            p->next = tmp;
            p = p->next;
            p2 = p2->next;
        }
    }
    while (p1 != NULL) {
        Node *tmp = new Node;
        tmp->data = p1->data;
        tmp->next = NULL;
        p->next = tmp;
        p = p->next;
        p1 = p1->next;
    }
    while (p2 != NULL) {
        Node *tmp = new Node;
        tmp->data = p2->data;
        tmp->next = NULL;
        p->next = tmp;
        p = p->next;
        p2 = p2->next;
    }
    //print
    p = head->next;
    while (p != NULL) {
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;
    //delete
    p = head1;
    while (p != NULL) {
        Node *tmp = p;
        p = p->next;
        delete tmp;
    }
    p = head2;
    while (p != NULL) {
        Node *tmp = p;
        p = p->next;
        delete tmp;
    }
    p = head;
    while (p != NULL) {
        Node *tmp = p;
        p = p->next;
        delete tmp;
    }
    delete[] a;
    delete[] b;
    
    return 0;
}
