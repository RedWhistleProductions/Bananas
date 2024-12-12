#pragma once
#include <SDL2/SDL.h>
#include <map>

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
    std::map<SDL_KeyCode, Key_Code> Key_Map;
    Key Keys[97];
    Keyboard();
    void Set_Key_Down(Key_Code Key, Digital_Function Pressed);
    void Set_Key_Up(Key_Code Key, Digital_Function Released);

    void Update(SDL_Event *e);

};

Keyboard::Keyboard()
{
    for(int i = 0; i < 97; i++)
    {
        Keys[i].Pressed = nullptr;
        Keys[i].Released = nullptr;
    }

    Key_Map[SDLK_a] = Key_A;
    Key_Map[SDLK_b] = Key_B;
    Key_Map[SDLK_c] = Key_C;
    Key_Map[SDLK_d] = Key_D;
    Key_Map[SDLK_e] = Key_E;
    Key_Map[SDLK_f] = Key_F;
    Key_Map[SDLK_g] = Key_G;
    Key_Map[SDLK_h] = Key_H;
    Key_Map[SDLK_i] = Key_I;
    Key_Map[SDLK_j] = Key_J;
    Key_Map[SDLK_k] = Key_K;
    Key_Map[SDLK_l] = Key_L;
    Key_Map[SDLK_m] = Key_M;
    Key_Map[SDLK_n] = Key_N;
    Key_Map[SDLK_o] = Key_O;
    Key_Map[SDLK_p] = Key_P;
    Key_Map[SDLK_q] = Key_Q;
    Key_Map[SDLK_r] = Key_R;
    Key_Map[SDLK_s] = Key_S;
    Key_Map[SDLK_t] = Key_T;
    Key_Map[SDLK_u] = Key_U;
    Key_Map[SDLK_v] = Key_V;
    Key_Map[SDLK_w] = Key_W;
    Key_Map[SDLK_x] = Key_X;
    Key_Map[SDLK_y] = Key_Y;
    Key_Map[SDLK_z] = Key_Z;
    Key_Map[SDLK_0] = Key_0;
    Key_Map[SDLK_1] = Key_1;
    Key_Map[SDLK_2] = Key_2;
    Key_Map[SDLK_3] = Key_3;
    Key_Map[SDLK_4] = Key_4;
    Key_Map[SDLK_5] = Key_5;
    Key_Map[SDLK_6] = Key_6;
    Key_Map[SDLK_7] = Key_7;
    Key_Map[SDLK_8] = Key_8;
    Key_Map[SDLK_9] = Key_9;
    Key_Map[SDLK_F1] = Key_F1;
    Key_Map[SDLK_F2] = Key_F2;
    Key_Map[SDLK_F3] = Key_F3;
    Key_Map[SDLK_F4] = Key_F4;
    Key_Map[SDLK_F5] = Key_F5;
    Key_Map[SDLK_F6] = Key_F6;
    Key_Map[SDLK_F7] = Key_F7;
    Key_Map[SDLK_F8] = Key_F8;
    Key_Map[SDLK_F9] = Key_F9;
    Key_Map[SDLK_F10] = Key_F10;
    Key_Map[SDLK_F11] = Key_F11;
    Key_Map[SDLK_F12] = Key_F12;
    Key_Map[SDLK_LEFT] = Key_Left;
    Key_Map[SDLK_RIGHT] = Key_Right;
    Key_Map[SDLK_UP] = Key_Up;
    Key_Map[SDLK_DOWN] = Key_Down;
    Key_Map[SDLK_SPACE] = Key_Space;
    Key_Map[SDLK_RETURN] = Key_Enter;
    Key_Map[SDLK_ESCAPE] = Key_Escape;
    Key_Map[SDLK_TAB] = Key_Tab;
    Key_Map[SDLK_BACKSPACE] = Key_BackSpace;
    Key_Map[SDLK_DELETE] = Key_Delete;
    Key_Map[SDLK_INSERT] = Key_Insert;
    Key_Map[SDLK_HOME] = Key_Home;
    Key_Map[SDLK_END] = Key_End;
    Key_Map[SDLK_PAGEUP] = Key_Page_Up;
    Key_Map[SDLK_PAGEDOWN] = Key_Page_Down;
    Key_Map[SDLK_LSHIFT] = Key_Left_Shift;
    Key_Map[SDLK_RSHIFT] = Key_Right_Shift;
    Key_Map[SDLK_LCTRL] = Key_Left_Control;
    Key_Map[SDLK_RCTRL] = Key_Right_Control;
    Key_Map[SDLK_LALT] = Key_Left_Alt;
    Key_Map[SDLK_RALT] = Key_Right_Alt;
    Key_Map[SDLK_CAPSLOCK] = Key_Caps_Lock;
    Key_Map[SDLK_NUMLOCKCLEAR] = Key_Num_Lock;
    Key_Map[SDLK_SCROLLLOCK] = Key_Scroll_Lock;
    Key_Map[SDLK_SEMICOLON] = Key_Semicolon;
    Key_Map[SDLK_QUOTE] = Key_Apostrophe;
    Key_Map[SDLK_COMMA] = Key_Comma;
    Key_Map[SDLK_PERIOD] = Key_Period;
    Key_Map[SDLK_SLASH] = Key_Slash;
    Key_Map[SDLK_BACKSLASH] = Key_Backslash;
    Key_Map[SDLK_LEFTBRACKET] = Key_Left_Bracket;
    Key_Map[SDLK_RIGHTBRACKET] = Key_Right_Bracket;
    Key_Map[SDLK_MINUS] = Key_Minus;
    Key_Map[SDLK_EQUALS] = Key_Equal;
    Key_Map[SDLK_KP_0] = Key_Num_0;
    Key_Map[SDLK_KP_1] = Key_Num_1;
    Key_Map[SDLK_KP_2] = Key_Num_2;
    Key_Map[SDLK_KP_3] = Key_Num_3;
    Key_Map[SDLK_KP_4] = Key_Num_4;
    Key_Map[SDLK_KP_5] = Key_Num_5;
    Key_Map[SDLK_KP_6] = Key_Num_6;
    Key_Map[SDLK_KP_7] = Key_Num_7;
    Key_Map[SDLK_KP_8] = Key_Num_8;
    Key_Map[SDLK_KP_9] = Key_Num_9;
    Key_Map[SDLK_KP_MULTIPLY] = Key_Num_Multiply;
    Key_Map[SDLK_KP_DIVIDE] = Key_Num_Divide;
    Key_Map[SDLK_KP_PLUS] = Key_Num_Add;
    Key_Map[SDLK_KP_MINUS] = Key_Num_Subtract;
    Key_Map[SDLK_KP_DECIMAL] = Key_Num_Decimal;
    Key_Map[SDLK_KP_ENTER] = Key_Num_Enter;
}

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
    auto it = Key_Map.find(static_cast<SDL_KeyCode>(e->key.keysym.sym));
    if (it != Key_Map.end())
    {
        Key_Code k = it->second;
        
        if(e->type == SDL_KEYDOWN && Keys[k].Pressed != nullptr)
        {
            Keys[k].Pressed();
        }
        else if(e->type == SDL_KEYUP && Keys[k].Released != nullptr)
        {
            Keys[k].Released();
        }
    }
}