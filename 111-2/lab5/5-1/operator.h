#include <iostream>
#include <string>

using namespace std;
class CComplex{
private:
    double real;
    double imag;
public:
    CComplex();
    CComplex (double r, double i);
    void inputComplex();
    CComplex operator + (CComplex& , CComplex&);
    CComplex operator - (CComplex& , CComplex&);
    CComplex operator * (CComplex& , CComplex&);
    void display();
    void switch_case(string);
};
/*
class Cas{
    double x,y;
    friend operator>>Pol() const;
};

class Pol{
    double r ,theta;
    friend operator>>Cas() const;
}
CComplex operator+ ( const CComplex& , const CComplex&);
CComplex operator- ( const CComplex& , const CComplex&);
CComplex operator* ( const CComplex& , const CComplex&);
*/




CComplex CComplex::operator+ (CComplex& o1, CComplex& o2){
    return CComplex(o1.real + o2.real, o1.imag + o2.imag);
}

CComplex CComplex::operator- (CComplex& o1, CComplex& o2){
    return CComplex(o1.real - o2.real, o1.imag - o2.imag);
}

CComplex CComplex::operator* (CComplex& o1, CComplex& o2){
    return CComplex(o1.real * o2.real, o1.imag * o2.imag);
}




