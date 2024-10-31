#pragma once
#include "Plugin.h"
#include "../Data_Source.h"

namespace Net_Client
{
    Plugin Module;

    //Create a function pointer for each function in the module
    int(*Connect)(std::string IP, int Port);
    void(*Disconnect)();

    void(*Send)(std::string Message);
    std::string(*Receive)();
    
    //Run an Appeal Script over the network
    bool(*Run)(std::string File_Name);

    //Download a file from the server
    bool(*Download)(std::string File_Name);
    
    void Init(std::string Name)
    {
        //Replace "New" with the name of the module
        Module.Load("Net_Client", Name);
        
        //Assign each function pointer to the corresponding function in the module
        //Module.Assign("Function_Name", Function_Name);
        Module.Assign("Connect", Connect);
        Module.Assign("Disconnect", Disconnect);
        Module.Assign("Send", Send);
        Module.Assign("Receive", Receive);
        Module.Assign("Run", Run);
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
        else if(Command == "Connect")
        {
            std::string IP;
            int Port;
            *Data >> IP;
            *Data >> Port;
            if(Connect(IP, Port) == 0)
            {
                std::cout << "Connected to " << IP << " on port " << Port << std::endl;
            }
            else
            {
                std::cout << "Failed to connect to " << IP << " on port " << Port << std::endl;
            }
            return "";
        }
        else if(Command == "Disconnect")
        {
            Disconnect();
            return "";
        }
        else if(Command == "Send")
        {
            std::string Message;
            *Data >> Message;
            Send(Message);
            return "";
        }
        else if(Command == "Receive")
        {
            std::string Message = Receive();
            std::cout << Message << std::endl;
            return "";
        }
        return "Error: "  + Command + " not found in Net_Client Dictionary";
    } 
}