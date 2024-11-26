#pragma once
#include "Shader.h"

#include "FileIO.h"
#include "Named_List.h"
#include "./vendor/glm/glm.hpp"

struct Attribute_Data
{
    GLuint ID;
    GLuint Size;
    std::string Type;
    void* Offset;
};

class Shader_Program
{
    public:
    bool DEBUG = true;
    //Generate program
    const std::string Shader_Source_Path = "../Resources/Shaders/";
    std::string Name;

    GLuint VBO = 0;
    GLuint IBO = 0;

    //VBO data
    void const* Vertex_Data;
    //IBO data
    void const* Index_Data;
    int Index_Size;

	GLuint ID;
    Shader Vertex_Shader;
    Shader Fragment_Shader;
    
    void Load(std::string name, std::string Config_File); 


    Named_List<GLint> Uniform_Location_List;
    void SetUniform1i(std::string name, GLint v0);
    void SetUniform4f(std::string name, float v0, float v1, float v2, float v3);
    void SetUniformMat4f(std::string name, const glm::mat4& matrix);

    int Stride = 0;
    Named_List<Attribute_Data> Attribute_Data_List;
    void Set_Attribute_Data(std::string name, GLint id, GLint Size, std::string Type);
    void Set_Attribute(std::string Attribute);

    //Pass Data into the VBO and IBO
    void Data(void const* VBO_Data, int sizeof_VBO_Data, void const* IBO_Data, int sizeof_IBO_Data);
    
    void Render();
    void Render(GLenum DrawMode);

    ~Shader_Program();

    GLint Get_Uniform_Location(std::string name);
    void Set_GL_Version(int Major, int Minor);
    void Init_Shader(GLuint type, std::string name, std::string file);
    bool Build();

    //Shader Debuging utility programs
    void Print_Log();
};

void Shader_Program::Load(std::string name, std::string Config_File)
{
	Name = name;

	
	std::string Full_Path = Shader_Source_Path + Config_File;
	std::string Command;
	
	FileIO Config(Full_Path);

	Config >> Command;
	if(Command == "Set_GL_Version")
	{
		int Major, Minor;
		Config >> Major;
		Config >> Minor;

		Set_GL_Version(Major, Minor);
	}
	
	glewExperimental = GL_TRUE; 
    GLenum glewError = glewInit();
    if( glewError != GLEW_OK )
    {
        printf( "Error initializing GLEW! %s\n", glewGetErrorString( glewError ) );
    }

	while(Command != "Done" and Config.Good())
	{
		Config >> Command;
		if(Command == "Init_Shader")
		{
			Config >> Command;
			std::string s_name, s_file;
			Config >> s_name;
			Config >> s_file;

			if(Command == "GL_VERTEX_SHADER")
			{
				
				Init_Shader(GL_VERTEX_SHADER, s_name, s_file);
			}
			else if(Command == "GL_FRAGMENT_SHADER")
			{
				Init_Shader(GL_FRAGMENT_SHADER, s_name, s_file);
			}
		}
		
		else if(Command == "Set_Attribute_Data")
		{
			std::string name = Config.S();
			GLint id = Config.I();
			GLint size = Config.I();
			std::string type = Config.S();
			Set_Attribute_Data(name, id, size, type);
		}
		
		else if(Command == "Build")
		{
			// Link all the shaders into a Shader Program
			Build();
		}

		else if(Command == "Get_Uniform_Location")
		{
			Get_Uniform_Location(Config.S());
		}
	}	
    
    //Initialize clear color
    glClearColor( 0.f, 0.f, 0.f, 1.f );
}

void Shader_Program::Set_GL_Version(int Major, int Minor)
{
    if(DEBUG)std::cout << "Set_GL_Version " << Major << "." << Minor << std::endl;
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, Major);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, Minor);
    SDL_GL_SetAttribute( SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE );
}

void Shader_Program::Init_Shader(GLuint type, std::string name, std::string file)
{
	std::string Full_Path = Shader_Source_Path + file;
    if (type == GL_VERTEX_SHADER)
    {
        Vertex_Shader.Init(type, name, Full_Path);
    }    
    else
    {
        Fragment_Shader.Init(type, name, Full_Path);
    }
}

void Shader_Program::Set_Attribute_Data(std::string name, GLint id,  GLint Size, std::string Type)
{
	glBindAttribLocation(ID, id, name.c_str());
	Attribute_Data_List.Add_Node(name);
	Attribute_Data_List.Current->Value.ID = id;
	Attribute_Data_List.Current->Value.Size = Size;
	Attribute_Data_List.Current->Value.Type = Type;
	Attribute_Data_List.Current->Value.Offset = reinterpret_cast<void*>(static_cast<uintptr_t>(Stride));
	if(Type == "GLfloat"){Stride += Size * sizeof(GLfloat);}
}

