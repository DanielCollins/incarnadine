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

#ifndef ENGINE_TOOLS_H
#define ENGINE_TOOLS_H

#include <cmath>
#include "cml_config.h"   
#include <cml/cml.h>

typedef cml::vector3f Vector3;
typedef cml::matrix44f_c Matrix44;
typedef cml::quaternionf_p iquaternion;

#define BUFFER_OFFSET(i) ((char*)0 + (i))

#define DEGREES_FROM_RADIANS(x) ((x) * 180.0 / 3.14159265)
#define RADIANS_FROM_DEGREES(x) ((x) * 3.14159265 / 180.0)

#endif //ENGINE_TOOLS_H

