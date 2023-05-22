#include "EEE.h"
#include "Student.h"
#include "Group.h"
#include <iostream>
#include <algorithm>

using namespace std;

bool sortID(Student &o1, Student &o2){
    return o1.id < o2.id;
}

bool sortName(Student &o1, Student &o2){
    return o1.name < o2.name;
}

EEE::EEE(){
    Group p;
    groups["cls_A"] = p;
    groups["cls_B"] = p;
    groups["cls_C"] = p;
}
EEE::~EEE(){

}
void EEE::addStudent(string cla, Student stu){
    groups[cla].addStudent(stu); 
}
void EEE::removeStudentByID(string cla, string Id){
    if (groups[cla].student_num == 0){
        cout << "Group doesn't exist" <<endl;
        return;
    }
    groups[cla].removeStudentByID(Id);
}

void EEE::removeStudentByName(string cla, string na){
    if (groups[cla].student_num == 0){
        cout << "Group doesn't exist" <<endl;
        return;
    }
    groups[cla].removeStudentByName(na);
}
void EEE::gradeDistribution(string cla){
    if (groups[cla].student_num == 0){
        cout << "Group doesn't exist" <<endl;
        return;
    }
    groups[cla].gradeDistribution();
}
void EEE::viewInfo(string cla, int mode){
    //time / id / name
    if (groups[cla].student_num == 0){
        cout << "Group doesn't exist" << endl;
        return;
    }
    cout << "Student Num: " << groups[cla].student_num << endl;
    if(mode == 0){
        for (int i = 0 ;i < (int)groups[cla].students.size(); i++){
            cout << "<Student " << i + 1 << ">";
            cout << groups[cla].students[i];
        }
    } else if (mode == 1){
        vector<Student> newStu(groups[cla].students);
        sort(newStu.begin(), newStu.end(), sortID);
        for (int i = 0 ;i < (int)newStu.size(); i++){
            cout << "<Student " << i + 1 << ">";
            cout << newStu[i];
        }
    } else if (mode == 2){
        vector<Student> newStu(groups[cla].students);
        sort(newStu.begin(), newStu.end(), sortName);
        for (int i = 0 ;i < (int)newStu.size(); i++){
            cout << "<Student " << i + 1 << ">";
            cout << newStu[i];
        }
    }
}
