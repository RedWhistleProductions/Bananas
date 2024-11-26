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

#include "View_Port.h"

extern SDL_GLContext Context;
extern SDL_Event sdl_event;


class Window
{
public:
    std::string Title;
	unsigned int Id;
	int Monitor_Number;// The Monitor Number This Window is displayed on.
	SDL_Rect *Monitor = nullptr;;// The Boundaries of The current Monitor
	SDL_Window *Win = nullptr;
	int X = 0;
	int Y = 0;
	int W = 640;
	int H = 480;
	bool Visible, Focus, Is_Full_Screen;
	
	unsigned int window_flags = SDL_WINDOW_OPENGL;
	
    enum class SCREEN_SIZE
	{
		is640x480,
		is1366x768,
		fullscreen
	} curr_screen_size = SCREEN_SIZE::is640x480,
	  last_non_fullscreen_size = SCREEN_SIZE::is640x480;

    View_Port View;
	bool Init();
	bool Init(std::string Title);
	
    ~Window();

	void Set_Title(std::string title);
	void Close();
	void Set_Focus();
	void Full_Screen();
	void Set();
	void Event(SDL_Event& e);

	void Set(SDL_GLContext &Context);
	void Set_Monitor(int N, SDL_Rect &Display);
	void Cls();
	void Hide();
	void Show();
	void Move(int x, int y);

	void Update();
};

bool Window::Init(std::string Title)
{
    if (SDL_Init(SDL_INIT_VIDEO))
	{
		printf("Failed to init SDL Video, error: %s", SDL_GetError());
		return false;
	}

    // Create an application window with the following settings:
	Win = SDL_CreateWindow(
		Title.c_str(), // window title
		SDL_WINDOWPOS_UNDEFINED,					  // initial x position
		SDL_WINDOWPOS_UNDEFINED,					  // initial y position
		W,									  // width, in pixels
		H,									  // height, in pixels
		window_flags								  // flags - see below
	);

	// Check that the window was successfully created
	if (Win == nullptr)
	{
		printf("Could not create window: %s", SDL_GetError());
		return false;
	}
    
    if(Context == nullptr) Context = SDL_GL_CreateContext(Win);
    
    View.Set(0, 0, W, H);

	Id = SDL_GetWindowID(Win);
	Monitor_Number = SDL_GetWindowDisplayIndex( Win );

    return true;
}

bool Window::Init()
{
	return Init("");
}

void Window::Set()
{
    SDL_GL_MakeCurrent(Win, Context);
}

Window::~Window()
{
    SDL_DestroyWindow(Win);

}  

void Window::Set_Title(std::string title)
{
	Title = title;
	SDL_SetWindowTitle(Win, Title.c_str());
}

void Window::Full_Screen()
{
	SDL_SetWindowFullscreen(Win, SDL_WINDOW_FULLSCREEN_DESKTOP);
	SDL_DisplayMode dm;
	SDL_GetDesktopDisplayMode(Monitor_Number, &dm);
	H = dm.h;
	W = dm.w;
    View.Set(0,0, W, H);
}

void Window::Set_Focus()
{
	if(not Visible)
	{
		SDL_ShowWindow(Win);
		Visible = true;
	}
	SDL_RaiseWindow( Win );
}

void Window::Set_Monitor(int N, SDL_Rect &Display)
{
	Monitor_Number = N;
	Monitor = &Display;
	SDL_SetWindowPosition( Win, Monitor->x + ( Monitor->w - W ) / 2, Monitor->y + ( Monitor->h - H ) / 2 );
}

void Window::Move(int x, int y)
{
	SDL_SetWindowPosition(Win, x, y);
}

void Window::Event(SDL_Event& e)
{
	switch( e.window.event ) 
	{

		case SDL_WINDOWEVENT_MOVED:
			Monitor_Number = SDL_GetWindowDisplayIndex( Win );
		break;

		case SDL_WINDOWEVENT_SIZE_CHANGED:
			W = e.window.data1;
			H = e.window.data2;
			//glViewport (0, 0, W, H);
			//Update();
		break; //Repaint on exposure

		case SDL_WINDOWEVENT_EXPOSED:
			//Update();
		break;

		//Mouse entered window
		case SDL_WINDOWEVENT_ENTER:
			Focus = true;
		break;

		//Mouse left window
		case SDL_WINDOWEVENT_LEAVE:
			Focus = false;
		break;

		//Window has keyboard focus
		case SDL_WINDOWEVENT_FOCUS_GAINED:
			Focus = true;
		break;

		//Window lost keyboard focus
		case SDL_WINDOWEVENT_FOCUS_LOST:
			Focus = false;
		break;

		//Window minimized
		case SDL_WINDOWEVENT_MINIMIZED:
			Visible = false;
		break;

		//Window maxized
		case SDL_WINDOWEVENT_MAXIMIZED:
			Visible = true;
		break;

		//Window restored
		case SDL_WINDOWEVENT_RESTORED:
			Visible = true;
		break;

		case SDL_WINDOWEVENT_CLOSE:
			Close();
		break;
	}
}

void Window::Close()
{
	Visible = false;
	SDL_HideWindow(Win);
}

void Window::Update()
{
	SDL_GL_SwapWindow(Win);
}

void Window::Cls()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void Window::Hide()
{
	Visible = false;
	SDL_HideWindow(Win);
}

void Window::Show()
{
	Visible = true;
	SDL_ShowWindow(Win);
	Set_Focus();
}
