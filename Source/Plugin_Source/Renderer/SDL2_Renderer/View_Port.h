#include "./vendor/glm/glm.hpp"
#include "./vendor/glm/gtc/matrix_transform.hpp"

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

#include "Camera.h"

class View_Port
{
    public:
    bool Enabled = true;
    bool Perspective = true;
    int X, Y, W, H;
    float Fovy, Near, Far, Left, Right, Bottom, Top;
    glm::mat4 Projection = glm::mat4(1.0f);
    Camera Cam;

    void Set();
    void Set(int x, int y, int w, int h);
    void Set_Perspective(float Fovy, float Near, float Far);
    void Set_Ortho(float Left, float Right, float Bottom, float Top, float Near, float Far);
    
};

void View_Port::Set()
{
    glViewport(X, Y, W, H);
}

void View_Port::Set(int x, int y, int w, int h)
{
    X = x; 
    Y = y; 
    W = w; 
    H = h;

    glViewport(X, Y, W, H);
}

void View_Port::Set_Perspective(float fovy, float near, float far)
{
    Perspective = true;
    
    Fovy = fovy;
    Near = near;
    Far  = far;
 
    Projection = glm::perspective(glm::radians(Fovy), (float)(W/H), Near, Far);
}

void View_Port::Set_Ortho(float left, float right, float bottom, float top, float near, float far)
{
    Perspective = false;
    Left = left;
    Right = right;
    Bottom = bottom;
    Top = top;
    Near = near;
    Far = far;
    
    Projection = glm::ortho(Left, Right, Bottom, Top, Near, Far);
}

