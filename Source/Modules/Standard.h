#pragma once
#include "Plugin.h"
#include "../Data_Source.h"
#include "../File_Data_Source.h"


/*
    This Module is for the Standard Library
    Ironically, it is not standard as it doesn't use a plugin file
*/
extern Appeal App;

namespace Standard
{
    void Init(std::string Name)
    {       
        //Assign each function pointer to the corresponding function in the module
        //Module.Assign("Function_Name", Function_Name);   
    }

    std::string Interpreter(Data_Source *Data)
    {
        std::string Command;
        *Data >> Command;

        if( Command == "Print")
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