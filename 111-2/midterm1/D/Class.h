#include <string>
#include <vector>
using namespace std;

class Teacher;
class Student;
class Course;x

class Course
{
private:
    int stu_num;
    int teacher_num;
    string name;
    Teacher **tea_arr;
    Student **stu_arr;
    vector<string> HW_vec;

public:
    static vector<string> total_vec;
    static vector<Course*> total_obj_ptr_vec;
    static void createNewCourse(string name, Teacher* teacher_ptr);

    friend class Teacher;
    friend class Student;
    Course();
    Course(string name, Teacher* teacher_ptr){
        tea_arr = new *Teacher [2];
        tea_arr = teacher_ptr;
    }
    ~Course();
    
    friend ostream& operator<<(ostream& out, Course& c);
};
ostream& operator<<(ostream& out, Course& c){
    cout << "this course is " << c.name << endl;
    cout << "teacher: " << total_obj_ptr_vec.tea_arr[0] << endl;
    cout << ""
}
class Teacher
{
private:
    int course_num;
    string name;
    Course **course_arr;
    const string password;

public:
    static vector<string> total_vec;
    static vector<Teacher*> total_obj_ptr_vec;
    static void createNewTeacher(string name, string password);

    Teacher();
    Teacher(string name, string password){
        this->name = name;
        this->password = password;
    }
    ~Teacher();
    bool check_password(string input) const{
        if (input == password) return true;
        return false;
    }
    bool menu();
    string get_name() const{
        return name;
    }
    void operator+=(Course *course_ptr){
    }
    
    operator Student() const;
    void Simulate_Student_mode();
};

class Student
{
private:
    int course_num;
    string name;
    const string password;
    Course **course_arr;

    bool simulate;
    
public:
    static vector<string> total_vec;
    static vector<Student*> total_obj_ptr_vec;
    static void createNewStudent(string name, string password);

    friend class Teacher;
    Student();
    Student(string name, string password){
        this->name = name;
        this->password = password;
    }
    ~Student();
    bool check_password(string input) const{
        if (input == password) return true;
        return false;
    }
    bool menu();
    void select_course();
    string get_name() const;

    void Back_to_Teacher_mode();
};
