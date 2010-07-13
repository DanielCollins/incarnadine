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

#ifndef ENGINE_MD2_H
#define ENGINE_MD2_H

class Md2Header
{
	public:
		int ident;
		int version;
		int skinwidth;
		int skinheight;
		int framesize;
		int num_skins;
		int num_vertices;
		int num_st;
		int num_tris;
		int num_glcmds;
		int num_frames;
		int offset_skins;
		int offset_st;
		int offset_tris;
		int offset_frames;
		int offset_glcmds;
		int offset_end;
};

typedef char Md2SkinName[64];

class Md2Vertex
{
	public:
		unsigned char v[3];
		unsigned char normalIndex;
};

class Md2TextureCoordinate
{
	public:
		short s;
		short t;
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
		Md2Vertex *vertices;
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

class Md2Model
{
//stub
};

#endif //ENGINE_MD2_H
