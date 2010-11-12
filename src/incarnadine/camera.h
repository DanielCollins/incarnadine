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

#ifndef ENGINE_CAMERA_H
#define ENGINE_CAMERA_H

#include "object.h"
#include "SDL.h"
#include "GL/glew.h"
#include "tools.h"

extern vector3 zeroVector;

namespace incarnadine
{
   class Camera : public Object
   {
      public:
         Camera(vector3 position, vector3 orientation, vector3 newVelocity, vector3 newAngularVelocity, vector3 newAcceleration, vector3 newAngularAcceleration, float newFov);
         void updateGL();
         void setFov(float newFov);
         float getFov();

      private:
         float fov;
   };
}

#endif //ENGINE_CAMERA_H

