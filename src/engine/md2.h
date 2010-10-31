/* 
   Copyright (c) 2010 Daniel Collins, Daniel Flahive

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

namespace incarnadine
{
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
         Texture** textures;
   
      public:
         Md2Model(std::string fileName);
         ~Md2Model();
         void draw();
   };

}
#endif //ENGINE_MD2_H
