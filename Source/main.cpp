#include "Appeal.h"

#include "Modules/Standard.h"

#include "Modules/Audio.h"
#include "Modules/Graphics.h"
#include "Modules/Net_Client.h"

//include "Modules/Net_Server.h"
//#include "Modules/Controller.h"

#include "File_Data_Source.h"
//#include <iostream>

int main(int argc, char* argv[])
{
    Appeal App;
    App.Add_Module("Standard", Standard::Interpreter);
    App.Add_Module("Audio", Audio::Interpreter);
    App.Add_Module("Graphics", Graphics::Interpreter);
    
    App.Add_Module("Net_Client", Net_Client::Interpreter);
   
    //Config calls init for each module and sets the plugin file for each module
    File_Data_Source Config("../Resources/Appeal/Config.Appeal");
    App.Data_Manager.Add_Source("Config", &Config);
   
    
    App.Run();
    /*
    std::string Message = Net_Client::Receive();
    std::cout << Message << std::endl;
    */

    //Keep the console open
    std::cin.get();
    
    return 0;
}