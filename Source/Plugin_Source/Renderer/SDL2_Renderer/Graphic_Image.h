#pragma once

#ifdef _WIN32
	#include <SDL2/SDL.h>
	#include<SDL2/SDL_image.h>
#endif

#ifdef __linux__
    /// linux
	#include <SDL2/SDL.h>
	#include<SDL2/SDL_image.h>
#endif

#ifdef __APPLE__
    /// OSX
#endif

#include <string>
#include <iostream>


class Graphic_Image
{
	public:
		std::string Path;
		std::string Ext;

		SDL_Rect Box;
		double Alpha;
		SDL_BlendMode Blend;
		SDL_Color Keyed;
		Graphic_Image();

		//Current displayed image
		SDL_Surface* Image;

		void Size(int w, int h);
		void Scale(double w, double h);
		void Load(std::string name);
		void V_Flip();

		~Graphic_Image();
		void Color_Key(SDL_Color C);
		void Color_Key(int Red, int Blue, int Green);

		SDL_Color Get_Pixel(int x, int y);
		void Set_Pixel(int x, int y, SDL_Color Color);
};

Graphic_Image::Graphic_Image(){
	Path =  "../Resources/Textures/";
	Ext = "";
	Image = NULL;
	Box.x = 0; Box.y = 0;
	Box.w = 0; Box.h = 0;
	//Alpha = 0.5;
	Blend = SDL_BLENDMODE_BLEND;
	//Keyed.r = 0;
	//Keyed.b = 255;
	//Keyed.g = 255;
}

void Graphic_Image::Scale(double w, double h){
	int W = int(Box.w * w);
	int H = int(Box.h * h);
	Size(W,H);
}

void Graphic_Image::Load(std::string name){
	std::string File = Path + name +Ext;
	std::cout << "Loading " << File << std::endl;
	Image = IMG_Load( File.c_str() );

	if(Image == NULL){
			File = Path + "NoPic.bmp";
			std::cout << File << std::endl;
			std::cout << "Image didn't load" << std::endl;
			IMG_Load(File.c_str());
	}
}

void Graphic_Image::Color_Key(SDL_Color C){
	Color_Key(C.r, C.b, C.g);
}

void Graphic_Image::Color_Key(int Red, int Blue, int Green){
	//SDL_SetColorKey(Image, SDL_TRUE, SDL_MapRGB(Image->format, Red, Green, Blue));
	int x, y;
	SDL_Color Pix;
	for(y = 0; y < Image->h; y++){
		for(x = 0; x < Image->w; x++){
			Pix = Get_Pixel(x, y);
			if(Pix.r == Red and Pix.b == Blue and Pix.g == Green){
				Pix.a = 255;
				Set_Pixel(x,y,Pix);
			}
		}
	}

}

void Graphic_Image::Size(int w, int h){
	Box.w = w;
	Box.h = h;
}

Graphic_Image::~Graphic_Image()
{
	SDL_FreeSurface(Image);
	Image = NULL;
}

SDL_Color Graphic_Image::Get_Pixel(int x, int y)
{
    SDL_Color Return_Color;

    //check to see if it is in range
    if(y < Image->h && x < Image->w)
    {
        Uint32 Color32;

        int bpp = Image->format->BytesPerPixel;

        Uint8 *p = (Uint8 *)Image->pixels + y * Image->pitch + x * bpp;
        Color32 = *(Uint32 *)p;

        //Blue = first byte
        //Green = second byte
        //Red = third byte
        //Alpha = fourth byte

        Return_Color.a = Color32/(256*256*256);// for color keying
        Return_Color.r = Color32/(256 * 256);
        Return_Color.g = (Color32/256)%256;
        Return_Color.b = Color32%(256*256);
    }

    return Return_Color;
}

void Graphic_Image::Set_Pixel( int x, int y, SDL_Color Color){
//check to see if it is in range
	if(y < Image->h && x < Image->w)
	{

		//Cast Color to a Uint32
		Uint32 Color32 = SDL_MapRGBA(Image->format, Color.r, Color.g, Color.b, Color.a);

		int bpp = Image->format->BytesPerPixel;

		Uint8 *p = (Uint8 *)Image->pixels + y * Image->pitch + x * bpp;
		*(Uint32 *)p = Color32;
	}

}

void Graphic_Image::V_Flip()
{
    SDL_LockSurface(Image);
    
    int pitch = Image->pitch; // row size
    char* temp = new char[pitch]; // intermediate buffer
    char* pixels = (char*) Image->pixels;
    
    for(int i = 0; i < Image->h / 2; ++i) {
        // get pointers to the two rows to swap
        char* row1 = pixels + i * pitch;
        char* row2 = pixels + (Image->h - i - 1) * pitch;
        
        // swap rows
        memcpy(temp, row1, pitch);
        memcpy(row1, row2, pitch);
        memcpy(row2, temp, pitch);
    }
    
    delete[] temp;

    SDL_UnlockSurface(Image);

}
