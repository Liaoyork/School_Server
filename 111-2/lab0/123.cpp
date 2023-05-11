#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
using namespace std;

ifstream in;
ofstream out;

class Grade{

public:
    Grade(){
        ;
    }
    ~Grade(){
        ;
    }
    void set_quiz1(double a){
        quiz1 = a;
    }
    void set_quiz2(double b){
        quiz2 = b;
    }
    void set_mid(double c){
        mid = c;
    }
    void set_final(double d){
        final = d;
        cal_average_grade();
        cal_letter_grade();
    }

    double get_quiz1(){
        return quiz1;
    }

    double get_quiz2(){
        return quiz2;
    }

    double get_mid(){
        return mid;
    }

    double get_final(){
        return final;
    }
    
    double get_average_grade(){
        return average_grade;
    }

    char get_letter_grade(){
        return letter_grade;
    }

private:
    double quiz1=0;
    double quiz2=0;
    double mid=0;
    double final=0;
    double average_grade=0;
    char letter_grade;

    void cal_average_grade(){
        average_grade = ((quiz1/10+quiz2/10)/2*0.25+mid/100*0.25+final/100*0.5)*100;
    }


    void cal_letter_grade(){
        
        if (average_grade >= 90) letter_grade = 'A';
        else if(average_grade >=80) letter_grade = 'B';
        else if(average_grade >=70) letter_grade = 'C';
        else if(average_grade >=60) letter_grade = 'D';
        else letter_grade = 'F';

    }
};

int main(int argc , char* argv[]){

    in.open(argv[1]);
    out.open(argv[2]);
    //in.open("input.txt");
    //out.open("Output_hw4-2.txt");
    
    string ss;
    double temp;
    Grade grade;
    
    in >> ss;
    temp = stod(ss);
    grade.set_quiz1(temp);

    in >> ss;
    temp = stod(ss);
    grade.set_quiz2(temp);

    in >> ss;
    temp = stod(ss);
    grade.set_mid(temp);

    in >> ss;
    temp = stod(ss);
    grade.set_final(temp);

    out << "Quiz 1: " << grade.get_quiz1() << endl;
    out << "Quiz 2: " << grade.get_quiz2() << endl;
    out << "Midterm: " << grade.get_mid() << endl;
    out << "Final: " << grade.get_final() << endl;
    out << "Average numeric score: " << grade.get_average_grade() << endl;
    out << "Final letter grade: " << grade.get_letter_grade() << endl;

    return 0;
}
