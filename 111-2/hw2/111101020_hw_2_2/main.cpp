#include <cstdlib>
#include <ctime>
#include <iostream>

#include "hw2-2.h"

using namespace std;

int main() {
    vector<Role *> players;
    Mage *a;
    Warrior *b;
    Vampire *c;

    srand(time(NULL));
    int role[2] = {0};
    for (int i = 0; i < 2; i++) {
        cout << "Player " << i + 1 << " choose role:" << endl;
        cout << "1. Mage\n2. Warrior\n3. Vampire\n";
        cin >> role[i];
        if (role[i] == 1 || role[i] == 2 || role[i] == 3) {
        } else {
            i--;
        }
    }
    for (int i = 0; i < 2; i++) {
        int hp, att, def, speed, MA;
        float CR, LS;
        cout << "Player " << i + 1 << ": ";
        switch (role[i]) {
            case 1:
                cout << "Mage" << endl;
                cout << "HP: ";
                cin >> hp;
                cout << "Attack: ";
                cin >> att;
                cout << "Defense: ";
                cin >> def;
                cout << "Speed: ";
                cin >> speed;
                cout << "Magic Attack: ";
                cin >> MA;
                a = new Mage(hp, att, def, speed, MA, 'M');
                players.push_back(a);
                break;
            case 2:
                cout << "Warrior" << endl;
                cout << "HP: ";
                cin >> hp;
                cout << "Attack: ";
                cin >> att;
                cout << "Defense: ";
                cin >> def;
                cout << "Speed: ";
                cin >> speed;
                cout << "Crit Rate: ";
                cin >> CR;
                b = new Warrior(hp, att, def, speed, CR, 'W');
                players.push_back(b);
                break;
            case 3:
                cout << "Vampire" << endl;
                cout << "HP: ";
                cin >> hp;
                cout << "Attack: ";
                cin >> att;
                cout << "Defense: ";
                cin >> def;
                cout << "Speed: ";
                cin >> speed;
                cout << "Life Steal: ";
                cin >> LS;
                c = new Vampire(hp, att, def, speed, LS, 'V');
                players.push_back(c);
                break;
        }
        cout << endl;
    }
    Role *Main_player, *Sec_player;
    Role *k;
    int round = 1;
    int t = 0;
    if (players.at(0)->getSpeed() > players.at(1)->getSpeed()) {
        Main_player = players.at(0);
        Sec_player = players.at(1);
        t = 2;
    } else {
        Main_player = players.at(1);
        Sec_player = players.at(0);
        t = 1;
    }
    while (1) {
        int control;
        cout << "Round: " << round << endl;
        cout << "player " << t % 2 + 1 << "'s turn" << endl;
        // output the kaomoji of total info
        for (int i = 0; i < 5; i++) {
            cout << "\t";
            if (i == 2) {
                if (players.at(0)->getDefence()) {
                    if (players.at(1)->getDefence()) {
                        cout << "/-+-)        (-+-\\" << endl;
                    } else {
                        cout << "/-+-)        \\-+-\\" << endl;
                    }
                } else {
                    if (players.at(1)->getDefence()) {
                        cout << "/-+-/        (-+-\\" << endl;
                    } else {
                        cout << "/-+-/        \\-+-\\" << endl;
                    }
                }
                continue;
            }
            players.at(0)->showmovement(i);
            cout << "        ";
            players.at(1)->showmovement(i);
            cout << endl;
        }

        cout << "      "
             << "p1: " << players.at(0)->gethp()
             << "\t   p2: " << players.at(1)->gethp() << endl;

        cout << "1. Attack\n2. Defense\n";
        cin >> control;
        if (control == 1) {
            for (int i = 0; i < 5; i++) {
                cout << "\t";
                if (players.at(0) == Main_player) {
                    cout << "\t";
                    if (i == 2) {
                        if (players.at(1)->getDefence()) {
                            cout << "/-+---o (--+-\\" << endl;
                        } else {
                            cout << "/-+-----o\\-+-\\" << endl;
                        }
                        continue;
                    }
                } else if (players.at(1) == Main_player) {
                    if (i == 2) {
                        if (players.at(0)->getDefence()) {
                            cout << "/-+--) 0---+-\\" << endl;
                        } else {
                            cout << "/-+-/0-----+-\\" << endl;
                        }
                        continue;
                    }
                }
                players.at(0)->showmovement(i);
                cout << "    ";
                players.at(1)->showmovement(i);
                cout << endl;
            }
            Sec_player->subhp(Main_player->attacking(), Main_player);
        } else if (control == 2) {
            Main_player->setDefense();
            if (Main_player->getPro() == 'V') {
                Sec_player->subHP_V(Main_player->attacking());
            }
        }

        // output the kaomoji of Mp movement
        if (Sec_player->gethp() <= 0) {
            cout << "Player " << t % 2 << " lose" << endl;
            break;
        }
        // change
        k = Main_player;
        Main_player = Sec_player;
        Sec_player = k;

        cout << "Round: " << round << endl;
        cout << "player " << t % 2 << "'s turn" << endl;

        // output the kaomoji of total info
        for (int i = 0; i < 5; i++) {
            cout << "\t";
            if (i == 2) {
                if (players.at(0)->getDefence()) {
                    if (players.at(1)->getDefence()) {
                        cout << "/-+-)        (-+-\\" << endl;
                    } else {
                        cout << "/-+-)        \\-+-\\" << endl;
                    }
                } else {
                    if (players.at(1)->getDefence()) {
                        cout << "/-+-/        (-+-\\" << endl;
                    } else {
                        cout << "/-+-/        \\-+-\\" << endl;
                    }
                }
                continue;
            }
            players.at(0)->showmovement(i);
            cout << "        ";
            players.at(1)->showmovement(i);
            cout << endl;
        }
        cout << "      "
             << "p1: " << players.at(0)->gethp()
             << "\t   p2: " << players.at(1)->gethp() << endl;
        cout << "1. Attack\n2. Defense\n";
        cin >> control;
        if (control == 1) {
            for (int i = 0; i < 5; i++) {
                cout << "\t";
                if (players.at(0) == Main_player) {
                    cout << "\t";
                    if (i == 2) {
                        if (players.at(1)->getDefence()) {
                            cout << "/-+---o (--+-\\" << endl;
                        } else {
                            cout << "/-+-----o\\-+-\\" << endl;
                        }
                        continue;
                    }
                } else if (players.at(1) == Main_player) {
                    if (i == 2) {
                        if (players.at(0)->getDefence()) {
                            cout << "/-+--) 0---+-\\" << endl;
                        } else {
                            cout << "/-+-/0-----+-\\" << endl;
                        }
                        continue;
                    }
                }
                players.at(0)->showmovement(i);
                cout << "    ";
                players.at(1)->showmovement(i);
                cout << endl;
            }
            Sec_player->subhp(Main_player->attacking(), Main_player);
        } else if (control == 2) {
            Main_player->setDefense();
            if (Main_player->getPro() == 'V') {
                Sec_player->subHP_V(Main_player->attacking());
            }
        }
        // output the kaomoji of Sp
        if (Sec_player->gethp() <= 0) {
            cout << "Player " << t % 2 + 1 << " lose" << endl;
            break;
        }
        round++;
        k = Main_player;
        Main_player = Sec_player;
        Sec_player = k;
    }
}

