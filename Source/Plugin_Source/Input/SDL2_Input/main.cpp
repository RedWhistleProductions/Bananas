#include <iostream>
#include <SDL2/SDL.h>

#include "Named_List.h"
#include "Control_Set.h"

SDL_Event e;

using Analog_Function =  void(*)(int);
using Digital_Function = void(*)();

Named_List<Control_Set> Control_Set_List;

   
extern "C" void Constructor()
{
    std::cout << "Input Module Constructor" << std::endl;
    SDL_Init(SDL_INIT_EVENTS | SDL_INIT_GAMECONTROLLER | SDL_INIT_HAPTIC | SDL_INIT_JOYSTICK);

}

extern "C" void Destructor()
{
    std::cout << "Input Module Destructor" << std::endl;
    SDL_Quit();
}

extern "C" void Add_Controll_Set(std::string Name)
{
    std::cout << "Add_Controll_Set" << std::endl;
    Control_Set_List.Add_Node(Name);
}

extern "C" void Set_Controll_Set(std::string Name)
{
    std::cout << "Set_Controll_Set" << std::endl;
    Control_Set_List.Find(Name);
}

extern "C" void Update(std::string Controll_Set)
{
    std::cout << "Update" << std::endl;
    Control_Set_List.Find(Controll_Set);
    
    Control_Set_List.Current->Value.Update(&e);
}

// Mouse Functions
extern "C" void Set_Mouse_Left_Down(Digital_Function Foo)
{
    std::cout << "Set_Mouse_Left_Down" << std::endl;
    Control_Set_List.Current->Value.M.Set_Mouse_Left_Down(Foo);
}

extern "C" void Set_Mouse_Left_Up(Digital_Function Foo)
{
    std::cout << "Set_Mouse_Left_Up" << std::endl;
    Control_Set_List.Current->Value.M.Set_Mouse_Left_Up(Foo);
}

extern "C" void Set_Mouse_Middle_Down(Digital_Function Foo)
{
    std::cout << "Set_Mouse_Middle_Down" << std::endl;
    Control_Set_List.Current->Value.M.Set_Mouse_Middle_Down(Foo);
}

extern "C" void Set_Mouse_Middle_Up(Digital_Function Foo)
{
    std::cout << "Set_Mouse_Middle_Up" << std::endl;
    Control_Set_List.Current->Value.M.Set_Mouse_Middle_Up(Foo);
}

extern "C" void Set_Mouse_Right_Down(Digital_Function Foo)
{
    std::cout << "Set_Mouse_Right_Down" << std::endl;
    Control_Set_List.Current->Value.M.Set_Mouse_Right_Down(Foo);
}

extern "C" void Set_Mouse_Right_Up(Digital_Function Foo)
{
    std::cout << "Set_Mouse_Right_Up" << std::endl;
    Control_Set_List.Current->Value.M.Set_Mouse_Right_Up(Foo);
}

extern "C" void Set_Mouse_X(Analog_Function Foo)
{
    std::cout << "Set_Mouse_X" << std::endl;
    Control_Set_List.Current->Value.M.Set_Mouse_X(Foo);
}

extern "C" void Set_Mouse_Y(Analog_Function Foo)
{
    std::cout << "Set_Mouse_Y" << std::endl;
    Control_Set_List.Current->Value.M.Set_Mouse_Y(Foo);
}

// Keyboard Functions
extern "C" void Set_Key_Down(Key_Code Key, Digital_Function Foo)
{
    std::cout << "Set_Key_Down" << std::endl;
    Control_Set_List.Current->Value.KB.Set_Key_Down(Key, Foo);
}

extern "C" void Set_Key_Up(Key_Code Key, Digital_Function Foo)
{
    std::cout << "Set_Key_Up" << std::endl;
    Control_Set_List.Current->Value.KB.Set_Key_Up(Key, Foo);
}

// Controller Functions
extern "C" void Set_Joy_Digital(Digital_Button Button, Digital_Function Function)
{
    std::cout << "Set_Joy_Digital" << std::endl;
    Control_Set_List.Current->Value.Joy.Set_Joy_Digital(Button, Function);
}

extern "C" void Set_Joy_Analog(Analog_Button Button, Analog_Function Function)
{
    std::cout << "Set_Joy_Analog" << std::endl;
    Control_Set_List.Current->Value.Joy.Set_Joy_Analog(Button, Function);
}
