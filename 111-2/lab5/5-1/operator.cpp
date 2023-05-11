#include <iostream>
#include <string>
#include "operator.h"

using namespace std;

/*
CComplex::printComplex(){

}
*/

CComplex::CComplex(){
    ;
}

CComplex::CComplex(double r, double i){
    real = r;
    imag = i;
}

//friend CComplex operator+ (const CComplex& o1, const CComplex& o2);

//friend CComplex operator- (const CComplex& o1, const CComplex& o2);

//friend CComplex operator* (const CComplex& o1, const CComplex& o2);

void CComplex::switch_case(string op){
    if (op == "+"){
        ;
    } else if (op == "-") {
        ;
    } else if (op == "*") {
        ;
    } else if (op == ">>") {
        ;
    }
}

void CComplex::inputComplex(){ 
    bool getC = false;
    string ss, tmp;
    cin >> ss;
    //cout << ss << endl;
    for (int i = ss.length() - 2 ; i >= 0 ; i--){
        while (isdigit(ss[i])){
            tmp = ss[i] + tmp;
            cout << tmp << endl;
            i--;
            if (i <= 0) break;
        }
        if (tmp == "") continue;
        if (!getC) {
            //cout << ss[i - 1] << endl;
            if (ss[i] == '+') {
                imag = stod(tmp);
                tmp = "";
                getC = true;
                //cout << ss[i] << endl;
            } else{
                imag = -stod(tmp);
                tmp = "";
                getC = true;
            }
        } else {
            //cout << tmp << endl;
            if (ss[0] == '-') {
                real = -stod(tmp);
                tmp = "";
            } else{
                real = stod(tmp);
                tmp = "";
            }
        }
    }
}

void CComplex::display(){

    string oper;
    cout << "input complex number: " ;
    inputComplex();
    cout << "input operater: ";
    cin >> oper;
    
}



/*
Cas::operator Polar() const{ 
    return Polar(sqrt(x*x+y*y),atan(y/x));
}
Polar::operator Cartesian() const{
    return Cas(r*cos(theta),r*sin(theta));
}
*/


