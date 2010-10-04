//========================================================================
//
// Copyright (c) 2010 Daniel Flahive
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

#ifndef ENGINE_OBJMODEL_H
#define ENGINE_OBJMODEL_H


#include <exception>
#include <cctype>
#include <cstring>
#include <map>
#include <vector>
#include <string>
#include <fstream>
#include "GL/glew.h"
#include "renderable.h"
#include "tools.h"

namespace incarnadine
{
	struct objFaceTriangle
	{
		vector3 vertex[3];
		vector3 normal[3];
		vector3 texcoord[3];
		bool hasNormals;
		bool hasTexCoords;
	};

	struct objGroup
	{
		std::vector<objFaceTriangle>* faces;
		bool smooth;
	};

	typedef std::map<std::string, objGroup>::iterator objGroupIter;

	class ObjModel : public Renderable
	{
	public:
		ObjModel(std::string filename);
		~ObjModel();

		void onContextReset();
		void draw();

	private:

		void parseLine(char* line, objGroupIter& activeGroup);
		inline void addFaceTriangle(const objFaceTriangle& face, objGroupIter activeGroup);
	
		std::map<std::string, objGroup> m_groups;
		std::vector<vector3> m_vertices, m_normals, m_texCoords;

		unsigned int m_displayListIndex;
		bool m_useDisplayList;

	};

}

#endif
