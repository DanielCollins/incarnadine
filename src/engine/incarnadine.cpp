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

using namespace incarnadine;

Incarnadine::Incarnadine(Camera* newCamera, Scene* newScene, Display* newDisplay)
{
	SDL_Init(SDL_INIT_VIDEO);

	int imgFlags = IMG_INIT_PNG | IMG_INIT_JPG;
	int imgStatus = IMG_Init(imgFlags);
	if ((imgStatus & imgFlags) != imgFlags) throw 0;
	
	display = newDisplay;

	if(TTF_Init() == -1) throw 0;
	
	input = new InputManager(display);
	
	renderer = new RenderManager(newCamera, newScene, display);

	GLenum errorNum = glewInit();
	if (errorNum != GLEW_OK) throw 0;

}

Incarnadine::~Incarnadine()
{
	renderables.clear();

	if (input)
	{
		delete input;
		input = 0;
	}

	IMG_Quit();
	
	SDL_Quit();
}

void Incarnadine::renderScene()
{
	renderer->draw();
	GLenum errorCode = glGetError();
	if(errorCode != GL_NO_ERROR) throw 0;
}

void Incarnadine::renderScene(float timeDelta)
{
	renderer->draw(timeDelta);
	GLenum errorCode = glGetError();
	if(errorCode != GL_NO_ERROR) throw 0;
}

Renderable* Incarnadine::loadModel(std::string uri)
{
	Renderable* r;
	std::map<std::string, Renderable*>::iterator i = renderables.find(uri);
	if(i != renderables.end()) return i->second;

	std::string::size_type pos = uri.find_last_of('.');
	if (pos != std::string::npos && (uri.length() - pos - 1) > 0)
	{
		std::string extension;
		extension = uri.substr(pos + 1, uri.length() - pos - 1);

		if (extension.compare("md2") == 0)
			r = new Md2Model(uri);
		else if (extension.compare("obj") == 0)
			r = new ObjModel(uri);
		else
			throw 0;
	}

	renderables.insert(std::pair<std::string, Renderable*>(uri, r));
	return r;
}

TrueTypeFont* Incarnadine::loadFont(std::string uri, int size)
{
	TrueTypeFont* f;
	std::map<std::string, TrueTypeFont*>::iterator i = fonts.find(uri);
	if(i != fonts.end()) return i->second;
	f = new TrueTypeFont(uri, size);
	fonts.insert(std::pair<std::string, TrueTypeFont*>(uri, f));
	return f;
}

unsigned int Incarnadine::getTicks()
{
	return clock.getTicks();
}

Clock* Incarnadine::getClock()
{
	return (Clock*)&clock;
}

void Incarnadine::addPanel(Panel* p)
{
	renderer->addPanel(p);
}

void Incarnadine::removePanel(Panel* p)
{
	renderer->removePanel(p);
}
