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

vector3 zeroVector(0.0, 0.0, 0.0);

Camera::Camera(vector3 newPosition, vector3 newForward, vector3 newUp, float newFov) : Object (newPosition, newForward, newUp)
{
	setFov(newFov);
}

matrix44 Camera::lookAtMatrix()
{
	matrix44 view;
	matrix_look_at_RH(view, zeroVector, forward, up);
	return view;
}

void Camera::setFov(float newFov)
{
	fov = newFov;
}

float Camera::getFov()
{
	return fov;
}

