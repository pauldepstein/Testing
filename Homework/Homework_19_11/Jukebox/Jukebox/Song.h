#ifndef SONG_H_INCLUDED
#define SONG_H_INCLUDED
#include <string>
#include <iostream>
#include "stringHandling.h"

class Song
{
    // Time in minutes that song plays for.
    double playLength;

    int minutes; // number of minutes
    int seconds; // number of seconds.

    std::string songTitle; // title of song.

    public:
    Song(std::string songName): songTitle(songName)
    {

    }

    void setPlaylength (double songTime)
    {
        playLength = songTime;
        minutes = int(playLength);
        seconds = int( (playLength - minutes) * 60);
    }

    double getPlayLength() const {return playLength;}
    void play() const {std::cout<< "\n" + songTitle + " will play for " + intToString(minutes) << " minutes\n" <<
                       "and " << intToString( seconds ) << " seconds.";}

    std::string getSong() const {return songTitle;}

};



#endif // SONG_H_INCLUDED
