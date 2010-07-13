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
	vbo = 0;
	std::ifstream file(fileName.c_str (), std::ios::binary);
	if(file.fail())throw 1;
	file.read(reinterpret_cast<char *>(&header), sizeof(Md2Header));
	if(header.ident != Md2Magic) throw 1;
	if(header.version != Md2Version) throw 1;
	file.close();
}

Md2Model::~Md2Model()
{
	if(vbo)delete vbo;
}

void Md2Model::draw()
{
}
