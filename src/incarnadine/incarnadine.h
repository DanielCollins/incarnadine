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

#ifndef INCARNADINE_INCARNADINE_H_
#define INCARNADINE_INCARNADINE_H_

#include <string>
#include <map>
#include "SDL.h"
#include "SDL_image.h"
#include "SDL_ttf.h"
#include "SDL_mixer.h"
#include "GL/glew.h"
#include "window.h"
#include "input.h"
#include "render.h"
#include "camera.h"
#include "scene.h"
#include "clock.h"
#include "renderable.h"
#include "visible.h"
#include "md2.h"
#include "obj.h"
#include "font.h"

namespace incarnadine
{
   class Incarnadine
   {
      public:
         Incarnadine();
         ~Incarnadine();
   };
}
#endif //INCARNADINE_INCARNADINE_H_

