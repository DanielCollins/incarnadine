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

#include "display.h"

Display::Display()
{
}

Display::~Display()
{
	SDL_FreeSurface(surface);
}

bool Display::init()
{
	//require at least 5 bits per colour
	SDL_GL_SetAttribute(SDL_GL_RED_SIZE, 5);
	SDL_GL_SetAttribute(SDL_GL_GREEN_SIZE, 5);
	SDL_GL_SetAttribute(SDL_GL_BLUE_SIZE, 5);
	
	//require at least 2 byte depth buffer
	SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 16);
	
	//require double buffering
	SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
	
	if (SDL_Init(SDL_INIT_VIDEO) != 0)	return false;	 
	SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
	surface = SDL_SetVideoMode(640, 480, 16, SDL_OPENGL | SDL_HWSURFACE);
	return true;
}

//Show next frame
void Display::update()
{
	glFlush();
	SDL_GL_SwapBuffers();
}
