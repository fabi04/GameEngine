#include "Camera.h"

glm::mat4 Camera::getViewMatrix() const
{
	return glm::lookAt(_pos, _pos + _front, _up);
}

glm::vec3 Camera::getPos() const
{
	return _pos;
}

void Camera::processInput()
{
	float delta = (SDL_GetTicks() - _lastTickCount) / 1000.0f;
	_lastTickCount = SDL_GetTicks();
	if (_listener->getKeyDown(SDL_SCANCODE_DOWN))
	{
		processKeyboard(BACKWARD, delta);
	}
	else if(_listener->getKeyDown(SDL_SCANCODE_UP))
	{
		processKeyboard(FORWARD, delta);
	}
	else if(_listener->getKeyDown(SDL_SCANCODE_LEFT))
	{
		processKeyboard(LEFT, delta);
	}
	else if(_listener->getKeyDown(SDL_SCANCODE_RIGHT))
	{
		processKeyboard(RIGHT, delta);
	}
	int x, y;
	_listener->getUserMouseInput(x, y);
	processMouseMovement(x - _lastMouseX, _lastMouseY - y );
	_lastMouseX = x;
	_lastMouseY = y;
}

void Camera::processKeyboard(const CameraMovement direction, float deltaTime)
{
	float velocity = _movementSpeed * deltaTime;
	switch (direction)
	{
	case FORWARD: _pos += _front * velocity; break;
	case BACKWARD: _pos -= _front * velocity; break;
	case LEFT: _pos -= _right * velocity; break;
	case RIGHT: _pos += _right * velocity; break;
	}
}

void Camera::processMouseMovement(float xOffset, float yOffset, bool constrainPitch)
{
	xOffset *= _mouseSensitivity;
	yOffset *= _mouseSensitivity;

	_yaw += xOffset;
	_pitch += yOffset;

	if (constrainPitch)
	{
		if (_pitch > 89.0f) _pitch = 89.0f;
		else if (_pitch < -89.0f) _pitch = -89.0f;
	}
	updateCameraVectors();
}

void Camera::processMouseScroll(float offset)
{
	_zoom -= offset;
	if (_zoom < 1.0f) _zoom = 1.0f;
	else if (_zoom > 45.0f) _zoom = 45.0;
}

void Camera::updateCameraVectors()
{
	glm::vec3 front;
	front.x = cos(glm::radians(_yaw)) * cos(glm::radians(_pitch));
	front.y = sin(glm::radians(_pitch));
	front.z = sin(glm::radians(_yaw)) * cos(glm::radians(_pitch));
	_front = glm::normalize(front);
	_right = glm::normalize(glm::cross(_front, _worldUp));
	_up = glm::normalize(glm::cross(_right, _front));
}
