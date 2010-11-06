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

#include "font.h"

using namespace incarnadine;

TrueTypeFont::TrueTypeFont(std::string filename, int size)
{
   font = TTF_OpenFont(filename.c_str(), size);
   if(!font) throw 0;
}

TrueTypeFont::~TrueTypeFont()
{
   TTF_CloseFont(font);
}

Texture* TrueTypeFont::renderText(std::string text, char r, char g, char b)
{ 
   SDL_Color colour = {r,g,b,0};
   return new Texture(TTF_RenderText_Blended(font, text.c_str(), colour));;
}

