#include <bits/stdc++.h>

using namespace std;

template <class T>
T *new_pvec(int n) {
    /*
    FUNCTION:
    New the number of n spaces in type T.
    */
    T *m = new T[n];
    for (int i = 0; i < n; i++) {
        m[i] = 0;
    }
    return m;
    // NEED SOME CODES
}
template <class T>
void copy_pvec(T *p1, T *p2, int n) {
    /*
    FUNCTION:
    Copy the number of n spaces in type T from p2 to p1.
    You don’t need to allocate new spaces to p1.
    */
    // NEED SOME CODES
    for (int i = 0; i < n; i++) {
        p1[i] = p2[i];
    }
}
template <class T>
void del_pvec(T *vecs) {
    /*
    FUNCTION:
    Delete an array.
    */
    // NEED SOME CODES
    delete[] vecs;
}
template <class T>
void display_pvec(T *vecs, int n) {
    /*
    FUNCTION:
    Display the number of n elements using cout.
    */
    for (int i = 0; i < n; i++) {
        cout << vecs[i] << "\n";
    }
    // NEED SOME CODES
}

class Point2D {
   private:
    int *x;
    int *y;

   public:
    Point2D(int n1, int n2) {
        /*
        FUNCTION:
        Constructor assigns memory and value.
        n1 -> x, n2 -> y.
        */
        // NEED SOME CODES
        x = new int(n1);
        y = new int(n2);
    }
    Point2D() {
        /*
        FUNCTION:
        Constructor assigns memory and random value in range [0,
       999].
        */
        // NEED SOME CODES
        int a = rand() % 1000;
        x = new int(a);
        // cout << " " << *x;
        a = rand() % 1000;
        y = new int(a);
        // cout << " " << *y;
    }
    Point2D(Point2D &p) {
        /*
        FUNCTION:
        Constructor copys data value from p.
        */
        // NEED SOME CODES
        x = new int (p.getX());
        y = new int (p.getY());
    }
    int getX() {
        return *x;
    }
    int getY() {
        return *y;
    }
    friend ostream &operator<<(ostream &out, Point2D &p);
    void operator=(Point2D &p){
        /*
        FUNCTION:
        Assign values to the data members from p.
        */
        // NEED SOME CODES
        x = new int (p.getX());
        y = new int (p.getY());
    };
    virtual void display() { cout << (*this); }
};
ostream &operator<<(ostream &out, Point2D &p) {
    /*
    FUNCTION:
    As shown in the output file, display point p.
    */
    // NEED SOME CODES
    cout << "x=" << p.getX() << " "
         << "y=" << p.getY();
    return out;
}
template <>
Point2D *new_pvec(int n) {
    Point2D *m = new Point2D[n];
    return m;
}
// template <>
// void display_pvec(Point2D *k, int n) {
//     for (int i = 0; i < n; i++) {
//         cout << k[i];
//     }
// }
class Point4D : public Point2D {
   private:
    int *z;
    int *t;

   public:
    Point4D() : Point2D() {
        /*
        FUNCTION:
        Constructor assigns memory and random value in range [0,
       999].
        */
        // NEED SOME CODES
        z = new int(rand() % 1000);
        t = new int(rand() % 1000);
    }
    ~Point4D() {
        /*
        FUNCTION:
        Delete memory of data members.

         */
        // NEED SOME CODES
    }
    void display() {
        cout << (*this);
        cout << " z=" << *z << " "
             << "t= " << *t;
    }
    friend ostream &operator<<(ostream &out, Point4D &p);
};
ostream &operator<<(ostream &out, Point4D &p) {
    /*
    FUNCTION:
    As shown in the output, display point p.
    */
    cout << "x=" << p.getX() << " "
         << "y=" << p.getY();
    return out;
}
class Shape {
   protected:
    int color;
    Point2D *points;

   public:
    virtual void area() = 0;
    virtual bool is_polygon() = 0;
    ~Shape() {}
};
class Polygon : public Shape {
   public:
    bool is_polygon() { return true; }
};
class Circle : public Shape {
   private:
    Point2D center;
    double radius;

