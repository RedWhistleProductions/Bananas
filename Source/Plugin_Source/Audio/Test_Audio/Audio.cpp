/**********************************
* Bananas Game Engine (TM)        *
* Copyright (C) Billy Snyder 2024 *
**********************************/

#include <string>
#include <iostream>


extern "C" void Set_Paths(std::string Path_of_Resources)
{
	std::cout << "Setting Paths" << std::endl;
}

extern "C" void Constructor()
{
	std::cout << "Audio Module Constructor Called" << std::endl;
}


extern "C" void Destructor()
{
	std::cout << "Audio Module Destructor Called" << std::endl;
}

extern "C" void Play()
{
	std::cout << "Playing" << std::endl;
}

extern "C" void Play_Track(int Track)
{
	std::cout << "Playing Track " << Track << std::endl;
}

extern "C" void Play_Song(std::string Name)
{
	std::cout << "Playing Song " << Name << std::endl;
}


extern "C" void Load_Song(std::string Name, std::string Music_File)
{
	std::cout << "Loading Song " << Name << " From " << Music_File << std::endl;
}

extern "C" void Stop()
{
	std::cout << "Stopping" << std::endl;
}

extern "C" void Next()
{
	std::cout << "Next" << std::endl;
}

extern "C" void Back()
{
	std::cout << "Back" << std::endl;
}

extern "C" void Load_Play_List(std::string Play_List)
{
	std::cout << "Loading Play List " << Play_List << std::endl;
}

extern "C" void Load_SFX(std::string Name, std::string SFX_File)
{
	std::cout << "Loading SFX " << Name << " From " << SFX_File << std::endl;
}

extern "C" void Play_SFX()
{
	std::cout << "Playing SFX" << std::endl;
}

extern "C" void Play_SFX_Name(std::string Name)
{
	std::cout << "Playing SFX " << Name << std::endl;
}

extern "C" void Mute()
{
	std::cout << "Muting" << std::endl;
}

extern "C" void UnMute()
{
	std::cout << "UnMuting" << std::endl;
}
