#pragma once
#include <string>
#include <vector>
#ifndef _P_
#define _P_
#include "Personnel.h"
#endif

using namespace std;

class Course;

class Student : public virtual Personnel {
   protected:
    string degree;
    int tuition;
    vector<Course*> attendedCourses;

   public:
    Student(string id, string name, string email, string password, string degree, int tuition);
    ~Student();
    void printInfo();
    void addAttendCourse(Course* course);
};
