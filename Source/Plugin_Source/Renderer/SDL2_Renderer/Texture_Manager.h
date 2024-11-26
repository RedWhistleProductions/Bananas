#pragma once

#include "Named_List.h"
#include "Texture.h"

class Texture_Manager
{
public:
    Named_List<Texture> Texture_List;
    void Add(std::string Name, std::string File_Name);
    void Bind(std::string Name, int Slot);
    void Unbind();
    int Slot();
    int Slot(std::string Name);
};

void Texture_Manager::Add(std::string Name, std::string File_Name)
{
    Texture_List.Add_Node(Name);
    Texture_List.Current->Value.Load(File_Name);
}

void Texture_Manager::Bind(std::string Name, int Slot)
{
    Texture_List.Find(Name);
    Texture_List.Current->Value.Bind(Slot);
}

void Texture_Manager::Unbind()
{
    Texture_List.Current->Value.Unbind();
}

int Texture_Manager::Slot()
{
    return Texture_List.Current->Value.Slot;
}

int Texture_Manager::Slot(std::string Name)
{
    Texture_List.Find(Name);
    return Slot();
}