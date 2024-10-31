#pragma once
#include "Plugin.h"
#include "../Data_Source.h"

namespace Graphics
{
    Plugin Module;

    void(*Load_Image)(std::string Name, std::string Image_File);
    void(*Paste_Image)(std::string Name, int x, int y);

    void(*Load_Model)(std::string Name, std::string Model_File);
    void(*Paste_Model)(std::string Name, int x, int y, int z);

    void (*Load_Scene)(std::string Name, std::string Scene_File);
    void (*Paste_Scene)(std::string Name);
    void(*Render)();

    void Init(std::string Name)
    {     
        Module.Load("Graphics", Name);
        
        Module.Assign("Load_Image", Load_Image);
        Module.Assign("Paste_Image", Paste_Image);
        Module.Assign("Load_Model", Load_Model);
        Module.Assign("Paste_Model", Paste_Model);
        Module.Assign("Load_Scene", Load_Scene);
        Module.Assign("Paste_Scene", Paste_Scene);
        Module.Assign("Render", Render);
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
        else if(Command == "Load_Image")
        {
            std::string Name;
            std::string Image_File;
            *Data >> Name;
            *Data >> Image_File;
            Load_Image(Name, Image_File);
            return "";
        }
        else if(Command == "Paste_Image")
        {
            std::string Name;
            int x, y;
            *Data >> Name;
            *Data >> x;
            *Data >> y;
            Paste_Image(Name, x, y);
            return "";
        }
        else if(Command == "Load_Model")
        {
            std::string Name;
            std::string Model_File;
            *Data >> Name;
            *Data >> Model_File;
            Load_Model(Name, Model_File);
            return "";
        }
        else if(Command == "Paste_Model")
        {
            std::string Name;
            int x, y, z;
            *Data >> Name;
            *Data >> x;
            *Data >> y;
            *Data >> z;
            Paste_Model(Name, x, y, z);
            return "";
        }
        else if(Command == "Load_Scene")
        {
            std::string Name;
            std::string Scene_File;
            *Data >> Name;
            *Data >> Scene_File;
            Load_Scene(Name, Scene_File);
            return "";
        }
        else if(Command == "Paste_Scene")
        {
            std::string Name;
            *Data >> Name;
            Paste_Scene(Name);
            return "";
        }
        else if(Command == "Render")
        {
            Render();
            return "";
        }

        return "Error: " + Command + " is not found in the Graphics Dictionary";
    }
}