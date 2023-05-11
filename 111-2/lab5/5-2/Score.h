#include <iostream>
#include <string>

using namespace std;
class Score {
private:
    friend class Weight;
    string name;
    double math, science, english;
    double average;

    class Weight {
    private:
        friend class Score;
        double weighted_avg;
        double math_weight, science_weight, english_weight;
        Score &score;

    public:
        //Weight();
        //Weight(){}
        Weight(Score& x);
        void set_weight();
        void weight_avg();
    };

public:
    Weight w;
    Score();
    void set_score();
    void avg();
    void Change();
};

