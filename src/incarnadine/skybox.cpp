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

#include "skybox.h"

using namespace incarnadine;

void Skybox::draw()
{
   glDisable(GL_BLEND);
   glDisable(GL_DEPTH_TEST);
   glBegin(GL_TRIANGLES);
   glColor3f(0.0f, 0.5f, 0.5f);
   glVertex3f(0.0f, 100.0f, -100.0f);
   glVertex3f(-100.0f, -100.0f, -100.0f);
   glVertex3f(100.0f, -100.0f, -100.0f);
   glEnd();
   glEnable(GL_BLEND);
   glEnable(GL_DEPTH_TEST);
}

