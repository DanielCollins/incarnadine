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

#include "md2.h"

Md2Model::Md2Model(vector3 position, vector3 orientation, vector3 newVelocity, vector3 newAngularVelocity, vector3 scaleFactor, std::string fileName) : Renderable (position, orientation, newVelocity, newAngularVelocity, scaleFactor)
{
	std::ifstream file(fileName.c_str(), std::ios::binary);
	if(file.fail())throw 1;
	file.read(reinterpret_cast<char*>(&header), sizeof(Md2Header));
	if(header.ident != md2Magic) throw 1;
	if(header.version != md2Version) throw 1;
	skins = new Md2SkinName[header.numberOfSkins];
	file.seekg(header.offsetToSkins, std::ios::beg);
	file.read(reinterpret_cast<char*>(skins), header.numberOfSkins * sizeof(Md2SkinName));
	textureCoordinates = new Md2TextureCoordinate[header.numberOfTextureCoordinates];
	file.seekg(header.offsetToTextureCoordinates, std::ios::beg);
	file.read(reinterpret_cast<char*>(textureCoordinates), header.numberOfTextureCoordinates * sizeof(Md2TextureCoordinate));
	triangles = new Md2Triangle[header.numberOfTriangles];
	file.seekg(header.offsetToTriangles, std::ios::beg);
	file.read(reinterpret_cast<char*>(triangles), header.numberOfTriangles * sizeof(Md2Triangle));
	frames = new Md2Frame[header.numberOfFrames];
	file.seekg(header.offsetToFrames, std::ios::beg);
	for(int i = 0; i < header.numberOfFrames; i++)
	{
		float translation[3];
		float scale[3];
		std::vector<Vertex> vertexData;
		Vertex newVertex;
		frames[i].vertices = new Md2Vertex[header.numberOfVertices];
		file.read(reinterpret_cast<char*>(&scale), sizeof(float) * 3);
		file.read(reinterpret_cast<char*>(&translation), sizeof(float) * 3);
		file.read(reinterpret_cast<char*>(&frames[i].name), sizeof(char) * 16);
		file.read(reinterpret_cast<char*>(frames[i].vertices), header.numberOfVertices * sizeof(Md2Vertex));
		for(int j = 0; j < header.numberOfVertices; j++)
		{
			frames[i].vertices[j].v[0] = frames[i].vertices[j].v[0] * scale[0] + translation[0];
			frames[i].vertices[j].v[1] = frames[i].vertices[j].v[1] * scale[1] + translation[1];
			frames[i].vertices[j].v[2] = frames[i].vertices[j].v[2] * scale[2] + translation[2];
			newVertex.position.x = (float) frames[i].vertices[j].v[0];
			newVertex.position.y = (float) frames[i].vertices[j].v[1];
			newVertex.position.x = (float) frames[i].vertices[j].v[2];
			newVertex.colour.r = 1.0;
			newVertex.colour.b = 0.0;
			newVertex.colour.g = 1.0;
			newVertex.colour.a = 1.0;
			vertexData.push_back(newVertex);
		}
		frameBuffers.push_back(new VertexBufferObject(vertexData));
	}
	openGLCommands = new int[header.numberOfOpenGLCommands];
	file.seekg(header.offsetToOpenGLCommands, std::ios::beg);
	file.read(reinterpret_cast<char*>(openGLCommands), header.numberOfOpenGLCommands * sizeof(int));
	file.close();
}

Md2Model::~Md2Model()
{
	delete [] skins;
	skins = 0;
	delete [] textureCoordinates;
	textureCoordinates = 0;
	delete [] triangles;
	triangles = 0;
	delete [] frames;
	frames = 0;
	delete [] openGLCommands;
	openGLCommands = 0;
	frameBuffers.erase();
}

void Md2Model::draw()
{
	glPushMatrix();
	glRotatef(orientation[0], 1, 0, 0);
	glRotatef(orientation[1], 0, 1, 0);
	glRotatef(orientation[2], 0, 0, 1);
	glScalef(scale[0], scale[1], scale[2]);
	glTranslatef(position[0], position[1], position[2]);
	std::vector<Renderable*>::iterator i;
	frameBuffers[0].draw();
	for(i = children.begin(); i != children.end(); i++) (*i)->draw(); 
	glPopMatrix();
}

Md2Frame::~Md2Frame()
{
	delete [] vertices;
	vertices = 0;
}
