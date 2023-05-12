#include "Square.h"

#include "Shape.h"

Square::Square(int L, int x, int y, int can) : Rect(L, L, x, y, can) {
    points.clear();
}
void Square::ComputePoints() {
    int m = getPos_x();
    int n = getPos_y();
    int l = getL();
    for (int i = 0; i < l + 1; i++) {
        Point p;
        appendPoints(m - l / 2 + i, n - l / 2);
        appendPoints(m - l / 2 + i, n + l / 2);
        p.x = m - l / 2 + i;
        p.y = n + l / 2;
    }
    cout << endl;
    for (int i = 0; i < l - 1; i++) {
        Point p;
        appendPoints(m - l / 2, n - l / 2 + i + 1);
        appendPoints(m + l / 2, n - l / 2 + i + 1);
        p.x = m + l / 2;
        p.y = n + l / 2 + i - 1;
        // cout << "(" << p.x << ", " << p.y << ")";
    }
}
void Square::ComputePerimeter() {
    cout << "Perimeter: " << 4 * getL() << endl;
}
void Square::ComputeArea() {
    cout << "Area: " << getL() * getL() << endl;
}

vector<Point> Square::getPoints() {
    return points;
}

