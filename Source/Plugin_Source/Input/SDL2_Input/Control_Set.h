#pragma once
#include <SDL2/SDL.h>
#include "Keyboard.h"
#include "Mouse.h"
#include "Controller.h"

class Control_Set
{
public:
    Keyboard KB;
    Mouse M;
    Controller Joy;

    void Update(SDL_Event *e);
};

void Control_Set::Update(SDL_Event *e)
{   
    bool Quit = false;
    while(!Quit)
    {
        while(SDL_PollEvent(e) != 0)
        {
            if(e->type == SDL_QUIT)
            {
                Quit = true;
            }
            else if(e->type == SDL_KEYDOWN)
            {
                KB.Update(e);
            }
            else if(e->type == SDL_KEYUP)
            {
                KB.Update(e);
            }
            else if(e->type == SDL_MOUSEBUTTONDOWN or e->type == SDL_MOUSEBUTTONUP or e->type == SDL_MOUSEMOTION)
            {
                M.Update(e);
            }
            
        }
    }
   
}