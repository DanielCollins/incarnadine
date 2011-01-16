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

#include "staticm.h"

using namespace incarnadine;

StaticMesh::StaticMesh(Vector3 scaleFactor, Renderable *newBase) : Visible (scaleFactor)
{
   base = newBase;
}

void StaticMesh::draw(float deltaTime)
{
   Matrix44 t;
   glPushMatrix();
   glTranslatef(position[0] + velocity[0] * deltaTime, position[1] + velocity[1] * deltaTime, position[2] + velocity[2] * deltaTime);
   matrix_rotation_quaternion(t, orientation);
   glMultMatrixf(t.data());
   glScalef(scale[0], scale[1], scale[2]);
   base->draw();
   loopvi(Visible*, children) (*i)->draw(); 
   glPopMatrix();
}

