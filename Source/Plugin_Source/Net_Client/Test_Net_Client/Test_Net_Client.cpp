#include <iostream>
#include <string>

extern "C" void Constructor(const char* name)
{
    std::cout << "Net Client Module Constructor: " << name << '\n';
}

extern "C" void Destructor()
{
    std::cout << "Net Client Module Destructor" << '\n';
}

extern "C" int Connect(std::string IP, int Port)
{
    std::cout << "Connect: " << IP << " " << Port << std::endl;
    return 0;
}

extern "C" void Disconnect()
{
    std::cout << "Disconnect" << std::endl;
}

extern "C" void Send(std::string Message)
{
    std::cout << "Send: " << Message << std::endl;
}

extern "C" std::string Receive()
{
    std::string Message = "Receive: Hello";
    return Message;
}
    
    //Run an Appeal Script over the network
extern "C" bool Run(std::string File_Name)
{
    std::cout << "Run: " << File_Name << std::endl;
    return true;
}
    