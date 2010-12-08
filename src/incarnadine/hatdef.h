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

#ifndef ENGINE_HATDEF_H
#define ENGINE_HATDEF_H

#include "SDL_events.h"

enum HatPosition {INC_HAT_LEFTUP = SDL_HAT_LEFTUP,
                  INC_HAT_UP = SDL_HAT_UP,
                  INC_HAT_RIGHTUP = SDL_HAT_RIGHTUP,
                  INC_HAT_LEFT = SDL_HAT_LEFT,
                  INC_HAT_CENTERED = SDL_HAT_CENTERED,
                  INC_HAT_RIGHT = SDL_HAT_RIGHT,
                  INC_HAT_LEFTDOWN = SDL_HAT_LEFTDOWN,
                  INC_HAT_DOWN = SDL_HAT_DOWN,
                  INC_HAT_RIGHTDOWN = SDL_HAT_RIGHTDOWN};


#endif //ENGINE_HATDEF_H

