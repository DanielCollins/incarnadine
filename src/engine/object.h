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

#ifndef ENGINE_OBJECT_H
#define ENGINE_OBJECT_H

#include "tools.h"

namespace incarnadine
{
   using namespace cml;

   class Object
   {
      public:
         Object(vector3 position, vector3 orientation, vector3 velocity,
                  vector3 angularVelocity, vector3 acceleration, vector3 angularAcceleration);
         vector3 getPosition();
         /*void setVelocity(vector3 v);
         void setAngularVelocity(vector3 v);*/
         void localRotate(vector3 eulerRotation);
         void localRotate(iquaternion q);
         void localRotateX(float angle);
         void localRotateY(float angle);
         void localRotateZ(float angle);
         void setVelocity(vector3 v);
         void setAngularVelocity(vector3 v);
         void goTo(vector3 location);
         void localTranslate(vector3 displacement);
         void globalTranslate(vector3 displacement);
         void updatePosition(unsigned int deltaTicks);

      protected:
         vector3 position, velocity, acceleration;
         iquaternion orientation, angularVelocity, angularAcceleration;
   };
}
#endif //ENGINE_OBJECT_H

