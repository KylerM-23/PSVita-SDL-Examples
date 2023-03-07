#include <psp2/kernel/processmgr.h>
#include <psp2/ctrl.h>

#include <SDL2/SDL.h>
#include <SDL2/SDL_mixer.h>

#include <string>

#include "debugScreen.h"
#define printf psvDebugScreenPrintf

//SDL Pointers
SDL_Window *window = NULL;
SDL_Surface *screenSurface = NULL;
Mix_Music *music = NULL;
int wait_time = 1000;

bool mix_init() //init SDL components and open Audio channel
{
  psvDebugScreenInit();

  if (SDL_Init(SDL_INIT_AUDIO|SDL_INIT_VIDEO) < 0)  //init audio and video
  {
    printf(SDL_GetError());
    SDL_Delay(wait_time);
    return false;
  }

  if (Mix_Init(MIX_INIT_MP3) < 0)                   //init MP3 mixer
  {
    printf(Mix_GetError());
    SDL_Delay(wait_time);
    return false;
  }

  if (Mix_OpenAudio(22050, MIX_DEFAULT_FORMAT, 2, 4096) < 0) //open audio
  {
    printf(Mix_GetError());
    SDL_Delay(wait_time);
    return false;
  }
  return true;
}

Mix_Music* loadMusic(std::string path) 
{
  Mix_Music* music_file = Mix_LoadMUS(path.c_str());  //load music
  if (music_file == NULL)
  {
    printf(Mix_GetError());            //display error if NULL ptr
    SDL_Delay(wait_time);
  }
  return music_file;
}

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
  if (!mix_init()) //if SDL fails, return
    return false;
  if (!screenSetup())   //if screen fails, return
    return false;
  return true;
}

int main(int argc, char* args[]) {
  if (!init()) return 1;   //if init fails, return

  bool run = true;         //status var
  SceCtrlData ctrl;        //Vita button input var

  printf("Playing L'estro armonico.\nWritten By: Antonio Vivaldi\nPerformed By: San Antonio Symphony Orchestra.\n");
  printf("Press Circle to quit.\n");

  music = loadMusic("app0:/music/L_Estro_Armonico.mp3");  //Load song
  Mix_PlayMusic(music, 1);                                //Play Music, loop = 1
  
  while(run) //while running
  {
    sceCtrlPeekBufferPositive(0, &ctrl, 1);   //get button inputs

    if ((ctrl.buttons & SCE_CTRL_CIRCLE))     //if circle is pressed
    {
      Mix_HaltMusic();                        //stop music
      run = false;                            //adjust status
    }
  }
  close();
  return 0;
}
