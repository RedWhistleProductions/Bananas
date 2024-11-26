#include "Window_Manager.h"

#include "Frame_Rate_Controller.h"
#include "Shader_Program.h"

#include "Texture_Manager.h"
#include "Asset.h"

SDL_GLContext Context = nullptr;
SDL_Event sdl_event;

Window_Manager WM;

Shader_Program Shade;
Frame_Rate_Controller Frame_Rate(30);
Texture_Manager TM;

float Speed, Rotation;

Named_List<Asset> Assets;
Named_List<Shader_Program> Shaders;

extern "C" void Set_View_Port(std::string Window_Name, int x, int y, int w, int h)
{
	WM.Find(Window_Name);
	WM.Selected->View.Set(x, y, w, h);
}

extern "C" void Set_Perspective(std::string Window_Name, float Fovy, float Near, float Far)
{
	WM.Find(Window_Name);
	WM.Selected->View.Set_Perspective(Fovy, Near, Far);
}

extern "C" void Set_Ortho(std::string Window_Name, float Left, float Right, float Bottom, float Top, float Near, float Far)
{
	WM.Find(Window_Name);
	WM.Selected->View.Set_Ortho(Left, Right, Bottom, Top, Near, Far);
}

extern "C" void Set_Camera_Location(std::string Window_Name, float X, float Y, float Z)
{
	WM.Find(Window_Name);
	WM.Selected->View.Cam.Set_Location(X, Y, Z);
}

extern "C" void Set_Camera_Orientation(std::string Window_Name, float Yaw, float Pitch, float Roll)
{
	WM.Find(Window_Name);
	WM.Selected->View.Cam.Set_Orientation(Yaw, Pitch, Roll);
}

extern "C" void Move_Camera(std::string Window_Name, float X, float Y, float Z)
{
	WM.Find(Window_Name);
	WM.Selected->View.Cam.Move(X, Y, Z);
}

extern "C" void Rotate_Camera(std::string Window_Name, float Yaw, float Pitch, float Roll)
{
	WM.Find(Window_Name);
	WM.Selected->View.Cam.Rotate(Yaw, Pitch, Roll);
}

extern "C" void Update_Camera(std::string Window_Name)
{
	WM.Find(Window_Name);
	WM.Selected->View.Cam.Update();
}

extern "C" void Load_Shader(std::string Name, std::string Full_Path)
{
	Shaders.Add_Node(Name);
	Shaders.Current->Value.Load(Name, Full_Path);
}

extern "C"  void Load_Asset(std::string Name, std::string Full_Path)
{
	Assets.Add_Node(Name);
	Assets.Current->Value.Load(Full_Path);
}

extern "C" void Set_Texture(std::string Name, std::string Texture_Name)
{
	Assets.Find(Name);
	Assets.Current->Value.Texture_Name = Texture_Name;
}

extern "C" void Set_Shader(std::string Name, std::string Shader_Name)
{
	Assets.Find(Name);
	Shaders.Find(Shader_Name);
	Assets.Current->Value.Shade = &Shaders.Current->Value;
}

extern "C" void Set_Location(std::string Name, float X, float Y, float Z)
{
	Assets.Find(Name);
	Assets.Current->Value.Set_Location(X, Y, Z);
}

extern "C" void Set_Orientation(std::string Name, float Yaw, float Pitch, float Roll)
{
	Assets.Find(Name);
	Assets.Current->Value.Set_Orientation(Yaw, Pitch, Roll);
}

extern "C" void Set_Scale(std::string Name, float X, float Y, float Z)
{
	Assets.Find(Name);
	Assets.Current->Value.Set_Scale(X, Y, Z);
}

extern "C" void Load_Texture(std::string Name, std::string Full_Path)
{
	TM.Add(Name, Full_Path);
}

extern "C" void Render()
{
	int Win = 0;
	for(WM.Windows.Go_To(0); Win < WM.Windows.Nodes; WM.Windows.Next(), Win++)
	{
		//Set the current window to render to
		WM.Windows.Current->Value.Set();
			//Clear color buffer
			glClear( GL_COLOR_BUFFER_BIT  | GL_DEPTH_BUFFER_BIT);
			
			int i = 0;
			for(Assets.Go_To(0); i < Assets.Nodes; Assets.Next(), i++)
			{
				//Render the asset to the View_Port of the current Window
				Assets.Current->Value.Render(&WM.Windows.Current->Value.View);
			}
		// swap to new updated screen to render
		SDL_GL_SwapWindow(WM.Windows.Current->Value.Win);
	}
	Frame_Rate.Delay();
}

