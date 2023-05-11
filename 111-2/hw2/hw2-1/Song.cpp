#include "Song.h"

#include <iostream>
#include <string>

using namespace std;
Song::Song(string name, string artist, string song_len) {
    this->name = name;
    this->artist = artist;
    this->song_len = song_len;
}
Song::~Song() {
    ;
}

string Song::getLen() const {
    return song_len;
}
string Song::getArt() const {
    return artist;
}
string Song::getName() const {
    return name;
}
