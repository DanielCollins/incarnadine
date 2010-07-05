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

#include "vbo.h"

VertexBufferObject::VertexBufferObject()
{
	bufferIdentifier = 0;
	glGenBuffers(1, (GLuint*) &bufferIdentifier);
}

VertexBufferObject::~VertexBufferObject()
{
	glDeleteBuffers(1, (GLuint*) &bufferIdentifier);
}

void VertexBufferObject::setVertices(std::vector<Coordinate> newCoordinates, std::vector<Colour> newColours)
{
	if(newCoordinates.size() != newColours.size() || newCoordinates.size() == 0) return; 
	coordinates = newCoordinates;
	colours = newColours;
	glBindBuffer(GL_ARRAY_BUFFER, (GLuint) bufferIdentifier);
	glBufferData(GL_ARRAY_BUFFER, (sizeof(Coordinate) + sizeof(Colour)) * coordinates.size() , 0, GL_DYNAMIC_DRAW);
	glBufferSubData(GL_ARRAY_BUFFER, (GLintptr) BUFFER_OFFSET(0), sizeof(Coordinate) * coordinates.size(), &coordinates[0]);
	glBufferSubData(GL_ARRAY_BUFFER, (GLintptr) BUFFER_OFFSET(sizeof(Coordinate) * coordinates.size()), sizeof(Colour) * colours.size(), &colours[0]);
}

void VertexBufferObject::draw()
{
	if(bufferIdentifier == 0 || coordinates.size() == 0 || coordinates.size() != colours.size()) return;	
	glBindBuffer(GL_ARRAY_BUFFER, (GLuint) bufferIdentifier);
	glVertexPointer(3, GL_FLOAT, 0, BUFFER_OFFSET(0));
	glColorPointer(4, GL_FLOAT, 0, BUFFER_OFFSET(sizeof(Coordinate) * coordinates.size()));
	glEnableClientState(GL_VERTEX_ARRAY);
	glEnableClientState(GL_COLOR_ARRAY);
	glDrawArrays(GL_TRIANGLES, 0, coordinates.size());
	glDisableClientState(GL_COLOR_ARRAY);
	glDisableClientState(GL_VERTEX_ARRAY);	
}
