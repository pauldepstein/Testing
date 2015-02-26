#include <iostream>
#include "Playlist.h"
#include "Song.h"
#include <string>
#include <vector>

using namespace std;

int main()
{
    vector<string> songTitles;
    vector<Song> songs;

    songTitles.push_back("first song today");
    songTitles.push_back("second song today");
    songTitles.push_back("Third song");

    for(int i = 0; i < songTitles.size(); i++)
        songs.push_back(Song(songTitles[i]));

    Playlist playlist = Playlist(songs);


    playlist.rotation(2);
    playlist.play();
    playlist.displayPlayTime();





    return 0;
}
