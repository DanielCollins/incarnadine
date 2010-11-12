/* 
   Copyright (c) 2010 Daniel Collins

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
