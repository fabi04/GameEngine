#include "EventListener.h"
#include <iostream>


EventListener::EventListener()
{
    SDL_SetRelativeMouseMode(SDL_TRUE);
    SDL_CaptureMouse(SDL_TRUE);
    _keyStates = SDL_GetKeyboardState(nullptr);
}

EventListener* EventListener::getInstance()
{
    static EventListener instance;
    return &instance;
}

void EventListener::keyUp()
{
    _keyStates = SDL_GetKeyboardState(nullptr);
}

void EventListener::keyDown()
{
    _keyStates = SDL_GetKeyboardState(nullptr);
}


void EventListener::getUserKeyInput()
{
    SDL_Event event;
    while (SDL_PollEvent(&event))
    {
        switch (event.type)
        {
        case SDLK_ESCAPE: SDL_SetRelativeMouseMode(SDL_FALSE);
        case SDL_KEYDOWN: keyDown(); break;
        case SDL_KEYUP: keyUp(); break;
        }
    }
}

void EventListener::getUserMouseInput(int& xPos, int& yPos) const
{
    SDL_GetMouseState(&xPos, &yPos);
}

bool EventListener::getKeyDown(SDL_Scancode key)
{
    return _keyStates[key] == 1;
}

