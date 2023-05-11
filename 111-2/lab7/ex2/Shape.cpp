#include "Shape.h"

Shape::Shape(int m,int n,int o){
    canvas_size = 20;
    setVectorSize();
}
Shape::Shape(int m,int n,int o,int c){
    L = m;
    pos_x = n;
    pos_y = o;
    canvas_size = c;
    setVectorSize();
}

void Shape::setVectorSize(){
    Point p;
    p.x = -1;
    p.y = -1;
    points.resize(canvas_size * canvas_size, p);
}
void Shape::appendPoints(int x, int y){
    Point p;
    p.x = x;
    p.y = y;
    points.insert(points.begin() + y + canvas_size *  x, p);
}
void Shape::draw(){
    cout << "|";
    for (int i = 0 ; i < canvas_size; i++){
        cout << canvas_size % 10;
    }
    cout << "|" << endl;

    int t = canvas_size - 1;
    for (int i = 0; i < canvas_size; i++){
        cout << t % 10;
        for (int j = 0 ; j < canvas_size; j++){
            if (points[j + i * canvas_size].x != -1){
                cout << "*";
            } else {
                cout << " ";
            }
        }
        cout << t % 10;
        t--;
    }

    cout << "|";
    for (int i = 0 ; i < canvas_size; i++){
        cout << canvas_size % 10;
    }
    cout << "|" << endl;

}

