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

#include "scene.h"

SceneManager::SceneManager()
{
	int vertexCount = 3;
	Vertex vertexData[vertexCount];
	vertexData[0].colour.r = 1.0;
	vertexData[0].colour.g = 0.0;
	vertexData[0].colour.b = 0.0;
	vertexData[0].colour.a = 1.0;
	vertexData[0].position.x = 0.0;
	vertexData[0].position.y = 1.0;
	vertexData[0].position.z = 0.0;
	vertexData[1].colour.r = 0.0;
	vertexData[1].colour.g = 1.0;
	vertexData[1].colour.b = 0.0;
	vertexData[1].colour.a = 1.0;
	vertexData[1].position.x = 1.0;
	vertexData[1].position.y = -1.0;
	vertexData[1].position.z = 0.0;
	vertexData[2].colour.r = 0.0;
	vertexData[2].colour.g = 0.0;
	vertexData[2].colour.b = 1.0;
	vertexData[2].colour.a = 1.0;
	vertexData[2].position.x = -1.0;
	vertexData[2].position.y = -1.0;
	vertexData[2].position.z = 0.0;

	glGenBuffers(1, (GLuint*) bufferIdentifiers[0]);
	glBindBuffer(GL_ARRAY_BUFFER, (GLuint) bufferIdentifiers[0]);
	glBufferData(GL_ARRAY_BUFFER, sizeof(Vertex) * vertexCount, vertexData, GL_DYNAMIC_DRAW);
}

SceneManager::~SceneManager()
{
	glDeleteBuffers(MAX_BUFFER_OBJECTS, bufferIdentifiers);
}

void SceneManager::rasterize()
{
	glColorPointer(4, GL_FLOAT, sizeof(Vertex), BUFFER_OFFSET(sizeof(Coordinate))); //r,g,b,a = 4
	glVertexPointer(3, GL_FLOAT, sizeof(Vertex), BUFFER_OFFSET(0)); //x,y,z = 3

	glEnableClientState(GL_VERTEX_ARRAY);
	glEnableClientState(GL_COLOR_ARRAY);

	glDrawArrays(GL_TRIANGLES, 0, 3); //vertexCount = 3

	glDisableClientState(GL_COLOR_ARRAY);
	glDisableClientState(GL_VERTEX_ARRAY);	
}
