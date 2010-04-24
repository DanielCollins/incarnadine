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

#include "camera.h"

Camera::Camera(vector3 newPosition, vector3 newForward, vector3 newUp, float fov) : Object (newPosition, newForward, newUp)
{
	setFov(fov);
}

void Camera::update()
{
	//build a look-at matrix
	matrix44 view;
	matrix_look_at_RH(view, zeroVector, forward, up);
    
	//future matrix inputs modify model view...
	glMatrixMode(GL_MODELVIEW);
    
	//initialise model view matrix to identity
	glLoadIdentity();
	
	//apply rotate world openGL primitives around camera
	glLoadMatrixf(view.data());

	//translate opnGL primitives so that camera sits at (0, 0, 0)
	glTranslatef(-position[0], -position[1], -position[2]);
    
    return;
}


//This function is not safe to call during openGL rendering! (crash if done during, won't work if done after)
void Camera::setFov(float fov)
{
	//calculate aspect ratio
	const SDL_VideoInfo* videoInfo = SDL_GetVideoInfo();
	float aspectRatio = (float) videoInfo->current_w / (float) videoInfo->current_h;
	
	//setting up projection...
	glMatrixMode(GL_PROJECTION);
	
	//initialise projection matrix to identity
	glLoadIdentity();

	//apply a Frustum to projection matrix
	glFrustum (-aspectRatio, aspectRatio, -1.0, 1.0, fov, 1000);
}

