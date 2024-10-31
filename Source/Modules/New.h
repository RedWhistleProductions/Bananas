#pragma once
#include "Plugin.h"
#include "../Data_Source.h"

//This is a template for creating a new module

//Replace "New" with the name of the module
namespace New
{
    Plugin Module;

    //Create a function pointer for each function in the module

    //void(*Function_Name)(Function_Arguments);
    
    void Init(std::string Name)
    {
        //Replace "New" with the name of the module
        Module.Load("New", Name);
        
        //Assign each function pointer to the corresponding function in the module
        //Module.Assign("Function_Name", Function_Name);
        
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
        // Add an else if statement for each function in the module

        return "Error: " + Command + " not found in New Dictionary";
    }
    
}