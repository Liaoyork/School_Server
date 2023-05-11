#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main (){
    //vector<string> vec;
    string *vec = new string [2];
    string a = "123456";
    string b = "789";
    vec[0] = a;
    vec[1] = b;
    //vec.push_back(a);
    //vec.push_back(b);
    cout << vec[0] << " " << vec[1] << endl;
    return 0;
}
