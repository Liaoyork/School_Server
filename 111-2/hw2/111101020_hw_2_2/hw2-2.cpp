#include "hw2-2.h"

#include <cstdlib>
#include <ctime>
#include <iostream>

using namespace std;

int Role::attacking() {
    cout << "error!" << endl;
    return 0;
}

void Role::subHP_V(int a) {
    hp -= a;
}

Role::Role(int hp, int attack, int defense, int speed, char Pro) : oriHP(hp) {
    this->hp = hp;
    this->attack = attack;
    this->defense = defense;
    this->speed = speed;
    this->Pro = Pro;
    isDefence = false;
}
Role::~Role(){
    ;
}
void Role::subhp(int spec, Role* player) {
    if (!isDefence) {
        hp -= spec;
        hp -= player->attack;
        return;
    }
    if (player->Pro == 'V') {
        isDefence = false;
        hp -= spec;
        if (player->attack - defense <= 0) {
            return;
        }
        hp = hp - (player->attack - defense);
    } else if (player->getPro() == 'M') {
        isDefence = false;
        hp -= spec;
        if (player->attack - defense <= 0) {
            return;
        }
    } else if (player->getPro() == 'W') {
        isDefence = false;
        if (player->attack + spec - defense <= 0) {
            return;
        }
        hp = hp - (player->attack + spec - defense);
    }
}
int Role::gethp() {
    return hp;
}
char Role::getPro() {
    return Pro;
}
void Role::addhp(int a) {
    hp += a;
    if (hp > oriHP) {
        hp = oriHP;
    }
}
int Role::getSpeed() {
    return speed;
}

void Role::setDefense() {
    isDefence = true;
}

Mage::Mage(int hp, int attack, int defence, int speed, int magic, char Pro) : Role(hp, attack, defence, speed, Pro) {
    magicAttack = magic;
}

int Mage::attacking() {
    return magicAttack;
}

Warrior::Warrior(int hp, int attack, int defence, int speed, float critRate, char Pro) : Role(hp, attack, defence, speed, Pro) {
    this->critRate = critRate;
}

int Role::getAttack(){
    return attack;
}
int Warrior::attacking() {
    if (rand() % 100 < 100 * critRate)
        return getAttack();
    return 0;
}

Vampire::Vampire(int hp, int attack, int defence, int speed, float lifeSteal, char Pro) : Role(hp, attack, defence, speed, Pro) {
    this->lifeSteal = lifeSteal;
}

int Vampire::attacking() {
    Role::addhp(lifeSteal * oriHP);
    return lifeSteal * oriHP;
}

void Role::showmovement(int k) {
}
void Mage::showmovement(int k) {
    if (k >= 3) {
        k--;
    }
    for (int i = 0; i < 5; i++) {
        cout << ori[k][i];
    }
}
void Warrior::showmovement(int k) {
    if (k >= 3) {
        k--;
    }
    for (int i = 0; i < 5; i++) {
        cout << ori[k][i];
    }
}
void Vampire::showmovement(int k) {
    if (k >= 3) {
        k--;
    }
    for (int i = 0; i < 5; i++) {
        cout << ori[k][i];
    }
}

