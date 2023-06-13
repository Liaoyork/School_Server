#include <algorithm>
#include <cmath>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Puzzle {
   private:
    int size;
    string patterm;
    int up;
    int down;
    int left;
    int right;
    int rotate;

   public:
    Puzzle() {
        size = 0;
        patterm = "";
        rotate = 5;
    }
    ~Puzzle() {
        ;
    }
    Puzzle(int si) {
        size = si;
    }
    Puzzle(const Puzzle &o1) {
        size = o1.size;
        patterm = o1.patterm;
        up = o1.up;
        down = o1.down;
        left = o1.left;
        right = o1.right;
        rotate = o1.rotate;
    }
    string getpatterm() {
        return patterm;
    }
    int getsize() {
        return size;
    }
    int getRotate() {
        return rotate;
    }
    void setRotate(int n) {
        if (rotate == 5) rotate = n;
    }
    void clockwiseRotate() {
        int temp = left;
        left = down;
        down = right;
        right = up;
        up = temp;
    }
    void setpatterm(string t) {
        patterm = t;
    }
    int getUp() {
        return up;
    }
    int getDown() {
        return down;
    }
    int getRight() {
        return right;
    }
    int getLeft() {
        return left;
    }
    void setDirection(int *a) {
        left = a[0];
        up = a[1];
        right = a[2];
        down = a[3];
    }

    bool operator==(Puzzle &o1) {
        if (left != o1.left) return false;
        if (right != o1.right) return false;
        if (up != o1.up) return false;
        if (down != o1.down) return false;
        if (patterm != o1.patterm) return false;
        if (rotate != o1.rotate) return false;
        return true;
    }
};

