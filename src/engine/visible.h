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

#ifndef ENGINE_VISIBLE_H
#define ENGINE_VISIBLE_H

#include <vector>
#include "object.h"
#include "tools.h"
#include "aabb.h"

namespace incarnadine
{
   class Visible : public Object
   {
      public:
         AxisAlignedBoundingBox bound;
         vector3 scale;
         std::vector<Visible*> children;

         Visible(vector3 position, vector3 orientation, vector3 velocity, vector3 angularVelocity, vector3 newAcceleration, vector3 newAngularAcceleration, vector3 scaleFactor);
         void rescale(vector3 scaleFactor);
         vector3 getScale();
         virtual void draw() = 0;
         virtual void draw(float) = 0;
   };
}
#endif //ENGINE_VISIBLE_H
