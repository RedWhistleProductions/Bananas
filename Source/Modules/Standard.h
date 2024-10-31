#pragma once
#include "Plugin.h"
#include "../Data_Source.h"
#include "../File_Data_Source.h"


/*
    This Module is for the Standard Library
    Ironically, it is not standard as it doesn't use a plugin file
*/

namespace Standard
{
    Named_List<File_Data_Source> Scripts_List;

    void Init(std::string Name)
    {

        void (*Init)(std::string);
        //Assign each function pointer to the corresponding function in the module
        //Module.Assign("Function_Name", Function_Name);
        
    }

    std::string Interpreter(Data_Source *Data)
    {
        std::string Command;
        *Data >> Command;

        if(Command == "Load")
        {
            std::string Name;
            *Data >> Name;
            Scripts_List.Add_Node(Name);
            Scripts_List.Current->Value.Load(Name);
            return "";
        }
        else if( Command == "Print")
        {
            std::string Str;
            *Data >> Str;
            std::cout << Str << std::endl;
            return "";
        }
        else if( Command == "Done")
        {
            
            return "Done";
        }

        return Command;
    }
    
}