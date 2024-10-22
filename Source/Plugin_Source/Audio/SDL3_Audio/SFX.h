/**********************************
* Bananas Game Engine (TM)        *
* Copyright (C) Billy Snyder 2024 *
**********************************/

#pragma once

#ifdef __MINGW32__
	///Windows
	#include "SDL_mixer.h"
#endif

#ifdef __linux__
    /// linux
	#include "SDL2/SDL_mixer.h"
#endif

#ifdef __APPLE__
    /// OSX
#endif

#include <string>
#include <iostream>

extern std::string Resources;

class SFX
{

public:
    Mix_Chunk *Effect;
    int Channel;
    std::string Name;
    std::string Path;
    SFX();
    void Load(std::string name);
    void Play();
    void Play(int);
    void SetChannel(int);
};

SFX::SFX()
{
    Effect = NULL;
    Path =  Resources + "/SFX/";
}


void SFX::Load(std::string File)
{
    Name = File;
    File = Path + Name;
    if(Effect != NULL)Mix_FreeChunk(Effect);
    Effect = Mix_LoadWAV(File.c_str() );
    /*
        Set Channel to -1 sets Channel to what ever Channel is avaiable
        then store that Channel by using Channel = Mix_PlayChannel( Channel, Effect, 0 );
    */
    Channel =  -1;

    //For Debugging
    if(Effect == NULL){
		std::cout << "File did not load"<< std::endl
			<< "Path = " << File << std::endl;
	}
}

void SFX::Play()
{
    Channel = Mix_PlayChannel( Channel, Effect, 0 );
}

void SFX::SetChannel(int X)
{
    Channel = X;
}

void SFX::Play(int X)
{
    Channel = Mix_PlayChannel( Channel, Effect, X );
}



