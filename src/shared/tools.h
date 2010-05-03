#ifndef SHARED_TOOLS_H
#define SHARED_TOOLS_H

#include "cml_config.h"   
#include <cml/cml.h>

typedef cml::vector3f vector3;
typedef cml::matrix44f_c matrix44;

#include <cmath>

#define BUFFER_OFFSET(i) ((char*)0 + (i))

#endif //SHARED_TOOLS_H