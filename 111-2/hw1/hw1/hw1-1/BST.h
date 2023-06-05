// BST.h
#ifndef BST_H
#define BST_H
#include <iostream>
using namespace std;
struct node {
    void* dataPtr;
    node* left;
    node* right;
};
class BST{
   private:
    int count;
    int (*compare)(void* argu1, void* argu2);
    node* root;
   public:
    BST();
    BST(int (*compare)(void* argu1, void* argu2));
    ~BST();
    bool BST_Insert(void* dataPtr);
    bool BST_Delete(void* dltKey);
    void BST_Traverse(void (*process)(void* dataPtr));
    bool BST_Empty();
    bool BST_Full();
    int BST_Count();
    void gogo(node*,void(*)(void*));
    node *gogoD(node*, void*);
    node* _insert(node* root, node* newPtr);  // Call by BST_Insert
    bool go(node*);
};
#endif
