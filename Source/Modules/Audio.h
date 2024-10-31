#pragma once

#include "Plugin.h"
#include "../Data_Source.h"

namespace Audio
{
    Plugin Module;

    void (*Back)();
    void (*Load_Play_List)(std::string Play_List);
    void (*Load_SFX)(std::string Name, std::string SFX_File);
    void (*Load_Song)(std::string Name, std::string Music_File);
    void (*Mute)();
    void (*Next)();
    void (*Play)();
    void (*Play_SFX)();
    void (*Play_SFX_Name)(std::string Name);
    void (*Play_Song)(std::string Name);
    void (*Play_Track)(int Track);
    void (*Set_Paths)(std::string Resources);
    void (*Stop)();
    void (*UnMute)();

    void Init(std::string Name)
    {
        Module.Load("Audio", Name);
        Module.Assign("Back", Back);
        Module.Assign("Load_Play_List", Load_Play_List);
        Module.Assign("Load_SFX", Load_SFX);
        Module.Assign("Load_Song", Load_Song);
        Module.Assign("Mute", Mute);
        Module.Assign("Next", Next);
        Module.Assign("Play", Play);
        Module.Assign("Play_SFX", Play_SFX);
        Module.Assign("Play_SFX_Name", Play_SFX_Name);
        Module.Assign("Play_Song", Play_Song);
        Module.Assign("Play_Track", Play_Track);             
        Module.Assign("Set_Paths", Set_Paths);
        Module.Assign("Stop", Stop);
        Module.Assign("UnMute", UnMute);
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

        else if(Command == "Back")
        {
            Back();
            return "";
        }

        else if(Command == "Load_Play_List")
        {
            *Data >> Command;
            Load_Play_List(Command);
            return "";
        }

        else if(Command == "Load_SFX")
        {
            std::string Name;
            std::string SFX_File;
            *Data >> Name;
            *Data >> SFX_File;
            Load_SFX(Name, SFX_File);
            return "";
        }

        else if(Command == "Load_Song")
        {
            std::string Name;
            std::string Music_File;
            *Data >> Name;
            *Data >> Music_File;
            Load_Song(Name, Music_File);
            return "";
        }

        else if(Command == "Mute")
        {
            Mute();
            return "";
        }

        else if(Command == "Next")
        {
            Next();
            return "";
        }

        else if(Command == "Play")
        {
            Play();
            return "";
        }

        else if(Command == "Play_SFX")
        {
            Play_SFX();
            return "";
        }

        else if(Command == "Play_SFX_Name")
        {
            std::string Name;
            *Data >> Name;
            Play_SFX_Name(Name);
            return "";
        }

        else if(Command == "Play_Song")
        {
            std::string Name;
            *Data >> Name;
            Play_Song(Name);
            return "";
        }

        else if(Command == "Play_Track")
        {
            int Track;
            *Data >> Track;
            Play_Track(Track);
            return "";
        }

        else if(Command == "Set_Paths")
        {
            std::string Resources;
            *Data >> Resources;
            Set_Paths(Resources);
            return "";
        }

        else if(Command == "Stop")
        {
            Stop();
            return "";
        }

        else if(Command == "UnMute")
        {
            UnMute();
            return "";
        }

        return "Error: "  + Command + " not found in Audio Dictionary";
    }   
}