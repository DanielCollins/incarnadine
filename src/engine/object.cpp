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

Object::Object(vector3 newPosition, vector3 newForward, vector3 newUp)
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
	vector3 v1 = up * - sin(angle);
	vector3 v2 = forward * cos(angle));
	forward = (v1 + v2).normalize();

	//Y'= Z' ^ X'
	up = normalize(cross(forward, left));
}

void Object::localRotateY(float angle)
{
	//Y' = Y
    
	//Z' = sin(angle).X+cos(angle).Z
	vector3 v1 = left * sin(angle);
	vector3 v2 = forward * cos(angle);
	forward = normalize(v1 + v2);

	//X' = Y' ^ Z'
	left = normalize(cross(up, forward));
}


void Object::localRotateZ(float angle)
{
	//Z' = Z
	
	//X' =
	vector3 v1 = left * cos(angle);
	vector3 v2 = forward * - sin(angle);
	left = normalize(v1 + v2);
	
	//Y' =
	up = normalize(cross(forward, left));
}

void Object::goTo(vector3 location)
{
	position = location;
}

void Object::localTranslate(vector3 displacement)
{
	position[0] = displacement.[0] * left[0] + displacement[1] * up[0] + displacement[2] * forward[0];
	position[1] = displacement[0] * left[1] + displacement[1] * up[1] + displacement[2] * forward[1]; 
	position[2] = displacement[0] * left[2] + displacement[1] * up[2] + displacement[2] * forward[2];
}

void Object::globalTranslate(vector3 displacement)
{
	position = position + displacement;
}


