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

#include "triangle.h"

Triangle::Triangle(vector3 position, vector3 forward, vector3 up, float scaleFactor) : Primitive (position, forward, up, scaleFactor)
{
	load();
}

void Triangle::load()
{
	Vertex vertexData;
	std::vector<Vertex> vertices;

	vertexData.colour.r = 1.0;
	vertexData.colour.g = 0.0;
	vertexData.colour.b = 0.0;
	vertexData.colour.a = 1.0;
	vertexData.position.x = 0.0;
	vertexData.position.y = 1.0;
	vertexData.position.z = 0.0;
	vertices.push_back(vertexData);

	vertexData.colour.r = 0.0;
	vertexData.colour.g = 1.0;
	vertexData.colour.b = 0.0;
	vertexData.colour.a = 1.0;
	vertexData.position.x = 1.0;
	vertexData.position.y = -1.0;
	vertexData.position.z = 0.0;
	vertices.push_back(vertexData);

	vertexData.colour.r = 0.0;
	vertexData.colour.g = 0.0;
	vertexData.colour.b = 1.0;
	vertexData.colour.a = 1.0;
	vertexData.position.x = -1.0;
	vertexData.position.y = -1.0;
	vertexData.position.z = 0.0;
	vertices.push_back(vertexData);

	vbo->setVertices(vertices);
}