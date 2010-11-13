/* 
   Copyright (c) 2010 Daniel Flahive

   Permission to use, copy, modify, and distribute this software for any
   purpose with or without fee is hereby granted, provided that the above
   copyright notice and this permission notice appear in all copies.
 
   THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES
   WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF
   MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR
   ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES
   WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN
   ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF
   OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.
*/

#ifndef ENGINE_OBJ_H
#define ENGINE_OBJ_H


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
      Vector3 vertex[3];
      Vector3 normal[3];
      Vector3 texcoord[3];
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

         void parseLine(char *line, objGroupIter& activeGroup);
         inline void addFaceTriangle(const objFaceTriangle& face, objGroupIter activeGroup);
   
         std::map<std::string, objGroup> m_groups;
         std::vector<Vector3> m_vertices, m_normals, m_texCoords;

         unsigned int m_windowListIndex;
         bool m_useWindowList;

   };

}

#endif //ENGINE_OBJ_H

