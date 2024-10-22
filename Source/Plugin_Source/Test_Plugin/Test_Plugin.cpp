#include <iostream>

extern "C" void Constructor(const char* name)
{
    std::cout << "Constructor: " << name << '\n';
}

extern "C" void Destructor()
{
    std::cout << "Destructor" << '\n';
}

