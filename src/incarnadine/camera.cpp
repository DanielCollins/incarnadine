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

#include "camera.h"

using namespace incarnadine;

Camera::Camera(float newFov)
{
   setFov(newFov);
}

void Camera::setFov(float newFov)
{
   fov = newFov;
}

float Camera::getFov()
{
   return fov;
}

void Camera::updateGL()
{
   const SDL_VideoInfo *videoInfo = SDL_GetVideoInfo();
   float aspectRatio = (float) videoInfo->current_w / (float) videoInfo->current_h;
   glMatrixMode(GL_PROJECTION);
   glLoadIdentity();
   glFrustum(-aspectRatio, aspectRatio, -1.0, 1.0, fov, 100000);
   glMatrixMode(GL_MODELVIEW);
   glLoadIdentity();
   matrix44 t;
   matrix_rotation_quaternion(t, orientation * -1);
   glLoadMatrixf(t.data());
   glTranslatef(-position[0], -position[1], -position[2]);
}

