#pragma once
#include <string>
#include <vector>

#ifndef _P_
#define _P_
#include "Personnel.h"
#endif
using namespace std;

class Course;

class Teacher : public virtual Personnel {
   protected:
    int salary;
    vector<Course*> taughtCourses;

   public:
    Teacher(string id, string name, string email, string password, int salary);
    ~Teacher();
    void printInfo();
    void addTaughtCourse(Course* course);
    int getSalary() {
        return salary;
    }
};
