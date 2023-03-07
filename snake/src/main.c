#include <psp2/kernel/processmgr.h>
#include <SDL2/SDL.h>
#include <time.h>
#include <stdlib.h>

#include <stdio.h>
#include <psp2/ctrl.h>

#include "debugScreen.h"
#include "helperVita.h"
#include "helperCtrl.h"

//Screen dimension constants


SDL_Window    * gWindow   = NULL;
SDL_Renderer  * gRenderer = NULL;

const int maxSize = 10;
const int objSize = 10;

int randint(int lower, int upper)
{
  return (rand() % (upper - lower + 1)) + lower;
}

int snake()
{
  SDL_Rect body = {0,0,objSize,objSize};
  int size = 1;
  int speed[] = {0,0};
  int xPos[maxSize];
  int yPos[maxSize];
  int appleX = objSize*randint(10, 90);
  int appleY = objSize*randint(10, 50);

  xPos[0] = objSize*randint(10, 90);
  yPos[0] = objSize*randint(10, 50);

  if( SDL_Init( SDL_INIT_VIDEO ) < 0 )
      return -1;

  if ((gWindow = SDL_CreateWindow("Snake", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN)) == NULL)
    return -1;

  if ((gRenderer = SDL_CreateRenderer(gWindow, -1, 0)) == NULL)
      return -1;

  unsigned int buttons = 0;
  SceCtrlData ctrl;
  
  while (size < maxSize+1)
  {  
    sceCtrlPeekBufferPositive(0, &ctrl, 1);
    buttons = ctrl.buttons;

    if (buttons & SCE_CTRL_UP)
      {speed[0] = 0; speed[1] = -objSize;}
    else if (buttons & SCE_CTRL_DOWN)
      {speed[0] = 0; speed[1] = objSize;}
    else if (buttons & SCE_CTRL_LEFT)
      {speed[1] = 0; speed[0] = -objSize;}
    else if (buttons & SCE_CTRL_RIGHT)
      {speed[1] = 0; speed[0] = objSize;}

    SDL_SetRenderDrawColor(gRenderer, 0,0,0,255);
    SDL_RenderClear(gRenderer);

    for (int i = size; i > 0; i--)
    {
      xPos[i] = xPos[i-1];
      yPos[i] = yPos[i-1];
    }

    xPos[0] = xPos[0] + speed[0];
    yPos[0] = yPos[0] + speed[1];

    if (xPos[0] == appleX && yPos[0] == appleY)
    {
      size++;
      appleX = objSize*randint(10, 90);
      appleY = objSize*randint(10, 50);
    }

    body.x = appleX;
    body.y = appleY;
    SDL_SetRenderDrawColor(gRenderer, 255,0,0,255);
    SDL_RenderFillRect( gRenderer, &body);

    if ((xPos[0] >= SCREEN_WIDTH || yPos[0] >= SCREEN_HEIGHT)
          || (xPos[0] <0 || yPos[0] <0))
      return -1;

    for (int i = 0; i < size; i++)
    {
      body.x = xPos[i];
      body.y = yPos[i];
      if (i == 0)
        SDL_SetRenderDrawColor(gRenderer, 0,255,0,255);
      else
      {
        SDL_SetRenderDrawColor(gRenderer, 0,255,255,255);
        if (xPos[i] == xPos[0] && yPos[i] == xPos[i])
          return -1;
      }
      SDL_RenderFillRect( gRenderer, &body);
    }
    SDL_RenderPresent( gRenderer );
    SDL_Delay(100);
  }
  return 0;
}
int main(int argc, char *argv[]) 
{
  
  srand(time(NULL));
  setupCtrls();
  waitUntilButtonPress(SCE_CTRL_START);
  
  if (snake() <0)
    SDL_SetRenderDrawColor(gRenderer, 255,0,0,255);
  else
    SDL_SetRenderDrawColor(gRenderer, 0,0,255,255);

  SDL_RenderClear(gRenderer);

  SDL_Delay(10000);

  SDL_DestroyRenderer( gRenderer );
  SDL_DestroyWindow( gWindow );
  gWindow = NULL;
  gRenderer = NULL;
  
  SDL_Quit();
  sceKernelExitProcess(0);
  return 0;
}
