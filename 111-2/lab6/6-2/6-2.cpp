#include <iostream>
#include <cmath>
#include <fstream>
#include <algorithm>
using namespace std;

int main (){
    ifstream input("3.dat", ios::binary);
    ofstream output("2.out", ios::binary);
    int in;
    if (!input) {
        cout << "1.dat is not opened";
        return -1;
    }
    //cout << sizeof(int) << endl;
    int a[100] = {0};
    int i = 0;
    while (!input.eof()) {
        input.read((char *)&in, sizeof(int));
        a[i] = in;
        i++;
    }
    sort(a,a+i-1);
    for (int k = 0 ; k < i - 1 ; k++){
        cout << a[k] << " ";
    }
    cout << endl;
    /*
    for (int i = 0 ; i < 15 ; i++){
        input.read((char *)&in, sizeof(int));
        cout << in << " " << endl;
    }
    */
    
}
