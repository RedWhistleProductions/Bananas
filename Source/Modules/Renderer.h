#pragma once
#include "Plugin.h"
#include "../Data_Source.h"

namespace Renderer
{
    Plugin Module;

    //Window Functions
    std::string (*Update)();
    void (*Add_Full_Screen_Window)(std::string Name, int Monitor_Num);
    void (*Add_Window)(std::string Name, std::string Title, int Monitor_Num);
    void (*Delete_Window)(std::string Name);
    void (*Hide)(std::string Name);
    void (*Set_Focus)(std::string Name);
    void (*Set_Monitor)(std::string Name, int N);
    void (*Show)(std::string Name);

    //View Port Functions
    void (*Set_View_Port)(std::string Window_Name, int x, int y, int w, int h);
    void (*Set_Perspective)(std::string Window_Name, float Fovy, float Near, float Far);
    void (*Set_Ortho)(std::string Window_Name, float Left, float Right, float Bottom, float Top, float Near, float Far);
    
    //Camera Functions
    void (*Set_Camera_Location)(std::string Window_Name, float X, float Y, float Z);
    void (*Set_Camera_Orientation)(std::string Window_Name, float Yaw, float Pitch, float Roll);
    void (*Move_Camera)(std::string Window_Name, float X, float Y, float Z);
    void (*Rotate_Camera)(std::string Window_Name, float Yaw, float Pitch, float Roll);
    void (*Update_Camera)(std::string Window_Name);

    //Renderer Functions
    void (*Set_FPS)(int Frames);
    void (*Load_Shader)(std::string Name, std::string Full_Path);
    void (*Render)();

    //Asset Functions
    void (*Load_Asset)(std::string Name, std::string Full_Path);
    void (*Move_Asset)(std::string Name, float X, float Y, float Z);
    void (*Rotate_Asset)(std::string Name, float Yaw, float Pitch, float Roll);
    void (*Set_Texture)(std::string Name, std::string Texture_Name);
    void (*Set_Shader)(std::string Name, std::string Shader_Name);
    void (*Set_Location)(std::string Name, float X, float Y, float Z);
    void (*Set_Orientation)(std::string Name, float Yaw, float Pitch, float Roll);
    void (*Set_Scale)(std::string Name, float X, float Y, float Z);

    // Texture Functions
    void (*Load_Texture)(std::string Name, std::string Full_Path);
    
