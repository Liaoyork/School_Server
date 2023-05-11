#include <fstream>
#include <iostream>
#include <string>

using namespace std;

struct group {
    string name;
    int little_score;
    int big_score;
};

int main(int argc, char* argv[]) {
    ifstream in;
    in.open(argv[1]);
    struct group teams[8][4];
    ofstream out;
    out.open(argv[2]);

    for (int i = 0; i < 8; i++)
        for (int j = 0; j < 4; j++) {
            in >> teams[i][j].name;
            teams[i][j].little_score = 0;
            teams[i][j].big_score = 0;
        }

    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 6; j++) {
            string team1, team2, tem;
            int score1, score2;
            int n1 = 0, n2 = 0;
            int i1 = 0, i2 = 0;
            in >> team1 >> team2;
            in >> score1;
            in >> tem;
            in >> score2;

            for (int n = 0; n < 4; n++) {
                for (int ii = 0; ii < 8; ii++) {
                    if (teams[ii][n].name == team1) {
                        n1 = n;
                        i1 = ii;
                    }

                    if (teams[ii][n].name == team2) {
                        n2 = n;
                        i2 = ii;
                    }
                }
            }

            if (score1 > score2) {
                teams[i1][n1].big_score += 3;
            } else if (score1 == score2) {
                teams[i1][n1].big_score += 1;
                teams[i2][n2].big_score += 1;
            } else {
                teams[i2][n2].big_score += 3;
            }

            teams[i1][n1].little_score += score1;
            teams[i2][n2].little_score += score2;
        }
    }

    for (int i = 0; i < 8; i++) {
        for (int k = 3; k > 0; k--) {
            for (int m = 0; m <= k - 1; m++) {
                if (teams[i][m].big_score < teams[i][m + 1].big_score) {
                    swap(teams[i][m], teams[i][m + 1]);
                } else if (teams[i][m].big_score == teams[i][m + 1].big_score) {
                    if (teams[i][m].little_score < teams[i][m + 1].little_score) {
                        swap(teams[i][m], teams[i][m + 1]);
                    }
                }
            }
        }
    }

    bool who_win[15];
    string tem_input;

    int now_num = 0;
    while (getline(in, tem_input) && now_num < 16) {
        if (tem_input == "=") break;
        if (tem_input == "") continue;
        int score[2];
        bool first = true;
        string s1 = "", s2 = "";
        bool have_PK = false;
        for (int i = 0; i < tem_input.length(); i++) {
            if (tem_input[i] == '(') {
                have_PK = true;
                break;
            }
        }

        for (int i = 0; i < tem_input.length(); i++) {
            if (have_PK) {
                if (tem_input[i] == '(') {
                    for (int k = i; k < tem_input.length(); k++) {
                        if (tem_input[k] == ')') {
                            if (first) {
                                s1 = tem_input.substr(i + 1, k - i - 1);
                                k = 0;
                                first = false;
                                break;
                            } else {
                                s2 = tem_input.substr(i + 1, k - i - 1);
                                break;
                            }
                        }
                    }
                }
            } else {
                if (isdigit(tem_input[i])) {
                    if (first)
                        s1 += tem_input[i];
                    else
                        s2 += tem_input[i];
                } else {
                    i += 5;
                    first = false;
                }
            }
        }
        score[0] = stoi(s1);
        score[1] = stoi(s2);
        if (score[0] > score[1])
            who_win[now_num] = false;
        else
            who_win[now_num] = true;
        now_num++;
    }

    int where_TED = now_num - 1;
    int drawing_result[16] = {0};
    struct group ko_teams[16];
    struct group ko_teams8[8];
    struct group ko_teams4[4];
    struct group ko_teams2[2];
    tem_input = "";

    bool first_out = true;
    while (getline(in, tem_input)) {
        if (first_out)
            first_out = false;
        else
            out << "=" << endl;

        int drawing_queue = 0;
        string tem_queue = "";
        for (int i = 0; i < tem_input.length(); i++) {
            if (isdigit(tem_input[i])) {
                tem_queue += tem_input[i];
            } else {
                drawing_result[drawing_queue] = stoi(tem_queue);
                tem_queue = "";

                drawing_queue++;
            }
            if (i == tem_input.length() - 1) {
                drawing_result[drawing_queue] = stoi(tem_queue);
                tem_queue = "";
                drawing_queue++;
            }
        }

        for (int i = 0; i < 8; i++) {
            ko_teams[drawing_result[i] - 1] = teams[i][0];
        }
        for (int i = 8; i < 16; i++) {
            ko_teams[drawing_result[i] - 1] = teams[i - 8][1];
        }

        for (int i = 0; i < 8; i++) {
            if (i > where_TED)
                out << "\tThe game is coming soon...";
            else {
                out << ko_teams[i * 2].name;
                out << " v.s. ";
                out << ko_teams[i * 2 + 1].name;
                out << "\tThe winner is ";
                out << ko_teams[i * 2 + who_win[i]].name;
                out << endl;

                ko_teams8[i] = ko_teams[i * 2 + who_win[i]];
            }
        }

        for (int i = 0; i < 4; i++) {
            if (i + 8 > where_TED)
                out << "\tThe game is coming soon...";
            else {
                out << ko_teams8[i * 2].name;
                out << " v.s. ";
                out << ko_teams8[i * 2 + 1].name;
                out << "\tThe winner is ";
                out << ko_teams8[i * 2 + who_win[i + 8]].name;
                out << endl;

                ko_teams4[i] = ko_teams8[i * 2 + who_win[i + 8]];
            }
        }

        for (int i = 0; i < 2; i++) {
            if (i + 12 > where_TED) {
                if (ko_teams4[i * 2].name == "") {
                    out << "TBD";
                } else {
                    out << ko_teams4[i * 2].name;
                }

                out << " v.s. ";

                if (ko_teams4[i * 2 + 1].name == "") {
                    cout << "TBD";
                } else {
                    out << ko_teams4[i * 2 + 1].name;
                }
                out << "\tThe game is coming soon...\n";
            } else {
                out << ko_teams4[i * 2].name;
                out << " v.s. ";
                out << ko_teams4[i * 2 + 1].name;
                out << "\tThe winner is ";
                out << ko_teams4[i * 2 + who_win[i + 12]].name;
                out << endl;

                ko_teams2[i] = ko_teams4[i * 2 + who_win[i + 12]];
            }
        }

        if (where_TED == 14) {
            out << ko_teams2[0].name;
            out << " v.s. ";
            out << ko_teams2[1].name;
            out << "\tThe game is coming soon...\n";
        } else if (where_TED > 14) {
            out << ko_teams2[0].name;
            out << " v.s. ";
            out << ko_teams2[1].name;
            out << "\tThe winner is ";
            out << ko_teams2[0].name;
        } else {
            out << "TBD";
            out << " v.s. ";
            out << "TBD";
            out << "\tThe game is coming soon...\n";
        }
    }
    return 0;
}
