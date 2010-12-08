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

#ifndef INCARNADINE_FONT_H_
#define INCARNADINE_FONT_H_

#include <string>
#include "SDL.h"
#include "SDL_ttf.h"
#include "texture.h"
#include "vertex.h"

namespace incarnadine
{
   class TrueTypeFont
   {
      public:
         TrueTypeFont(std::string, int);
         ~TrueTypeFont();
         Texture *renderText(std::string, Colour c);
         void setSize(int);

      private:
         std::string name;
         TTF_Font* font;
   };
}

#endif //INCARNADINE_FONT_H_

