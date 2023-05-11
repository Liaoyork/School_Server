#include "Circle.h"
#include "Shape.h"
#include <cmath>

Circle::Circle(int l, int x,int y,int canva) : Shape::Shape(l,x,y,canva){
    L = l;
    pos_x = x;
    pos_y = y;
}
Circle::Circle(int l, int x,int y) :Shape::Shape(l,x,y){
    L = l;
    pos_x = x;
    pos_y = y;
    canvas_size = 20;
}
void Circle::ComputeArea(){
    cout << "Area: " << L * L * PI << endl; 
}
void Circle::ComputePerimeter(){
    cout << "Perimeter: " << 2 * L * PI << endl; 
}
void Circle::ComputePoints(){
    for(int i = pos_y - L ; i < pos_y; i++){
        for (int j = pos_x - L; j < pos_x + L + 1; j++){
            if (abs(pos_y - i) == L || abs(pos_y + i) == L)
        }
    }
    
}
void Circle::draw(){
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

