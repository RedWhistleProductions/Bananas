#pragma once
#include <string>
#include "Modules/Renderer.h"
#include "Modules/Input.h"

namespace Actor
{
    std::string Asset_Name;
    int X, Y, Z;
    int Width, Height, Depth;
    int Turn, Tilt, Pitch;
    int Speed;

    void Strafe_Left()
    {
        X -= Speed;
        Renderer::Move_Asset(Asset_Name, X, Y, Z);
    }

    void Strafe_Right()
    {
        X += Speed;
        Renderer::Move_Asset(Asset_Name, X, Y, Z);
    }

    void Init()
    {
        Asset_Name = "Cube";
        X = 0;
        Y = 0;
        Z = 0;
        Width = 1;
        Height = 1;
        Depth = 1;
        Turn = 0;
        Tilt = 0;
        Pitch = 0;
        Speed = 1;

        Input::Set_Key_Down(Input::Key_A, Strafe_Left);
        Input::Set_Key_Down(Input::Key_D, Strafe_Right);
    }


}

