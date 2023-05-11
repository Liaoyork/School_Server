#include "Score.h"
#include <iostream>
#include <cmath>

Score::Score():w(Weight(*this)){
    //w = Weight(this);   
}

//Weight(){}

Score::Weight::Weight(Score& x):score(x) {
    ;
}


/*
Score::Weight::Weight(){
    //score = Score();
}
*/
void Score::Weight::set_weight() {
    cout << "math weight: "; cin >> math_weight; 
    cout << "science weight: "; cin >> science_weight; 
    cout << "english weight: "; cin >> english_weight; 
}
void Score::Weight::weight_avg() {
    weighted_avg = ( score.math * math_weight  + score.science * science_weight + score.english * english_weight );
    cout << "Weighted average is: " << weighted_avg << endl;
}

void Score::set_score(){
    cout << "name: "; cin >> name;
    cout << "math score: "; cin >> math;
    cout << "science score: "; cin >> science;
    cout << "english score: "; cin >> english;
}
void Score::avg(){
    average = ( math + science + english ) / 3;
    cout << "average is: " << average << endl;
}
void Score::Change(){
    math = sqrt(math) * 10;
    science = sqrt(science) * 10;
    english = sqrt(english) * 10;
    avg();
}

