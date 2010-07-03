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

#include "incarnadine.h"

Incarnadine::Incarnadine(Camera* newCamera, SceneManager* newSceneManager)
{
	SDL_Init(SDL_INIT_VIDEO);
	
	display = new Display();
	display->init();
	
	input = new InputManager(display);
	
	renderer = new RenderManager(newCamera, newSceneManager, display);

	log = new Logger("incarnadine.log", LOG_INFO, LOG_ALL);
	iiout(LOG_DEBUG, "init");
}

Incarnadine::~Incarnadine()
{
	iiout(LOG_DEBUG, "exiting");	

	delete input;
	input = 0;

	delete display;
	display = 0;

	delete log;
	log = 0;
	
	SDL_Quit();
}

void Incarnadine::renderScene()
{
	renderer->draw();
	GLenum errorCode = glGetError();
	if(errorCode != GL_NO_ERROR)
	{
		iiout(LOG_ERROR, gluErrorString(errorCode));
		throw 0;
	}
}

void Incarnadine::iout(LogLevel level, char* message)
{
	if(log) log->log(level, message);
}

void Incarnadine::iiout(LogLevel level, char* message)
{
	char[100] buff;
	strcpy(buff, "Incarnadine Engine: ");
	strncat(buff, message, 79);
	iout(level, buff);
}

unsigned int Incarnadine::getTicks()
{
	return SDL_GetTicks();
}