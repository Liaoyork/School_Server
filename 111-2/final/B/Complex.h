#ifndef C_
#define C_
#include <iostream>
using namespace std;
// Complex.h
class Complex{
private:
    double real;
    double imag;
public:
    // please add constructors
    Complex();
    Complex(double a, double b){
        real = a;
        imag = b;
    }
    void set_real(double);
    void set_imag(double);
    void operator=(const Complex &);
    Complex operator+(const Complex &);
    Complex operator-(const Complex &);
    void operator+=(const Complex &);
    void operator-=(const Complex &);
    friend std::ostream &operator<<(std::ostream &os, const Complex);
};

#endif
