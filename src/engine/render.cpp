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

RenderManager::RenderManager(Camera* newCamera, SceneManager* newScene, Display* newDisplay)
{
	camera = newCamera;
	scene = newScene;
	display = newDisplay;
	
	glShadeModel(GL_SMOOTH);
	glClearColor (1.0, 1.0, 1.0, 0.0);
}

void RenderManager::draw()
{
	//calculate aspect ratio
	const SDL_VideoInfo* videoInfo = SDL_GetVideoInfo();
	float aspectRatio = (float) videoInfo->current_w / (float) videoInfo->current_h;
	
	//setting up projection...
	glMatrixMode(GL_PROJECTION);
	
	//initialise projection matrix to identity
	glLoadIdentity();

	//apply a Frustum to projection matrix
	glFrustum (-aspectRatio, aspectRatio, -1.0, 1.0, camera->getFov(), 1000);

	//future matrix inputs modify model view...
	glMatrixMode(GL_MODELVIEW);
    
	//initialise model view matrix to identity
	glLoadIdentity();
	
	//rotate world openGL primitives around camera
	glLoadMatrixf(camera->lookAtMatrix().data());

	//translate openGL primitives so that camera sits at (0, 0, 0)
	vector3 cPosition = camera->getPosition();
	glTranslatef(-cPosition[0], -cPosition[1], -cPosition[2]);

	//blank screen buffers
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    
	scene->rasterize();
	display->update();
}

void RenderManager::setCamera(Camera* newCamera)
{
	camera = newCamera;
}