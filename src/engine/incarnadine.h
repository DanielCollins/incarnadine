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

#ifndef ENGINE_INCARNADINE_H
#define ENGINE_INCARNADINE_H

#include <string>
#include <map>
#include "SDL.h"
#include "SDL_image.h"
#include "GL/glew.h"
#include "display.h"
#include "input.h"
#include "render.h"
#include "camera.h"
#include "scene.h"
#include "clock.h"
#include "renderable.h"
#include "visible.h"
#include "md2.h"

class Incarnadine
{
	private:
		RenderManager* renderer;
		Clock clock;
		std::map<std::string, Renderable*> renderables;

	public:
		Display* display;
		InputManager* input;

		Incarnadine(Camera* newCamera, Scene* newScene);
		~Incarnadine();
		void renderScene();
		void renderScene(float);
		Renderable* loadModel(std::string uri);
		unsigned int getTicks();
		Clock* getClock();
};

#endif //ENGINE_INCARNADINE_H
