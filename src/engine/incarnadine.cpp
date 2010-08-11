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

#include "incarnadine.h"

Incarnadine::Incarnadine(Camera* newCamera, Scene* newScene)
{
	log = new Logger("incarnadine.log", LOG_INFO, LOG_ALL);
	iiout(LOG_DEBUG, "init");

	SDL_Init(SDL_INIT_VIDEO);

	int imgFlags = IMG_INIT_PNG | IMG_INIT_JPG;
	int imgStatus = IMG_Init(imgFlags);
	if ((imgStatus & imgFlags) != imgFlags)
	{
		iiout(LOG_ERROR, std::string("SDL_image initialization failed: ").append((const char*)IMG_GetError()));
		throw 0;
	}
	
	display = new Display();

	if (!display->init())
	{
		iiout(LOG_ERROR, std::string("Failed to initialize the display: ").append(SDL_GetError()));
		throw 0;
	}
	
	input = new InputManager(display);
	
	renderer = new RenderManager(newCamera, newScene, display);

	GLenum errorNum = glewInit();
	if (errorNum != GLEW_OK)
	{
		iiout(LOG_ERROR, std::string("GLEW initialization failed: ").append((const char*)glewGetErrorString(errorNum)));
		throw 0;
	}

}

Incarnadine::~Incarnadine()
{
	iiout(LOG_DEBUG, "exiting");

	renderables.clear();

	if (input)
	{
		delete input;
		input = 0;
	}

	if (display)
	{
		delete display;
		display = 0;
	}

	if (log)
	{
		delete log;
		log = 0;
	}

	IMG_Quit();
	
	SDL_Quit();
}

void Incarnadine::renderScene()
{
	renderer->draw();
	GLenum errorCode = glGetError();
	if(errorCode != GL_NO_ERROR)
	{
		iiout(LOG_ERROR, (char*) gluErrorString(errorCode));
		throw 0;
	}
}

void Incarnadine::iout(LogLevel level, std::string message)
{
	if(log) log->log(level, message);
}

Renderable* Incarnadine::loadModel(std::string uri)
{
	Renderable* r;
	std::map<std::string, Renderable*>::iterator i = renderables.find(uri);
	if(i != renderables.end()) return i->second();
	r = new Md2Model(uri);
	renderables.insert(std::pair<std::string, Renderable*>(uri, r));
	return r;
}

void Incarnadine::iiout(LogLevel level, std::string message)
{
	std::string buff = "Incarnadine Engine: " + message;
	iout(level, buff);
}

unsigned int Incarnadine::getTicks()
{
	return clock.getTicks();
}

Clock* getClock()
{
	return (Clock*)&clock;
}
