//========================================================================
//
// Copyright (c) 2010 Daniel Collins
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

InputManager::InputManager(Display *d)
{
	display = d;
	SDL_ShowCursor(SDL_DISABLE);
	resetMousePosition();
}

void InputManager::update()
{
	SDL_Event Event;
	
	while(SDL_PollEvent(&Event))
	{
		switch(Event.type)
		{
			case SDL_MOUSEMOTION:
			{
				MouseMove e;
				e.x = Event.motion.x;
				e.y = Event.motion.y;
				e.xrel = Event.motion.xrel;
				e.yrel = Event.motion.yrel;
				sMouseMove.fire(&e);
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
	SDL_WarpMouse(display->width() / 2, display->height() / 2);
}

