#pragma once
#include <string>
#include "FileIO.h"
#include "Named_List.h"

#include "Data_Source.h"

class Data_Source_Manager
{
    public:
    Named_List<Data_Source*> Data_Sources;
    void Add_Source(std::string Name, Data_Source *Source);
    void Remove_Source(std::string Name);
    std::string Get_Data();
    void operator >> (std::string &Data);
    void operator >> (int &Data);
    void operator >> (float &Data);
    void operator >> (double &Data);
};

void Data_Source_Manager::Add_Source(std::string Name, Data_Source *Source)
{
    Data_Sources.Add_Node(Name, Source);
}

void Data_Source_Manager::Remove_Source(std::string Name)
{
    Data_Sources.Remove(Name);
}

std::string Data_Source_Manager::Get_Data()
{
    if(Data_Sources.Nodes == 0)
    {
        std::cout << "Error: No Data Sources" << std::endl;
        return "";
    }
    return Data_Sources.Out()->Get_Data();
}

void Data_Source_Manager::operator >> (std::string &Data)
{
    Data = Get_Data();
}

void Data_Source_Manager::operator >> (int &Data)
{
    std::string Str;
    *this >> Str;
    Data = std::stoi(Str);
}

void Data_Source_Manager::operator >> (float &Data)
{
    std::string Str;
    *this >> Str;
    Data = std::stof(Str);
}

void Data_Source_Manager::operator >> (double &Data)
{
    std::string Str;
    *this >> Str;
    Data = std::stod(Str);
}