#include <string>
#include <vector>

#include "Playlist.h"
#ifndef USER_H
#define USER_H
using namespace std;
// Add any Boolean Function for sorting you need
bool sortSong(const Song *a, const Song *b);
class User {
   private:
    friend class Spotify;
    string name;                       // name of user
    string passwd;                     // password of user
    Playlist *curr_list;               // points to  current playlist, Null at first
    vector<Playlist *> all_list;       // store all playlists of the user
    const vector<const Song *> songs;  // store the songs provided in streaming service (can't modified)

    void show_list();    // show all playlists of the user
    void choose_list();  // choose a playlist
    void add_list();     // add a playlist

   public:
    User(string name, string passwd, vector<const Song *> &songs);
    ~User();
    // Add any Accessor & Mutator functions, or friend class declaration you need
};

#endif
