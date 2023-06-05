#include <iostream>
#include "BST.h"

using namespace std;

int compareInt(void* num1, void* num2);
void printBST(void* num1);
void printMenu();

int main(){
    int (*fpi)(void*,void*);
    void (*fpv)(void*);
    BST xx(fpi);
    while (1){
        int mod = 0;
        printMenu();
        cin >> mod;
        int a;
        void *data = &a;
        switch(mod){
            case 1:
                cout << "Enter an integer: "; cin >> a;
                xx.BST_Insert(data);   break;
            case 2:
                if (xx.BST_Empty()) {
                    cout << "The BST is empty." << endl;
                    continue;
                }
                cout << "Enter an integer: "; cin >> a;
                if (xx.BST_Delete(data)){
                    fpv = printBST;
                    if (xx.BST_Count() != 0) cout << "New BST: ";
                    xx.BST_Traverse(fpv);
                    cout << endl;
                } else {
                    cout << "The number is not in BST." << endl;
                }
                break;
            case 3:
                if (xx.BST_Empty()) {
                    cout << "The BST is empty." << endl;
                    break;
                }
                fpv = printBST;
                xx.BST_Traverse(fpv);
                cout << endl;
                break;
            case 4:
                if (!xx.BST_Full()) {
                    cout << "BST is not full yet" << endl;
                } else {
                    cout << "BST is full" << endl;
                }
                break;
            case 5:
                cout << "There are " << xx.BST_Count() << " nodes in BST." << endl;    break;
            case 6:
                exit(0);
        }
    }
    return 0;
}
int compareInt(void* num1, void* num2){
    return 0;
}
void printBST(void* num1){
    cout << *(int*)num1 << " ";   
}
void printMenu(){
    cout << "The following are six options for your BST:" << endl;
    cout << "1. Insert" << endl;
    cout << "2. Delete" << endl;
    cout << "3. Print the BST" << endl;
    cout << "4. Check the BST is full or not" << endl;
    cout << "5. Print the number of nodes in BST" << endl;
    cout << "6. Exit" << endl;
    cout << "Please enter: ";
}
