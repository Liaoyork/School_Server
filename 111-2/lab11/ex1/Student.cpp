#include "Student.h"
#include <iostream>

using namespace std;

Student::Student(string id, string name, vector<int> a){
    this->id = id;
    this->name = name;
    for (int i = 0 ;i < (int)a.size(); i++){
        Scores.push_back(a.at(i));
    }
}
Student::~Student(){

}
ostream &operator<<(ostream &out, const Student a){ 
    cout << " ID: " << a.id << ", Name: " << a.name << endl;
    cout << "Score >" << endl;
    cout << "\tCalculus: " << a.Scores[0] << endl;
    cout << "\tEnglish: " << a.Scores[1] << endl;
    cout << "\tPhysics: " << a.Scores[2] << endl;
    return out;
}
