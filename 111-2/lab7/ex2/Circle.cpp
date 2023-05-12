#include "Circle.h"

#include <cmath>

#include "Shape.h"

bool sortT(double &o1, double &o2) {
    return o1 > o2;
}
Circle::Circle(int l, int x, int y, int canva) : Shape::Shape(l, x, y, canva) {
    points.clear();
}
Circle::Circle(int l, int x, int y) : Shape::Shape(l, x, y, 20) {
    points.clear();
}
void Circle::ComputeArea() {
    cout << "Area: " << getL() * getL() * PI << endl;
}
void Circle::ComputePerimeter() {
    cout << "Perimeter: " << 2 * getL() * PI << endl;
}
void Circle::ComputePoints() {
    int l = getL();
    int m = getPos_x();
    int n = getPos_y();
    vector<pair<Point, double>> temp;
    for (int i = getCanva() - 1; i >= 0; i--) {
        for (int j = 0; j < getCanva(); j++) {
            if (round(sqrt((m - j) * (m - j) + (n - i) * (n - i))) <= l && round(sqrt((m - j) * (m - j) + (n - i) * (n - i))) > (l - 1)) {
                appendPoints(j, i);
                Point p;
                p.x = j;
                p.y = i;
                // temp.push_back(make_pair(p, (double)sqrt((m - j) * (m - j) + (n - i) * (n - i))));
                points.push_back(p);
                // cout << "(" << p.x << ", " << p.y << ") ";
            }
        }
    }

    // not finish
    // for (int i = 0; i < getL() - 1; i++) {
    //     appendPoints(getPos_x() - i, getPos_y() + i);
    // }
    // for (int i = 0; i < getL() - 1; i++) {
    //     appendPoints(getPos_x() + i, getPos_y() - i);
    // }
    // for (int i = 0; i < getL() - 1; i++) {
    //     appendPoints(getPos_x() + i, getPos_y() - i);
    // }
}

vector<Point> Circle::getPoints() {
    return points;
}

