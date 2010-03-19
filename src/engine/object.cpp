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

#include "object.h"

Object::Object(Vector3 newPosition, Vector3 newForward, Vector3 newUp)
{
	position = newPosition;
	forward = newForward;
	up = newUp;
	

	left = normalize(cross(forward, up));
	up = normalize(cross(left, forward));
	forward = normalize(forward);
}


void Object::localRotateX(float angle)
{
	//X' = X
	
    //Z' = -sin(angle).Y+cos(angle).Z
	Vector3 v1 = up * - sin(angle);
	Vector3 v2 = forward * cos(angle));
	forward = (v1 + v2).normalize();

	//Y'= Z' ^ X'
	up = normalize(cross(forward, left));
}

void Object::localRotateY(float angle)
{
	//Y' = Y
    
	//Z' = sin(angle).X+cos(angle).Z
	Vector3 v1 = left * sin(angle);
	Vector3 v2 = forward * cos(angle);
	forward = normalize(add(v1, v2));

	//X' = Y' ^ Z'
	left = normalize(cross(up, forward));
}


void Object::localRotateZ(float angle)
{
	//Z' = Z
	
	//X' =
	Vector3 v1 = left * cos(angle);
	Vector3 v2 = forward * - sin(angle);
	left = normalize(add(v1, v2));
	
	//Y' =
	up = normalize(cross(forward, left));
}

void Object::goTo(Vector3 location)
{
	position = location;
}

void Object::localTranslate(Vector3 displacement)
{
	left = displacement.[0] * left[0] + displacement[1] * up[0] + displacement[2] * forward[0];
	up = displacement[0] * left[1] + displacement[1] * up[1] + displacement[2] * forward[1]; 
	forward = displacement[0] * left[2] + displacement[1] * up[2] + displacement[2] * forward[2];
}

void Object::globalTranslate(Vector3 displacement)
{
	position = position + displacement;
}