bool Shader_Program::Build()
{
	ID = glCreateProgram();
	
    glAttachShader(ID, Vertex_Shader.ID);
	glAttachShader(ID, Fragment_Shader.ID);
    
    glLinkProgram( ID );

    //Check for errors
    GLint programSuccess = GL_TRUE;
    glGetProgramiv( ID, GL_LINK_STATUS, &programSuccess );
    if( programSuccess != GL_TRUE )
    {
        printf( "Error linking program %d!\n", ID );
        Print_Log();
        return false;
    }
    
    return true;
}

GLint Shader_Program::Get_Uniform_Location(std::string name)
{	
	if(Uniform_Location_List.Find(name))
	{
		return Uniform_Location_List.Current->Value;
	}
	else
	{
		int location = glGetUniformLocation(ID, name.c_str());
		if(location == -1)
		{
			std::cout << "Error: "<< name << " is not a uniform\n";
		}
		else
		{
			Uniform_Location_List.Add_Node(name, location);
		}
		
		return location;
	}
}

void Shader_Program::SetUniform1i(std::string name, GLint v0)
{
	glUniform1i(Get_Uniform_Location(name), v0);
}

void Shader_Program::SetUniform4f(std::string name, float v0, float v1, float v2, float v3)
{
	glUniform4f(Get_Uniform_Location(name), v0, v1, v2, v3);
}

void Shader_Program::SetUniformMat4f(std::string name, const glm::mat4& matrix)
{
	glUniformMatrix4fv(Get_Uniform_Location(name), 1, GL_FALSE, &matrix[0][0]);
}

void Shader_Program::Print_Log()
{
	//Make sure name is shader
	if( glIsProgram( ID ) )
	{
		//Program log length
		int infoLogLength = 0;
		int maxLength = infoLogLength;
		
		//Get info string length
		glGetProgramiv( ID, GL_INFO_LOG_LENGTH, &maxLength );
		
		//Allocate string
		char* infoLog = new char[ maxLength ];
		
		//Get info log
		glGetProgramInfoLog( ID, maxLength, &infoLogLength, infoLog );
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
		printf( "Name %d is not a program\n", ID );
	}
}

Shader_Program::~Shader_Program()
{
    //Deallocate program
	glDeleteProgram( ID );
}

void Shader_Program::Set_Attribute(std::string Attribute )
{ 
	Attribute_Data_List.Find(Attribute);
	// index, size, type, normal, stride, pointer                   
	
	glVertexAttribPointer( 
		Attribute_Data_List.Current->Value.ID,
		Attribute_Data_List.Current->Value.Size,
		GL_FLOAT,
		GL_FALSE,
		Stride,
		Attribute_Data_List.Current->Value.Offset
	);

	//Enable vertex position gVertexPos4DLocation
	glEnableVertexAttribArray( Attribute_Data_List.Current->Value.ID);	
}

void Shader_Program::Data(void const* VBO_Data, int sizeof_VBO_Data, void const* IBO_Data, int sizeof_IBO_Data)
{
	Vertex_Data = VBO_Data;
	Index_Data = IBO_Data;
	Index_Size = sizeof_IBO_Data;

	sizeof_VBO_Data = sizeof_VBO_Data  * sizeof(float);
	sizeof_IBO_Data = sizeof_IBO_Data * sizeof(int);
	

	//Create VBO * sizeof(int)
	glGenBuffers( 1, &VBO );

	//Create IBO
	glGenBuffers( 1, &IBO );
	
	glBindBuffer( GL_ARRAY_BUFFER, VBO );
	glBindBuffer( GL_ELEMENT_ARRAY_BUFFER, IBO );
   
    glBufferData( GL_ARRAY_BUFFER, sizeof_VBO_Data, Vertex_Data, GL_STATIC_DRAW );
    glBufferData( GL_ELEMENT_ARRAY_BUFFER, sizeof_IBO_Data, Index_Data, GL_STATIC_DRAW );
}

void Shader_Program::Render()
{
	Render(GL_TRIANGLES);
}

void Shader_Program::Render(GLenum DrawMode)
{
	glUseProgram( ID );
	
	//Set vertex data
	glBindBuffer( GL_ARRAY_BUFFER, VBO );
	
	//Set index data and render
	glBindBuffer( GL_ELEMENT_ARRAY_BUFFER, IBO );

	Attribute_Data_List.Go_To(0);
	for(int i = 0; i <= Attribute_Data_List.Nodes; i++)
	{
		Set_Attribute(Attribute_Data_List.Current->Name);
		Attribute_Data_List.Next();
	}

	glDrawElements( DrawMode, Index_Size, GL_UNSIGNED_INT, NULL );
	
	//Disable vertex positions
	Attribute_Data_List.Go_To(0);
	for(int i = 0; i <= Attribute_Data_List.Nodes; i++)
	{
		glDisableVertexAttribArray(Attribute_Data_List.Current->Value.ID);
		Attribute_Data_List.Next();
	}
}