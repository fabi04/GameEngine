#pragma once
#ifndef EVENTLISTENER
#define EVENTLISTENER
#include <SDL.h>
#include <vector>

class EventListener
{
private:
	EventListener();
	const Uint8* _keyStates;
	void keyUp();
	void keyDown();
public:
	void getUserKeyInput();
	void getUserMouseInput(int& xPos, int& Pos) const;
	bool getKeyDown(SDL_Scancode key);
	static EventListener* getInstance();

};

#endif