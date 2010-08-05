//========================================================================
//
// Copyright (c) 2010 Daniel Collins, Daniel Flahive
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

#ifndef ENGINE_MD2_H
#define ENGINE_MD2_H

#include <fstream>
#include <string>
#include <vector>
#include "renderable.h"
#include "vbo.h"
#include "vertex.h"
#include "GL/glew.h"
#include "texture.h"

class Md2Header
{
	public:
		int ident;
		int version;
		int skinWidth;
		int skinHeight;
		int sizeOfFrame;
		int numberOfSkins;
		int numberOfVertices;
		int numberOfTextureCoordinates;
		int numberOfTriangles;
		int numberOfOpenGlCommands;
		int numberOfFrames;
		int offsetToSkins;
		int offsetToTextureCoordinates;
		int offsetToTriangles;
		int offsetToFrames;
		int offsetToOpenGlCommands;
		int offsetToEnd;
};

const int md2Magic = 844121161;
const int md2Version = 8;

typedef char Md2SkinName[64];

class Md2VertexCompressed
{
	public:
		unsigned char v[3];
		unsigned char normalIndex;
};

class Md2Vertex
{
	public:
		float v[3];
		unsigned char normalIndex;
};


class Md2Triangle
{
	public:
		unsigned short vertex[3];
		unsigned short st[3];
};

class Md2Frame
{
	public:
		float scale[3];
		float translation[3];
		char name[16];
		Md2Vertex* vertices;
		~Md2Frame();
};

class Md2OpenGlCommand
{
	public:
		float s;
		float t;
		int index;
};

class Md2AnimationInfo
{
	public:
		int start;
		int end;
};

class Md2Model : public Renderable
{
	private:
		Md2Header header;
		Md2SkinName* skins;
		TextureCoordinate* textureCoordinates;
		Md2Triangle* triangles;
		Md2Frame* frames;
		int* openGlCommands;
		Texture* textures;

	public:
		Md2Model(vector3 position, vector3 orientation, vector3 newVelocity, vector3 newAngularVelocity, vector3 scaleFactor, std::string fileName);
		~Md2Model();
		void draw();
};


#endif //ENGINE_MD2_H
