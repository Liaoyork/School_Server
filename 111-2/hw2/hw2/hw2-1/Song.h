#ifndef SONG_H
#define SONG_H
using namespace std;
// Add any Boolean Function for sorting you need
class Song {
   private:
    string name;      // title of song
    string artist;    // artist of song
    string song_len;  // length of song

   public:
    Song(string name, string artist, string song_len);
    ~Song();
    // Add any Accessor & Mutator functions, or friend class declaration you need
};

#endif