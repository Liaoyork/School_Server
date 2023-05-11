#include <iostream>
#include <string>
#include "Class.h"

using namespace std;


Class::Class(){
    ;
}
Class::Class(Class &p){
    class_size = p.class_size;
    students = p.students;
    passing_score = p.passing_score;
}
void Class::set_class_size(int size){
    class_size = size;
}
void Class::set_stu(Student *stu){
    stu = new Student [class_size];
    for (int i = 0 ; i < class_size; i++){
        string ss;
        int ii;
        cout <<"Student Name: ";    cin >> ss;
        stu[i].name = ss;
        cout << "Student ID: ";     cin >> ss;
        stu[i].stu_id = ss;
        cout << "Score: ";          cin >> ii;
        stu[i].score = ii;
    }
   students = stu;
}
int Class::find_stu(string stu_na){
    bool find = false;
    for (int i = 0 ; i < class_size ; i++){
        if (students[i].name == stu_na){
            find = true;
        }
    }
    return 0;
}
double Class::find_avg(){
    double avg = 0.0;
    for (int i = 0 ; i < class_size ; i++){
        avg += students[i].score;
    }
    return (avg / class_size);
}
double Class::find_mid(){
    for (int i = 0 ; i < class_size ; i++){
        for (int j = 0 ; j < class_size ; j++){
            if (students[i].score > students[j].score){
                swap (students[i], students[j]);
            }
        }
    }
    if (class_size %  2 == 0){
        return (double(students[class_size/2 - 1].score) + double(students[class_size / 2].score)) / 2;
    } else {
        return double(students[class_size/2].score);
    }
}
int Class::find_fail(){
    int count = 0;
    for (int i = 0 ; i < class_size ; i++){
        if (students[i].score < passing_score){
            count++;
        }
    }
    return count;
}


void Class::initialize(){
    cout << "Number of students: ";
    int in;
    cin >> in;
    set_class_size(in);
    cout << "Set Passing Score: ";
    cin >> in;
    set_passing_score(in);
    set_stu(students);
}
void Class::stu_info(){
    for (int i = 0 ; i < class_size ; i++){
        for (int j = 0 ; j < class_size ; j++){
            if (students[i].stu_id < students[j].stu_id){
                swap (students[i], students[j]);
            }
        }
    }
    for (int i = 0 ; i < class_size ; i++){
        cout << students[i].name << "\t" 
             << students[i].stu_id << "\t" 
             << students[i].score << endl;
    }
    cout << endl;
}
void Class::score_info(){
    cout << "Average Score: " << find_avg() << endl;
    cout << "Median Score: " << find_mid() <<endl;
    cout << "Fail Student Number: " << find_fail() << endl;
    cout << endl
         << endl;
}
void Class::set_passing_score(int sco){
    passing_score = sco;
}
void Class::set_score(string na,int sco){
    bool find = false;
    for (int i = 0; i < class_size ; i++){
        if (students[i].name == na){
            find = true;
            students[i].score = sco;
        }
    }
}
void Class::add_stu(Student stu){
    Student *temp = new Student [class_size + 1];
    for (int i = 0 ; i < class_size ; i++){
        temp[i] = students[i];
    }
    temp[class_size] = stu;
    class_size++;
    students = temp;
}
void Class::remove_stu(string stu){
    bool find = false;
    int t = 0;
    Student *temp = new Student [class_size - 1];
    for (int i = 0 ; i < class_size ; i++){
        if (students[i].name != stu){
            temp[t] = students[i];
            t++;
        }
        if (students[i].name == stu) find = true;
    }
    if (!find) cout << "student doesn't exist!" << endl;
    else class_size--;
    students = temp;
}
