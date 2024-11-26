#pragma once

#include "./vendor/glm/glm.hpp"
#include "./vendor/glm/gtc/matrix_transform.hpp"

#include "View_Port.h"
#include "Shader_Program.h"
#include "FileIO.h"
#include <vector>
#include "Texture_Manager.h"

extern Texture_Manager TM;

class Asset
{
public:
    glm::vec3 Location, Orientation;
    std::string Texture_Name;
    Shader_Program *Shade;
    glm::mat4 Model;
    std::vector<float> VBO;
    std::vector<int> IBO;

    void Set_Location(float X, float Y, float Z);
    void Set_Orientation(float Yaw, float Pitch, float Roll);
    
    void Move(float X, float Y, float Z);   
    void Rotate(float Yaw, float Pitch, float Roll);
    
    void Load(std::string Name);
    void Save(std::string Name);
    
    void Render(View_Port *View);
    void operator = (Asset B);
    void Set_Scale(float Scale);
    void Set_Scale(float x, float y, float z);
};

void Asset::Set_Location(float X, float Y, float Z)
{
    Location = glm::vec3(X, Y, Z); 
}

void Asset::Move(float X, float Y, float Z)
{
    glm::vec3 temp(X, Y, Z);
    Location += temp;
}

void Asset::Set_Orientation(float Yaw, float Pitch, float Roll)
{
    Orientation = glm::vec3(Yaw, Pitch, Roll);
}

void Asset::Rotate(float Yaw, float Pitch, float Roll)
{
    glm::vec3 temp(Yaw, Pitch, Roll);
    Orientation += temp;
}

void Asset::Load(std::string Name)
{
    FileIO File(Name);
    std::string Command;
    Command = File.S();
    while(Command != "Done")
    {
        if(Command == "VBO")
        {            
            int nodes = File.I();
            float node;
            for(int i = 1; i <= nodes; i++ )
            {
                //node = File.F();
                File.Read(node);
                VBO.push_back(node);
            }
        }
        else if(Command == "IBO")
        {
            int nodes = File.I();
            for(int i = 1; i <= nodes; i++ )
            {
                int node = File.I();
                IBO.push_back(node);
            }
        }
        File >> Command;
    }
}

void Asset::Render(View_Port *View)
{
    TM.Bind(Texture_Name.c_str(), 1);
    Shade->SetUniform1i("u_Texture", TM.Slot());

    Shade->Data(&VBO[0], VBO.size(), &IBO[0], IBO.size() );
    Model = glm::mat4(1.0f);
    Model = glm::translate(Model, Location);
    
    Model = glm::rotate(Model, glm::radians(Orientation.x), glm::vec3(1.0f, 0.0f, 0.0f));
    Model = glm::rotate(Model, glm::radians(Orientation.y), glm::vec3(0.0f, 1.0f, 0.0f));
    Model = glm::rotate(Model, glm::radians(Orientation.z), glm::vec3(0.0f, 0.0f, 1.0f));

    Shade->SetUniformMat4f("u_MVP", View->Projection * View->Cam.View * Model);
    Shade->Render();
}

void Asset::operator = (Asset B)
{
    B.VBO.clear();
    B.IBO.clear();
    B.VBO = VBO;
    B.IBO = IBO;
    B.Shade = Shade;
}

void Asset::Set_Scale(float Scale){Set_Scale(Scale, Scale, Scale);}

void Asset::Set_Scale(float x, float y, float z)
{
    int offset;
    for(int i = 0; i < (int)VBO.size(); i++)
    {
        offset = (i+1)%5;
        switch (offset)
        {
            case 1:
                VBO[i] = VBO[i] * x;
            break;

            case 2:
                VBO[i] = VBO[i] * y;
            break;

            case 3:
                VBO[i] = VBO[i] * z;
            break;
        
            default:
            break;
        }
    }
}
