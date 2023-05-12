#include "Triangle.h"

#include <cmath>
#include <iostream>

using namespace std;

Triangle::Triangle(int L, int x, int y, int canva) : Shape(L, x, y, canva) {
    points.clear();
}
Triangle::Triangle(int L, int x, int y) : Shape(L, x, y, 20) {
    points.clear();
}
void Triangle::ComputeArea() {
    cout << "Area: " << getL() * getL() << endl;
}

void Triangle::ComputePoints() {
    int m = getPos_x();
    int n = getPos_y();
    int l = getL();
    for (int i = 0; i < 2 * getL() + 1; i++) {
        appendPoints(m - l + i, n - l);
        Point p;
        p.x = m - l + i;
        p.y = n - l;
        points.push_back(p);
    }
    // cout << endl;
    bool first = true;
    for (int i = 0; i < getL(); i++) {
        Point p;
        appendPoints(m - i, n - i);
        appendPoints(m + i, n - i);
        p.x = m + i;
        p.y = n - i;
        points.push_back(p);
        p.x = m - i;
        p.y = n - i;
        points.push_back(p);
        // cout << "(" << p.x << ", " << p.y << ")";
    }
    // cout << endl;
}

void Triangle::ComputePerimeter() {
    cout << "Perimeter: " << setprecision(4) << sqrt(2 * getL() * getL()) * 2 + getL() * 2 << endl;
}

vector<Point> Triangle::getPoints() {
    return points;
}

