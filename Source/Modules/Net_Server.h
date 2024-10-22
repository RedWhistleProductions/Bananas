#pragma once
#include "Plugin.h"

namespace Network
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

    void Interpreter(FileIO *Script)
    {
        std::string Command;
        *Script >> Command;

        if(Command == "Init")
        {
            std::string Name;
            *Script >> Name;
            Init(Name);
        }
        // Add an else if statement for each function in the module
    }
    
}