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

#include "vbo.h"

VertexBufferObject::VertexBufferObject()
{
	bufferIdentifier = 0;
	vertexCount = 0;
	glGenBuffers(1, (GLuint*) &bufferIdentifier);
}

~VertexBufferObject::VertexBufferObject()
{
	glDeleteBuffers(1, bufferIdentifier);
}

void VertexBufferObject::setVertices(int length, Vertex newVertices[])
{
	vertices = newVertices;
	vertexCount = length;
	glBindBuffer(GL_ARRAY_BUFFER, (GLuint) bufferIdentifier);
	glBufferData(GL_ARRAY_BUFFER, sizeof(Vertex) * vertexCount, vertices, GL_DYNAMIC_DRAW);
}

void VertexBufferObject::draw()
{
	if(bufferIdentifier == 0 || vertexCount == 0) return;
	
	glBindBuffer(GL_ARRAY_BUFFER, (GLuint) bufferIdentifier);
	
	glColorPointer(4, GL_FLOAT, sizeof(Vertex), BUFFER_OFFSET(sizeof(Coordinate)));
	glVertexPointer(3, GL_FLOAT, sizeof(Vertex), BUFFER_OFFSET(0));

	glEnableClientState(GL_VERTEX_ARRAY);
	glEnableClientState(GL_COLOR_ARRAY);

	glDrawArrays(GL_TRIANGLES, 0, vertexCount);

	glDisableClientState(GL_COLOR_ARRAY);
	glDisableClientState(GL_VERTEX_ARRAY);	
}