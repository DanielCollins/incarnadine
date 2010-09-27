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

#ifndef ENGINE_VERTEX_H
#define ENGINE_VERTEX_H

namespace incarnadine
{
/* not using vectors 3 and 4 here becuase uploading to graphics memory requires 
	vertices live in contiguious main memory to acheive a reasonable level of
	efficiency and cml::vector std::vector combo cannnot garentee this */	

	struct Colour
	{
		float r;
		float g;
		float b;
		float a;
	};

	struct TextureCoordinate
	{
		short s;
		short t;
	};

	struct Coordinate
	{
		float x;
		float y;
		float z;
	};

	struct Vertex
	{
		Coordinate position;
		Colour colour;	
	};
}
#endif //ENGINE_VERTEX_H
