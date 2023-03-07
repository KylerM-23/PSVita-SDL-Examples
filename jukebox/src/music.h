#ifndef _MUSIC_H_INCLUDED
#define _MUSIC_H_INCLUDED

#include <string>
#include <vector>

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_mixer.h>

//Class Declarations
class Song;     //Object for a single song/audio file
class Album;    //Object for a collection of songs

class Song{
public:
    Song(); //default constructor
    
    //Constructor for non-album usage
    Song(
        std::string name,
        std::string artist,
        std::string album,
        int         track,
        std::string m_dir,
        std::string song_f_name,
        std::string song_f_type,
        std::string a_dir,
        std::string art_f_name,
        std::string art_f_type
    );

    //Constructor for album usage
    Song(
        std::string name,
        std::string artist,
        std::string album_n,
        int         track,
        std::string m_dir,
        std::string song_f_name,
        std::string song_f_type,
        Album* album_ptr
    );

    ~Song();    //Not Used

    //Functions to return Song & Art Data
    std::string get_song_file_path();
    std::string get_art_file_path();

    //Song Info
    std::string song_name;
    std::string artist_name;

    //Album Info
    std::string album_name;
    int track_num;
    Album* album; //pointer to album if used.

    //File Info
    std::string music_dir;
    std::string song_file_name;
    std::string song_file_type;

    //Art Info
    std::string art_dir;
    std::string art_file_name;
    std::string art_file_type;
};

class Album{
public:
    Album(std::string name, std::string a_dir, std::string art_f_name, std::string art_f_type); //create album
    ~Album();   //Free songs

    //Add a song, returns true if successful
    bool add_song(
        std::string name,
        std::string artist,
        std::string m_dir,
        std::string song_f_name,
        std::string song_f_type
    );

    //Functions to access music, art, and song information
    Mix_Music* load_song(int track_num);
    std::string get_song_name(int track_num);
    std::string get_artist(int track_num);
    std::string get_art_file_path();
    SDL_Surface* get_art();
    void free_art();

    //Album Info
    std::string album_name;

    //Track Info
    std::vector<Song*> tracklist;
    int track_size;

    //Art
    SDL_Surface* album_art = NULL;

    //File Info
    std::string art_dir;
    std::string art_file_name;
    std::string art_file_type;
   
};
#endif  // _MUSIC_H_INCLUDED