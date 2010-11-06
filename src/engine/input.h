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

#ifndef ENGINE_INPUT_H
#define ENGINE_INPUT_H

#include "SDL.h"
#include "events.h"
#include "inputsignals.h"
#include "window.h"

namespace incarnadine
{
   class InputManager
   {
      public:
         Signal<KeyUp> sKeyUp;
         Signal<KeyDown> sKeyDown;
         Signal<MouseMove> sMouseMove;
         Signal<Exiting> sExiting;
         Window *window;

         InputManager(Window *d);
         ~InputManager();
         void update();
         void resetMousePosition();

      private:
         bool ignoreNextMouseMove;
   };
}

#endif //ENGINE_INPUT_H
