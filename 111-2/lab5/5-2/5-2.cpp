#include <iostream>
#include <string>
#include "Score.h"
using namespace std;

int main (){
    Score xx;
    int det = 0;
    while (1){
        cout << "input 1~5 to select function :" << endl;
        cout << "1.Set score" << endl
             << "2.Set weight" << endl
             << "3.Change score" << endl
             << "4.Show average" << endl
             << "5.Show weight average" << endl;
        cin >> det;
        switch (det){
            case 1:
                xx.set_score();
                break;
            case 2:
                xx.w.set_weight();
                break;
            case 3:
                xx.Change();
                break;
            case 4:
                xx.avg();
                break;
            case 5:
                xx.w.weight_avg();
        }
    }
}
