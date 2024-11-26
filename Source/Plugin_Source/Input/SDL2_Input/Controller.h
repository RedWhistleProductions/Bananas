#pragma once
#include <SDL2/SDL.h>

using Analog_Function =  void(*)(int);
using Digital_Function = void(*)();

enum Digital_Button
{
    Button_A, Button_B, Button_X, Button_Y, 
    Button_D_Pad_Up, Button_D_Pad_Down, 
    Button_D_Pad_Left, Button_D_Pad_Right, 
    Button_Start, Button_Select, 
    Button_L1,  Button_L3, 
    Button_R1,  Button_R3, 
};

enum Analog_Button
{
    Button_L2,Button_R2,Button_Left_Joy_Left, Button_Left_Joy_Right, 
    Button_Left_Joy_Up, Button_Left_Joy_Down,
    Button_Right_Joy_Left, Button_Right_Joy_Right,
    Button_Right_Joy_Up, Button_Right_Joy_Down
};


class Controller
{
    public:
    Digital_Function Digital_Buttons[14];
    Analog_Function Analog_Buttons[10];

    void Set_Joy_Digital(Digital_Button Button, Digital_Function Function);
    void Set_Joy_Analog(Analog_Button Button, Analog_Function Function);
    
    void Update(SDL_Event *e);
};

void Controller::Set_Joy_Digital(Digital_Button Button, Digital_Function Function)
{
    Digital_Buttons[Button] = Function;
}

void Controller::Set_Joy_Analog(Analog_Button Button, Analog_Function Function)
{
    Analog_Buttons[Button] = Function;
}

void Controller::Update(SDL_Event *e)
{
}