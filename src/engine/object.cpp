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

Object::Object(vector3 newPosition, vector3 newOrientation, vector3 newVelocity, vector3 newAngularVelocity, vector3 newAcceleration, vector3 newAngularAcceleration)
{
	position = newPosition;
	velocity = newVelocity;
	acceleration = newAcceleration;
	quaternion_rotation_euler(orientation, newOrientation[0], newOrientation[1], newOrientation[2], euler_order_xyz);
	quaternion_rotation_euler(angularVelocity, newAngularVelocity[0], newAngularVelocity[1], newAngularVelocity[2], euler_order_xyz);
	quaternion_rotation_euler(angularAcceleration , newAngularAcceleration[0], newAngularAcceleration[1], newAngularAcceleration[2], euler_order_xyz);
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

void Object::localRotate(iquaternion q)
{
	orientation = orientation * q;
	orientation.normalize();
}

void Object::localRotateX(float angle)
{
	quaternion_rotate_about_local_x(orientation, angle);
	orientation.normalize();
}

void Object::localRotateY(float angle)
{
	quaternion_rotate_about_local_y(orientation, angle);
	orientation.normalize();
}

void Object::localRotateZ(float angle)
{
	quaternion_rotate_about_local_z(orientation, angle);
	orientation.normalize();
}

void Object::goTo(vector3 location)
{
	position = location;
}

void Object::localTranslate(vector3 displacement)
{
	matrix44 transform;
	matrix_rotation_quaternion(transform, orientation);
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
/*
void Object::setVelocity(vector3 v)
{
	velocity = v;
}

void Object::setAngularVelocity(vector3 v)
{
	angularVelocity = v;
}
*/
