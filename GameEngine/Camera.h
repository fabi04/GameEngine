#pragma once
#ifndef CAMERA
#define CAMERA
#include <glm/glm/glm.hpp>
#include <glm/glm/gtc/matrix_transform.hpp>
#include "EventListener.h"


enum CameraMovement
{
	FORWARD, BACKWARD, LEFT, RIGHT, NONE
};

const float YAW = -90.0f;
const float PITCH = 0.0f;
const float SPEED = 2.5f;
const float SENSITIVITY = 0.1f;
const float ZOOM = 45.0f;

class 
	Camera
{
private:
	glm::vec3 _pos;
	glm::vec3 _front;
	glm::vec3 _up;
	glm::vec3 _right;
	glm::vec3 _worldUp;

	int _lastTickCount,_lastMouseX, _lastMouseY;
	float _yaw, _pitch, _movementSpeed, _mouseSensitivity, _zoom;
	EventListener* _listener;

public:
	Camera(glm::vec3 position = glm::vec3(0.0f, 0.0f, 0.0f), glm::vec3 up = glm::vec3(0.0f, 1.0f, 0.0f), float yaw = YAW, float pitch = PITCH) : _front(glm::vec3(0.0f, 0.0f, -1.0f)), _movementSpeed(SPEED), _mouseSensitivity(SENSITIVITY), _zoom(ZOOM)
	{
		_pos = position;
		_worldUp = up;
		_yaw = yaw;
		_pitch = pitch;
		_lastTickCount = SDL_GetTicks();
		updateCameraVectors();
		_listener = EventListener::getInstance();
	}

	Camera(float posX, float posY, float posZ, float upX, float upY, float upZ, float yaw, float pitch) : _front(glm::vec3(0.0f, 0.0f, -1.0f)), _movementSpeed(SPEED), _mouseSensitivity(SENSITIVITY), _zoom(ZOOM)
	{
		_pos = glm::vec3(posX, posY, posZ);
		_worldUp = glm::vec3(upX, upY, upZ);
		_yaw = yaw;
		_pitch = pitch;
		_lastTickCount = SDL_GetTicks();
		updateCameraVectors();
		_listener = EventListener::getInstance();
	}

	glm::mat4 getViewMatrix() const;
	glm::vec3 getPos() const;
	void processInput();
private:
	void updateCameraVectors();
	void processKeyboard(const CameraMovement direction, float deltaTime);
	void processMouseMovement(float xOffset, float yOffset, bool constrainPitch = true);
	void processMouseScroll(float offset);
};

#endif