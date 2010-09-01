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

#include "staticm.h"

StaticMesh::StaticMesh(vector3 position, vector3 orientation, vector3 newVelocity, vector3 newAngularVelocity, vector3 scaleFactor, Renderable* newBase) : Visible (position, orientation, newVelocity, newAngularVelocity, scaleFactor)
{
	base = newBase;
}

StaticMesh::~StaticMesh()
{
}

void StaticMesh::draw()
{
	glPushMatrix();
	glRotatef(orientation[0], 1, 0, 0);
	glRotatef(orientation[1], 0, 1, 0);
	glRotatef(orientation[2], 0, 0, 1);
	glScalef(scale[0], scale[1], scale[2]);
	glTranslatef(position[0], position[1], position[2]);
	base->draw();
	std::vector<Visible*>::iterator i;
	for(i = children.begin(); i != children.end(); i++) (*i)->draw(); 
	glPopMatrix();
}

void StaticMesh::draw(float deltaTime)
{
	glPushMatrix();
	glRotatef(orientation[0] + angularVelocity[0] * deltaTime, 1, 0, 0);
	glRotatef(orientation[1] + angularVelocity[1] * deltaTime, 0, 1, 0);
	glRotatef(orientation[2] + angularVelocity[2] * deltaTime, 0, 0, 1);
	glScalef(scale[0], scale[1], scale[2]);
	glTranslatef(position[0] + velocity[0] * deltaTime, position[1] + velocity[1] * deltaTime, position[2] + velocity[2] * deltaTime);
	base->draw();
	std::vector<Visible*>::iterator i;
	for(i = children.begin(); i != children.end(); i++) (*i)->draw(); 
	glPopMatrix();
}

