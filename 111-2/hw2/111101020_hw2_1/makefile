hw2-1:Spotify.o User.o Song.o Playlist.o main.o
	g++ Spotify.o User.o Playlist.o Song.o main.o -o hw2_1
	rm *.o
Spotify.o:Spotify.h Playlist.h User.h Song.h Spotify.cpp
	g++ -c Spotify.cpp
User.o:Spotify.h Playlist.h User.h Song.h User.cpp
	g++ -c User.cpp
Playlist.o:Spotify.h Playlist.h User.h Song.h Playlist.cpp
	g++ -c Playlist.cpp
Song.o:Spotify.h Playlist.h User.h Song.h Song.cpp
	g++ -c Song.cpp
main.o:Spotify.h Playlist.h User.h Song.h main.cpp
	g++ -c main.cpp
clean:
	rm -rf *.o hw2-1

