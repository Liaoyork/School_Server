#include <iostream>
#include <vector>
#include <cmath>
#include "3-1.h"

using namespace std;

LineGp::LineGp(){
    ;
}

void LineGp::set_L(){
    for (int i = 0 ; i < 3 ; i++){
        cout << "L" << i << ":" << endl;
        cout << "Point 1:";
        cin >> Li[i].p1.x; cin >> Li[i].p1.y;
        cout << "Point 2:";
        cin >> Li[i].p2.x; cin >> Li[i].p2.y;
    }
}

void LineGp::intersect(line L1, line L2){
    //static int count = 0;
    point a;
    double m = (L1.p2.y - L1.p1.y) * (-abs(L2.p1.x - L2.p2.x)) - (-abs(L1.p1.x - L1.p2.x))*(L2.p2.y - L2.p1.y);
    double x = (-abs(L2.p1.x - L2.p2.x)) * ((L1.p2.y - L1.p1.y) * L1.p1.x - L1.p1.y * (abs(L1.p1.x - L1.p2.x)))
                - (-abs(L1.p1.x - L1.p2.x)) * ((L2.p2.y - L2.p1.y) * L2.p1.x - L2.p1.y*(abs(L2.p1.x - L2.p2.x)));
    double y = (L1.p2.y - L1.p1.y) * ((L2.p2.y - L2.p1.y) *L2.p1.x - L2.p1.y *(abs(L2.p1.x - L2.p2.x)))
                - (L2.p2.y - L2.p1.y) * ((L1.p2.y - L1.p1.y) * L1.p1.x - L1.p1.y * (abs(L1.p1.x - L1.p2.x)));
    if (m == 0) {
        cout << "Two lines are parallel!" << endl;
    } else{   
        double ans_x = x / m;
        double ans_y = y / m;
        //cout << ans_x << " " << ans_y << endl;
        if (ans_x <= L1.p2.x && ans_x >= L1.p1.x && ans_x <= L2.p2.x && ans_x >= L2.p1.x){
            if (ans_y <= max(L1.p1.y, L1.p2.y) && ans_y >= min(L1.p1.y, L1.p2.y) && ans_y <= max(L2.p1.y, L2.p2.y) && ans_y >= min(L2.p1.y, L2.p2.y)){
                a.x = ans_x;
                a.y = ans_y;
                intersectP.push_back(a);
                cout << "Intersect at (" << ans_x << "," << ans_y << ")" << endl;
            }
            else {
                cout << "Intersect point isn't in range!" << endl; 
            }
        }
        else {
            cout << "Intersect point isn't in range!" << endl; 
        }
    }
    computeArea();
}

void LineGp::intersect_lines(){
    cout << "L0, " << "L1" << endl;
    cout << Li[0].p2.y - Li[0].p1.y << "x " << "- " << abs(Li[0].p1.x - Li[0].p2.x) 
         << "y = " << (Li[0].p2.y - Li[0].p1.y)*Li[0].p1.x - Li[0].p1.y*(abs(Li[0].p1.x - Li[0].p2.x)) << endl;
    cout << Li[1].p2.y - Li[1].p1.y << "x " << "- " << abs(Li[1].p1.x - Li[1].p2.x)
         << "y = " << (Li[1].p2.y - Li[1].p1.y)*Li[1].p1.x - Li[1].p1.y*(abs(Li[1].p1.x - Li[1].p2.x)) << endl;
    intersect(Li[0], Li[1]);


    cout << "L0, " << "L2" << endl;    
    cout << Li[0].p2.y - Li[0].p1.y << "x " << "- " << abs(Li[0].p1.x - Li[0].p2.x) 
         << "y = " << (Li[0].p2.y - Li[0].p1.y)*Li[0].p1.x - Li[0].p1.y*(abs(Li[0].p1.x - Li[0].p2.x)) << endl;
    cout << Li[2].p2.y - Li[2].p1.y << "x " << "- " << abs(Li[2].p1.x - Li[2].p2.x) 
         << "y = " << (Li[2].p2.y - Li[2].p1.y)*Li[2].p1.x - Li[2].p1.y*(abs(Li[2].p1.x - Li[2].p2.x)) << endl;
    intersect(Li[0], Li[2]);

    cout << "L1, " << "L2" << endl;
    cout << Li[1].p2.y - Li[1].p1.y << "x " << "- " << abs(Li[1].p1.x - Li[1].p2.x) 
         << "y = " << (Li[1].p2.y - Li[1].p1.y)*Li[1].p1.x - Li[1].p1.y*(abs(Li[1].p1.x - Li[1].p2.x)) << endl;
    cout << Li[2].p2.y - Li[2].p1.y << "x " << "- " << abs(Li[2].p1.x - Li[2].p2.x) 
         << "y = " << (Li[2].p2.y - Li[2].p1.y)*Li[2].p1.x - Li[2].p1.y*(abs(Li[2].p1.x - Li[2].p2.x)) << endl;
    intersect(Li[1], Li[2]);
    
}

void LineGp::set_lines(){
    set_L();
}

void LineGp::printLines(){
    for (int i = 0 ; i < 3 ; i++){
        if (Li[i].p1.x > Li[i].p2.x){
            swap(Li[i].p1, Li[i].p2);
        }
    }

    cout << "////LINES////" << endl;
    for (int i = 0 ; i < 3 ; i++){
        cout << "L" << i << ": (" << Li[i].p1.x << "," << Li[i].p1.y << ") ("
             << Li[i].p2.x << "," << Li[i].p2.y << ")" << endl; 
    }
    cout << "////LINES////" << endl;
    cout << endl << endl;
    
    intersect_lines();

}

void LineGp::computeArea(){
    if (intersectP.size() != 3) {
        cout << "No triangle" << endl;
    } 
    else {
        double area = intersectP[0].x * intersectP[1].y + intersectP[1].x * intersectP[2].y + intersectP[2].x * intersectP[0].y - intersectP[1].x * intersectP[0].y - intersectP[2].x *intersectP[1].y - intersectP[0].x * intersectP[2].y;
        cout << "Area is :"  << area * 0.5 << endl;

    }
}
