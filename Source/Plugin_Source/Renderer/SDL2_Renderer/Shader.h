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

#include <string>
#include <stdio.h>
#include <sstream>
#include <iostream>
#include <fstream>

class Shader
{
public:
    const bool DEBUG = false;
    GLuint ID;
    GLuint Shader_Type;
    std::string Source;
    std::string Name;
    std::string File_Name;
    
    void Init(GLuint type, std::string name, std::string file);
    void Print_Log();
    ~Shader();
};

void Shader::Init(GLuint type, std::string name, std::string file)
{
    Shader_Type = type;
	Name = name;
    File_Name = file;
	
	std::string line;
	if(DEBUG)std::cout << File_Name << std::endl;
	std::ifstream File(File_Name);	
	
	while (getline(File, line))
	{
		Source += line + "\n";
	}
	File.close();
	if(DEBUG)std::cout << Name << ":\n" << Source << std::endl;

	ID = glCreateShader(Shader_Type);
	const char* src = Source.c_str();
	glShaderSource(ID, 1, &src, nullptr);
	glCompileShader(ID);
	
	int result;
	glGetShaderiv(ID, GL_COMPILE_STATUS, &result);
	if (result == GL_FALSE)
	{
		/*
		int length;
		glGetShaderiv(ID, GL_INFO_LOG_LENGTH, &length);
		char* message = (char*)alloca(length * sizeof(char));
		glGetShaderInfoLog(ID, length, &length, message);
		*/
		std::cout << "Failed to compile " << Name << std::endl;
		//std::cout << message << std::endl;
		glDeleteShader(ID);
	}
	else
	{
		if(DEBUG)std::cout << Name << " Compiled Successfully" << std::endl;
	}
}

void Shader::Print_Log()
{
	//Make sure name is shader
	if( glIsShader( ID ) )
	{
		//Shader log length
		int infoLogLength = 0;
		int maxLength = infoLogLength;
		
		//Get info string length
		glGetShaderiv( ID, GL_INFO_LOG_LENGTH, &maxLength );
		
		//Allocate string
		char* infoLog = new char[ maxLength ];
		
		//Get info log
		glGetShaderInfoLog( ID, maxLength, &infoLogLength, infoLog );
		if( infoLogLength > 0 )
		{
			//Print Log
			
			printf( "%s\n", infoLog );
		}

		//Deallocate string
		delete[] infoLog;
	}
	else
	{
		printf( "Name %d is not a shader\n", ID );
	}
}

Shader::~Shader()
{
	glDeleteShader( ID );
}
