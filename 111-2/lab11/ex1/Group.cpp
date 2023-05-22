#include "Group.h"
#include "Student.h"
#include <iostream>
#include "iomanip"
using namespace std;

Group::Group(){
    student_num = 0;
    sum_score_Calculus = 0;
    high_Calculus = 0;
    low_Calculus = 100;
    sum_score_English = 0;
    high_English = 0;
    low_English = 100;
    sum_score_Physics = 0;
    high_Physics = 0;
    low_Physics = 100;
}
Group::~Group(){

}
void Group::addStudent(Student stu){
    students.push_back(stu);
    student_num++;
    for (int i = 0 ;i < student_num; i++){
        if (students[i].Scores[0] > high_Calculus){
            high_Calculus = students[i].Scores[0];
        } 
        if (students[i].Scores[0] < low_Calculus){
            low_Calculus = students[i].Scores[0];
        }

        if (students[i].Scores[1] > high_English){
            high_English = students[i].Scores[1];
        } 
        if (students[i].Scores[1] < low_English){
            low_English = students[i].Scores[1];
        }

        if (students[i].Scores[2] > high_Physics){
            high_Physics = students[i].Scores[2];
        } 
        if (students[i].Scores[2] < low_Physics){
            low_Physics = students[i].Scores[2];
        }
    }
    sum_score_Calculus += stu.Scores[0];
    sum_score_English += stu.Scores[1];
    sum_score_Physics += stu.Scores[2];
}
void Group::removeStudentByID(string Id){
    for (int i = 0 ; i < (int)students.size(); i++){
        if (Id == students[i].id){
            sum_score_Calculus -= students[i].Scores[0];
            sum_score_English -= students[i].Scores[1];
            sum_score_Physics -= students[i].Scores[2];
            students.erase(students.begin() + i);
            student_num--;
            cout << "Remove Successfully" << endl;
            return;
        }
    }
    cout << "Student does't exist" << endl;
}
void Group::removeStudentByName(string na){
    for (int i = 0 ; i < (int)students.size(); i++){
        if (na == students[i].name){
            sum_score_Calculus -= students[i].Scores[0];
            sum_score_English -= students[i].Scores[1];
            sum_score_Physics -= students[i].Scores[2];
            
            students.erase(students.begin() + i);
            student_num--;
            cout << "Remove Successfully" << endl;
            return;
        }
    }
    cout << "Student does't exist" << endl;
}
void Group::gradeDistribution(){
    cout << "Student Num: " << student_num << endl;
    cout << "<Calculus>\nAvg: " << fixed << setprecision(2) << (double)sum_score_Calculus/(double)student_num << endl;
    for (int i = 0 ;i < (int)students.size(); i++){
        if (high_Calculus < students[i].Scores[0]){
            high_Calculus = students[i].Scores[0];
        }
    }
    for (int i = 0 ;i < (int)students.size(); i++){
        if (low_Calculus > students[i].Scores[0]){
            low_Calculus = students[i].Scores[0];
        }
    }
    for (int i = 0 ;i < (int)students.size(); i++){
        if (high_English < students[i].Scores[1]){
            high_English = students[i].Scores[1];
        }
    }
    for (int i = 0 ;i < (int)students.size(); i++){
        if (low_English > students[i].Scores[1]){
            low_English = students[i].Scores[1];
        }
    }
    for (int i = 0 ;i < (int)students.size(); i++){
        if (high_Physics < students[i].Scores[2]){
            high_Physics = students[i].Scores[2];
        }
    }
    for (int i = 0 ;i < (int)students.size(); i++){
        if (low_Physics > students[i].Scores[2]){
            low_Physics = students[i].Scores[2];
        }
    }
    cout << "Max: " << high_Calculus << endl;
    cout << "Min: " << low_Calculus << endl;

    cout << "<English>\nAvg: " << fixed << setprecision(2) <<(double)sum_score_English/(double)student_num << endl;
    cout << "Max: " << high_English << endl;
    cout << "Min: " << low_English << endl;
    
    cout << "<Physics>\nAvg: " << setprecision(2) << (double)sum_score_Physics/(double)student_num << endl;
    cout << "Max: " << high_Physics << endl;
    cout << "Min: " << low_Physics << endl;
}
