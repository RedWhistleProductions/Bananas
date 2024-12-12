#pragma once

#include "Window.h"
#include "Named_List.h"

class Window_Manager
{
    public:
    Named_List<Window> Windows;
    Window* Selected = nullptr;
	Window* Main_Win = nullptr;
    int Displays = 0;
    SDL_Rect* Display;

    void Add_Full_Screen_Window();
    void Add_Full_Screen_Window(std::string Name);
    void Add_Full_Screen_Window(std::string Name, int Monitor_Num);
    void Add_Window();
    void Add_Window(std::string Name);
    void Add_Window(std::string Name, int Monitor_Num);
    void Add_Window(std::string Name, std::string Title);
    void Add_Window(std::string Name, std::string Title, int Monitor_Num);
    
    void Delete_Window(unsigned int Id);

    void Event(unsigned int Id, SDL_Event &e);
    
    void Find(unsigned int Id);
    bool Find(std::string Name);
    
    void Hide(std::string Name);
    
    void Init();
    
    int Open_Windows();
	void Set_Full_Screen(std::string Name);
    void Set_Focus(Window * Win);
	void Set_Focus(std::string Name);
    void Set_Monitor(int N);
	void Set_Monitor(std::string Name, int N);
    void Show(std::string Name);
};

void Window_Manager::Add_Full_Screen_Window()
{
    Add_Window("");
	Selected->Full_Screen();
}

void Window_Manager::Add_Full_Screen_Window(std::string Name)
{
    Add_Window(Name);
	Selected->Full_Screen();
}

void Window_Manager::Add_Full_Screen_Window(std::string Name, int Monitor_Num)
{
    Add_Window(Name, Monitor_Num);
	Selected->Full_Screen();
}

void Window_Manager::Add_Window()
{
    Add_Window("");
}

void Window_Manager::Add_Window(std::string Name)
{
    Windows.Add_Node(Name);
	Windows.Current->Value.Init();
	Selected = &Windows.Current->Value;
	if(Name == "Main"){
		Main_Win = Selected;
		Set_Focus(Main_Win);
		Init();
	}
}

void Window_Manager::Add_Window(std::string Name, int Monitor_Num)
{
    Add_Window(Name);
	Set_Monitor(Monitor_Num);
}

void Window_Manager::Add_Window(std::string Name, std::string Title)
{
    Add_Window(Name);
	Selected->Set_Title(Title);
}

void Window_Manager::Add_Window(std::string Name, std::string Title, int Monitor_Num)
{
    Add_Window(Name, Title);
	Set_Monitor(Monitor_Num);
}

void Window_Manager::Delete_Window(unsigned int Id)
{
    Find(Id);
	Selected = NULL;
}

void Window_Manager::Event(unsigned int Id, SDL_Event& e){
	if(Id == Selected->Id and e.window.event == SDL_WINDOWEVENT_CLOSE)
    {
		Selected->Close();
		Set_Focus(Main_Win);
	}
	else
    {
		while( Id != Windows.Current->Value.Id)
        {
			Windows.Next();
		}
		Windows.Current->Value.Event(e);
	}
}

void Window_Manager::Find(unsigned int Id)
{
    while(Id != Windows.Current->Value.Id)
    {
		Windows.Next();
	}
	Selected = &Windows.Current->Value;
}

bool Window_Manager::Find(std::string Name)
{
    if(Windows.Find(Name)){
		Selected = &Windows.Current->Value;
		return true;
	}
	else return false;
}

void Window_Manager::Hide(std::string Name)
{
    if(Find(Name)){Selected->Hide();}
}

void Window_Manager::Init()
{
    Displays = SDL_GetNumVideoDisplays();

    //std::cout << "\tNumber of Displays = " << Displays << std::endl;

	//Get bounds of each display
	Display = new SDL_Rect[ Displays ];
	for( int i = 0; i < Displays; ++i ){
		SDL_GetDisplayBounds( i, &Display[ i ] );
	}
}

int Window_Manager::Open_Windows()
{
    int open = 0;
	for(int i = 0; i < Windows.Nodes; i++)
    {
		if(Windows.Current->Value.Visible) open++;
		Windows.Next();
	}
	return open;
}

void Window_Manager::Set_Focus(std::string Name)
{
    Find(Name);
	Set_Focus(Selected);
}

void Window_Manager::Set_Focus(Window * Win)
{
    Selected = Win;
    Win->Set_Focus();
}

void Window_Manager::Set_Full_Screen(std::string Name)
{
	if(Find(Name)){Selected->Full_Screen();}
}

void Window_Manager::Set_Monitor(int N)
{
    if(N <= SDL_GetNumVideoDisplays() and N > 0){
		Selected->Set_Monitor(N-1, Display[N-1]);
	}
}

void Window_Manager::Set_Monitor(std::string Name, int N)
{
	Find(Name);
	Set_Monitor(N);
}

void Window_Manager::Show(std::string Name)
{
    if(Find(Name)){Selected->Show();}
}





