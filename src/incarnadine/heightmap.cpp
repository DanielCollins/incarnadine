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

#include "heightmap.h"

using namespace incarnadine;

Heightmap::Heightmap(std::string filename)
{
   surface = IMG_Load(filename.c_str());
   if(!surface) throw 1;
}

Heightmap::~Heightmap()
{
   if(surface) SDL_FreeSurface(surface);
}

unsigned int getpixel(SDL_Surface *s, int x, int y) 
{
   return ((unsigned int*) s->pixels)[y * (s->pitch / sizeof(unsigned int)) + x];
}

void Heightmap::draw()
{
   unsigned char r, g, b;
   int t;
   if(SDL_LockSurface(surface) < 0) throw 1;
   for(int y = 0; y < surface->h + 1; ++y)
   {
      t = y + 1;
      glBegin(GL_TRIANGLE_STRIP);
      glColor3b(0, 255, 255);
      for(int x = 0; x < surface->w; ++x)
      {
         SDL_GetRGB(getpixel(surface, x, y), surface->format, &r, &g, &b);
         glVertex3i((int) x, (int) r, (int) y);
         SDL_GetRGB(getpixel(surface, x, t), surface->format, &r, &g, &b);
         glVertex3i((int) x, (int) r, (int) t);
      }
      glEnd();
   }
}


