#include "Teacher.h"

#include <iostream>

#include "Course.h"

using namespace std;

Teacher::Teacher(string id, string name, string email, string password, int salary) : Personnel(id, name, email, password) {
    this->salary = salary;
}

Teacher::~Teacher(){
    //for (int i = 0 ; i < (int)taughtCourses.size(); i++){
    //    delete taughtCourses[i];
    //}
    taughtCourses.clear();
}

void Teacher::printInfo() {
    cout << "Teacher: " << endl;
    cout << "\t"; Personnel::printInfo();
    cout << "salary: " << salary << endl;
    cout << "\tTaught Courses: ";
    for (int i = 0; i < (int)taughtCourses.size(); i++) {
        cout << "\"";
        cout << taughtCourses[i]->getName();
        cout << "\"";
        cout << " ";
    }
    cout << endl;
}
void Teacher::addTaughtCourse(Course* course) {
    taughtCourses.push_back(course);
}
