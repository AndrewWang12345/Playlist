#include "playlist.h"
#include <iostream>
using namespace std;

// public function in Song class that return the song title
std::string Song::get_title(){
    return title;
}

// public function in Song class that return the song artist
std::string Song::get_artist(){
    return artist;
}

// public function in Song class that sets the song title
void Song::set_title(std::string songTitle){
    title = songTitle;
}

// public function in Song class that sets the song artist
void Song::set_artist(std::string songArtist){
    artist = songArtist;
}

//initializes the playlistClass object by setting Song array size to the desired size inputted by user, the size variable to size1,
// and song_count currently in the playlist to 0
playlistClass::playlistClass(int size1){
    songs = new Song[size1];
    size = size1;
    song_count=0;
}

//destructor, not sure if needed
playlistClass::~playlistClass(){
    delete[] songs;
}

//plays the song at index
void playlistClass::get_song(int index){
    //if the index is less than songs currently in playlist, play song at said index
    if(index < song_count){
        std::cout<<"played "+std::to_string(index)+" "+songs[index].get_title()+";"+songs[index].get_artist()<<std::endl;
    } else {//if the index is greater than songs currently in playlist, tell user that song cannot be played
        std::cout<<"can not play "+std::to_string(index)<<std::endl;
    }
    
}

//function to add a song to playlist at index(always set to the end)
void playlistClass::add_song(std::string songTitle, std::string songArtist, int index){
    if(songTitle == "My Heart Will Go On"){// checks if song is "My Heart Will Go On". If it is, don't add it
        std::cout<<"can not insert "+songTitle+";"+songArtist<<std::endl;
        return;
    } else if(songTitle == "Baby" && songArtist == "Justin Bieber"){// checks if song is "Baby" by Justin Bieber, if it is, don't add it
        std::cout<<"can not insert "+songTitle+";"+songArtist<<std::endl;
        return;
    } else if(index >= size){ //if the list is full, don't add it
        std::cout<<"can not insert "+songTitle+";"+songArtist<<std::endl;
        return;
    } else { //checks if the song is already in the list, if it is, don't add it
        for(int i = 0; i < index; i++){
            if(songs[i].get_artist() == songArtist && songs[i].get_title() == songTitle){
                std::cout<<"can not insert "+songTitle+";"+songArtist<<std::endl;
                return;
            }
        }
    }
    
    //if the song passes all the tests above, it is added to the playlist
    songs[index].set_artist(songArtist);
    songs[index].set_title(songTitle);
    song_count++;
    std::cout<<"success"<<std::endl;
}

//function to remove song at index
void playlistClass::remove_song(int index){
    if(index >= song_count){//if the index is higher than the number of songs in the list, return that you can't remove the song
        std::cout<<"can not erase "+std::to_string(index)<<std::endl;
    } else {
        for(int i = index; i < song_count-1; i++){//otherwise, shift all the songs after it up by one
            songs[i] = songs[i+1];
        }
        std::cout<<"success"<<std::endl;
        song_count--;//also decrease the song count
    }
}
        
        