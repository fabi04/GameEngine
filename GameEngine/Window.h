#pragma once
#ifndef WINDOW
#define WINDOW

#include <SDL.h>
#include "EventListener.h"

class Window
{
private:
	SDL_Window* _window;
	SDL_GLContext _glContext;
	EventListener* _listener;
	unsigned int _height;
	unsigned int _width;
public:
	Window(const char* name, const int sizeX, const int size);
	~Window();
	void update();
	bool isClosed();
	unsigned int getHeight() const;
	unsigned int getWidth() const;
};

#endif