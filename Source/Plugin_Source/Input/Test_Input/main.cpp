#include <iostream>
#include "Named_List.h"

using Analog_Function = int (*)();
using Digital_Function = bool (*)();


Named_List<Digital_Function> Digital_Function_List;
Named_List<Analog_Function> Analog_Function_List;

enum Buttons
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
   
extern "C" void Constructor()
{
    std::cout << "Input Module Constructor" << std::endl;
}

extern "C" void Destructor()
{
    std::cout << "Input Module Destructor" << std::endl;
}

extern "C" void Add_Controll_Set(std::string Name)
{
    std::cout << "Add_Controll_Set" << std::endl;
}

extern "C" void Set_Controll_Set(std::string Name)
{
    std::cout << "Set_Controll_Set" << std::endl;
}

extern "C" void Update(std::string Controll_Set)
{
    std::cout << "Update" << std::endl;
}

// Mouse Functions
extern "C" void Set_Mouse_Left_Down(Digital_Function Foo)
{
    std::cout << "Set_Mouse_Left_Down" << std::endl;
}

extern "C" void Set_Mouse_Left_Up(Digital_Function Foo)
{
    std::cout << "Set_Mouse_Left_Up" << std::endl;
}

extern "C" void Set_Mouse_Middle_Down(Digital_Function Foo)
{
    std::cout << "Set_Mouse_Middle_Down" << std::endl;
}

extern "C" void Set_Mouse_Middle_Up(Digital_Function Foo)
{
    std::cout << "Set_Mouse_Middle_Up" << std::endl;
}

extern "C" void Set_Mouse_Right_Down(Digital_Function Foo)
{
    std::cout << "Set_Mouse_Right_Down" << std::endl;
}

extern "C" void Set_Mouse_Right_Up(Digital_Function Foo)
{
    std::cout << "Set_Mouse_Right_Up" << std::endl;
}

extern "C" void Set_Mouse_X(Analog_Function Foo)
{
    std::cout << "Set_Mouse_X" << std::endl;
}

extern "C" void Set_Mouse_Y(Analog_Function Foo)
{
    std::cout << "Set_Mouse_Y" << std::endl;
}

// Keyboard Functions
extern "C" void Set_Key_Down(Key_Code Key, Digital_Function Foo)
{
    std::cout << "Set_Key_Down" << std::endl;
}

extern "C" void Set_Key_Up(Key_Code Key, Digital_Function Foo)
{
    std::cout << "Set_Key_Up" << std::endl;
}

// Controller Functions
extern "C" void Set_Joy_Digital(Buttons Button, Digital_Function Function)
{
    std::cout << "Set_Joy_Digital" << std::endl;
}

extern "C" void Set_Joy_Analog(Buttons Button, Analog_Function Function)
{
    std::cout << "Set_Joy_Analog" << std::endl;
}
