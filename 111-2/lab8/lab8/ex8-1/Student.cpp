#include "Student.h"

#include <fstream>
#include <iostream>

#include "Course.h"

using namespace std;

Student::Student(string id, string name, string email, string password, string degree, int tuition) : Personnel(id, name, email, password) {
    this->degree = degree;
    this->tuition = tuition;
}

Student::~Student(){
    attendedCourses.clear();
}
void Student::printInfo() {
    cout << "\t"; Personnel::printInfo();
    cout << "Degree: " << degree << "\t"
         << "Tuition: " << tuition << endl;
    
    cout << "\tAttend Courses: ";
    for (int i = 0; i < (int)attendedCourses.size(); i++) {
        cout << "\"";
        cout << attendedCourses[i]->getName();
        cout << "\"";
        cout << " ";
    }
    cout << endl;
}
void Student::addAttendCourse(Course* course) {
    attendedCourses.push_back(course);
}
