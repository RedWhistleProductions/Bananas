#pragma once
#include <SDL2/SDL.h>

using Analog_Function =  void(*)(int);
using Digital_Function = void(*)();

class Mouse
{
    private:
        // Used to get the relative mouse movement
        int Last_X, Last_Y;

    public:
        Digital_Function Mouse_Left_Down;
        Digital_Function Mouse_Left_Up;
        Digital_Function Mouse_Middle_Down;
        Digital_Function Mouse_Middle_Up;
        Digital_Function Mouse_Right_Down;
        Digital_Function Mouse_Right_Up;
        Analog_Function Mouse_X;
        Analog_Function Mouse_Y;

        Mouse();
        void Set_Mouse_Left_Down(Digital_Function Foo);
        void Set_Mouse_Left_Up(Digital_Function Foo);
        void Set_Mouse_Middle_Down(Digital_Function Foo);
        void Set_Mouse_Middle_Up(Digital_Function Foo);
        void Set_Mouse_Right_Down(Digital_Function Foo);
        void Set_Mouse_Right_Up(Digital_Function Foo);
        
        void Set_Mouse_X(Analog_Function Foo);
        void Set_Mouse_Y(Analog_Function Foo);

        void Update(SDL_Event *e);
        void Reset();
};

Mouse::Mouse()
{
    Reset();
}

void Mouse::Set_Mouse_Left_Down(Digital_Function Foo){Mouse_Left_Down = Foo;}

void Mouse::Set_Mouse_Left_Up(Digital_Function Foo){Mouse_Left_Up = Foo;}

void Mouse::Set_Mouse_Middle_Down(Digital_Function Foo){Mouse_Middle_Down = Foo;}

void Mouse::Set_Mouse_Middle_Up(Digital_Function Foo){Mouse_Middle_Up = Foo;}

void Mouse::Set_Mouse_Right_Down(Digital_Function Foo){Mouse_Right_Down = Foo;}

void Mouse::Set_Mouse_Right_Up(Digital_Function Foo){Mouse_Right_Up = Foo;}

void Mouse::Set_Mouse_X(Analog_Function Foo){Mouse_X = Foo;}

void Mouse::Set_Mouse_Y(Analog_Function Foo){Mouse_Y = Foo;}

void Mouse::Update(SDL_Event *e)
{
    if(e->type == SDL_MOUSEBUTTONDOWN)
    {
        if(e->button.button == SDL_BUTTON_LEFT and Mouse_Left_Down != nullptr)
        {
            Mouse_Left_Down();
        }
        else if(e->button.button == SDL_BUTTON_MIDDLE and Mouse_Middle_Down != nullptr)
        {
            Mouse_Middle_Down();
        }
        else if(e->button.button == SDL_BUTTON_RIGHT and Mouse_Right_Down != nullptr)
        {
            Mouse_Right_Down();
        }
    }
    else if(e->type == SDL_MOUSEBUTTONUP)
    {
        if(e->button.button == SDL_BUTTON_LEFT and Mouse_Left_Up != nullptr)
        {
            Mouse_Left_Up();
        }
        else if(e->button.button == SDL_BUTTON_MIDDLE and Mouse_Middle_Up != nullptr)
        {
            Mouse_Middle_Up();
        }
        else if(e->button.button == SDL_BUTTON_RIGHT and Mouse_Right_Up != nullptr)
        {
            Mouse_Right_Up();
        }
    }
    /*else if(e->type == SDL_MOUSEMOTION)
    {
        
        int x, y;
        SDL_GetMouseState(&x, &y);
        Mouse_X(x - Last_X);
        Mouse_Y(y - Last_Y);
        Last_X = x;
        Last_Y = y;
    
    }*/
}

void Mouse::Reset()
{
    Last_X = 0;
    Last_Y = 0;
}