#include "E3.h"

#include <fstream>
#include <iostream>
#include <string>

#include "Course.h"
#include "TA.h"

using namespace std;

E3::E3(){
    ;
}

E3::~E3() {
    
    for (int i = 0 ; i < (int)students.size(); i++){
        delete students[i];
    }
    
    for (int i = 0 ; i < (int)personnels.size(); i++){
        delete personnels[i];
    }
     
    for (int i = 0 ; i < (int)teachers.size(); i++){
        delete teachers[i];
    }
    for (int i = 0 ; i < (int)TAs.size(); i++){
        delete TAs[i];
    }
    
    for (int i = 0 ; i < (int) courses.size(); i++){
        delete courses[i];
    }
}

void E3::importPersonnelsFromCsv(string personnelsFilename) {
    ifstream in(personnelsFilename);
    string ss, tmp;
    string id, name, mail, password, position, deg;
    getline(in,ss);
    while (getline(in, ss)) {
        int i = 0;
        for (int j = 0; j < (int)ss.length(); j++) {
            if (ss[j] != ',')
                ;
            else {
                tmp = ss.substr(i, j - i);
                i = j + 1;
                break;
            }
        }
        id = tmp;
        tmp = "";

        for (int j = i; j < (int)ss.length(); j++) {
            if (ss[j] != ',' || ss[j] == ' ')
                ;
            else {
                tmp = ss.substr(i, j - i);
                i = j + 1;
                break;
            }
        }
        name = tmp;
        // cout << name << endl;
        tmp = "";

        for (int j = i; j < (int)ss.length(); j++) {
            if (ss[j] != ',')
                ;
            else {
                tmp = ss.substr(i, j - i);
                i = j + 1;
                break;
            }
        }
        mail = tmp;
        tmp = "";

        for (int j = i; j < (int)ss.length(); j++) {
            if (ss[j] != ',')
                ;
            else {
                tmp = ss.substr(i, j - i);
                i = j + 1;
                break;
            }
        }
        password = tmp;
        tmp = "";

        Personnel *p = new Personnel(id, name, mail, password);
        personnels.push_back(p);

        for (int j = i; j < (int)ss.length(); j++) {
            if (ss[j] != ',')
                ;
            else {
                tmp = ss.substr(i, j - i);
                i = j + 1;
                break;
            }
        }
        position = tmp;
        if (tmp != "") tmp = "";

        for (int j = i; j < (int)ss.length(); j++) {
            if (ss[j] != ',')
                ;
            else {
                tmp = ss.substr(i, j - i);
                i = j + 1;
                break;
            }
        }
        deg = tmp;
        // cout << deg << endl;
        if (tmp != "") tmp = "";

        for (int j = i; j < (int)ss.length(); j++) {
            if (ss[j] != ',')
                ;
            else {
                tmp = ss.substr(i, j - i);
                i = j + 1;
                break;
            }
        }
        int tui = 0;
        if (tmp != "") tui = stoi(tmp);
        if (tmp != "") tmp = "";

        for (int j = i; j < (int)ss.length(); j++) {
            if (j != (int)ss.length() - 1)
                ;
            else {
                tmp = ss.substr(i, j - i + 2);
                i = j + 1;
                break;
            }
        }
        int sal = 0;
        if (tmp != "") sal = stoi(tmp);
        if (tmp != "") tmp = "";
        // cout << sal << endl;
        if (position == "Student") {
            Student *a = new Student(id, name, mail, password, deg, tui);
            students.push_back(a);
        } 
        if (position == "TA") {
            TA *a = new TA(id, name, mail, password, deg, tui, sal);
            TAs.push_back(a);
        } 
        if (position == "Teacher") {
            Teacher *a = new Teacher(id, name, mail, password, sal);
            teachers.push_back(a);
        }
    }
}
void E3::importCoursesFromCsv(string csvFilename) {
    ifstream in(csvFilename);
    string ss, tmp;
    string id, name, Pro_id;
    vector<string> stu_id, TA_id;
    getline(in, ss);  // only get info
    //getline(in, ss);  
    
    while (getline(in, ss)) {
        int j = 0;
        // id
        for (int i = j; i < (int)ss.length(); i++) {
            if (ss[i] != ',')
                ;
            else {
                id = ss.substr(j, i - j);
                j = i + 1;
                break;
            }
        }
        // course name
        for (int i = j; i < (int)ss.length(); i++) {
            if (ss[i] != ',')
                ;
            else {
                name = ss.substr(j, i - j);
                j = i + 1;
                break;
            }
        }
        // Professor name
        for (int i = j; i < (int)ss.length(); i++) {
            if (ss[i] != ',')
                ;
            else {
                Pro_id = ss.substr(j, i - j);
                j = i + 1;
                break;
            }
        }
        // TAs
        int t = j;
        while (1) {
            if (ss[t] == ',') {
                TA_id.push_back(ss.substr(j, t - j));
                j = t + 1;
                break;
            } else if (ss[t] == '|') {
                TA_id.push_back(ss.substr(j, t - j));
                j = t + 1;
                t = j;
            } else {
                t++;
            }
        }

        // stu
        t = j;
        while (1) {
            if (t == (int)ss.length() - 1) {
                stu_id.push_back(ss.substr(j, t - j + 1));
                j = t + 1;
                break;
            }
            if (ss[t] == '|') {
                stu_id.push_back(ss.substr(j, t - j));
                j = t + 1;
                t = j;
            } else {
                t++;
            }
        }
        // new new course
        Course *p;
        for (int i = 0; i < (int)teachers.size(); i++) {
            if (teachers[i]->getId() == Pro_id) {
                p = new Course(id, name, teachers[i]);
                teachers[i]->addTaughtCourse(p);
                break;
            }
        }
        for (int i = 0; i < (int)stu_id.size(); i++) {
            for (int k = 0; k < (int)students.size(); k++) {
                if (stu_id[i] == students[k]->getId()) {
                    p->addStudent(students[k]);
                    students[k]->addAttendCourse(p);
                    break;
                }
            }
        }
        for (int i = 0; i < (int)stu_id.size(); i++) {
            for (int k = 0; k < (int)TAs.size(); k++) {
                if (TAs[k]->getId() == stu_id[i]) {
                    p->addStudent(TAs[k]);
                    TAs[k]->addAttendCourse(p);
                    break;
                }
            }
        }

        for (int i = 0; i < (int)TA_id.size(); i++) {
            for (int k = 0; k < (int)TAs.size(); k++) {
                if (TAs[k]->getId() == TA_id[i]) {
                    p->addTA(TAs[k]);
                    TAs[k]->addTaughtCourse(p);
                    break;
                }
            }
        }
        courses.push_back(p);
        TA_id.erase(TA_id.begin(), TA_id.end());
        stu_id.erase(stu_id.begin(), stu_id.end());
    }
}

void E3::printAllPersonnel() {
    for (int i = 0; i < (int)personnels.size(); i++) {
        personnels[i]->printInfo();
        cout << endl;
    }
}
void E3::printAllCourse() {
    for (int c = 0; c < (int)courses.size(); c++) {
        courses[c]->printInfo();
    }
}
