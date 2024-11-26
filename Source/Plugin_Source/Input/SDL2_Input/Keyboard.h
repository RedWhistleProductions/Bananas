#pragma once
#include <SDL2/SDL.h>

using Digital_Function = void(*)();

struct Key
{
    Digital_Function Pressed;
    Digital_Function Released;
};

enum Key_Code
{
    Key_A, Key_B, Key_C, Key_D, Key_E, Key_F, Key_G, Key_H, Key_I, Key_J, Key_K, Key_L, Key_M, Key_N, Key_O, Key_P, Key_Q, Key_R, Key_S, Key_T, Key_U, Key_V, Key_W, Key_X, Key_Y, Key_Z,
    Key_0, Key_1, Key_2, Key_3, Key_4, Key_5, Key_6, Key_7, Key_8, Key_9,
    Key_F1, Key_F2, Key_F3, Key_F4, Key_F5, Key_F6, Key_F7, Key_F8, Key_F9, Key_F10, Key_F11, Key_F12,
    Key_Left, Key_Right, Key_Up, Key_Down,
    Key_Space, Key_Enter, Key_Escape, Key_Tab, Key_BackSpace, Key_Delete, Key_Insert, Key_Home, Key_End, Key_Page_Up, Key_Page_Down,
    Key_Left_Shift, Key_Right_Shift, Key_Left_Control, Key_Right_Control, Key_Left_Alt, Key_Right_Alt,
    Key_Caps_Lock, Key_Num_Lock, Key_Scroll_Lock,
    Key_Semicolon, Key_Apostrophe, Key_Comma, Key_Period, Key_Slash, Key_Backslash, Key_Left_Bracket, Key_Right_Bracket, Key_Minus, Key_Equal,
    Key_Num_0, Key_Num_1, Key_Num_2, Key_Num_3, Key_Num_4, Key_Num_5, Key_Num_6, Key_Num_7, Key_Num_8, Key_Num_9,
    Key_Num_Multiply, Key_Num_Divide, Key_Num_Add, Key_Num_Subtract, Key_Num_Decimal, Key_Num_Enter
};

class Keyboard
{
public:
    Key Keys[97];
    
    void Set_Key_Down(Key_Code Key, Digital_Function Pressed);
    void Set_Key_Up(Key_Code Key, Digital_Function Released);

    void Update(SDL_Event *e);

};

void Keyboard::Set_Key_Down(Key_Code Key, Digital_Function Pressed)
{
    Keys[Key].Pressed = Pressed;
}

void Keyboard::Set_Key_Up(Key_Code Key, Digital_Function Released)
{
    Keys[Key].Released = Released;
}

void Keyboard::Update(SDL_Event *e)
{
    if(e->type == SDL_KEYDOWN)
    {
        Keys[e->key.keysym.sym].Pressed();
    }
    else if(e->type == SDL_KEYUP)
    {
        Keys[e->key.keysym.sym].Released();
    }
}