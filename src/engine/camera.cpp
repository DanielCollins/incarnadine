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

using namespace incarnadine;

Camera::Camera(vector3 newPosition, vector3 newOrientation, vector3 newVelocity, vector3 newAngularVelocity, vector3 newAcceleration, vector3 newAngularAcceleration, float newFov) : Object (newPosition, newOrientation, newVelocity, newAngularVelocity, newAcceleration, newAngularAcceleration)
{
	setFov(newFov);
}

void Camera::setFov(float newFov)
{
	fov = newFov;
}

float Camera::getFov()
{
	return fov;
}

void Camera::updateGL()
{
	const SDL_VideoInfo* videoInfo = SDL_GetVideoInfo();
	float aspectRatio = (float) videoInfo->current_w / (float) videoInfo->current_h;
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glFrustum(-aspectRatio, aspectRatio, -1.0, 1.0, fov, 100000);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	matrix44 t;
	matrix_rotation_quaternion(t, orientation * -1);
	glLoadMatrixf(t.data());
	glTranslatef(-position[0], -position[1], -position[2]);
}

