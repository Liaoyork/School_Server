#include "User.h"

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

#include "Playlist.h"
#include "Song.h"
using namespace std;

bool sortList(Playlist* o1, Playlist* o2){
    return o1->name < o2->name;
}

void User::show_list() {
    cout << "|| PLAY LIST: ";
    sort(all_list.begin(), all_list.end(), sortList);
    for (int i = 0; i < (int)all_list.size(); i++) {
        cout << all_list[i]->name << " ";
    }
    cout << "||" << endl;
}
void User::choose_list() {
    cout << "CHOOSE LIST" << endl;
    string ss;
    cout << "list name: ";
    cin >> ss;
    bool find = false;
    for (int i = 0; i < (int)all_list.size(); i++) {
        if (all_list[i]->name == ss) {
            curr_list = all_list[i];
            find = true;
            break;
        }
    }
    if (!find) cout << "List doesn't exist" << endl;
}
void User::add_list() {
    string ss;
    cout << "ADD LIST" << endl;
    cout << "List Name: ";
    cin >> ss;
    Playlist *p = new Playlist(ss, songs);
    all_list.push_back(p);
}

User::User(string name, string passwd, vector<const Song *> &songs) : songs(songs) {
    this->name = name;
    this->passwd = passwd;
    curr_list = NULL;
}
User::~User() {
    for (int i = 0 ; i < (int)all_list.size(); i++){
        delete all_list[i];
    }
    /*
    for (int i = 0; i < (int)songs.size(); i++){
        delete songs[i];
    }
    */
}
