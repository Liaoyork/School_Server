#include "Complex.h"

Complex::Complex(){
    real = 0;
    imag = 0;
}
void Complex::set_real(double r){
    real = r;
}
void Complex::set_imag(double i){
    imag = i;
}
void Complex::operator=(const Complex &o1){
    real = o1.real;
    imag = o1.imag;
}
Complex Complex::operator+(const Complex &o1){
    Complex p;
    p.set_real(0);
    p.set_imag(0);
    p.set_real(o1.real + real);
    p.set_imag(o1.imag + imag);
    return p;
}
Complex Complex::operator-(const Complex &o1){
    Complex p;
    p.set_real(0);
    p.set_imag(0);
    p.set_real(real - o1.real);
    p.set_imag(imag - o1.imag);
    return p;
    
}
void Complex::operator+=(const Complex &o1){
    this->real += o1.real;
    this->imag += o1.imag;
}
void Complex::operator-=(const Complex &o1){
    this->real -= o1.real;
    this->imag -= o1.imag;

}
std::ostream &operator<<(std::ostream &os, const Complex o1){
    if (o1.real >= 0){
        cout << o1.real;
        if (o1.imag >= 0){
            cout << "+" << o1.imag << "j";
        } else {
            cout << o1.imag << "j";
        }
    } else {
        cout << "-" << abs(o1.real);
        if (o1.imag >= 0){
            cout << "+" << o1.imag << "j";
        } else {
            cout << o1.imag << "j";
        }
    }
    return os;
}

