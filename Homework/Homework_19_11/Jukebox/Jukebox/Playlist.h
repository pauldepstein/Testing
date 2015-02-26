#ifndef PLAYLIST_H_INCLUDED
#define PLAYLIST_H_INCLUDED
#include <vector>
#include <algorithm>
#include "Song.h"
#include <iostream>
#include <stdexcept>

class Playlist
{
    std::vector<Song> songs;
    double playingTime;

    // assign play lengths as a simple function of the song title length.
    void assignPlaylengths()
    {
        for(int i = 0; i < songs.size(); i++)
        {
            double songTime = songs[i].getSong().size() + 0.1;
            songs[i].setPlaylength(songTime);
            playingTime += songs[i].getPlayLength();
        }

    }

public:
    Playlist(std::vector<Song> songsToPlay):playingTime(0)
    {
        for(int i = 0; i<songsToPlay.size(); i++)
            songs.push_back(songsToPlay[i]);

        assignPlaylengths();
    }

    void play()const
    {
        for(int i = 0; i<songs.size(); i++)
            songs[i].play();
    }

    void displayPlayTime() const
    {
        std::cout << "\nTotal playing time in minutes is: " << playingTime;
    }

    void rotation(unsigned i)
    {
        if(i >= songs.size())
            throw std::domain_error("Out of range song");

        std::rotate(songs.begin(), songs.begin()+i, songs.end());
    }

};


#endif // PLAYLIST_H_INCLUDED
