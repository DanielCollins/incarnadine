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

using namespace incarnadine;

Md2Model::Md2Model(std::string fileName)
{
	std::ifstream file(fileName.c_str(), std::ios::binary);
	if(file.fail()) throw 1;
	file.read(reinterpret_cast<char*>(&header), sizeof (Md2Header));
	if(header.ident != md2Magic || header.version != md2Version) throw 1;
	skins = new Md2SkinName[header.numberOfSkins];
	textureCoordinates = new TextureCoordinate[header.numberOfTextureCoordinates];
	triangles = new Md2Triangle[header.numberOfTriangles];
	frames = new Md2Frame[header.numberOfFrames];
	openGlCommands = new int[header.numberOfOpenGlCommands];
	file.seekg(header.offsetToSkins, std::ios::beg);
	file.read(reinterpret_cast<char*>(skins), sizeof(Md2SkinName) * header.numberOfSkins);
	file.seekg(header.offsetToTextureCoordinates, std::ios::beg);
	file.read(reinterpret_cast<char*>(textureCoordinates), sizeof(TextureCoordinate) * header.numberOfTextureCoordinates);
	file.seekg(header.offsetToTriangles, std::ios::beg);
	file.read(reinterpret_cast<char*>(triangles), sizeof(Md2Triangle) * header.numberOfTriangles);
	file.seekg(header.offsetToFrames, std::ios::beg);
	for(int i = 0; i < header.numberOfFrames; i++)
	{
		file.read(reinterpret_cast<char*>(&frames[i].scale), sizeof(float) * 3);
		file.read(reinterpret_cast<char*>(&frames[i].translation), sizeof(float) * 3);
		file.read(reinterpret_cast<char*>(&frames[i].name), sizeof(char) * 16);
		Md2VertexCompressed* vertices = new Md2VertexCompressed[header.numberOfVertices];
		file.read(reinterpret_cast<char*>(vertices), sizeof(Md2VertexCompressed) * header.numberOfVertices);
		frames[i].vertices = new Md2Vertex[header.numberOfVertices];
		for(int j = 0; j < header.numberOfVertices; j++)
		{
			frames[i].vertices[j].v[0] = frames[i].scale[0] * vertices[j].v[0] + frames[i].translation[0];
			frames[i].vertices[j].v[1] = frames[i].scale[1] * vertices[j].v[1] + frames[i].translation[1];
			frames[i].vertices[j].v[2] = frames[i].scale[2] * vertices[j].v[2] + frames[i].translation[2];
		}
		delete [] vertices;
	}
	file.seekg(header.offsetToOpenGlCommands, std::ios::beg);
	file.read(reinterpret_cast<char*>(openGlCommands), sizeof(int) * header.numberOfOpenGlCommands);
	file.close();
	textures = new Texture*[header.numberOfSkins];
	for(int i = 0; i < header.numberOfSkins; i++)
	{
		textures[i] = new Texture(skins[i]);
	}
}

Md2Model::~Md2Model()
{
	for(int i = 0; i < header.numberOfSkins; i++)
	{
		delete textures[i];
	}
	delete [] textures;
	delete [] skins;
	delete [] textureCoordinates;
	delete [] triangles;
	delete [] frames;
	delete [] openGlCommands;
}

void Md2Model::draw()
{
	glPushAttrib(GL_POLYGON_BIT);
	glFrontFace(GL_CW);
	glEnable(GL_CULL_FACE);
	glCullFace(GL_BACK);

	if(header.numberOfSkins > 0) textures[0]->bind();
	
	int frame = 0;
	int maxFrame = header.numberOfFrames - 1;
	if((frame < 0) || (frame > maxFrame)) return;
	int *pGlcmds = openGlCommands;
	glColor3f(0.0, 1.0, 1.0);
	int i;
	while((i = *(pGlcmds++)) != 0)
	{
		if (i < 0)
		{
			glBegin(GL_TRIANGLE_FAN);
			i = -i;	
		}
		else
		{
			glBegin(GL_TRIANGLE_STRIP);
		}
		for(; i > 0; i--, pGlcmds += 3)
		{
			Md2OpenGlCommand *pGLcmd = reinterpret_cast<Md2OpenGlCommand*>(pGlcmds);
			Md2Frame *pFrame = &frames[frame];
			Md2Vertex *pVert = &pFrame->vertices[pGLcmd->index];			
			glTexCoord2f(pGLcmd->s, pGLcmd->t);
			glVertex3fv(pVert->v);

		}
		glEnd();
	}
	glDisable(GL_CULL_FACE);
	glPopAttrib();
}

Md2Frame::~Md2Frame()
{
	delete [] vertices;
}
