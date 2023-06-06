#include "Spotify.h"

#include <algorithm>
#include <fstream>
#include <iomanip>
#include <iostream>

using namespace std;
bool sortSong(const Song *a, const Song *b) {
    return a->getLen() < b->getLen();
}
Spotify::Spotify(string file) {
    curr_user = NULL;
    string s1, s2, s3;
    ifstream in(file);
    while (in >> s1) {
        in >> s2;
        in >> s3;
        Song *p = new Song(s1, s2, s3);
        songs.push_back(p);
    }
    sort(songs.begin(), songs.end(), sortSong);
    for (int i = 0; i < (int)songs.size(); i++) {
        for (int j = i + 1; j < (int)songs.size(); j++) {
            if (songs[i]->song_len == songs[j]->song_len && songs[i]->name > songs[j]->name) {
                swap(songs[i], songs[j]);
            }
        }
    }
}
Spotify::~Spotify() {
    for (int i = 0; i < (int)users.size(); i++){
        delete users[i];
    }

    for (int i = 0; i < (int)songs.size(); i++){
        delete songs[i];
    }
}
void Spotify::addSong() {
    string name, artist, len;
    cout << "ADD SONG" << endl;
    cout << "Song Name: ";
    cin >> name;
    cout << "Artist: ";
    cin >> artist;
    cout << "Song Length: ";
    cin >> len;
    Song *p = new Song(name, artist, len);
    songs.push_back(p);
    sort(songs.begin(), songs.end(), sortSong);
    for (int i = 0; i < (int)songs.size(); i++) {
        for (int j = i + 1; j < (int)songs.size(); j++) {
            if (songs[i]->song_len == songs[j]->song_len && songs[i]->name > songs[j]->name) {
                swap(songs[i], songs[j]);
            }
        }
    }
}

void Spotify::createUser() {
    string name, passwd;
    cout << "CREATE USER" << endl;
    cout << "User Name: ";
    cin >> name;
    cout << "User Passwd: ";
    cin >> passwd;
    for (int i = 0; i < (int)users.size(); i++) {
        if (users[i]->name == name) {
            cout << "User already exists." << endl;
            return;
        }
    }
    User *p = new User(name, passwd, songs);
    users.push_back(p);
}
void Spotify::logIN() {
    bool find = false;
    int index = 0;
    string name, passwd;
    cout << "LOG IN" << endl;
    cout << "User Name: ";
    cin >> name;
    cout << "User Passwd: ";
    cin >> passwd;
    if ((int)users.size() == 0){
        cout << "The User doesn't exist" << endl;
        return;
    }
    for (int i = 0; i < (int)users.size(); i++) {
        if (users[i]->name == name) {
            index = i;
            find = true;
            break;
        }
        if (!find && i == (int)users.size() - 1) {
            cout << "The User doesn't exist" << endl;
            return;
        }
    }
    find = false;
    if (users[index]->passwd == passwd) {
        find = true;
        curr_user = users[index];
        cout << "Log In Successfully" << endl;
        cout << "Welcome, " << curr_user->name << endl;
    }
    if (!find) {
        cout << "The Password is wrong" << endl;
        return;
    }
}
void Spotify::logOUT() {
    cout << "LOG OUT" << endl;
    cout << "Are You Sure to Log Out? (y/n) ";
}
void Spotify::printSongList() {
    cout << "12345678901234567890123456789012345" << endl;  // so werid
    for (int i = 0; i < (int)songs.size(); i++) {
        cout << left << setw(15) << songs[i]->name;
        cout << left << setw(15) << songs[i]->artist;
        cout << left << songs[i]->song_len << endl;
    }
}
void Spotify::printUserList() {
    for (int i = 0; i < (int)users.size(); i++) {
        cout << users[i]->name << "\t";
    }
    cout << endl;
}

void Spotify::controlManual() {
    while (1) {
        while (1) {
        menu:
            scene1();
            char c;
            cout << ">> ";
            cin >> c;
            if (c == 'i' || c == 'I') {
                logIN();
                if (curr_user != NULL) {
                    goto UserPage;
                }
            } else if (c == 'q' || c == 'Q') {
                return;
            } else if (c == 'a' || c == 'A') {
                addSong();
            } else if (c == 'c' || c == 'C') {
                createUser();
            } else if (c == 's' || c == 'S') {
                printSongList();
            } else if (c == 'u' || c == 'U') {
                printUserList();
            }
        }
        while (1) {
        UserPage:
            char c;
            scene2();
            curr_user->show_list();
            cout << ">> ";
            cin >> c;
            if (c == 'c' || c == 'C') {
                curr_user->choose_list();
                if (curr_user->curr_list != NULL) {
                    goto MyPlaylist;
                }
            } else if (c == 'a' || c == 'A') {
                curr_user->add_list();
            } else if (c == 'o' || c == 'O') {
                logOUT();
                char con;
                cin >> con;
                if (con == 'y' || con == 'Y') {
                    cout << "Log Out Successfully" << endl;
                    goto menu;
                } else if (con == 'n' || con == 'N') {
                    ;
                }
            }
        }
        while (1) {
        MyPlaylist:
            char c;
            scene3();
            cout << "|| SONG IN LIST ||" << endl;
            curr_user->curr_list->show_song();
            cout << ">> ";
            cin >> c;
            if (c == 'p' || c == 'P') {
                if ((int)curr_user->curr_list->song_in_list.size() == 0) {
                    cout << "The list is empty." << endl;
                }
                if ((int)curr_user->curr_list->song_in_list.size() != 0) goto Music;
            } else if (c == 'a' || c == 'A') {
                curr_user->curr_list->add_song();
            } else if (c == 'r' || c == 'R') {
                curr_user->curr_list->remove_song();
            } else if (c == 'b' || c == 'B') {
                goto UserPage;
            }
        }
        while (1) {
        Music:
            scene4();
            curr_user->curr_list->play_song();
            char c;
            cout << ">> ";
            cin >> c;
            if (c == 'n' || c == 'N') {
                curr_user->curr_list->next_song();
            } else if (c == 'p' || c == 'P') {
                curr_user->curr_list->prev_song();
            } else if (c == 'b' || c == 'B') {
                goto MyPlaylist;
            }
        }
    }
}


