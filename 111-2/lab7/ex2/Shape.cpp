#include "Shape.h"

#include <algorithm>

bool sortV(Point &o1, Point &o2) {
    if (o1.y > o2.y)
        return true;
    if (o1.y == o2.y) {
        if (o1.x < o2.x) {
            return true;
        }
    }
    return false;
}
Shape::Shape(int m, int n, int o) {
    L = m;
    pos_x = n;
    pos_y = o;
    canvas_size = 20;
    points.clear();
}
Shape::Shape(int m, int n, int o, int c) {
    L = m;
    pos_x = n;
    pos_y = o;
    canvas_size = c;
    points.clear();
}

int Shape::getPos_x() {
    return pos_x;
}

int Shape::getPos_y() {
    return pos_y;
}

int Shape::getCanva() {
    return canvas_size;
}

void Shape::appendPoints(int x, int y) {
    Point p;
    p.x = x;
    p.y = y;
    for (int i = 0; i < (int)points.size(); i++) {
        if (points.at(i).x == p.x && points.at(i).y == p.y) {
            return;
        }
    }
    points.push_back(p);
    // cout << "(" << p.x << ", " << p.y << ") ";
    // cout << points.size();
}
void Shape::draw() {
    sort(points.begin(), points.end(), sortV);
    cout << "|";
    for (int i = 0; i < canvas_size; i++) {
        cout << i % 10;
    }
    cout << "|" << endl;

    int t = canvas_size - 1;
    int p = 0;
    // for (int p = 0; p < (int)points.size(); p++) {
    for (int i = canvas_size - 1; i >= 0; i--) {
        cout << abs(i) % 10;
        for (int j = 0; j < canvas_size; j++) {
            if (points[p].x == j && points[p].y == i) {
                cout << "*";
                if (p < (int)points.size() - 1) p++;
            } else {
                cout << " ";
            }
            // cout << " ";
        }
        cout << abs(i) % 10;
        cout << endl;
    }
    cout << "|";
    for (int i = 0; i < canvas_size; i++) {
        cout << i % 10;
    }
    cout << "|" << endl;
    // }
    // cout << p;
}

int Shape::getL() {
    return L;
}

void Shape::ComputeArea() {
    ;
}

void Shape::ComputePoints() {
    ;
}

void Shape::ComputePerimeter() {
    ;
}

