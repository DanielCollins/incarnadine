/* 
   Copyright (c) 2010 Daniel Flahive, Daniel Collins

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

#ifndef ENGINE_TEXTURE_H
#define ENGINE_TEXTURE_H

#include <string>
#include "vertex.h"
#include "GL/glew.h"
#include "SDL.h"
#include "SDL_image.h"

namespace incarnadine
{
   class Texture
   {
      public:
         Texture(std::string filename);
         Texture(SDL_Surface* textureSurface);
         ~Texture();
         void bind();
         int getWidth();
         int getHeight();

      private:
         void load(SDL_Surface* textureSurface);
         void cleanup();
         GLuint id;
         SDL_Surface* surface;
   };
}
#endif
