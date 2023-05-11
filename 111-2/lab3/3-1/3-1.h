#include <iostream>
#include <vector>
using namespace std;

struct point{
    double x;
    double y;
};

struct line{
    point p1;
    point p2;
};

class LineGp{
private:
    line Li[3];
    vector<point> intersectP;
    void set_L();
    void intersect(line, line);
    void intersect_lines();
public:
    LineGp();
    void set_lines();
    void printLines();
    void computeArea();
};

