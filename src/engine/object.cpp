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

Object::Object(vector3 newPosition, vector3 newForward, vector3 newUp)
{
	position = newPosition;
	forward = newForward;
	up = newUp;

	left = normalize(cross(forward, up));
	up = normalize(cross(left, forward));
	forward = normalize(forward);
}

vector3 Object::getPosition()
{
	return position;
}

void Object::localRotate(vector3 direction, float angle)
{
	direction = normalize(direction);
	forward = rotate_vector(forward, direction, angle);
	left = rotate_vector(left, direction, angle);
	up = rotate_vector(up, direction, angle);
}

void Object::localRotateX(float angle)
{
	forward = rotate_vector(forward, left, angle);
	up = normalize(cross(forward, left));
}

void Object::localRotateY(float angle)
{
	forward = rotate_vector(forward, up, angle);
	left = normalize(cross(up, forward));
}


void Object::localRotateZ(float angle)
{
	left = rotate_vector(left, forward, angle);
	up = normalize(cross(forward, left));
}

void Object::goTo(vector3 location)
{
	position = location;
}

void Object::localTranslate(vector3 displacement)
{
	position[0] = displacement[0] * left[0] + displacement[1] * up[0] + displacement[2] * forward[0];
	position[1] = displacement[0] * left[1] + displacement[1] * up[1] + displacement[2] * forward[1];
	position[2] = displacement[0] * left[2] + displacement[1] * up[2] + displacement[2] * forward[2];
}

void Object::globalTranslate(vector3 displacement)
{
	position = position + displacement;
}

