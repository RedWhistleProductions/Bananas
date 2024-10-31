#pragma once
#include "Plugin.h"


namespace Controller
{
    Plugin Module;
    enum
    {
        Button_A, Button_B, Button_X, Button_Y, 
        Button_D_Pad_Up, Button_D_Pad_Down, 
        Button_D_Pad_Left, Button_D_Pad_Right, 
        Button_Start, Button_Select, 
        Button_L1, Button_L2, Button_L3, 
        Button_R1, Button_R2, Button_R3, 
        Button_Left_Joy_Left, Button_Left_Joy_Right, 
        Button_Left_Joy_Up, Button_Left_Joy_Down,
        Button_Right_Joy_Left, Button_Right_Joy_Right,
        Button_Right_Joy_Up, Button_Right_Joy_Down
    };

    using Control_Set = int[24];

    using Analog_Function = void(*)(int);
    using Digital_Function = void(*)();
      
    void (*Set_A)(Digital_Function Function);
    void (*Set_B)(Digital_Function Function);
    void (*Set_X)(Digital_Function Function);
    void (*Set_Y)(Digital_Function Function);
    void (*Set_D_Pad_Up)(Digital_Function Function);
    void (*Set_D_Pad_Down)(Digital_Function Function);
    void (*Set_D_Pad_Left)(Digital_Function Function);
    void (*Set_D_Pad_Right)(Digital_Function Function);
    void (*Set_Start)(Digital_Function Function);
    void (*Set_Select)(Digital_Function Function);
    void (*Set_L1)(Digital_Function Function);
    void (*Set_L2)(Analog_Function Function);
    void (*Set_L3)(Digital_Function Function);
    void (*Set_R1)(Digital_Function Function);
    void (*Set_R2)(Analog_Function Function);
    void (*Set_R3)(Digital_Function Function);
    void (*Set_Left_Joy_Left)(Analog_Function Function);
    void (*Set_Left_Joy_Right)(Analog_Function Function);
    void (*Set_Left_Joy_Up)(Analog_Function Function);
    void (*Set_Left_Joy_Down)(Analog_Function Function);
    void (*Set_Right_Joy_Left)(Analog_Function Function);
    void (*Set_Right_Joy_Right)(Analog_Function Function);
    void (*Set_Right_Joy_Up)(Analog_Function Function);
    void (*Set_Right_Joy_Down)(Analog_Function Function);


    void Init(std::string Name)
    {
        Module.Load("Controller", Name);
    }

    std::string Interpreter(FileIO *Script)
    {
        std::string Command;
        *Script >> Command;

        if(Command == "Init")
        {
            std::string Name;
            *Script >> Name;
            Init(Name);
            return "";
        }
        
        return "Error : " + Command + " not found in Controller Dictionary";
    }   
}