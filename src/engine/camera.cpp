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
#include <GL/glfw.h>

Camera::Camera(Vector3 newPosition, Vector3 newForward, Vector3 newUp, float fov) : Object (newPosition, newForward, newUp)
{
	setFov(fov);
}

Camera::update()
{
	//build a look-at matrix
    matrix44 view;
    matrix_look_at_RH(view, position, foward, up);
    
    //future matrix inputs modify model view...
    glMatrixMode(GL_MODELVIEW);
    
    //apply Object to scene
    glLoadMatrixf(view.data());
	return;
}

//This function is not safe to call during openGL rendering! (crash if done during, won't work if done after)
Camera::setFov(float fov)
{
	//calculate aspect ratio
	int width;
	int height;
	glfwGetWindowSize(&width, &height);
    float ratio = (float) width / (float) height;
    
    //setting up projection...
	glMatrixMode(GL_PROJECTION);
	
	//initialise projection matrix to identity
	glLoadIdentity();
	
	//apply a Frustum to projection matrix
    glFrustum (-ratio, ratio, -1.0, 1.0, fov, 1000);
}

