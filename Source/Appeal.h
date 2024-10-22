#pragma once

#include "FileIO.h"
#include "Named_List.h"
#include "Data_Source_Manager.h"


using Appeal_Dictionary= void (*)(Data_Source *Data);

class Appeal
{
    public:
    bool DEBUG = false;
    Data_Source_Manager Data_Manager;

    void Add_Module(std::string Name, void (*Interpreter)(Data_Source *Data));
    void Run();
    

    private:
    bool Done = false;  
    std::string Command;
    Named_List<Appeal_Dictionary> Dictionary_List;
    void (*Interpreter)(Data_Source *Data);
    
    int Command_Error = 0;
    int Command_Error_Limit = 3;
};

void Appeal::Add_Module(std::string Name, void (*Interpreter)(Data_Source *Data))
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
        Data_Manager >> Command;
        if(DEBUG){std::cout << "Command: " << Command << std::endl;}
        

        if(Command == "Done")
        {
            Done = true;
        }
        else if( Command == "Print")
        {
            std::string Str;
            Data_Manager >> Str;
            std::cout << Str << std::endl;
        }
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
