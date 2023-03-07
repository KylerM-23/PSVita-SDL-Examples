#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_mixer.h>
#include <SDL2/SDL_ttf.h>

#include <string>

#include "debugScreen.h"
#include "SDL_helper.h"
#include "helperVita.h"

#define printf psvDebugScreenPrintf

void SDL_error_msg(int wait_time) //Display error & wait
{
  printf(SDL_GetError());
  SDL_Delay(wait_time);
}

bool graphics_init(int wait_time) //init SDL components and open Audio channel
{
  psvDebugScreenInit();

  if (SDL_Init(SDL_INIT_AUDIO|SDL_INIT_VIDEO) < 0)  //init audio and video
  {
    SDL_error_msg();
    return false;
  }

  if (!(IMG_Init(IMG_INIT_PNG | IMG_INIT_JPG)))     //init PNG & JPG
  {
    printf(IMG_GetError());
    SDL_Delay(wait_time);
    return false;
  }

  if (TTF_Init() < 0)                               //init font
  {
    printf(TTF_GetError());
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

SDL_Surface* loadImage(std::string path) {
  SDL_Surface* img = IMG_Load(path.c_str());  //create surface
  if (img ==  NULL)                           //display error if no
  {                                           //images are made
    printf(IMG_GetError());
    SDL_Delay(5000);
  }
  return img;
}

Mix_Music* loadMusic(std::string path) 
{
  Mix_Music* music_file = Mix_LoadMUS(path.c_str());  //load music
  if (music_file == NULL) SDL_error_msg();            //display error if NULL ptr
  return music_file;
}

SDL_Surface* createText(TTF_Font* font, std::string text, SDL_Color textColor)
{
  SDL_Surface* txtSurface = TTF_RenderText_Solid(font, text.c_str(), textColor);  //render text
  if (txtSurface== NULL)                                                          //display error if NULL ptr
  {                  
    printf(IMG_GetError());
    SDL_Delay(5000);
  }
  return txtSurface;
}

void display_text(TTF_Font* font, std::string txt, SDL_Color color, SDL_Rect* rect, SDL_Surface* surface) 
{
  SDL_Surface* font_img = createText(font, txt, color); //create text surface
  SDL_BlitSurface(font_img, NULL, surface, rect); //show img and free
  SDL_FreeSurface(font_img);
}

//display text with outline
void display_text(TTF_Font* font, TTF_Font* font_outline, std::string txt, SDL_Color color, SDL_Color color_outline, 
      SDL_Rect* rect, SDL_Surface* surface)
{
  rect->x -= 3; rect->y -= 3;                                     //move x and y for proper offset
  display_text(font_outline, txt, color_outline, rect, surface);  //display outline
  rect->x += 3; rect->y += 3;                                     //revert to original
  display_text(font, txt, color, rect, surface);                  //display text
} 

//display with crop effect, return if ther image is fully displayed
bool display_text_crop(TTF_Font* font, std::string txt, SDL_Color color, SDL_Rect* rect, SDL_Rect* crop, int pix, SDL_Surface* surface)
{
  SDL_Surface* font_img = createText(font, txt, color);    //create image
  crop->x = pix;   crop->y = 0;                            //set crop rect
  crop->w = rect->w+10; crop->h = rect->h+10;
  
  bool done = crop->x + rect->w >= font_img->w;           //at the end of the image?
  SDL_BlitSurface(font_img, crop, surface, rect);         //show image and free resources
  SDL_FreeSurface(font_img);
  return done;
}

//display with crop effect and outline, return if ther image is fully displayed
bool display_text_crop(TTF_Font* font, TTF_Font* font_outline, std::string txt, SDL_Color color, SDL_Color color_outline, SDL_Rect* rect, SDL_Rect* crop, int pix, SDL_Surface* surface)
{
  if (pix <0) return false;                 //if the offset is negative, don't crop, move the start pos instead
  bool done = false;                        //image has not finished scrolling by default
  rect->x -= 3; rect->y -= 3;               //adjust for outline
  done = display_text_crop(font_outline, txt, color_outline, rect, crop, pix, surface); //display outline, done is based on outline.
  rect->x += 3; rect->y += 3;               //return to original shape
  display_text_crop(font, txt, color, rect, crop, pix, surface); //display text and return status
  return done;
}
