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

Panel::Panel(int nx, int ny, int nw, int nh)
{
   x = nx;
   y = ny;
   w = nw;
   h = nh;
}

void Panel::draw()
{
   glBegin(GL_QUADS);
   glColor3d(1.0, 0, 0);
   glVertex3d(x, y, -20);
   glVertex3d(x + w, y, -20);
   glVertex3d(x + w, y - h, -20);
   glVertex3d(x, y - h, -20);
   glEnd();
}

