//========================================================================
//
// Copyright (c) 2010 Daniel Collins
//
// This software is provided 'as-is', without any express or implied
// warranty. In no event will the authors be held liable for any damages
// arising from the use of this software.
//
// Permission is granted to anyone to use this software for any purpose,
// including commercial applications, and to alter it and redistribute it
// freely, subject to the following restrictions:
//
// 1. The origin of this software must not be misrepresented; you must not
//    claim that you wrote the original software. If you use this software
//    in a product, an acknowledgment in the product documentation would
//    be appreciated but is not required.
//
// 2. Altered source versions must be plainly marked as such, and must not
//    be misrepresented as being the original software.
//
// 3. This notice may not be removed or altered from any source
//    distribution.
//
//========================================================================

#ifndef SHARED_TOOLS_H
#define SHARED_TOOLS_H

#include "cml_config.h"   
#include <cml/cml.h>

typedef cml::vector3f vector3;
typedef cml::matrix44f_c matrix44;

#include <cmath>

#define BUFFER_OFFSET(i) ((char*)0 + (i))

#define DEGREES_FROM_RADIANS(x) ((x) * 180.0 / 3.14159265)
#define RADIANS_FROM_DEGREES(x) ((x) * 3.14159265 / 180.0)

#endif //SHARED_TOOLS_H
