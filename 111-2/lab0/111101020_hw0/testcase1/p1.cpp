#include <math.h>

#include <fstream>
#include <iostream>
#include <string>
using namespace std;
int main(int argc, char *argv[]) {
    ifstream input;
    input.open(argv[1]);
    ofstream output;
    output.open(argv[2]);
    string context[10001], word;
    int n, length = 0;
    getline(input, word);
    n = stoi(word);
    int squ[10001][5] = {0};
    while (getline(input, word)) {
        int count_num = 0;
        string num = "";
        int i;
        for (i = 0; i < word.length(); i++) {
            if (count_num == 4) break;
            if (word[i] != ' ' && i != word.length()) {
                num += word[i];
            } else {
                if (i == word.length() - 1)
                    num += word[i];
                squ[length][count_num] = stoi(num);
                num = "";
                count_num++;
            }
        }
        word = word.substr(i + 1);
        word = word.substr(0, word.length() - 1);
        context[length] = word;

        length++;
    }

    int up = squ[0][1], x = 0, y = 0, left;
    bool find;
    // 找左上拼圖
    while (up != 0) {
        find = 0;
        for (int i = 0; i < length; i++) {
            for (int j = 0; j < 4; j++) {
                if (up + squ[i][j] == 0) {
                    find = 1;
                    y = (j + 2) % 4;
                    up = squ[i][(j + 2) % 4];
                    break;
                }
            }
            if (find == 1) {
                x = i;
                break;
            }
        }
    }
    left = squ[x][(y + 3) % 4];
    while (left != 0) {
        find = 0;
        for (int i = 0; i < length; i++) {
            for (int j = 0; j < 4; j++) {
                if (left + squ[i][j] == 0) {
                    find = 1;
                    y = (j + 2) % 4;
                    left = squ[i][(j + 2) % 4];
                    break;
                }
            }
            if (find == 1) {
                x = i;
                break;
            }
        }
    }

    int map[200][200], right, down;
    for (int i = 0; i < 200; i++)
        for (int j = 0; j < 200; j++)
            map[i][j] = -1;
    map[0][0] = x;
    right = squ[x][(y + 2) % 4];
    down = squ[x][(y + 3) % 4];
    int curr_y = y;

    int weight = length, height = length;
    int tem1 = 0, tem2 = 0;
    bool w_find = false;
    for (int k = 0; k < height; k++) {
        if (k != 0) {
            find = 0;
            for (int i = 0; i < length; i++) {
                for (int j = 0; j < 4; j++) {
                    if (down + squ[i][j] == 0) {
                        find = 1;
                        y = (j + 3) % 4;
                        down = squ[i][(j + 2) % 4];
                        right = squ[i][(j + 1) % 4];
                        squ[i][4] = y;

                        break;
                    }
                }
                if (find == 1) {
                    x = i;
                    if (down == 0) {
                        tem1 = k + 1;
                    }
                    break;
                }
            }
            map[k][0] = x;
        }

        find = 0;

        for (int j = 1; j < weight; j++) {
            find = 0;
            for (int i = 0; i < length; i++) {
                for (int j = 0; j < 4; j++) {
                    if (right + squ[i][j] == 0) {
                        find = 1;
                        y = (j) % 4;
                        right = squ[i][(j + 2) % 4];
                        squ[i][4] = y;

                        break;
                    }
                }
                if (find == 1) {
                    x = i;
                    tem2++;
                    if (right == 0 && !w_find) {
                        weight = tem2 + 1;
                        height = length / weight;
                        w_find = true;
                    }
                    break;
                }
            }
            map[k][j] = x;
        }
    }

    height = tem1;
    weight = length / height;

    for (int i = 0; i < height; i++) {  // 大的

        for (int j = 0; j < n; j++) {  // 小的

            for (int q = 0; q < weight; q++) {
                for (int p = 0; p < n; p++) {
                    string a;
                    a = context[map[i][q]];

                    if (squ[map[i][q]][4] == 0) {
                        output << a[j * n + p];
                    }
                    if (squ[map[i][q]][4] == 1) {
                        output << a[(n - j - 1) + p * n];
                    }
                    if (squ[map[i][q]][4] == 2) {
                        output << a[(n - j - 1) * n + n - 1 - p];
                    }
                    if (squ[map[i][q]][4] == 3) {
                        output << a[(n - p - 1) * n + j];
                    }
                }
            }
            output << endl;
        }
    }
    return 0;
}

