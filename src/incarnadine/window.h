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

#ifndef INCARNADINE_DISPLAY_H_
#define INCARNADINE_DISPLAY_H_

#include <string>
#include <vector>
#include "SDL.h"
#include "GL/glew.h"
#include "widget.h"
#include "tools.h"

namespace incarnadine
{
   const int SCREEN_WIDTH = 640;
   const int SCREEN_HEIGHT = 480;

   class Widget;
   class Window
   {
     public:
         Window(std::string, int=SCREEN_WIDTH, int=SCREEN_HEIGHT, bool=false);
         ~Window();
         void update();
         int width();
         int height();
         void addWidget(Widget*);
         void removeWidget(Widget*);

      private:
         SDL_Surface *surface;
         std::vector<Widget*> widgets;
         void drawWidgets();
         bool fullscreen;
   };
}

#endif //INCARNADINE_DISPLAY_H_