int main(int argc, char *argv[]) {
    ifstream in(argv[1]);
    ofstream out(argv[2]);
    int size = 0;
    in >> size;
    string ss, temp = "";
    Puzzle *p;
    vector<Puzzle> puzzle;
    int count = 1;
    while (getline(in, ss)) {
        if (ss == "") continue;
        p = new Puzzle;
        for (int i = 0; i < (int)ss.length(); i++) {
            int *a = new int[4];
            for (int j = 0; j < 4; j++) {
                while (isdigit(ss[i]) || ss[i] == '-') {
                    temp += ss[i];
                    i++;
                }
                a[j] = stoi(temp);
                temp = "";
                i++;
            }
            p->setDirection(a);
            if (ss[i] == '"') {
                temp = ss.substr(i + 1, size * size);
                p->setpatterm(temp);
                temp = "";
                break;
            }
            delete[] a;
        }
        puzzle.push_back(*p);
        delete p;
    }

    vector<Puzzle> ans;

    // find left-up
    int m = 0;
    int mt = 0;
    int w = 0;
    while (1) {
        bool find = true;
        int rotate = 0;
        for (int i = 0; i < (int)puzzle.size(); i++) {
        co:
            if (puzzle[m].getLeft() + puzzle[i].getRight() == 0) {
                puzzle[i].setRotate(rotate);
                rotate = 0;
                m = i;
                mt = i;
                i = 0;
                if (puzzle[m].getLeft() == 0) {
                    find = true;
                    break;
                }
            } else {
                if (rotate > 3) {
                    rotate = 0;
                } else {
                    puzzle[i].clockwiseRotate();
                    rotate++;
                    goto co;
                }
            }
        }
        if (find) break;
    }
    while (1) {
        bool find = true;
        int rotate = 0;
        for (int i = 0; i < (int)puzzle.size(); i++) {
        compp:
            if (puzzle[m].getUp() + puzzle[i].getDown() == 0) {
                puzzle[i].setRotate(rotate);
                rotate = 0;
                m = i;
                mt = i;
                i = 0;
                if (puzzle[m].getLeft() == 0 && puzzle[m].getUp() == 0) {
                    find = true;
                    break;
                }
            } else {
                if (rotate > 3) {
                    rotate = 0;
                } else {
                    puzzle[i].clockwiseRotate();
                    rotate++;
                    goto compp;
                }
            }
        }
        if (find) break;
    }

    Puzzle ptr = puzzle[m];
    ans.push_back(ptr);

    // find 1st-row
    while (1) {
        bool find = false;
        int rotate = 0;
        for (int i = 0; i < (int)puzzle.size(); i++) {
        compare:
            if (puzzle[m].getRight() + puzzle[i].getLeft() == 0) {
                puzzle[i].setRotate(rotate);
                Puzzle ptr = puzzle[i];
                rotate = 0;
                ans.push_back(ptr);
                m = i;
                i = 0;
                if (puzzle[m].getRight() == 0 && puzzle[m].getUp() == 0) {
                    find = true;
                    break;
                }
            } else {
                if (rotate > 3) {
                    rotate = 0;
                } else {
                    puzzle[i].clockwiseRotate();
                    rotate++;
                    goto compare;
                }
            }
        }
        if (find) break;
    }
    int row = (int)ans.size();
    int col = (int)puzzle.size() / row;

    vector<Puzzle> ans_new[col];
    for (int i = 0; i < (int)ans.size(); i++) {
        ans_new[0].push_back(ans[i]);
    }

    // find 1st-column
    m = mt;
    for (int j = 1; j < col; j++) {
        while (1) {
            bool find = false;
            int rotate = 0;
            for (int i = 0; i < (int)puzzle.size(); i++) {
            comp:
                if (puzzle[m].getDown() + puzzle[i].getUp() == 0) {
                    puzzle[i].setRotate(rotate);
                    Puzzle ptr = puzzle[i];
                    rotate = 0;
                    ans_new[j].push_back(ptr);
                    m = i;
                    i = 0;
                    if (puzzle[m].getLeft() == 0) {
                        find = true;
                        break;
                    }
                } else {
                    if (rotate > 3) {
                        rotate = 0;
                    } else {
                        puzzle[i].clockwiseRotate();
                        rotate++;
                        goto comp;
                    }
                }
            }
            if (find) break;
        }
    }

    // find the remaining row by 1st-column
    for (int j = 1; j < col; j++) {
        while (1) {
            bool find = false;
            int rotate = 0;
            for (int i = 0; i < (int)puzzle.size(); i++) {
                if (ans_new[j][0] == puzzle[i]) {
                    m = i;
                    break;
                }
            }
            for (int i = 0; i < (int)puzzle.size(); i++) {
            com:
                if (puzzle[m].getRight() + puzzle[i].getLeft() == 0) {
                    puzzle[i].setRotate(rotate);
                    Puzzle ptr = puzzle[i];
                    rotate = 0;
                    ans_new[j].push_back(ptr);
                    m = i;
                    i = -1;
                    if (puzzle[m].getRight() == 0 && puzzle[m].getDown() != 0) {
                        find = true;
                        break;
                    } else if (puzzle[m].getRight() == 0 && puzzle[m].getDown() == 0 && j == col - 1) {
                        find = true;
                        break;
                    }
                } else {
                    if (rotate > 3) {
                        rotate = 0;
                    } else {
                        puzzle[i].clockwiseRotate();
                        rotate++;
                        goto com;
                    }
                }
            }
            if (find) break;
        }
    }


    // output
    for (int i = 0; i < col; i++) {
        for (int k = 0; k < size; k++) {
            for (int j = 0; j < row; j++) {
                for (int l = 0; l < size; l++) {
                    ss = ans_new[i][j].getpatterm();
                    if (ans_new[i][j].getRotate() == 0) {
                        out << ss[k * size + l];
                    }
                    if (ans_new[i][j].getRotate() == 1) {
                        out << ss[(size - l - 1) * size + k];
                    }
                    if (ans_new[i][j].getRotate() == 2) {
                        out << ss[(size - k - 1) * size + size - 1 - l];
                    }
                    if (ans_new[i][j].getRotate() == 3) {
                        out << ss[(size - k - 1) + l * size];
                    }
                }
            }
            out << endl;
        }
    }
    return 0;
}

