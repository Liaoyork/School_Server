#pragma once
#include <string>
#include <vector>

#ifndef _S_
#define _S_
#include "Student.h"
#endif
#ifndef _T_
#define _T_
#include "Teacher.h"
#endif

using namespace std;

class TA : public Student, public Teacher {
   private:
   public:
    TA(string id, string name, string email, string password, string degree, int tuition, int salary);
    ~TA();
    void printInfo();
};
