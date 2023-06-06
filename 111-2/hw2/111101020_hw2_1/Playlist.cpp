#include "Playlist.h"

#include <algorithm>
#include <iomanip>
#include <iostream>
#include <string>
#include <vector>

#include "Song.h"
#include "User.h"
void Playlist::show_song() {
    for (int i = 0; i < (int)song_in_list.size(); i++) {
        cout << left << setw(15) << song_in_list[i]->name;
        cout << left << setw(15) << song_in_list[i]->artist;
        cout << left << song_in_list[i]->song_len << endl;
    }
}
void Playlist::add_song() {
    bool find = false;
    cout << "ADD SONG" << endl;
    cout << "Song Name: ";
    string ss;
    cin >> ss;
    for (int i = 0; i < (int)songs.size(); i++) {
        if (songs[i]->name == ss) {
            find = true;
            song_in_list.push_back(songs[i]);
            sort(song_in_list.begin(), song_in_list.end(), sortSong);
            break;
        }
    }
    for (int i = 0; i < (int)song_in_list.size(); i++) {
        for (int j = i + 1; j < (int)song_in_list.size(); j++) {
            if (song_in_list[i]->song_len == song_in_list[j]->song_len &&
                song_in_list[i]->name > song_in_list[j]->name) {
                swap(song_in_list[i], song_in_list[j]);
            }
        }
    }
    if (!find) cout << "Doesn't find the song." << endl;
}
void Playlist::remove_song() {
    bool find = false;
    cout << "REMOVE SONG" << endl;
    cout << "Song Name: ";
    string ss;
    cin >> ss;
    for (int i = 0; i < (int)song_in_list.size(); i++) {
        if (song_in_list[i]->name == ss) {
            find = true;
            song_in_list.erase(song_in_list.begin() + i);
            break;
        }
    }
    if (!find) cout << "Doesn't find the song." << endl;
}
void Playlist::play_song() {
    cout << "//// SONG INFO ////" << endl;
    cout << "Name: " << song_in_list[curr_song_index]->name << endl;
    cout << "Artist: " << song_in_list[curr_song_index]->artist << endl;
    cout << "Length: " << song_in_list[curr_song_index]->song_len << endl;
    cout << "//// SONG INFO ////" << endl;
}
void Playlist::next_song() {
    if (curr_song_index == (int)song_in_list.size() - 1) {
        curr_song_index = 0;
        return;
    }
    curr_song_index++;
}
void Playlist::prev_song() {
    if (curr_song_index == 0) {
        curr_song_index = (int)song_in_list.size() - 1;
        return;
    }
    curr_song_index--;
}
Playlist::Playlist(string name, const vector<const Song *> &songs) : songs(songs) {
    this->name = name;
    curr_song_index = 0;
}
Playlist::~Playlist() {
    /*
    for (int i = 0 ; i < (int)song_in_list.size();i++){
        delete song_in_list[i];
    }
    */
}