   public:
    Circle(Point2D p, double r) : center(p), radius(r) {}
    void area() {
        /*
        FUNCTION:
        Print the area as the output shows.
        // NEED SOME CODES
        */
        cout << "Circle Area is " << fixed << setprecision(5) << get_area() << endl;
    }
    double get_area() {
        return radius * radius * M_PI;
    }
    bool is_polygon() {
        return false;
    }
};
class Triangle : public Polygon {
   private:
    Point2D *pvecs;

   public:
    Triangle(Point2D *vecs) {
        pvecs = new Point2D[3];
        copy_pvec<Point2D>(pvecs, vecs, 3);
    }
    ~Triangle() { delete[] pvecs; }
    void area() {
        /*
        FUNCTION:
        Print the area as the output shows.
        */
        // NEED SOME CODES
        for (int i = 0; i < 3; i++) {
            cout << pvecs[i] << "\n";
        }
        cout << "Triangle Area is " << get_area() << endl;
    };
    double get_area() {
        /*
        FUNCTION:
        Return the area of this triangle.
        */
        // NEED SOME CODES
        double a = pvecs[0].getX() * pvecs[1].getY() + pvecs[1].getX() * pvecs[2].getY() + pvecs[2].getX() * pvecs[0].getY();
        double b = pvecs[1].getX() * pvecs[0].getY() + pvecs[2].getX() * pvecs[1].getY() + pvecs[0].getX() * pvecs[2].getY();
        return abs(a - b) * 0.5;
    }
    bool is_polygon() { return true; }
};
class Triangle_and_Circle : public Triangle, public Circle {
   public:
    Triangle_and_Circle(Point2D p, double r, Point2D *vecs) : Triangle(vecs), Circle(p, r) {}
    void area() {
        /*

         FUNCTION:
        Print the area as the output shows.
        */
        // NEED SOME CODES
        cout << fixed << setprecision(5) << get_area() << "\n";
    };
    double get_area() {
        /*
        FUNCTION:
        Return the area of this triangle minus circle.
        */
        // NEED SOME CODES
        return Triangle::get_area() - Circle::get_area();
    }
    bool is_polygon() { return true; }
};
int main() {
    srand(1);
    cout << "===== int vecs template =====" << endl;
    int *vec_int = new_pvec<int>(3);
    display_pvec(vec_int, 3);
    del_pvec(vec_int);
    vec_int = new int[4];
    vec_int[0] = 10;
    vec_int[1] = 20;
    vec_int[2] = 30;
    vec_int[3] = 40;
    int *vec_int2 = new int[4];
    copy_pvec(vec_int2, vec_int, 4);
    display_pvec(vec_int, 3);
    del_pvec(vec_int);
    del_pvec(vec_int2);
    cout << endl;
    cout << "===== Point2D p1 =====" << endl;
    Point2D p1(0, 0);
    cout << p1 << endl;
    cout << endl;
    cout << "===== Point2D p2 =====" << endl;
    Point2D p2;
    cout << p2 << endl;
    cout << endl;
    cout << "===== Point4D p4 =====" << endl;
    Point2D *p = new Point4D;
    p->display();
    cout << endl;
    cout << "===== new vec =====" << endl;
    Point2D *vec = new_pvec<Point2D>(3);
    display_pvec(vec, 3);
    cout << endl;

    cout << "===== Circle and Triangle =====" << endl;
    Triangle_and_Circle tc(p1, 10, vec);
    tc.area();
    if (tc.is_polygon())
        cout << "This is a polygon" << endl;
    else
        cout << "This is not a polygon" << endl;
    cout << endl;

    cout << "===== Delete =====" << endl;
    del_pvec<Point2D>(vec);
    cout << endl;

    cout << "===== Area of the Circle =====" << endl;
    tc.Circle::area();
    if (tc.Circle::is_polygon())
        cout << "This is a polygon" << endl;
    else
        cout << "This is not a polygon" << endl;
    cout << endl;
    cout << "===== Area of the Triangle =====" << endl;
    tc.Triangle::area();
    if (tc.Triangle::is_polygon())
        cout << "This is a polygon" << endl;
    else
        cout << "This is not a polygon" << endl;
    cout << endl;
    return 0;
}
