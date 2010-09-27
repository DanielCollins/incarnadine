//========================================================================
//
// Copyright (c) 2010 Daniel Collins, darkf
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

#include "object.h"

using namespace incarnadine;

Object::Object(vector3 newPosition, vector3 newOrientation, vector3 newVelocity, vector3 newAngularVelocity)
{
	position = newPosition;
	orientation = newOrientation;
	velocity = newVelocity;
	angularVelocity = newAngularVelocity;
	localRotate(zero<3>());
}

vector3 Object::getPosition()
{
	return position;
}

void Object::localRotate(vector3 eulerRotation)
{
	localRotateX(eulerRotation[0]);
	localRotateY(eulerRotation[1]);
	localRotateZ(eulerRotation[2]);
}

void Object::localRotateX(float angle)
{
	orientation[0] += angle;
	while(orientation[0] >= 360.0) orientation[0] -= 360.0;
	while(orientation[0] < 0.0) orientation[0] += 360.0;
}

void Object::localRotateY(float angle)
{
	orientation[1] += angle;
	while(orientation[1] >= 360.0) orientation[1] -= 360.0;
	while(orientation[1] < 0.0) orientation[1] += 360.0;
}


void Object::localRotateZ(float angle)
{
	orientation[2] += angle;
	while(orientation[2] >= 360.0) orientation[2] -= 360.0;
	while(orientation[2] < 0.0) orientation[2] += 360.0;
}

void Object::goTo(vector3 location)
{
	position = location;
}

void Object::localTranslate(vector3 displacement)
{
	matrix44 transform;
	matrix_rotation_euler(transform, orientation[0], orientation[1], orientation[2], euler_order_xyz);
	position += transform_vector(transform, displacement);
}

void Object::globalTranslate(vector3 displacement)
{
	position = position + displacement;
}

void Object::updatePosition(unsigned int deltaTicks)
{
	localTranslate(velocity * deltaTicks);
	localRotate(angularVelocity * deltaTicks);
}

