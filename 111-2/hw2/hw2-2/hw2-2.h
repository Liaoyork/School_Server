#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Role {
   private:
    int hp;
    int attack;
    int defense;
    int speed;
    bool isDefence;
    char Pro;

   public:
    Role(int, int, int, int, char);
    const int oriHP;
    void subHP_V(int);
    int getSpeed();
    void subhp(int, Role*);
    int gethp();
    char getPro();
    void addhp(int);
    int getAttack();
    bool getDefence() {
        return isDefence;
    }
    void setDefense();
    virtual int attacking();
    virtual void showmovement(int);
};
class Mage : public Role {
   private:
    int magicAttack;

   public:
    const vector<char> ori[4]{
        {' ', '^', '_', '^', ' '},
        {' ', '(', ' ', ')', ' '},
        {' ', ' ', '|', ' ', ' '},
        {' ', '/', ' ', '\\', ' '}};
    Mage(int, int, int, int, int, char);
    void showmovement(int);
    int attacking();
};

class Warrior : public Role {
   private:
    float critRate;

   public:
    const vector<char> ori[4]{
        {' ', ' ', '_', ' ', ' '},
        {' ', '(', ' ', ')', ' '},
        {' ', '[', '|', ']', ' '},
        {' ', '/', ' ', '\\', ' '}};
    Warrior(int, int, int, int, float, char);
    int attacking();
    void showmovement(int);
};
class Vampire : public Role {
   private:
    float lifeSteal;

   public:
    const vector<char> ori[4]{
        {' ', ' ', '_', ' ', ' '},
        {' ', '(', 'v', ')', ' '},
        {' ', ' ', '|', ' ', ' '},
        {' ', '/', ' ', '\\', ' '}};
    Vampire(int, int, int, int, float, char);
    int attacking();
    void showmovement(int);
};
