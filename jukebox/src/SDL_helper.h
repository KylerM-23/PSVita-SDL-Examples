#ifndef _SDLHELPER_H_INCLUDED
#define _SDLHELPER_H_INCLUDED

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_mixer.h>
#include <SDL2/SDL_ttf.h>

#include <string>

/*
Helper functions for SDL

SDL_error_msg: display error messages for the time specified
graphics_init: startup SDL components, returns true if successful
loadImage: create a surface from the file path
loadMusic: create music file from file path
createText: create text surface of a specified font, text, and color
display_text (1): display text on surface
display_text (2): display text with outline
display_text_crop (1): display text, crop image with crop rectangle, return true if the whole image has been shown (end)
display_text_crop (2): crop with outline
*/

void SDL_error_msg(int wait_time = 5);
bool graphics_init(int wait_time = 5);
SDL_Surface* loadImage(std::string path);
Mix_Music* loadMusic(std::string path);
SDL_Surface* createText(TTF_Font* font, std::string text, SDL_Color textColor);

void display_text(TTF_Font* font, std::string txt, SDL_Color color, SDL_Rect* rect, SDL_Surface* surface);
void display_text(TTF_Font* font, TTF_Font* font_outline, std::string txt, SDL_Color color, SDL_Color color_outline, 
    SDL_Rect* rect, SDL_Surface* surface);
bool display_text_crop(TTF_Font* font, std::string txt, SDL_Color color, SDL_Rect* rect, SDL_Rect* crop, int pix,
    SDL_Surface* surface);
bool display_text_crop(TTF_Font* font, TTF_Font* font_outline, std::string txt, SDL_Color color, SDL_Color color_outline, 
    SDL_Rect* rect, SDL_Rect* crop, int pix, SDL_Surface* surface);

#endif  // _SDLHELPER_H_INCLUDED