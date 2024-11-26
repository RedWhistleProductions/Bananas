#pragma once
#include <map>
#include "Plugin.h"
#include "../Data_Source.h"

namespace Input
{
    using Analog_Function =  void(*)(int);
    using Digital_Function = void(*)();

    Plugin Module;
    Named_List<Digital_Function> Digital_Function_List;
    Named_List<Analog_Function> Analog_Function_List;

    enum Digital_Button
    {
        Button_A, Button_B, Button_X, Button_Y, 
        Button_D_Pad_Up, Button_D_Pad_Down, 
        Button_D_Pad_Left, Button_D_Pad_Right, 
        Button_Start, Button_Select, 
        Button_L1,  Button_L3, 
        Button_R1,  Button_R3
    };

    enum Analog_Button
    {
        Button_L2, Button_R2,
        Button_Left_Joy_X, Button_Left_Joy_Y, 
        Button_Right_Joy_X, Button_Right_Joy_Y
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
        Key_Num_Multiply, Key_Num_Divide, Key_Num_Add, Key_Num_Subtract, Key_Num_Decimal, Key_Num_Enter,
    };


    //Used to convert Strings to Buttons
    std::map<std::string, Digital_Button> Digital_Button_Map;
    std::map<std::string, Analog_Button> Analog_Button_Map;
    std::map<std::string, Key_Code> Key_Map;


    void (*Add_Controll_Set)(std::string Name);
    void (*Set_Controll_Set)(std::string Name);
    void (*Update)(std::string Controll_Set);

    // Mouse Functions
    void (*Set_Mouse_Left_Down)(Digital_Function Foo);
    void (*Set_Mouse_Left_Up)(Digital_Function Foo);
    void (*Set_Mouse_Middle_Down)(Digital_Function Foo);
    void (*Set_Mouse_Middle_Up)(Digital_Function Foo);
    void (*Set_Mouse_Right_Down)(Digital_Function Foo);
    void (*Set_Mouse_Right_Up)(Digital_Function Foo);
    void (*Set_Mouse_X)(Analog_Function Foo);
    void (*Set_Mouse_Y)(Analog_Function Foo);

    // Keyboard Functions
    void (*Set_Key_Down)(Key_Code Key, Digital_Function Foo);
    void (*Set_Key_Up)(Key_Code Key, Digital_Function Foo);

        // Controller Functions
    void (*Set_Joy_Digital)(Digital_Button Button, Digital_Function Function);
    void (*Set_Joy_Analog)(Analog_Button Button, Analog_Function Function);
    
