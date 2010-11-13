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

#ifndef INCARNADINE_STATICM_H_
#define INCARNADINE_STATICM_H_

#include "renderable.h"
#include "visible.h"
#include "vbo.h"
#include "tools.h"
#include "vertex.h"
#include <vector>
#include "GL/glew.h"

namespace incarnadine
{
   class StaticMesh : public Visible
   {

      public:
         StaticMesh(Vector3 scaleFactor, Renderable *newBase);
         ~StaticMesh();
         void draw();
         void draw(float);

      protected:
         Renderable *base;
   };
}
#endif //INCARNADINE_STATICM_H_

