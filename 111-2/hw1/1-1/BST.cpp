#include <iostream>
#include "BST.h"

using namespace std;

bool findD = false;

void BST::gogo(node *ptr, void (*fp)(void *data)){
    if (count == 0){
        cout << "The BST is empty.";
        return;
    }
    if (ptr == NULL) return;
    gogo(ptr->left, fp);
    fp(ptr->dataPtr);
    gogo(ptr->right, fp);
}

node* BST::gogoD(node *root, void *dltKey){
    if (root == NULL) return root;
    else if (*(int*)dltKey < *(int*)(root->dataPtr)) root->left = gogoD(root->left, dltKey);
    else if (*(int*)dltKey > *(int*)(root->dataPtr)) root-> right = gogoD(root->right, dltKey);
    else {
        //with no child
        if (root->left == NULL && root->right == NULL){
            delete root;
            root = NULL;
            findD = true;
            return root;
        }
        //have one child
        else if (root->left == NULL){
            node *temp = root;
            root = root->right;
            delete temp;
            findD = true;
            return root;

        }
        else if (root->right == NULL){
            node *temp = root;
            root = root->left;
            delete temp;
            findD = true;
            return root;
        }
        //have two child
        else {
            findD = true;
            node *temp = root->right;
            root->dataPtr = temp->dataPtr;
            root->right = gogoD(root->right, temp->dataPtr);
        }
    }
    return root;
}

BST::BST(int (*compare)(void* argu1, void* argu2)){
    root = NULL;
    count = 0;
}
BST::~BST(){
    ;
}
node* BST::_insert(node* root, node* newPtr){
   return root;
}
bool BST::BST_Insert(void* data){
    node *newPtr = new node;
    newPtr->dataPtr = new void*;
    *(int*)(newPtr->dataPtr) = *(int*)(data);
    node *ptr = this->root , *curr;
    bool isLeft;
    if (count == 0){
        root = new node;
        count++;
        root->dataPtr = newPtr->dataPtr;
        return true;
    }
     
    while (1){
        if (*(int*)data >= *(int*)(ptr->dataPtr)){
            if (ptr->right == NULL) {
                isLeft = false; 
                break;
            }
            else ptr = ptr->right;
        } else if (*(int*)data < *(int*)ptr->dataPtr){
            if (ptr->left == NULL) {
                isLeft = true;
                break;
            }
            else ptr = ptr->left;
        }
    }
    
    curr = ptr;
    ptr = new node;
    if (ptr) count++;

    if (isLeft) {
        curr->left = ptr;
    } else {
        curr->right = ptr;
    }
    ptr->dataPtr = newPtr->dataPtr;
    
    return true;
}
bool BST::BST_Delete(void* dltKey){
    root = gogoD(root, dltKey);
    if (!findD) return false;
    count--;
    findD = false;
    return true;
}
void BST::BST_Traverse(void (*process)(void* dataPtr)){
    gogo(root, process);
}
bool BST::BST_Empty(){
    if(count) return false;
    return true;
}
bool BST::BST_Full(){
    return go(root);
}

int BST::BST_Count(){
    return count;
}

bool BST::go(node *ptr){
    static bool a = true;
    if (ptr == NULL) return true;
    if (ptr->left == NULL) {
        if (ptr->right != NULL) a = false;
    } else if (ptr->right == NULL){
        if (ptr->left != NULL) a = false;
    }
    go(ptr->left);
    go(ptr->right);
    return a;
}
