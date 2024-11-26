#pragma once

#include "./vendor/glm/glm.hpp"
#include "./vendor/glm/gtc/matrix_transform.hpp"


class Camera
{
    public:
    
    glm::mat4 View;
    
    Camera();
    void Reset();

    void Set_Location(float X, float Y, float Z);
    void Set_Orientation(float Yaw, float Pitch, float Roll);
    
    void Move(float X, float Y, float Z);   
    void Rotate(float Yaw, float Pitch, float Roll);

    void Update();
    
    glm::vec3 Location, Orientation;
};

Camera::Camera()
{
    Reset();
    Update();
}

void Camera::Reset(){Set_Location(0.0f, 0.0f, 0.0f); Set_Orientation(0.0f, 0.0f, 0.0f);}

void Camera::Set_Location(float X, float Y, float Z)
{
    Location = glm::vec3(X, Y, Z); 
}

void Camera::Move(float X, float Y, float Z)
{
    glm::vec3 temp(X, Y, Z);
    Location += temp;
}

void Camera::Set_Orientation(float Yaw, float Pitch, float Roll)
{
    Orientation = glm::vec3(Yaw, Pitch, Roll);
}

void Camera::Rotate(float Yaw, float Pitch, float Roll)
{
    glm::vec3 temp(Yaw, Pitch, Roll);
    Orientation += temp;
}

void Camera::Update()
{
    View = glm::mat4(1.0f);
    View = glm::translate(View, Location);
    
    View = glm::rotate(View, glm::radians(Orientation.x), glm::vec3(1.0f, 0.0f, 0.0f));
    View = glm::rotate(View, glm::radians(Orientation.y), glm::vec3(0.0f, 1.0f, 0.0f));
    View = glm::rotate(View, glm::radians(Orientation.z), glm::vec3(0.0f, 0.0f, 1.0f));
}