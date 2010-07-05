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

StaticMesh::StaticMesh(vector3 position, vector3 forward, vector3 up, vector3 scaleFactor) : Renderable (position, forward, up, scaleFactor)
{
	vbo = 0;
}

StaticMesh::~StaticMesh()
{
	if(vbo)delete vbo;
}

void StaticMesh::draw()
{
	glPushMatrix();
	glScalef(scale[0], scale[0], scale[0]);
	glTranslatef(position[0], position[1], position[2]);
	if(vbo)vbo->draw();
	glPopMatrix();
}
