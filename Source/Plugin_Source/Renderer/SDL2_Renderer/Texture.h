#pragma once

#ifdef __linux__
	#include <SDL2/SDL.h>
	#include <GL/glew.h>
	#include <SDL2/SDL_opengl.h>
	#include <GL/glu.h>
#endif

#ifdef _WIN32
	#include <SDL2/SDL.h>
	#include <GL/glew.h>
	#include <SDL2/SDL_opengl.h>
	#include <GL/glu.h>
#endif

#include "Graphic_Image.h"
#include <string>
#include <iostream>
#include <fstream>


class Texture:public Graphic_Image
{
public:
    GLuint ID;
    std::string Name;
    GLuint Slot = 0;

    Texture();
    Texture(std::string);
    void Load(std::string);

    void Bind(GLuint);
    void Unbind();
    ~Texture();
};

Texture::Texture() {}

Texture::Texture(std::string File)
{
    Load(File);
}

void Texture::Load(std::string File)
{
    Name = File;
    Graphic_Image::Load(File);
    Graphic_Image::V_Flip();

    glGenTextures(1, &ID);
    // Bind the texture object
    glBindTexture(GL_TEXTURE_2D, ID);

    GLenum format;
    switch (Image->format->BytesPerPixel)
    {
    case 4:
        format = (Image->format->Rmask == 0x000000ff) ? GL_RGBA : GL_BGRA;
        break;
    case 3:
        format = (Image->format->Rmask == 0x000000ff) ? GL_RGB : GL_BGR;
        break;
    }

    // Set the texture's stretching properties
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    // Set the modes for the texture to wrap
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

    // Edit the texture object's image data using the information SDL_Surface gives us
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA8, Image->w, Image->h, 0, format, GL_UNSIGNED_BYTE, Image->pixels);
    glGenerateMipmap(GL_TEXTURE_2D);
    Unbind();
}

void Texture::Bind(GLuint slot = 0)
{ 
    Slot = slot;
    glBindTexture(GL_TEXTURE_2D, ID);
    glActiveTexture(GL_TEXTURE0 + Slot);
}

void Texture::Unbind()
{
    glBindTexture(GL_TEXTURE_2D, 0);
}

Texture::~Texture()
{
    glDeleteTextures(1, &ID);
}
