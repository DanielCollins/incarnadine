//========================================================================
//
// Copyright (c) 2010 Daniel Collins, Daniel Flahive
//
// This software is provided 'as-is', without any express or implied
// warranty. In no event will the authors be held liable for any damages
// arising from the use of this software.
//
// Permission is granted to anyone to use this software for any purpose,
// including commercial applications, and to alter it and redistribute it
// freely, subject to the following restrictions:
//
// 1. The origin of this software must not be misrepresented; you must not
//    claim that you wrote the original software. If you use this software
//    in a product, an acknowledgment in the product documentation would
//    be appreciated but is not required.
//
// 2. Altered source versions must be plainly marked as such, and must not
//    be misrepresented as being the original software.
//
// 3. This notice may not be removed or altered from any source
//    distribution.
//
//========================================================================

#include "input.h"

using namespace incarnadine;

InputManager::InputManager(Display *d)
{
	display = d;
	ignoreNextMouseMove = false;
	SDL_ShowCursor(SDL_DISABLE);
	SDL_WM_GrabInput(SDL_GRAB_ON);
	resetMousePosition();
}

InputManager::~InputManager()
{
	SDL_WM_GrabInput(SDL_GRAB_OFF);
	SDL_ShowCursor(SDL_ENABLE);
}

void InputManager::update()
{
	SDL_Event Event;
	
	while(SDL_PollEvent(&Event))
	{
		switch(Event.type)
		{
			case SDL_KEYDOWN:
			{
				KeyDown e;
				e.key = (Key) Event.key.keysym.sym;
				sKeyDown.fire(&e);
				break;
			}
			case SDL_KEYUP:
			{
				KeyUp e;
				e.key = (Key) Event.key.keysym.sym;
				sKeyUp.fire(&e);
				break;
			}
			case SDL_MOUSEMOTION:
			{
				if (ignoreNextMouseMove)
				{
					ignoreNextMouseMove = false;
				}
				else
				{
					MouseMove e;
					e.x = Event.motion.x;
					e.y = Event.motion.y;
					e.xrel = Event.motion.xrel;
					e.yrel = Event.motion.yrel;

					sMouseMove.fire(&e);
				}
				break;
			}	
			case SDL_QUIT:
			{
				Exiting e;
				sExiting.fire(&e);
			}
		}
	}
}

void InputManager::resetMousePosition()
{
	ignoreNextMouseMove = true;
	SDL_WarpMouse(display->width() / 2, display->height() / 2);
}

