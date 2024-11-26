#pragma once

#ifdef __linux__
	#include <SDL2/SDL.h>
#endif

#ifdef _WIN32
	#include <SDL2\SDL.h>
#endif

class Frame_Rate_Controller
{
	public:
		Frame_Rate_Controller();
		Frame_Rate_Controller(int Frames);
		int Frames_Per_Second;
		int Time_Between_Frames;
		int Last_Frame;
		void Set_FPS(int Frames);
		void Delay();
};

Frame_Rate_Controller::Frame_Rate_Controller()
{
	Set_FPS(60);
}

Frame_Rate_Controller::Frame_Rate_Controller(int Frames){
	Set_FPS(Frames);
}

void Frame_Rate_Controller::Set_FPS(int Frames){
	Frames_Per_Second = Frames;
	Time_Between_Frames = 1000/Frames;
	Last_Frame = Time_Between_Frames;
}

void Frame_Rate_Controller::Delay(){
	int Next_Frame = Last_Frame + Time_Between_Frames;
	int Time_Passed = SDL_GetTicks() - Last_Frame;
	int Delay_Needed = Next_Frame - Time_Passed;
	Last_Frame = Next_Frame;

	if(Delay_Needed > 0)SDL_Delay(Delay_Needed);
}
