#include <iostream>

using namespace std;

struct Student{
    string name;
    string stu_id;
    int score;
};

class Class{
private:
    int class_size;
    int passing_score;
    Student *students;
    void set_class_size(int size);
    void set_stu(Student *);
    int find_stu(string);
    double find_avg();
    double find_mid();
    int find_fail();
public:
    Class();
    Class(Class &);
    void initialize();
    void stu_info();
    void score_info();
    void set_passing_score(int);
    void set_score(string,int);
    void add_stu(Student);
    void remove_stu(string);
};
