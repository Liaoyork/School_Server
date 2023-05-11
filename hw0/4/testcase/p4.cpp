#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

class country {
   private:
    string name;
    int point;
    int score;
    int score_R;

   public:
    country() {
        point = 0;
        score = 0;
        score_R = 0;
    }
    country(string TBD) {
        name = TBD;
    }
    ~country() {
        ;
    }
    int getpoint() {
        return point;
    }
    void calpoint(int p) {
        point += p;
    }
    void resetScore() {
        score = 0;
    }
    int getscore() {
        return score;
    }
    void setscore(int s) {
        score = s;
    }
    void storeScore(int s) {
        score_R += s;
    }
    int getSR() {
        return score_R;
    }
    void setName(string n) {
        name = n;
    }
    string getname() {
        return name;
    }
};

int main(int argc, char *argv[]) {
    ifstream in(argv[1]);
    ofstream out(argv[2]);
    country **c = new country *[8];
    string ss;
    for (int i = 0; i < 8; i++) {
        c[i] = new country[4];
    }
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 4; j++) {
            in >> ss;
            c[i][j].setName(ss);
        }
    }

    for (int i = 0; i < 48; i++) {
        country *p;
        country *n;
        in >> ss;

        for (int j = 0; j < 8; j++) {
            for (int k = 0; k < 4; k++) {
                if (c[j][k].getname() == ss)
                    p = &c[j][k];
            }
        }

        in >> ss;
        for (int j = 0; j < 8; j++) {
            for (int k = 0; k < 4; k++) {
                if (c[j][k].getname() == ss) n = &c[j][k];
            }
        }

        int t;
        in >> t;
        // cout << p[0][0].getname() << endl;
        p->setscore(t);
        p->storeScore(t);

        in >> ss;

        in >> t;
        n->setscore(t);
        n->storeScore(t);

        if (p->getscore() > n->getscore())
            p->calpoint(3);
        else if (p->getscore() < n->getscore())
            n->calpoint(3);
        else {
            p->calpoint(1);
            n->calpoint(1);
        }

        for (int j = 0; j < 8; j++) {
            for (int k = 0; k < 4; k++) {
                c[j][k].resetScore();
            }
        }
    }
    // cout << c[5][3].getpoint() << endl;
    vector<country> _16old;
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 4; j++) {
            for (int k = 0; k < 4; k++) {
                if (c[i][k].getpoint() < c[i][j].getpoint()) {
                    swap(c[i][k], c[i][j]);
                    // cout << "hihi";
                } else if (c[i][k].getpoint() == c[i][j].getpoint()) {
                    if (c[i][k].getSR() < c[i][j].getSR()) {
                        swap(c[i][k], c[i][j]);
                    }
                }
            }
        }
    }

    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 8; j++) {
            _16old.push_back(c[j][i]);
        }
    }

    vector<int> sc[2];
    vector<int> sequence;

    while (1) {
        in >> ss;
        if (ss == "=") break;
        bool flag = false;
        for (int j = 0; j < (int)ss.length(); j++) {
            if (!isdigit(ss[j])) {
                flag = true;
            }
        }
        string temp = "";
        if (flag) {
            int p;
            int q;
            for (int i = (int)ss.length() - 1; i >= 0; i--) {
                if (ss[i] == '(') p = i;
                if (ss[i] == ')') q = i;
            }
            temp = ss.substr(p + 1, q - 1);
            sc[0].push_back(stoi(temp));
        }
        if (!flag) sc[0].push_back(stoi(ss));
        in >> ss;
        in >> ss;
        if (flag) {
            int p;
            int q;
            for (int i = (int)ss.length() - 1; i >= 0; i--) {
                if (ss[i] == '(') p = i;
                if (ss[i] == ')') q = i;
            }
            temp = ss.substr(p + 1, q - 1);
            sc[1].push_back(stoi(temp));
        }
        if (!flag) sc[1].push_back(stoi(ss));
    }

    vector<int> win;
    for (int i = 0; i < (int)sc[0].size(); i++) {
        if (sc[0][i] > sc[1][i])
            win.push_back(1);
        else
            win.push_back(0);
    }

    string temp = "";
    vector<country> _16(16);
    vector<country> _8;
    vector<country> _4;
    vector<country> _2;
    vector<country> _1;
    bool first = true;
    // getline(in, ss);
    // getline(in, ss);
    //  cout << ss;
    while (getline(in, ss)) {
        if (ss == "") continue;

        // sequence
        for (int i = 0; i < ss.length(); i++) {
            while (isdigit(ss[i])) {
                temp += ss[i];
                i++;
            }
            sequence.push_back(stoi(temp));
            temp = "";
        }

        // rearrange the race sequence
        for (int i = 0; i < 16; i++) {
            _16[sequence[i] - 1] = _16old[i];
        }

        // 16->8
        int m = 0;
        if ((int)win.size() >= 9) {
            m = 8;
        } else
            m = (int)win.size();

        for (int j = 0; j < m; j++) {
            if (win[j] == 1) {
                country *p = new country;
                p->setName(_16[2 * j].getname());
                _8.push_back(*p);
            } else if (win[j] == 0) {
                country *p = new country;
                p->setName(_16[2 * j + 1].getname());
                _8.push_back(*p);
            }
        }

        // stuck the space of _8
        while ((int)_8.size() < 8) {
            country *p = new country("TBD");
            _8.push_back(*p);
        }

        // // 8->4 only country name
        for (int j = 0; j < 4; j++) {
            if (j + 8 < (int)win.size()) {
                if (win[j + 8] == 1)
                    _4.push_back(_8[2 * j]);
                else if (win[j + 8] == 0)
                    _4.push_back(_8[2 * j + 1]);
            }
        }

        // // stuck the space of _4
        while ((int)_4.size() < 4) {
            country *p = new country("TBD");
            _4.push_back(*p);
        }

        // // 4->2 only country name
        for (int j = 0; j < 2; j++) {
            if (j + 12 < (int)win.size()) {
                if (win[j] == 1)
                    _2.push_back(_4[2 * j]);
                else
                    _2.push_back(_4[2 * j + 1]);
            }
        }

        // // stuck the space of _2
        while ((int)_2.size() < 2) {
            country *p = new country("TBD");
            _2.push_back(*p);
        }

        // // stuck and 2->1
        if ((int)win.size() == 15) {
            if (win[14] == 1)
                _1.push_back(_2[0]);
            else if (win[14] == 0)
                _1.push_back(_2[1]);
        } else {
            country *p = new country("TBD");
            _1.push_back(*p);
        }

        if (!first) {
            out << "=" << endl;
        } else {
            first = false;
        }
        int j = 0;
        for (int i = 0; i < 8; i++) {
            out << _16[j].getname() << " v.s. ";
            j++;
            out << _16[j].getname() << "\t";
            if (i >= (int)win.size())
                out << "The game is coming soon..." << endl;
            else
                out << "The winner is " << _8[i].getname() << endl;
            j++;
        }

        j = 0;
        for (int i = 0; i < 4; i++) {
            out << _8[j].getname() << " v.s. ";
            j++;
            out << _8[j].getname() << "\t";
            if (i >= (int)win.size() - 8)
                out << "The game is coming soon..." << endl;
            else
                out << "The winner is " << _4[i].getname() << endl;
            j++;
        }

        j = 0;
        for (int i = 0; i < 2; i++) {
            out << _4[j].getname() << " v.s. ";
            j++;
            out << _4[j].getname() << "\t";
            if (i >= (int)win.size() - 12)
                out << "The game is coming soon..." << endl;
            else
                out << "The winner is " << _2[i].getname() << endl;
            j++;
        }

        j = 0;
        for (int i = 0; i < 1; i++) {
            out << _2[j].getname() << " v.s. ";
            j++;
            out << _2[j].getname() << "\t";
            if (i >= (int)win.size() - 14)
                out << "The game is coming soon..." << endl;
            else
                out << "The winner is " << _1[i].getname() << endl;
        }
        sequence.erase(sequence.begin(), sequence.end());
        _8.erase(_8.begin(), _8.end());
        _4.erase(_4.begin(), _4.end());
        _2.erase(_2.begin(), _2.end());
        _1.erase(_1.begin(), _1.end());
    }
    return 0;
}

