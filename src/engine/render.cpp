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

#include "render.h"

RenderManager::RenderManager(Camera* newCamera, Scene* newScene, Display* newDisplay)
{
	camera = newCamera;
	scene = newScene;
	display = newDisplay;

	glShadeModel(GL_SMOOTH);
	glClearColor (1.0, 1.0, 1.0, 0.0);
}

void RenderManager::draw()
{
	camera->updateGL();
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	scene->rasterize();
	display->update();
}

void RenderManager::setCamera(Camera* newCamera)
{
	camera = newCamera;
}
