#include "Appeal.h"

#include "Modules/Standard.h"

#include "Modules/Audio.h"
#include "Modules/Net_Client.h"
#include "Modules/Input.h"
#include "Modules/Renderer.h"

#include "Actor.h"

//include "Modules/Net_Server.h"
bool Quit = false;

void Quit_App()
{
    std::cout << "Quit" << std::endl;
    Quit = true;
}

void Click()
{
    std::cout << "Click" << std::endl;
}


int main(int argc, char* argv[])
{
    Appeal App;
    App.Add_Module("Standard", Standard::Interpreter);
    App.Add_Module("Audio", Audio::Interpreter);
    App.Add_Module("Net_Client", Net_Client::Interpreter);
    App.Add_Module("Input", Input::Interpreter);
    App.Add_Module("Renderer", Renderer::Interpreter);
   
    
    //Config calls init for each module and sets the plugin file for each module
    App.Run("Config");
    
    App.Run("Test_Audio");
    App.Run("Test_Renderer");

    App.Run("Test_Input");
    Input::Set_Mouse_Left_Down(Click);
    Input::Set_Key_Down(Input::Key_Escape, Quit_App);
    Input::Set_Key_Down(Input::Key_Num_0, Audio::Stop);
    Input::Set_Key_Down(Input::Key_Num_1, Audio::Play);
    Input::Set_Key_Down(Input::Key_Num_2, Audio::Next);
    Input::Set_Key_Down(Input::Key_Num_3, Audio::Back);
    Input::Set_Key_Down(Input::Key_Num_4, Audio::Mute);
    Input::Set_Key_Down(Input::Key_Num_5, Audio::UnMute);
    
    Actor::Init();

    std::string Menu;
    
    while (Quit == false)
    {
        Input::Update("Default");
        Renderer::Render();
    }

    return 0;
}
