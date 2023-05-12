#include "Rect.h"

#include "Shape.h"

Rect::Rect(int l, int W, int x, int y, int canvas_size) : Shape(l, x, y, canvas_size) {
    this->W = W;
    points.clear();
}
Rect::Rect(int l, int W, int x, int y) : Shape(l, x, y, 20) {
    this->W = W;
    points.clear();
}
void Rect::ComputePoints() {
    int m = getPos_x();
    int n = getPos_y();
    int l = getL();
    for (int i = 0; i < l + 1; i++) {
        Point p;
        appendPoints(m - l / 2 + i, n - l / 2);
        p.x = m - l / 2 + i;
        p.y = n - l / 2;
        points.push_back(p);
        appendPoints(m - l / 2 + i, n + l / 2 - 1);
        p.x = m - l / 2 + i;
        p.y = n + l / 2 - 1;
        points.push_back(p);
    }
    for (int i = 0; i < W; i++) {
        Point p;
        appendPoints(m - l / 2, n - l / 2 + i + 1);
        p.x = m - l / 2;
        p.y = n - l / 2 + i + 1;
        points.push_back(p);
        appendPoints(m + l / 2, n - l / 2 + i + 1);
        p.x = m + l / 2;
        p.y = n - l / 2 + i + 1;
        points.push_back(p);
    }
}
void Rect::ComputePerimeter() {
    cout << "Perimeter: " << 2 * (getL() + W) << endl;
}
void Rect::ComputeArea() {
    cout << "Area: " << getL() * W << endl;
}

vector<Point> Rect::getPoints() {
    return points;
}

