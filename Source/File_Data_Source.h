#pragma once
#include "Data_Source.h"
#include "FileIO.h"

class File_Data_Source: public Data_Source
{
    private:
        bool Valid;
    public:
        FileIO File;
        File_Data_Source();
        File_Data_Source(std::string File_Name);
        void Load(std::string File_Name);
        std::string Get_Data() override;
        ~File_Data_Source();
};

File_Data_Source::File_Data_Source()
{
    Valid = false;
}

File_Data_Source::File_Data_Source(std::string File_Name)
{
    //File.DEBUG = true;
    Valid = File.Open(File_Name);
}

void File_Data_Source::Load(std::string File_Name)
{
    Valid = File.Open(File_Name);
}

std::string File_Data_Source::Get_Data()
{
    std::string Data;
    if(Valid)
    {   
        File >> Data;
    }
    else
    {
        Data = "Error: File Not Found";
    }
    return Data;
}

File_Data_Source::~File_Data_Source()
{
    if(Valid){File.Close();}
}