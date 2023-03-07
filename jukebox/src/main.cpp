#include <psp2/kernel/processmgr.h>
#include <psp2/ctrl.h>

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_mixer.h>
#include <SDL2/SDL_ttf.h>

#include <string>
#include <vector>

#include "debugScreen.h"
#include "music.h"
#include "SDL_helper.h"

#define FONT_PATH "app0:/vag_rounded.ttf"
#define printf psvDebugScreenPrintf

//SDL Pointers
SDL_Window *window = NULL;
SDL_Surface *screenSurface = NULL;
Mix_Music *music = NULL;
const int selection_limit = 16;
const int text_movement = 30;

void close() //release resources
{
  SDL_FreeSurface(screenSurface); screenSurface = NULL;
  SDL_DestroyWindow(window); window = NULL;
  Mix_FreeMusic(music);
  Mix_CloseAudio();
  SDL_Quit();
}

bool screenSetup() //setup screen, return success/fail
{
  //create window, return if failed
  window = SDL_CreateWindow("Jukebox", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
  if (window == NULL) 
    return false;
  //create surface, return if failed
  screenSurface = SDL_GetWindowSurface(window);
  if (screenSurface == NULL) 
    return false;
  return true;
}

bool init()             //init systems, return success
{
  if (!graphics_init()) //if SDL fails, return
    return false;
  if (!screenSetup())   //if screen fails, return
    return false;
  return true;
}

void selection_limits(int &select, int &start, int &end, int max) //determine tracklist selection limits
{
  if (max <= selection_limit)   //if the maximum tracks is less than or equal to the limits, start at 0, end at max
  {
    start = 0;
    end = max;
  }
  else                          //if the tracklist is too big
  {
    if (select > end-1)         //if the selection is greater than the bottom value
    {
      //3/4*max is the next 'frame' size for the tracks, move in chunks
      if (end+selection_limit*3/4 < max && select <= end+selection_limit*3/4 ) //if the frame move is less than the max and selection is in frame
      {
        end = end+selection_limit*3/4;                            //move the end by the frame size
        start = start+selection_limit*3/4;                        //move the start by the frame size
      }
      else if (select > end+selection_limit*3/4 && select < max)  //if select is greater than a frame size and less than max (wrap around condition)
      {
        end = select+1;                                           //end is one above select and start is adjusted to fit the screen
        start = end-selection_limit;
      }
      else                                                        //otherwise (bottom of screen)
      {
        end = max;                                                //end is the max amd start moves below it
        start = max-selection_limit;
      }
    }
    else if (select < start)                                      //if select is before start (wrap around or up condition)
    {
      start = select;                                             //start begins at the selection
      end = start + selection_limit;                              //selection goes as far as it needs
    }
    else
      end = start + selection_limit;                              //otherwise, the end is the start plus the selection_limit (normal conditions)
  }
}

int main(int argc, char* args[]) {
  if (!init()) return 1;                //if init fails, return
  SDL_Color white = {255,255,255,255};  //create white, black, green colors
  SDL_Color black = {0,0,0,255};
  SDL_Color green = {0,255,0,255};

  //Create Albums
  Album album1 = Album("Test Album 1", "app0:/art/", "art1", ".png");
  album1.add_song("French suite no. 4 in E-flat major", "Written By: Johann Sebastian Bach, Performed By: Luis Sarro", "app0:/Album1/", "Suite_No_4", ".mp3");

  Album album2 =  Album("Test Album 2", "app0:/art/", "art2", ".png");
  album2.add_song("L'estro armonico", "Written By: Antonio Vivaldi, Performed By: San Antonio Symphony Orchestra", "app0:/Album2/", "L_Estro_Armonico", ".mp3");

  std::vector<Album*> albums;       //add albums to vector
  albums.push_back(&album1);
  albums.push_back(&album2);
  Album* active_album = albums[0];  //by default first album is active
  
  int album_selection = 0;          
  const int text_size = 30;
  int artist_offset = 0, album_offset = 0, song_offset = 0; //offset vars

  TTF_Font* font = TTF_OpenFont(FONT_PATH, 20);         //create fonts
  TTF_Font* font_outline = TTF_OpenFont(FONT_PATH, 20);
  TTF_SetFontOutline(font_outline, 3);
  
  SceCtrlData ctrl;       //Vita button input var
  SDL_Surface* font_img;  //pointer for font_img
  SDL_Surface* background_img = loadImage("app0:/art/background.png");  //background art
  
  int start_x = 560, start_y = 400; //vars for reuse
  int text_rect_w = 350;

  //rectangles for different images
  SDL_Rect text_rect =        {20, 20, 150, text_size};
  SDL_Rect crop_rect =        { 0, 0 , text_rect_w, text_size};
  SDL_Rect album_rect =       {start_x, 50, 100, 100};
  SDL_Rect song_name_rect =   {start_x, start_y, text_rect_w, text_size};
  SDL_Rect artist_rect =      {start_x, start_y + 25, text_rect_w, text_size};
  SDL_Rect album_name_rect =  {start_x, start_y + 50, text_rect_w, text_size};

  //selection and limit vars
  int selection = -1, current = 0;
  int selection_start = 0;
  int selection_end = selection_limit;
  selection_limits(selection, selection_start, selection_end, albums[album_selection]->tracklist.size()); //reset limits

  //status vars
  bool run = true;
  bool music_playing = false;

  
  while(run) //while running
  {
    SDL_FillRect(screenSurface, NULL, SDL_MapRGB(screenSurface->format, 0, 0, 0));  //clear screen
    SDL_BlitSurface(background_img, NULL, screenSurface, NULL);                     //draw background

    sceCtrlPeekBufferPositive(0, &ctrl, 1);   //get button inputs

    //Update track selection, tracklist sizes are taken from the album selected
    if (ctrl.buttons & SCE_CTRL_UP) //if UP is pressed
    {
      selection--;  //decrease selection
      if (selection < 0) selection = albums[album_selection]->tracklist.size()-1;                             //if negative, go to the bottom
      selection_limits(selection, selection_start, selection_end, albums[album_selection]->tracklist.size()); //reset limits
    }

    else if (ctrl.buttons & SCE_CTRL_DOWN) //if DOWN is pressed
    {
      selection++;  //increase selection
      if (selection == albums[album_selection]->tracklist.size()) selection = 0;  //if above the tracksize, go to the beginning
      selection_limits(selection, selection_start, selection_end, albums[album_selection]->tracklist.size()); //reset limits
    }

    //if shoulders are pressed adjust album selection (Left - and Right +) and adjust track selection in case it is out of bounds and adjust limits.
    else if (ctrl.buttons & SCE_CTRL_LTRIGGER)
    { 
      album_selection--; 
      if (album_selection < 0) album_selection = albums.size()-1;  
      if (selection >= albums[album_selection]->tracklist.size()) selection = albums[album_selection]->tracklist.size()-1;  
      selection_limits(selection, selection_start, selection_end, albums[album_selection]->tracklist.size());    
    }

    else if (ctrl.buttons & SCE_CTRL_RTRIGGER)
    {
      album_selection++;
      if (album_selection == albums.size()) album_selection = 0;
      if (selection >= albums[album_selection]->tracklist.size()) selection = albums[album_selection]->tracklist.size()-1;
      selection_limits(selection, selection_start, selection_end, albums[album_selection]->tracklist.size());
    }

    //Play Music if selection is not -1
    if ((ctrl.buttons & SCE_CTRL_CROSS) && selection != -1)
    {
      if (music_playing)      //if music is playing, stop and free for new music
      {
        Mix_HaltMusic();
        Mix_FreeMusic(music);
      }

      active_album = albums[album_selection];     //set active album
      music = active_album->load_song(selection); //get active music
      if (music == NULL) return 1;                //if failed, exit
      music_playing = true;                       //set music status
      current = selection;                        //update song selection
      Mix_PlayMusic(music, 0);                    //Play Music, no loop

      //Reset rectangles and offsets
      song_name_rect =  {start_x, start_y, text_rect_w, text_size};
      artist_rect = {start_x, start_y + 25, text_rect_w, text_size};
      album_name_rect =  {start_x, start_y + 50, text_rect_w, text_size};

      song_offset = 0; artist_offset = 0; album_offset = 0;
    }

    //Stop Music if playing
    else if ((ctrl.buttons & SCE_CTRL_CIRCLE) && music_playing)
    {
      Mix_HaltMusic();        //stop and free music
      Mix_FreeMusic(music);   
      music_playing = false;  //adjust status
    }
    
    //Draw tracklist
    ///Draw Album
    text_rect.y = 20;
    display_text(font, font_outline, albums[album_selection]->album_name, white, black, &text_rect, screenSurface);
    text_rect.y = text_rect.y + 40;

    ///Draw the tracks within the limits
    for(int i = selection_start; i < selection_end; i++)
    {
      display_text(font, font_outline, albums[album_selection]->get_song_name(i), (i == selection)? green:white, black, &text_rect, screenSurface); //draw the song with the cursor in green
      text_rect.y = text_rect.y + 30;
    }
    
    //Draw current song info when music is playing
    if (music_playing)  
    {
      SDL_BlitSurface(active_album->get_art(), NULL, screenSurface, &album_rect); //draw album art

      //Draw Song_name, scroll if too long.
      if (display_text_crop(font, font_outline, active_album->get_song_name(current), white, black, &song_name_rect, &crop_rect, song_offset, screenSurface))
      { //When the image is fully shown
        song_name_rect = {start_x, start_y, text_rect_w, text_size}; //reset rect
        if (song_offset > 0)
        {
          song_offset = 0;                  //reset offset
          song_name_rect.x = start_x + 400; //put off screen
        }
      }
      else //If the entire image is not shown
      {
        song_name_rect.x  = (song_name_rect.x > start_x) ? song_name_rect.x-2 : start_x;  //if the image is not in its start position, move it, otherwise don't
        song_offset = (song_name_rect.x > start_x) ? 0 : song_offset + 2;                 //if the image is not in its start position, do not adjust offset, otherwise increase
      } 

      //Draw Artist Name, scroll if too long
      if (display_text_crop(font, font_outline, active_album->get_artist(current), white, black, &artist_rect, &crop_rect, artist_offset, screenSurface))
      {
        artist_rect = {start_x, start_y + 25, text_rect_w, text_size};
        if (artist_offset > 0)
        {
          artist_offset = 0;
          artist_rect.x = start_x + 400;
        }
      }
      else 
      {
        artist_rect.x  = (artist_rect.x > start_x) ? artist_rect.x-2 : start_x;
        artist_offset = (artist_rect.x > start_x) ? 0 : artist_offset+2;
      }

      //Draw album name, scroll if too long
      if (display_text_crop(font, font_outline, active_album->album_name, white, black, &album_name_rect,&crop_rect, album_offset, screenSurface))
      {
        album_name_rect = {start_x, start_y + 50, text_rect_w, text_size};
        if (album_offset > 0)
        {
          album_offset = 0;
          album_name_rect.x = start_x + 400;
        }
      }
      else 
      {
        album_name_rect.x = (album_name_rect.x > start_x) ? album_name_rect.x-2:start_x;
        album_offset = (album_name_rect.x > start_x) ? 0: album_offset+2;
      }
    }

    SDL_UpdateWindowSurface(window);  //update screen
    SDL_Delay(100);                   //wait 100ms
  }
  close();
  return 0;
}
