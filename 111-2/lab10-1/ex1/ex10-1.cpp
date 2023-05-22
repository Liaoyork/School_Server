// ex10-1.cpp
#include <iostream>
#include <typeinfo>
#include <iomanip>
using namespace std;


class Point2D
{
private:
    int x;
    int y;
public:
    void set(int a, int b){
        x = a;
        y = b;
    }
    friend ostream &operator << (ostream &, Point2D &);
    bool operator > (Point2D &o1){
        if (x > o1.x) return true;
        //if (y > o1.y) return true;
        else if (x == o1.x) {
            if (y > o1.y) return true;
            else return false;
        }
        return false;
    }
};
template<class T>
void rand1D(T *m ,int n){
    ;
}

template<>
void rand1D(int *ty, int n){
    for (int i = 0; i < n; i++){
        ty[i] = rand() % 10;
    }
}
template<>
void rand1D(double *ty, int n){
    for (int i = 0; i < n; i++){
        ty[i] = rand() % 1000 / 100.0;
    }
}
template<>
void rand1D(char *ty,int n){
    for (int i = 0; i < n; i++){
        ty[i] = (char)(rand() % 26 + 65);
    }
}
template<>
void rand1D(Point2D *ty, int n){
    for (int i = 0 ; i < n; i++){
        int a = rand() % 10;
        int b = rand() % 10;
        ty[i].set(a,b);
    }
}

ostream &operator << (ostream &out, Point2D &o1){
    cout << "(" << o1.x << ", " << o1.y << ") ";
    return out;
}


template<typename T>
void display1D(T *ty, int n){
    for (int i = 0; i < n ; i++){
        cout << ty[i] << " ";
    }
    cout << endl;
}
template<>
void display1D(double *ty, int n){
    for (int i = 0 ; i < n; i++){
        cout << fixed << setprecision(2) << ty[i] << " ";
    }
    cout << endl;
}

template<class T>
void sort1D(T *ty, int n){
    for (int i = 0 ; i < n; i++){
        for (int j = 0 ; j < n; j++){
            if (ty[j] > ty[i]){
                swap(ty[i],ty[j]);
            }
        }
    }
}

template<class T>
void analysis(int n) {
    T *vec = new T [n];
    rand1D<T>(vec, n);         
    // for int, 0~9
    // for double, 0.00~9.99, i.e., rand()%1000/100.0
    // for char, A~Z 
    // for Point2D, x: 0~9 y: 0~9
    display1D<T>(vec, n);
    // for double, set the precision with 2
    sort1D<T>(vec, n);
    display1D<T>(vec, n);
}

int main()
{
    int n;
    cout << "Enter n: ";
    cin >> n;
    
    srand(1);
    
    analysis<int>(n);
    analysis<double>(n);
    analysis<char>(n);
    analysis<Point2D>(n);

    return 0;
}