    void Init(std::string Name)
    {
        Module.Load("Renderer", Name);
        
        //Assign each function pointer to the corresponding function in the module
        //Module.Assign("Function_Name", Function_Name);
        
        //Window Functions
        Module.Assign("Update", Update);
        Module.Assign("Add_Full_Screen_Window", Add_Full_Screen_Window);
        Module.Assign("Add_Window", Add_Window);
        Module.Assign("Delete_Window", Delete_Window);
        Module.Assign("Hide", Hide);
        Module.Assign("Set_Focus", Set_Focus);
        Module.Assign("Set_Monitor", Set_Monitor);
        Module.Assign("Show", Show);
        
        //View Port Functions
        Module.Assign("Set_View_Port", Set_View_Port);
        Module.Assign("Set_Perspective", Set_Perspective);
        Module.Assign("Set_Ortho", Set_Ortho);

        //Camera Functions
        Module.Assign("Set_Camera_Location", Set_Camera_Location);
        Module.Assign("Set_Camera_Orientation", Set_Camera_Orientation);
        Module.Assign("Move_Camera", Move_Camera);
        Module.Assign("Rotate_Camera", Rotate_Camera);
        Module.Assign("Update_Camera", Update_Camera);

        //Renderer Functions
        Module.Assign("Set_FPS", Set_FPS);
        Module.Assign("Load_Shader", Load_Shader);
        Module.Assign("Render", Render);

        //Asset Functions
        Module.Assign("Load_Asset", Load_Asset);
        Module.Assign("Move_Asset", Move_Asset);
        Module.Assign("Rotate_Asset", Rotate_Asset);
        Module.Assign("Set_Texture", Set_Texture);
        Module.Assign("Set_Shader", Set_Shader);
        Module.Assign("Set_Location", Set_Location);
        Module.Assign("Set_Orientation", Set_Orientation);
        Module.Assign("Set_Scale", Set_Scale);

        //Texture Functions
        Module.Assign("Load_Texture", Load_Texture);
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
        else if(Command == "Update")
        {
            return Update();
        }
// Window Functions        
        else if(Command == "Add_Full_Screen_Window")
        {
            std::string Name;
            int Monitor_Num;
            *Data >> Name;
            *Data >> Monitor_Num;
            Add_Full_Screen_Window(Name, Monitor_Num);
            return "";
        }
        else if(Command == "Add_Window")
        {
            std::string Name;
            std::string Title;
            int Monitor_Num;
            *Data >> Name; 
            *Data >> Title; 
            *Data >> Monitor_Num;
            Add_Window(Name, Title, Monitor_Num);
            return "";
        }
        else if(Command == "Delete_Window")
        {
            std::string Name;
            *Data >> Name;
            Delete_Window(Name);
            return "";
        }
        else if(Command == "Hide")
        {
            std::string Name;
            *Data >> Name;
            Hide(Name);
            return "";
        }
        else if(Command == "Set_Focus")
        {
            std::string Name;
            *Data >> Name;
            Set_Focus(Name);
            return "";
        }
        else if(Command == "Set_Monitor")
        {
            std::string Name;
            int N;
            *Data >> Name;
            *Data >> N;
            Set_Monitor(Name, N);
            return "";
        }
        else if(Command == "Show")
        {
            std::string Name;
            *Data >> Name;
            Show(Name);
            return "";
        }
// View Port Functions
        else if(Command == "Set_View_Port")
        {
            std::string Window_Name;
            int x;
            int y;
            int w;
            int h;
            *Data >> Window_Name;
            *Data >> x;
            *Data >> y;
            *Data >> w;
            *Data >> h;
            Set_View_Port(Window_Name, x, y, w, h);
            return "";
        }
        else if(Command == "Set_Perspective")
        {
            std::string Window_Name;
            float Fovy;
            float Near;
            float Far;
            *Data >> Window_Name;
            *Data >> Fovy;
            *Data >> Near;
            *Data >> Far;
            Set_Perspective(Window_Name, Fovy, Near, Far);
            return "";
        }
        else if(Command == "Set_Ortho")
        {
            std::string Window_Name;
            float Left;
            float Right;
            float Bottom;
            float Top;
            float Near;
            float Far;
            *Data >> Window_Name;
            *Data >> Left;
            *Data >> Right;
            *Data >> Bottom;
            *Data >> Top;
            *Data >> Near;
            *Data >> Far;
            Set_Ortho(Window_Name, Left, Right, Bottom, Top, Near, Far);
            return "";
        }
// Camera Functions
        else if(Command == "Set_Camera_Location")
        {
            std::string Window_Name;
            float X;
            float Y;
            float Z;
            *Data >> Window_Name;
            *Data >> X;
            *Data >> Y;
            *Data >> Z;
            Set_Camera_Location(Window_Name, X, Y, Z);
            return "";
        }
        else if(Command == "Set_Camera_Orientation")
        {
            std::string Window_Name;
            float Yaw;
            float Pitch;
            float Roll;
            *Data >> Window_Name;
            *Data >> Yaw;
            *Data >> Pitch;
            *Data >> Roll;
            Set_Camera_Orientation(Window_Name, Yaw, Pitch, Roll);
            return "";
        }
        else if(Command == "Move_Camera")
        {
            std::string Window_Name;
            float X;
            float Y;
            float Z;
            *Data >> Window_Name;
            *Data >> X;
            *Data >> Y;
            *Data >> Z;
            Move_Camera(Window_Name, X, Y, Z);
            return "";
        }
        else if(Command == "Update_Camera")
        {
            std::string Window_Name;
            *Data >> Window_Name;
            Update_Camera(Window_Name);
            return "";
        }
// Renderer Functions
        else if(Command == "Set_FPS")
        {
            int Frames;
            *Data >> Frames;
            Set_FPS(Frames);
            return "";
        }
        else if(Command == "Load_Shader")
        {
            std::string Name;
            std::string Full_Path;
            *Data >> Name;
            *Data >> Full_Path;
            Load_Shader(Name, Full_Path);
            return "";
        }
        else if(Command == "Render")
        {
            Render();
            return "";
        }

// Asset Functions
        else if(Command == "Load_Asset")
        {
            std::string Name;
            std::string Full_Path;
            *Data >> Name;
            *Data >> Full_Path;
            Load_Asset(Name, Full_Path);
            return "";
        }
        else if(Command == "Set_Texture")
        {
            std::string Name;
            std::string Texture_Name;
            *Data >> Name;
            *Data >> Texture_Name;
            Set_Texture(Name, Texture_Name);
            return "";
        }
        else if(Command == "Set_Shader")
        {
            std::string Name;
            std::string Shader_Name;
            *Data >> Name;
            *Data >> Shader_Name;
            Set_Shader(Name, Shader_Name);
            return "";
        }
        else if(Command == "Set_Location")
        {
            std::string Name;
            float X;
            float Y;
            float Z;
            *Data >> Name;
            *Data >> X;
            *Data >> Y;
            *Data >> Z;
            Set_Location(Name, X, Y, Z);
            return "";
        }
        else if(Command == "Set_Orientation")
        {
            std::string Name;
            float Yaw;
            float Pitch;
            float Roll;
            *Data >> Name;
            *Data >> Yaw;
            *Data >> Pitch;
            *Data >> Roll;
            Set_Orientation(Name, Yaw, Pitch, Roll);
            return "";
        }
        else if(Command == "Set_Scale")
        {
            std::string Name;
            float X;
            float Y;
            float Z;
            *Data >> Name;
            *Data >> X;
            *Data >> Y;
            *Data >> Z;
            Set_Scale(Name, X, Y, Z);
            return "";
        }
        else if(Command == "Move_Asset")
        {
            std::string Name;
            float X;
            float Y;
            float Z;
            *Data >> Name;
            *Data >> X;
            *Data >> Y;
            *Data >> Z;
            Move_Asset(Name, X, Y, Z);
            return "";
        }
        else if(Command == "Rotate_Asset")
        {
            std::string Name;
            float Yaw;
            float Pitch;
            float Roll;
            *Data >> Name;
            *Data >> Yaw;
            *Data >> Pitch;
            *Data >> Roll;
            Rotate_Asset(Name, Yaw, Pitch, Roll);
            return "";
        }
        else if(Command == "Rotate_Asset")
        {
            std::string Name;
            float Yaw;
            float Pitch;
            float Roll;
            *Data >> Name;
            *Data >> Yaw;
            *Data >> Pitch;
            *Data >> Roll;
            Rotate_Asset(Name, Yaw, Pitch, Roll);
            return "";
        }
// Texture Functions
        else if(Command == "Load_Texture")
        {
            std::string Name;
            std::string Full_Path;
            *Data >> Name;
            *Data >> Full_Path;
            Load_Texture(Name, Full_Path);
            return "";
        }
        
        return "Error: " + Command + " not found in Window_Manager Dictionary";
    }
    
}