#include "Appeal.h"

#include "Modules/Standard.h"

#include "Modules/Audio.h"
#include "Modules/Net_Client.h"
#include "Modules/Input.h"
#include "Modules/Renderer.h"

//include "Modules/Net_Server.h"

#include "File_Data_Source.h"


int main(int argc, char* argv[])
{
    Appeal App;
    App.Add_Module("Standard", Standard::Interpreter);
    App.Add_Module("Audio", Audio::Interpreter);
    App.Add_Module("Net_Client", Net_Client::Interpreter);
    App.Add_Module("Input", Input::Interpreter);
    App.Add_Module("Renderer", Renderer::Interpreter);
   
    
    //Config calls init for each module and sets the plugin file for each module
    App.Add_Script("Config");
    App.Run("Config");
    //App.Add_Script("Test_Audio");
    //App.Run("Test_Audio");
    App.Add_Script("Test_Inuput");
    App.Run("Test_Input");
    
    std::string Menu;
    bool Quit = false;
    while (Quit == false)
    {
        Renderer::Render();
        Menu = Renderer::Update();
        if(Menu == "Quit")
        {
            Quit = true;
        }
        else if (Menu == "1")
        {
            Audio::Next();
        }
        else if(Menu == "2")
        {
            Audio::Back();
        }
        
    } 
    
    return 0;
}
