/**********************************
* Bananas Game Engine (TM)        *
* Copyright (C) Billy Snyder 2024 *
**********************************/

#include <string>
#include <iostream>


extern "C" void Constructor()
{
	std::cout << "Graphics Module Constructor Called" << std::endl;
}


extern "C" void Destructor()
{
	std::cout << "Graphics Module Destructor Called" << std::endl;
}

extern "C" void Load_Image(std::string Name, std::string Image_File)
{
    std::cout << "Loading Image: " << Name << " From File: " << Image_File << std::endl;
}

extern "C" void Paste_Image(std::string Name, int x, int y)
{
    std::cout << "Pasting Image: " << Name << " At: " << x << ", " << y << std::endl;
}

extern "C" void Load_Model(std::string Name, std::string Model_File)
{
    std::cout << "Loading Model: " << Name << " From File: " << Model_File << std::endl;
}

extern "C" void Paste_Model(std::string Name, int x, int y, int z)
{
    std::cout << "Pasting Model: " << Name << " At: " << x << ", " << y << ", " << z << std::endl;
}

extern "C" void Load_Scene(std::string Name, std::string Scene_File)
{
    std::cout << "Loading Scene: " << Name << " From File: " << Scene_File << std::endl;
}

extern "C" void Paste_Scene(std::string Name)
{
    std::cout << "Pasting Scene: " << Name << std::endl;
}

extern "C" void Render()
{
    std::cout << "Rendering Scene" << std::endl;
}