    void Init(std::string Name)
    {
        /*
        Digital_Button_Map, Analog_Button_Map, and Key_Map are used 
        by the interpreter to convert strings to enums
        */
        Digital_Button_Map["Button_A"] = Button_A;
        Digital_Button_Map["Button_B"] = Button_B;
        Digital_Button_Map["Button_X"] = Button_X;
        Digital_Button_Map["Button_Y"] = Button_Y;
        Digital_Button_Map["Button_D_Pad_Up"] = Button_D_Pad_Up;
        Digital_Button_Map["Button_D_Pad_Down"] = Button_D_Pad_Down;
        Digital_Button_Map["Button_D_Pad_Left"] = Button_D_Pad_Left;
        Digital_Button_Map["Button_D_Pad_Right"] = Button_D_Pad_Right;
        Digital_Button_Map["Button_Start"] = Button_Start;
        Digital_Button_Map["Button_Select"] = Button_Select;
        Digital_Button_Map["Button_L1"] = Button_L1;
        Digital_Button_Map["Button_L3"] = Button_L3;
        Digital_Button_Map["Button_R1"] = Button_R1;
        Digital_Button_Map["Button_R3"] = Button_R3;
 
        Analog_Button_Map["Button_L2"] = Button_L2;
        Analog_Button_Map["Button_R2"] = Button_R2;
        Analog_Button_Map["Button_Left_Joy_X"] = Button_Left_Joy_X;
        Analog_Button_Map["Button_Left_Joy_Y"] = Button_Left_Joy_Y;
        Analog_Button_Map["Button_Right_Joy_X"] = Button_Right_Joy_X;
        Analog_Button_Map["Button_Right_Joy_Y"] = Button_Right_Joy_Y;
                
        Key_Map["Key_A"] = Key_A;
        Key_Map["Key_B"] = Key_B;
        Key_Map["Key_C"] = Key_C;
        Key_Map["Key_D"] = Key_D;
        Key_Map["Key_E"] = Key_E;
        Key_Map["Key_F"] = Key_F;
        Key_Map["Key_G"] = Key_G;
        Key_Map["Key_H"] = Key_H;
        Key_Map["Key_I"] = Key_I;
        Key_Map["Key_J"] = Key_J;
        Key_Map["Key_K"] = Key_K;
        Key_Map["Key_L"] = Key_L;
        Key_Map["Key_M"] = Key_M;
        Key_Map["Key_N"] = Key_N;
        Key_Map["Key_O"] = Key_O;
        Key_Map["Key_P"] = Key_P;
        Key_Map["Key_Q"] = Key_Q;
        Key_Map["Key_R"] = Key_R;
        Key_Map["Key_S"] = Key_S;
        Key_Map["Key_T"] = Key_T;
        Key_Map["Key_U"] = Key_U;
        Key_Map["Key_V"] = Key_V;
        Key_Map["Key_W"] = Key_W;
        Key_Map["Key_X"] = Key_X;
        Key_Map["Key_Y"] = Key_Y;
        Key_Map["Key_Z"] = Key_Z;
        Key_Map["Key_0"] = Key_0;
        Key_Map["Key_1"] = Key_1;
        Key_Map["Key_2"] = Key_2;
        Key_Map["Key_3"] = Key_3;
        Key_Map["Key_4"] = Key_4;
        Key_Map["Key_5"] = Key_5;
        Key_Map["Key_6"] = Key_6;
        Key_Map["Key_7"] = Key_7;
        Key_Map["Key_8"] = Key_8;
        Key_Map["Key_9"] = Key_9;
        Key_Map["Key_F1"] = Key_F1;
        Key_Map["Key_F2"] = Key_F2;
        Key_Map["Key_F3"] = Key_F3;
        Key_Map["Key_F4"] = Key_F4;
        Key_Map["Key_F5"] = Key_F5;
        Key_Map["Key_F6"] = Key_F6;
        Key_Map["Key_F7"] = Key_F7;
        Key_Map["Key_F8"] = Key_F8;
        Key_Map["Key_F9"] = Key_F9;
        Key_Map["Key_F10"] = Key_F10;
        Key_Map["Key_F11"] = Key_F11;
        Key_Map["Key_F12"] = Key_F12;
        Key_Map["Key_Left"] = Key_Left;
        Key_Map["Key_Right"] = Key_Right;
        Key_Map["Key_Up"] = Key_Up;
        Key_Map["Key_Down"] = Key_Down;
        Key_Map["Key_Space"] = Key_Space;
        Key_Map["Key_Enter"] = Key_Enter;
        Key_Map["Key_Escape"] = Key_Escape;
        Key_Map["Key_Tab"] = Key_Tab;
        Key_Map["Key_BackSpace"] = Key_BackSpace;
        Key_Map["Key_Delete"] = Key_Delete;
        Key_Map["Key_Insert"] = Key_Insert;
        Key_Map["Key_Home"] = Key_Home;
        Key_Map["Key_End"] = Key_End;
        Key_Map["Key_Page_Up"] = Key_Page_Up;
        Key_Map["Key_Page_Down"] = Key_Page_Down;
        Key_Map["Key_Left_Shift"] = Key_Left_Shift;
        Key_Map["Key_Right_Shift"] = Key_Right_Shift;
        Key_Map["Key_Left_Control"] = Key_Left_Control;
        Key_Map["Key_Right_Control"] = Key_Right_Control;
        Key_Map["Key_Left_Alt"] = Key_Left_Alt;
        Key_Map["Key_Right_Alt"] = Key_Right_Alt;
        Key_Map["Key_Caps_Lock"] = Key_Caps_Lock;
        Key_Map["Key_Num_Lock"] = Key_Num_Lock;
        Key_Map["Key_Scroll_Lock"] = Key_Scroll_Lock;
        Key_Map["Key_Semicolon"] = Key_Semicolon;
        Key_Map["Key_Apostrophe"] = Key_Apostrophe;
        Key_Map["Key_Comma"] = Key_Comma;
        Key_Map["Key_Period"] = Key_Period;
        Key_Map["Key_Slash"] = Key_Slash;
        Key_Map["Key_Backslash"] = Key_Backslash;
        Key_Map["Key_Left_Bracket"] = Key_Left_Bracket;
        Key_Map["Key_Right_Bracket"] = Key_Right_Bracket;
        Key_Map["Key_Minus"] = Key_Minus;
        Key_Map["Key_Equal"] = Key_Equal;
        Key_Map["Key_Num_0"] = Key_Num_0;
        Key_Map["Key_Num_1"] = Key_Num_1;
        Key_Map["Key_Num_2"] = Key_Num_2;
        Key_Map["Key_Num_3"] = Key_Num_3;
        Key_Map["Key_Num_4"] = Key_Num_4;
        Key_Map["Key_Num_5"] = Key_Num_5;
        Key_Map["Key_Num_6"] = Key_Num_6;
        Key_Map["Key_Num_7"] = Key_Num_7;
        Key_Map["Key_Num_8"] = Key_Num_8;
        Key_Map["Key_Num_9"] = Key_Num_9;
        Key_Map["Key_Num_Multiply"] = Key_Num_Multiply;
        Key_Map["Key_Num_Divide"] = Key_Num_Divide;
        Key_Map["Key_Num_Add"] = Key_Num_Add;
        Key_Map["Key_Num_Subtract"] = Key_Num_Subtract;
        Key_Map["Key_Num_Decimal"] = Key_Num_Decimal;
        Key_Map["Key_Num_Enter"] = Key_Num_Enter;
        
        Module.Load("Input", Name);        
        //Assign each function pointer to the corresponding function in the module
        //Module.Assign("Function_Name", Function_Name);
        Module.Assign("Add_Controll_Set", Add_Controll_Set);
        Module.Assign("Set_Controll_Set", Set_Controll_Set);
        Module.Assign("Update", Update);

        Module.Assign("Set_Mouse_Left_Down", Set_Mouse_Left_Down);
        Module.Assign("Set_Mouse_Left_Up", Set_Mouse_Left_Up);
        Module.Assign("Set_Mouse_Middle_Down", Set_Mouse_Middle_Down);
        Module.Assign("Set_Mouse_Middle_Up", Set_Mouse_Middle_Up);
        Module.Assign("Set_Mouse_Right_Down", Set_Mouse_Right_Down);
        Module.Assign("Set_Mouse_Right_Up", Set_Mouse_Right_Up);
        Module.Assign("Set_Mouse_X", Set_Mouse_X);
        Module.Assign("Set_Mouse_Y", Set_Mouse_Y);

        Module.Assign("Set_Key_Down", Set_Key_Down);
        Module.Assign("Set_Key_Up", Set_Key_Up);

        Module.Assign("Set_Joy_Analog", Set_Joy_Analog);
        Module.Assign("Set_Joy_Digital", Set_Joy_Digital);

        if(Add_Controll_Set != nullptr) Add_Controll_Set("Default");
        else std::cout << "Error: Add_Controll_Set not found in Input Module" << std::endl;
    }

