#include <string>
#include <vector>
using namespace std;

class Student {
   private:
    string id;
    string name;
    vector<int> Scores;  // store 3 score {Calculus, English, Physics}
    friend class Group;
    friend class EEE;
   public:
    Student(string, string, vector<int>);  // (ID, Name, Scores)
    ~Student();
    friend ostream &operator<<(ostream &out, const Student a);
    friend bool sortID(Student &, Student &);
    friend bool sortName(Student &, Student &);
    // add any function you need
};
