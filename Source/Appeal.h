#pragma once

#include "FileIO.h"
#include "Named_List.h"
#include "Data_Source_Manager.h"


using Appeal_Dictionary= std::string (*)(Data_Source *Data);

class Appeal
{
    public:
    Data_Source_Manager Data_Manager;

    void Add_Module(std::string Name, std::string (*Interpreter)(Data_Source *Data));
    void Run();
    
    private:
    bool Done = false;  
    std::string Command;
    Named_List<Appeal_Dictionary> Dictionary_List;
    std::string (*Interpreter)(Data_Source *Data);
    
    int Command_Error = 0;
    int Command_Error_Limit = 3;
};

void Appeal::Add_Module(std::string Name, std::string (*Interpreter)(Data_Source *Data))
{
    Dictionary_List.Add_Node(Name, Interpreter);
}

void Appeal::Run()
{
    Done = false;
    if(Data_Manager.Data_Sources.Nodes == 0)
    {
        std::cout << "Error: No Data Sources" << std::endl;
        Done = true;
        return;
    }
    
    while(not Done)
    {
        //Set the Interpreter to the Standard Module
        Interpreter = Dictionary_List.Start->Value;
        
        /*
            If the next command is in the Standard dictionary it will be executed and
            the Interpreter will return "". Otherwise the Interpreter will return the Command
        */

        Command = Interpreter(Data_Manager.Data_Sources.Current->Value);
        if(Command != "")
        {
        
            //If the Command is "Done" the program will exit
            if(Command == "Done")
            {
                Done = true;
            }
            //Check if the Command is the name of a Dictionary
            else if(Dictionary_List.Find(Command))
            {
                Interpreter = Dictionary_List.Current->Value;
                Interpreter(Data_Manager.Data_Sources.Current->Value);
            }
            else
            {
                std::cout << "Command Not Found: " << Command << std::endl;
                Command_Error++;
                if(Command_Error > Command_Error_Limit)
                {
                    Done = true;
                }
            }
        }
    }
}