    std::string Interpreter(Data_Source *Data)
    {
        std::string Command;
        *Data >> Command;

        if(Command == "Init")
        {
            std::string Name;
            *Data >> Name;
            Init(Name);
            return "";
        }
        else if(Command == "Add_Controll_Set")
        {
            std::string Name;
            *Data >> Name;
            Add_Controll_Set(Name);
            return "";
        }
        else if(Command == "Set_Controll_Set")
        {
            std::string Name;
            *Data >> Name;
            Set_Controll_Set(Name);
            return "";
        }
        else if(Command == "Update")
        {
            std::string Controll_Set;
            *Data >> Controll_Set;
            Update(Controll_Set);
            return "";
        }
        else if(Command == "Set_Mouse_Left_Down")
        {
            std::string Function;
            *Data >> Function;
            Digital_Function_List.Find(Function);
            Set_Mouse_Left_Down(Digital_Function_List.Out());
            return "";
        }
        else if(Command == "Set_Mouse_Left_Up")
        {
            std::string  Function;
            *Data >> Function;
            Digital_Function_List.Find(Function);
            Set_Mouse_Left_Up(Digital_Function_List.Out());
            return "";
        }
        else if(Command == "Set_Mouse_Middle_Down")
        {
            std::string  Function;
            *Data >> Function;
            Digital_Function_List.Find(Function);
            Set_Mouse_Middle_Down(Digital_Function_List.Out());
            return "";
        }
        else if(Command == "Set_Mouse_Middle_Up")
        {
            std::string  Function;
            *Data >> Function;
            Digital_Function_List.Find(Function);
            Set_Mouse_Middle_Up(Digital_Function_List.Out());
            return "";
        }
        else if(Command == "Set_Mouse_Right_Down")
        {
            std::string  Function;
            *Data >> Function;
            Digital_Function_List.Find(Function);
            Set_Mouse_Right_Down(Digital_Function_List.Out());
            return "";
        }
        else if(Command == "Set_Mouse_Right_Up")
        {
            std::string  Function;
            *Data >> Function;
            Digital_Function_List.Find(Function);
            Set_Mouse_Right_Up(Digital_Function_List.Out());
            return "";
        }
        else if(Command == "Set_Mouse_X")
        {
            std::string  Function;
            *Data >> Function;
            Analog_Function_List.Find(Function);
            Set_Mouse_X(Analog_Function_List.Out());
            return "";
        }
        else if(Command == "Set_Mouse_Y")
        {
            std::string  Function;
            *Data >> Function;
            Analog_Function_List.Find(Function);
            Set_Mouse_Y(Analog_Function_List.Out());
            return "";
        }
        else if(Command == "Set_Key_Down")
        {
            std::string Key, Function;
            *Data >> Key;
            *Data >> Function;
            Digital_Function_List.Find(Function);
            Set_Key_Down(Key_Map[Key], Digital_Function_List.Out());
            return "";
        }
        else if(Command == "Set_Key_Up")
        {
            std::string  Key, Function;
            *Data >> Key;
            *Data >> Function;
            Digital_Function_List.Find(Function);
            Set_Key_Up(Key_Map[Key], Digital_Function_List.Out());
            return "";
        }
        else if(Command == "Set_Joy_Analog")
        {
            std::string  Button, Function;
            *Data >> Button;
            *Data >> Function;
            Analog_Function_List.Find(Function);

            Set_Joy_Analog(Analog_Button_Map[Button], Analog_Function_List.Out());
            return "";
        }
        else if(Command == "Set_Joy_Digital")
        {
            std::string Button, Function;
            *Data >> Button;
            *Data >> Function;
            Digital_Function_List.Find(Function);
            Set_Joy_Digital(Digital_Button_Map[Button], Digital_Function_List.Out());
            return "";
        }

        return "Error: " + Command + " not found in New Dictionary";
    }
    
}