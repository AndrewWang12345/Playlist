#include <string>
#include "playlist.h"
//#include "playlist.cpp"
#include <iostream>

int main(int argc, char *argv[]){
    std::string command;
    std::string parameter;
    std::string list_length;

    //takes in the maximum number of songs inputted by the user
    std::cin>>list_length;
    std::cin>>list_length; //list_length number of songs max
    std::cout<<"success"<<std::endl;

    //constructs a playlistClass objects with list_length number of songs
    playlistClass my_playlist(std::stoi(list_length));
    int song_count = 0; // number of songs already in the playlist

    // infinite loop that allows the user to repeatedly input commands
    while(true){
        std::cin>>command;

        //breaks out of the loop ending the program when users inputs "done"
        if(command == "done"){
            break;
        }

        std::getline(std::cin, parameter);

        // if the user wants to insert a new song, call the add_song function in playlistClass
        // it also extracts title and artist from inputted command
        if(command=="i"){
            std::string title = parameter.substr(1, parameter.find(";")-1);
            std::string artist = parameter.substr(parameter.find(";")+1,parameter.length()-1);
            my_playlist.add_song(title, artist, song_count);
            song_count++;
            continue;
        }

        // if the user wants to play song, call the get_song function in playlistClass
        if(command=="p"){
            my_playlist.get_song(std::stoi(parameter));
        }

        // if the user wants to erase a song, call the remove_song function in playlistClass
        if(command=="e"){
            my_playlist.remove_song(std::stoi(parameter));
            song_count--;
        }
    }

    return 0;
}

