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

#ifndef INCARNADINE_LABEL_H_
#define INCARNADINE_LABEL_H_

#include <string>
#include "GL/glew.h"
#include "SDL.h"
#include "widget.h"
#include "font.h"
#include "vertex.h"

namespace incarnadine
{
   class Label : public Widget
   {
      public:
         Label(TrueTypeFont*, std::string, Colour);
         std::string getText();
         void setText(std::string);
         TrueTypeFont* getFont();
         void setFont(TrueTypeFont*);
         Colour getTextColour();
         void setTextColour(Colour tc);

      protected:
         bool dirty;
         std::string text;
         TrueTypeFont *font;
         void updateTexture();
         Colour textColour;
   };
}

#endif //INCARNADINE_LABEL_H_

