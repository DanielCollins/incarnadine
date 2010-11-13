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

using namespace incarnadine;

StaticMesh::StaticMesh(Vector3 scaleFactor, Renderable *newBase) : Visible (scaleFactor)
{
   base = newBase;
}

StaticMesh::~StaticMesh()
{
}

void StaticMesh::draw()
{
   glPushMatrix();
   Matrix44 t;
   matrix_rotation_quaternion(t, orientation);
   glMultMatrixf(t.data());
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
   Matrix44 t;
   matrix_rotation_quaternion(t, orientation);
   glMultMatrixf(t.data());
   glScalef(scale[0], scale[1], scale[2]);
   glTranslatef(position[0] + velocity[0] * deltaTime, position[1] + velocity[1] * deltaTime, position[2] + velocity[2] * deltaTime);
   base->draw();
   std::vector<Visible*>::iterator i;
   for(i = children.begin(); i != children.end(); i++) (*i)->draw(); 
   glPopMatrix();
}

