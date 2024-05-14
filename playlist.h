#ifndef PLAYLIST_H
#define PLAYLIST_H
#include <string>

//class for songs
class Song {
    public:
        std::string get_title();
        std::string get_artist();
        void set_title(std::string songTitle);
        void set_artist(std::string songArtist);
    private:
        std::string title;
        std::string artist;
};

//class for the playlist
class playlistClass {
    public:
        void get_song(int index);
        void add_song(std::string songTitle, std::string songArtist, int index);
        void remove_song(int index);
        playlistClass(int size);
        ~playlistClass();
    private:
        Song* songs;
        int song_count;
        int size;
};
#endif
