#include <SDL2/SDL.h>
#include <SDL2/SDL_net.h>
#include <iostream>
#include <string>

IPaddress ip;
TCPsocket client;

extern "C" void Constructor(const char* name)
{
    std::cout << "Net Client Module Constructor: " << name << '\n';

    if (SDLNet_Init() < 0) 
    {
        std::cerr << "SDLNet Initialization failed: " << SDLNet_GetError() << std::endl;
    }
}

extern "C" int Connect(std::string IP, int Port)
{
    std::cout << "Connect: " << IP << " " << Port << std::endl;

    if (SDLNet_ResolveHost(&ip, IP.c_str(), Port) < 0) 
    { // Connect to localhost
        std::cerr << "Failed to resolve host: " << SDLNet_GetError() << std::endl;
        return -1;
    }

    client = SDLNet_TCP_Open(&ip);
    if (!client) 
    {
        std::cerr << "Failed to open connection: " << SDLNet_GetError() << std::endl;
        return -1;
    }
    return 0;
}

extern "C" void Send(std::string Data)
{
    if(client == NULL)
    {
        std::cerr << "Client is not connected" << std::endl;
    }
    else
    {
        std::cout << "Sending: " << Data << std::endl;
        SDLNet_TCP_Send(client, Data.c_str(), Data.length() + 1);
    }
}

extern "C" std::string Receive()
{
    char buffer[512];
    if (SDLNet_TCP_Recv(client, buffer, 512) > 0) 
    {
        std::string Data = buffer;
        return Data;
    }
    return "";
}
    
//Run an Appeal Script over the network
extern "C" bool Run(std::string File_Name)
{
    std::string Command = "Run " + File_Name;
    Send(Command);
    return true;
}

//Download a file from the server
extern "C" bool Download(std::string File_Name)
{
    std::string Command = "Download " + File_Name;
    Send(Command);
    return true;
}

extern "C" void Disconnect()
{
    if((client != NULL))
    {
        Send("Done");
        SDLNet_TCP_Close(client);
        client = nullptr;
        std::cout << "Disconnect" << std::endl;
    }
}

extern "C" void Destructor()
{
    std::cout << "Net Client Module Destructor" << '\n';
    Disconnect();
    SDLNet_Quit();
    SDL_Quit();
}   