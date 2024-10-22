#pragma once

#include <stdlib.h>
#include <stdio.h>
#include <string>
#include <iostream>


#ifdef __linux__
#include <dlfcn.h>

class Plugin
{
private:
    void *handle;
	char *error;

    void (*Constructor)();
    void (*Destructor)();

public:

    void Load(std::string Module_Name, std::string Plugin_Name);
    template<typename T>void Assign(std::string Key, T &func);

    ~Plugin();
};

void Plugin::Load(std::string Module_Name, std::string Plugin_Name)
{
    if(handle != 0){
        Destructor();
        dlclose(handle);
    }
    
    std::string Lib = "../Plugins/" + Module_Name + "/" + Plugin_Name + "/" + Plugin_Name + ".so";

    handle = dlopen (Lib.c_str(), RTLD_LAZY);
	if (!handle) {
        fputs (dlerror(), stderr);
        exit(1);
    }
    
    Assign("Constructor", Constructor);
    Assign("Destructor", Destructor);
    if(Constructor != nullptr) Constructor();
}


template<typename T>void Plugin::Assign(std::string Key, T &func)
{
    void *Value = dlsym(handle, Key.c_str());
    if ((error = dlerror()) != NULL)  
    {
        std::cout << "Error: " << Key << " not found" << std::endl;
        //fputs(error, stderr);
        //exit(1);
    } 
    else
    {
        func = reinterpret_cast<decltype(func)>(Value);
    }
}

Plugin::~Plugin()
{
    if(Destructor != nullptr)
    {
        Destructor();
    } 
    if(handle != 0)
    {
        dlclose(handle);
    }   
}

#endif

#ifdef __MINGW32__

#include <windows.h>
#include <iostream>

class Plugin
{
    private:
    HINSTANCE handle;
    char *error;

    public:
    void Load(std::string Module_Name, std::string Plugin_Name);
    template<typename T>
    void Assign(std::string Key, T &func);
    ~Plugin();
};


void Plugin::Load(std::string Module_Name, std::string Plugin_Name)
{
    std::string Lib = "./Plugins/" + Module_Name + "/" + Plugin_Name + ".dll";
    handle = LoadLibrary(Lib.c_str());
    if (!handle)
    {
        std::cerr << "Failed to load DLL: " << GetLastError() << std::endl;
        exit(1);
    }
}

template<typename T>
void Plugin::Assign(std::string Key, T &func)
{
    if(handle != 0){
	func = (T)GetProcAddress(handle, Key.c_str());
}
	else func = nullptr;
}


Plugin::~Plugin()
{
    FreeLibrary(handle);
}
#endif