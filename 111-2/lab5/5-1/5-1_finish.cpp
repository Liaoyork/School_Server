#include <cmath>
#include <iostream>
#include <string>
using namespace std;
class CComplex {
   private:
    double real;
    double imag;
    string operators;
    class Pol;
    friend class Pol;
    friend istream& operator>>(istream&, CComplex&);
    friend ostream& operator<<(ostream&, CComplex&);
    class Pol {
        double r, theta;
        friend class CComplex;
        friend ostream& operator<<(ostream&, CComplex&);
        friend istream& operator>>(istream&, CComplex&);

       public:
        Pol();
        Pol(CComplex&);
        void display();
    };

   public:
    Pol x1;
    CComplex();
    CComplex(double r, double i);
    void inputComplex();
    CComplex operator+(CComplex&);
    CComplex operator-(CComplex&);
    CComplex operator*(CComplex&);
    CComplex operator+=(CComplex& o1) {
        this->real = this->real + o1.real;
        this->imag = this->imag + o1.imag;
        return *this;
    }
    CComplex operator-=(CComplex& o1) {
        this->real = this->real - o1.real;
        this->imag = this->imag - o1.imag;
        return *this;
    }
    CComplex operator*=(CComplex& o1) {
        CComplex tmp(0, 0);
        tmp.real = o1.real * real - o1.imag * imag;
        tmp.imag = o1.imag * real + o1.real * imag;
        return CComplex(tmp.real, tmp.imag);
    }

    void printComplex();
    void inputOp();
    string Get_switch_case();
    void setNum(CComplex);
    void setOP(string);
    void toPolar();
    void reset();
};

void CComplex::setNum(CComplex o) {
    real = o.real;
    imag = o.imag;
}

void CComplex::setOP(string ss) {
    operators = ss;
}

void CComplex::reset() {
    real = 0;
    imag = 0;
}
istream& operator>>(istream&, CComplex&);

CComplex::Pol::Pol() {
    ;
}
void CComplex::toPolar() {
    x1.r = sqrt((real * real) + (imag * imag));
    x1.theta = atan(imag / real);
}
istream& operator>>(istream& in, CComplex& p1) {
    in >> p1.real >> p1.imag;
    return in;
}

ostream& operator<<(ostream& out, CComplex& p1) {
    if (p1.x1.theta < M_PI / 2 && p1.x1.theta > 0) {
        out << p1.x1.r << "(cos" << p1.x1.theta * 180 / M_PI;
    } else if (p1.x1.theta > -M_PI / 2 && p1.x1.theta < 0) {
        out << p1.x1.r << "(-cos" << p1.x1.theta * 180 / M_PI;
    }
    if (p1.x1.theta < M_PI / 2 && p1.x1.theta > 0) {
        out << "+isin" << p1.x1.theta * 180 / M_PI << ")" << endl;
    } else if (p1.x1.theta < M_PI / 2 && p1.x1.theta > 0) {
        out << "-isin" << p1.x1.theta * 180 / M_PI << ")"
            << ")" << endl;
    }
    return out;
}

CComplex CComplex::operator+(CComplex& o1) {
    return CComplex(o1.real + real, o1.imag + imag);
}

CComplex CComplex::operator-(CComplex& o1) {
    return CComplex(real - o1.real, imag - o1.imag);
}

CComplex CComplex::operator*(CComplex& o1) {
    CComplex tmp(0, 0);
    tmp.real = o1.real * real - o1.imag * imag;
    tmp.imag = o1.imag * real + o1.real * imag;
    return CComplex(tmp.real, tmp.imag);
}

void CComplex::printComplex() {
    cout << "Complex number is: ";
    if (real == 0 && imag == 0) {
        cout << 0 << endl;
        return;
    }

    if (real != 0) {
        cout << real;
    }
    if (imag > 0 && imag != 1) {
        if (real == 0)
            cout << imag << "j" << endl;
        else
            cout << "+" << imag << "j" << endl;
    } else if (imag < 0 && imag != -1) {
        cout << imag << "j" << endl;
    } else if (imag == 1) {
        if (real == 0)
            cout << "j" << endl;
        else
            cout << "+"
                 << "j" << endl;
    } else if (imag == -1) {
        cout << "-"
             << "j" << endl;
    }
    if (imag == 0) cout << endl;
}

CComplex::CComplex() {
    real = 0;
    imag = 0;
}

CComplex::CComplex(double r, double i) {
    real = r;
    imag = i;
}

string CComplex::Get_switch_case() {
    return operators;
}

void CComplex::inputComplex() {
    string ss, tmp;
    cout << "input complex number: ";
    cin >> ss;

    for (int i = ss.length() - 1; i >= 0; i--) {
        if (ss[i] == 'j') {
            if (i > 0) i--;
            while (isdigit(ss[i])) {
                tmp = ss[i] + tmp;
                i--;
                if (i <= 0) {
                    i = 0;
                    break;
                }
            }

            if (tmp == "") {
                if (ss[i] == '-')
                    imag += -1;
                else
                    imag += 1;
                continue;
            }

            if (ss[i] == '+' && i != 0) {
                imag += stod(tmp);
                tmp = "";
            } else if (ss[i] == '-') {
                imag += -stod(tmp);
                tmp = "";
            } else if (ss[0] != '-') {
                imag += stod(tmp);
                tmp = "";
            }
        } else {
            while (isdigit(ss[i])) {
                tmp = ss[i] + tmp;
                i--;
                if (i <= 0) {
                    i = 0;
                    break;
                }
            }

            if (ss[i] == '-') {
                real += -stod(tmp);
                tmp = "";
            } else {
                real += stod(tmp);
                tmp = "";
            }
        }
    }
}

void CComplex::inputOp() {
    cout << "input operater: ";
    cin >> operators;
}

using namespace std;

int main() {
    CComplex xx(0, 0), yy(0, 0), tmp;
    string ss, rem;
    bool isoverload = false;
    bool first = true;
    xx.inputComplex();
    while (1) {
    there:
        xx.inputOp();
        ss = xx.Get_switch_case();
        if (ss == "=")
            goto here;
            yy.reset();
        if (ss == "+") {
            yy.inputComplex();
            xx = xx + yy;
            xx.printComplex();
            yy.setOP(ss);
        } else if (ss == "-") {
            yy.inputComplex();
            xx = xx - yy;
            xx.printComplex();
            yy.setOP(ss);
        } else if (ss == "*") {
            yy.inputComplex();
            xx = xx * yy;
            xx.printComplex();
            yy.setOP(ss);
        } else if (ss == ">>") {
            xx.toPolar();
            cout << "Polar form is: " << xx;
            xx.printComplex();
        }
    }
here:
    if (yy.Get_switch_case() == "+") {
        xx += yy;
        xx.printComplex();
    } else if (yy.Get_switch_case() == "-") {
        xx -= yy;
        xx.printComplex();
    } else if (yy.Get_switch_case() == "*") {
        xx *= yy;
        xx.printComplex();
    }
    goto there;
    return 0;
}

