//========================================================================
//
// Copyright (c) 2010 Daniel Collins, darkf, Daniel Flahive
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

#ifndef ENGINE_VBO_H
#define ENGINE_VBO_H

#include "SDL.h"
#include "GL/glew.h"

#include "vertex.h"
#include "tools.h"
#include <vector>

namespace incarnadine
{
   class VertexBufferObject
   {
      public:
         VertexBufferObject(std::vector<Vertex> newVertices);
         ~VertexBufferObject();
         void draw();

      private:
         unsigned int bufferIdentifier;
         unsigned int vertexCount;
   };
}

#endif //ENGINE_VBO_H
