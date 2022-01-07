#include "Window.h"

Window::Window(const char* name, const int sizeX, const int sizeY) : _height(sizeX), _width(sizeY)
{
	SDL_Init(SDL_INIT_EVERYTHING);
	SDL_GL_SetAttribute(SDL_GL_RED_SIZE, 8);
	SDL_GL_SetAttribute(SDL_GL_GREEN_SIZE, 8);
	SDL_GL_SetAttribute(SDL_GL_BLUE_SIZE, 8);
	SDL_GL_SetAttribute(SDL_GL_ALPHA_SIZE, 8);
	SDL_GL_SetAttribute(SDL_GL_BUFFER_SIZE, 32);
	SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
	_window = SDL_CreateWindow(name, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, sizeX, sizeY, SDL_WINDOW_OPENGL);
	_glContext = SDL_GL_CreateContext(_window);
	_listener = EventListener::getInstance();
}

Window::~Window()
{
	SDL_DestroyWindow(_window);
}

void Window::update()
{
	if (_listener->getKeyDown(SDL_SCANCODE_ESCAPE))
	{
		SDL_SetRelativeMouseMode(SDL_FALSE);
		SDL_CaptureMouse(SDL_FALSE);
	}
	SDL_GL_SwapWindow(_window);
}

bool Window::isClosed()
{
	SDL_Event event;
	SDL_PollEvent(&event);
	return event.type == SDL_QUIT;
}

unsigned int Window::getHeight() const
{
	return _height;
}

unsigned int Window::getWidth() const
{
	return _width;
}


