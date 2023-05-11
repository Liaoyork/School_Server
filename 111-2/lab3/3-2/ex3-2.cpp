#include <iostream>
#include <string>
#include "Class.h"
using namespace std;

int main(){
    cout << "Math" << endl;
    Class Math;
    Math.initialize();
    Math.stu_info();
    Math.add_stu(Student{"Jimmy", "A1703", 92});
    Math.stu_info();
    Math.score_info();

    cout << "Chinese" << endl;
    Class Chinese(Math);
    Chinese.set_score("Amy", 92);
    Chinese.set_passing_score(50);
    Chinese.remove_stu("Zcck");
    Chinese.remove_stu("Zack");
    Chinese.stu_info();
    Chinese.score_info();

    cout << "Chemistry" << endl;
    Class Chemistry(Chinese);
    Chemistry.add_stu(Student{"Bob", "B4320", 54});
    Chemistry.add_stu(Student{"Jessica", "A0222", 77});
    Chemistry.set_passing_score(75);
    Chemistry.set_score("Brian", 64);
    Chemistry.remove_stu("Nancy");
    Chemistry.remove_stu("Roddy");
    Chemistry.stu_info();
    Chemistry.score_info();

    

    return 0;
}
