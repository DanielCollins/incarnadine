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

#include "panel.h"

using namespace incarnadine;

Panel::Panel(float nx, float ny, float nw, float nh)
{
   reposition(nx, ny);
   resize(nw, nh);
   texture = 0;
}

void Panel::resize(float nw, float nh)
{  
   if(nw > 1.0 || nw < 0.0) throw 1;
   if(nh > 1.0 || nh < 0.0) throw 1;  
   w = nw;
   h = nh;
   c = x + w;
   d = 1 - (y + h);
}

void Panel::reposition(float nx, float ny)
{
   if(nx > 1.0 || nx < 0.0) throw 1;
   if(ny > 1.0 || ny < 0.0) throw 1;
   x = nx;
   y = ny;
   b = 1 - y;
   c = x + w;
   d = 1 - (y + h);
}

void Panel::draw()
{
   updateTexture();
   glMatrixMode(GL_PROJECTION);
   glPushMatrix();
   glLoadIdentity();
   glOrtho(0.0, 1.0, 0.0, 1.0, -1.0, 1.0);
   glMatrixMode(GL_MODELVIEW);
   glPushMatrix();
   glLoadIdentity();
   texture->bind();
   glBegin(GL_QUADS);
   glTexCoord2d(0, 0);
   glVertex2f(x, b);
   glTexCoord2d(0, 1);
   glVertex2f(x, d);
   glTexCoord2d(1, 1);
   glVertex2f(c, d);
   glTexCoord2d(1, 0);
   glVertex2f(c, b);
   glEnd();   
   glMatrixMode(GL_PROJECTION);
   glPopMatrix();
   glMatrixMode(GL_MODELVIEW);
   glPopMatrix();
}