extern "C" void Constructor()
{
	std::cout << "SDL2_Window_Manager" << std::endl;

	WM.Add_Window("Main", "Bananas", 1);
	WM.Main_Win->Full_Screen();
	
	WM.Main_Win->View.Set_Perspective(45.0f, 0.1f, 100.0f);
	WM.Main_Win->View.Cam.Set_Location(0.0f, 0.0f, -5.0f);
	WM.Main_Win->View.Cam.Set_Orientation(0.0f, 0.0f, 0.0f);
	WM.Main_Win->View.Cam.Update();

	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LESS);
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	 
	Speed = 0.1;
	Rotation = 1.0;
}

extern "C" std::string Update()
{	
	while(SDL_PollEvent( &sdl_event ))
	{
		//User requests quit
		switch(sdl_event.type)
		{
			
			case SDL_MOUSEMOTION:
				switch(sdl_event.motion.state)
				{
					case SDL_BUTTON_LMASK:
						Assets.Find("Cube");
						Assets.Current->Value.Rotate(sdl_event.motion.yrel, sdl_event.motion.xrel, 0);
					break;

					case SDL_BUTTON_RMASK:
						Assets.Find("Cube");
						Assets.Current->Value.Move(sdl_event.motion.xrel * 0.01, sdl_event.motion.yrel * 0.01, 0);
					break;
				}

			break;

			case SDL_QUIT:
				return "0";
			break;

			case SDL_KEYDOWN:
				switch(sdl_event.key.keysym.sym)
				{
					case SDLK_ESCAPE:
					case SDLK_KP_0:
						return "0";
					break;

					case SDLK_KP_1:
						return "1";
					break;

					case SDLK_KP_2:
						return "2";
					break;

					case SDLK_UP:
					case SDLK_w:
						Assets.Find("Cube");
						Assets.Current->Value.Move(0, 0,-Speed);
					break;

					case SDLK_DOWN:
					case SDLK_s:
						Assets.Find("Cube");
						Assets.Current->Value.Move(0, 0,Speed);
					break;

					case SDLK_LEFT:
					case SDLK_a:
						Assets.Find("Cube");
						Assets.Current->Value.Move(-Speed, 0, 0);
					break;

					case SDLK_RIGHT:
					case SDLK_d:
						Assets.Find("Cube");
						Assets.Current->Value.Move(Speed, 0, 0);
					break;

					case SDLK_r:
						Assets.Find("Cube");
						Assets.Current->Value.Move(0, Speed, 0);
					break;
					
					case SDLK_f:
						Assets.Find("Cube");
						Assets.Current->Value.Move(0, -Speed, 0);
					break;

					case SDLK_t:
						Assets.Find("Cube");
						Assets.Current->Value.Rotate(0,Rotation,0);
					break;

					case SDLK_g:
						Assets.Find("Cube");
						Assets.Current->Value.Rotate(0,-Rotation,0);
					break;

					case SDLK_y:
						Assets.Find("Cube");
						Assets.Current->Value.Rotate(Rotation,0,0);
					break;

					case SDLK_h:
						Assets.Find("Cube");
						Assets.Current->Value.Rotate(-Rotation,0,0);
					break;
				}
			break;
			
			case SDL_WINDOWEVENT:
				if(sdl_event.window.windowID == WM.Main_Win->Id and sdl_event.window.event == SDL_WINDOWEVENT_CLOSE)
				{
					return "0";
				}

				WM.Event(sdl_event.window.windowID, sdl_event);
			break;
		}
		
	}

	return "";
}

extern "C" void Destructor()
{
	//Destroy window
	SDL_Quit();
}

extern "C" void Add_Full_Screen_Window(std::string Name, int Monitor_Num)
{
	WM.Add_Full_Screen_Window(Name, Monitor_Num);
}

extern "C" void Add_Window(std::string Name, std::string Title, int Monitor_Num)
{
	WM.Add_Window(Name, Title, Monitor_Num);
}

extern "C" void Delete_Window(std::string Name)
{
	WM.Find(Name);
	WM.Delete_Window( WM.Selected->Id );
}

extern "C" void Hide(std::string Name)
{
	WM.Hide(Name);
}

extern "C" void Set_Focus(std::string Name)
{
	WM.Set_Focus(Name);
}

extern "C" void Set_Monitor(std::string Name, int N)
{
	WM.Set_Monitor(Name, N);
}

extern "C" void Show(std::string Name)
{
	WM.Show(Name);
}

extern "C" void Set_FPS(int Frames)
{
	Frame_Rate.Set_FPS(Frames);
}

