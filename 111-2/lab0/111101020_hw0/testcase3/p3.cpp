#include <limits.h>
#include <math.h>

#include <fstream>
#include <iostream>
#include <vector>
using namespace std;

int main(int argc, char* argv[]) {
    ifstream in;
    in.open(argv[1]);
    string ss, input;
    int block[10000];
    int num = 0;

    while (getline(in, input)) {
        for (int i = 0; i < input.length(); i++) {
            while (isdigit(input[i])) {
                ss += input[i];
                i++;
            }
            if (ss == "")
                continue;
            else {
                block[num] = stoi(ss);
                num++;
                ss = "";
            }
        }
    }

    int** dis = new int*[num];
    for (int i = 0; i < num; i++) {
        dis[i] = new int[num];
        for (int j = 0; j < num; j++) {
            dis[i][j] = INT_MAX;
        }
    }

    int big_layer, small_layer, num_in_a_layer,
        target_num_in_layers, now_pos = 1;

    int ans = 0;
    int now_num = 0;
    big_layer = 1;
    small_layer = 1;

    while (now_num <= num) {
        target_num_in_layers = 0;
        num_in_a_layer = pow(2, big_layer - 1) * 6;

        // find the answer
        if (now_num + num_in_a_layer >= num) {
            if (block[now_num]) ans = now_num;
        }

        // cal target_num_in_layers
        for (int i = 1; i <= big_layer; i++) {
            if (i != big_layer) {
                target_num_in_layers += 6 * pow(2, i - 1) * i;
            } else {
                target_num_in_layers += small_layer * 6 * pow(2, i - 1);
            }
        }

        // first layer
        if (!block[now_num]) {
            now_num = now_num;
        } else if (small_layer == 1 && big_layer == 1) {
            // right
            if (block[(now_num + 7) % 6]) {
                dis[now_num][(now_num + 7) % 6] = block[(now_num + 7) % 6];
            }
            // left
            if (block[(now_num + 5) % 6]) {
                dis[now_num][(now_num + 5) % 6] = block[(now_num + 5) % 6];
            }
            // up
            if (block[(2 * now_num + 6)]) {
                dis[now_num][2 * now_num + 6] = block[2 * now_num + 6];
            }
            if (block[(2 * now_num + 7)]) {
                dis[now_num][2 * now_num + 7] = block[2 * now_num + 7];
            }
        } else {
            // right
            // maybe wrong

            if (now_pos == num_in_a_layer) {
                if (block[now_num - num_in_a_layer + 1]) {
                    dis[now_num][now_num - num_in_a_layer + 1] = block[now_num - num_in_a_layer + 1];
                }
            } else {
                if (block[now_num + 1]) {
                    dis[now_num][now_num + 1] = block[now_num + 1];
                }
            }
            // left
            if (now_pos == 1) {
                if (block[now_num + num_in_a_layer - 1]) {
                    dis[now_num][now_num + num_in_a_layer - 1] = block[now_num + num_in_a_layer - 1];
                }
            } else {
                if (block[now_num - 1]) {
                    dis[now_num][now_num - 1] = block[now_num - 1];
                }
            }
            // up

            if (small_layer == big_layer) {
                if (now_num + num_in_a_layer < num) {
                    if (block[(now_num + num_in_a_layer + now_pos)]) {
                        dis[now_num][now_num + num_in_a_layer + now_pos] = block[now_num + num_in_a_layer + now_pos];
                    }
                    if (block[(now_num + num_in_a_layer + now_pos - 1)]) {
                        dis[now_num][now_num + num_in_a_layer - 1 + now_pos] = block[now_num + num_in_a_layer - 1 + now_pos];
                    }
                }

                // help next layer to connect down layer
                //&&now_num+num_in_a_layer<num

                if (block[now_num] && now_num + num_in_a_layer + now_pos < num) {
                    if (block[now_num + num_in_a_layer + now_pos - 1]) {
                        dis[now_num + num_in_a_layer + now_pos - 1][now_num] = block[now_num];
                    }
                    if (block[now_num + num_in_a_layer + now_pos]) {
                        dis[now_num + num_in_a_layer + now_pos][now_num] = block[now_num];
                    }
                }

            } else {
                if (block[(now_num + num_in_a_layer)]) {
                    dis[now_num][now_num + num_in_a_layer] = block[now_num + num_in_a_layer];
                }
            }

            // down
            if (small_layer != 1) {
                if (block[now_num - num_in_a_layer]) {
                    dis[now_num][now_num - num_in_a_layer] = block[now_num - num_in_a_layer];
                }
            }
        }

        if (now_pos == num_in_a_layer) {
            if (now_num == target_num_in_layers - 1) {
                now_pos = 0;
                small_layer++;
            }
            if (small_layer > big_layer) {
                big_layer++;
                small_layer = 1;
                now_pos = 0;
            }
        }
        now_num++;
        now_pos++;
    }

    int pre[num];
    int ori_dis[num];

    for (int i = 0; i < num; i++) {
        if (i <= 6) {
            if (block[i]) {
                ori_dis[i] = block[i];
            } else {
                ori_dis[i] = INT_MAX;
            }
        }
    }

    int yeah = 0;

    for (int k = 0; k < 6; k++) {
        bool best[num];
        for (int i = 0; i < num; i++) {
            best[i] = false;
        }
        if (block[k]) {
            best[k] = true;
        } else
            continue;

        for (int i = k + 1; i < num; i++) {
            ori_dis[i] = dis[k][i];
            if (ori_dis[i] != INT_MAX)
                pre[i] = k;
            else
                pre[i] = -1;
        }

        for (int i = 0; i < num * num; i++) {
            int not_the_best = 0, num_not_the_best = INT_MAX;
            for (int j = k; j < num; j++) {
                if (!best[j]) {
                    if (num_not_the_best > ori_dis[j]) {
                        not_the_best = j;
                        num_not_the_best = ori_dis[j];
                    }
                }
            }
            best[not_the_best] = true;
            for (int j = k; j < num; j++) {
                if (!best[j]) {
                    if (dis[not_the_best][j] != INT_MAX) {
                        if (ori_dis[not_the_best] + dis[not_the_best][j] < ori_dis[j]) {
                            ori_dis[j] = ori_dis[not_the_best] + dis[not_the_best][j];
                            pre[j] = not_the_best;
                        }
                    }
                }
            }
        }
        if (ori_dis[ans] != INT_MAX) {
            int cur = ans;
            yeah = 1;
            vector<int> path;
            path.push_back(ans);
            while (cur != 1) {
                path.push_back(pre[cur]);
                cur = pre[cur];
            }
            cout << k;
            for (long i = path.size() - 2; i >= 0; i--) {
                cout << " -> " << path[i];
            }

            break;
        }
    }

    if (yeah == 0) cout << "fail";

    // cout << ori_dis[ans];

    return 0;
}
