#include "music.h"

#include <string>
#include <vector>

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "SDL_helper.h"


Song::Song(std::string name,
        std::string artist,
        std::string album,
        int         track,
        std::string m_dir,
        std::string song_f_name,
        std::string song_f_type,
        std::string a_dir,
        std::string art_f_name,
        std::string art_f_type
        ) 
{
    //Song Info
    song_name = name;
    artist_name = artist;

    //Album Info
    album_name = album;
    track_num = track;

    //File Info
    music_dir =  m_dir;
    song_file_name = song_f_name;
    song_file_type = song_f_type;

    art_dir = a_dir;
    art_file_name = art_f_name;
    art_file_type = art_f_type;
}

Song::Song(std::string name,
        std::string artist,
        std::string album_n,
        int         track,
        std::string m_dir,
        std::string song_f_name,
        std::string song_f_type,
        Album* album_ptr
        ) 
{
    //Song Info
    song_name = name;
    artist_name = artist;

    //Album Info
    album_name = album_n;
    track_num = track;

    //File Info
    music_dir =  m_dir;
    song_file_name = song_f_name;
    song_file_type = song_f_type;

    album = album_ptr;
}

Song::~Song() {}     // Not Used

std::string Song::get_song_file_path()  //Build and return music file path
{
    std::string fp = music_dir+song_file_name+song_file_type;
    return fp;
}

std::string Song::get_art_file_path() //Build and return art file path
{
    std::string fp = art_dir + art_file_name + art_file_type;
    return fp;
}

Album::Album(std::string name, std::string a_dir, std::string art_f_name, std::string art_f_type) 
{
    //Album Info
    album_name = name;

    art_dir = a_dir;
    art_file_name = art_f_name;
    art_file_type = art_f_type;
}

Album::~Album() 
{
    free_art();
    for (int i =0; i < tracklist.size(); i++)
        delete tracklist[i];
}//free up songs and art allocated

bool Album::add_song(
    std::string name,
    std::string artist,
    std::string m_dir,
    std::string song_f_name,
    std::string song_f_type
    )
{
    //add song to tracklist, add pointer to album
    tracklist.push_back(new Song(name, artist, album_name, tracklist.size()+1, m_dir, song_f_name, song_f_type, this)); 
    return true;
}

Mix_Music* Album::load_song(int track_num)
{
    if (track_num < 0 || track_num >= tracklist.size())
        return NULL; //out of range, return null
    return loadMusic(tracklist[track_num]->get_song_file_path()); //return song file path
}

SDL_Surface* Album::get_art()
{
    if (album_art == NULL)                          //if art is not made
        album_art = loadImage(get_art_file_path()); //load art
    return album_art;
}

void Album::free_art()
{
    if (album_art != NULL)              //if art is made
        SDL_FreeSurface(album_art);     //free art
}

std::string Album::get_art_file_path()  //build art file path
{
    std::string fp = art_dir + art_file_name + art_file_type;
    return fp;
}

std::string Album::get_song_name(int track_num)
{
    if (track_num < 0 || track_num >= tracklist.size())
        return NULL; //out of range, return null
    return tracklist[track_num]->song_name; //return song name for specified track
}

std::string Album::get_artist(int track_num)
{
    if (track_num < 0 || track_num >= tracklist.size())
        return NULL; //out of range, return null
    return tracklist[track_num]->artist_name; //return artist name
}