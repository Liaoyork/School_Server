#include <algorithm>
#include <fstream>
#include <iostream>
#include <map>
#include <string>
#include <vector>
using namespace std;

map<string, int> ori_num;
vector<string> ans;

bool rec(string ss, map<string, int> &dic) {
    if (dic.find(ss) != dic.end() && dic[ss] > 0) {
        dic[ss] -= 1;
        ans.push_back(ss);
        // for (auto &x : dic){
        //     string w = x.first;
        //     if ()
        // }
        return true;
    }

    int len = ss.size();

    for (int i = len - 1; i >= 1; i--) {
        string s1 = ss.substr(0, i);
        string s2 = ss.substr(i);
        if (dic.find(s1) == dic.end() || dic[s1] == 0) continue;
        dic[s1] -= 1;
        ans.push_back(s1);
        if (rec(s2, dic)) return true;
        dic[s1] += 1;
        ans.pop_back();
    }
    return false;
}
bool sortStr(string &s1, string &s2) {
    return s1 > s2;
}
int main(int argc, char *argv[]) {
    map<string, int> dictionary;
    ifstream in(argv[1]);
    string ss;
    int amo;
    while (in >> ss >> amo) {
        dictionary.insert(pair<string, int>(ss, amo));
        ori_num.insert(pair<string, int>(ss, amo));
    }
    string testcase = argv[2];
    if (rec(testcase, dictionary)) {
        cout << "True\n";
        for (auto &n : dictionary) {
            string p = n.first;
            cout << p << ": " << ori_num[p] - dictionary[p] << "(" << ori_num[p] << "->" << dictionary[p] << ")\n";
        }
        for (int i = 0; i < (int)ans.size(); i++) {
            cout << ans.at(i) << " ";
        }
        cout << endl;
    } else {
        cout << "False" << endl;
    }
}

