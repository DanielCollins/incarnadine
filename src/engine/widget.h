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

#ifndef ENGINE_PANEL_H
#define ENGINE_PANEL_H

#include "GL/glew.h"
#include "texture.h"
#include "window.h"

namespace incarnadine
{
   class Window;
   class Widget
   {
      public:
         Widget(float nx, float ny, float nw, float nh);
         void resize(float nw, float nh);
         void reposition(float nx, float ny);
         void draw();
         void setWindow(Window*);

      protected:
         float x, y, w, h, b, c, d;
         Texture *texture;
         virtual void updateTexture() = 0;
         Window *window;
   };
}

#endif //ENGINE_PANEL_H

