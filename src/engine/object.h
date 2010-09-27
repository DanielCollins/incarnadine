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

#ifndef ENGINE_OBJECT_H
#define ENGINE_OBJECT_H

#include "tools.h"

namespace incarnadine
{
	using namespace cml;

	class Object
	{
		protected:
			vector3 position;
			vector3 orientation;
			vector3 velocity;
			vector3 angularVelocity;
			vector3 acceleration;
			vector3 angularAcceleration;

		public:
			Object(vector3 position, vector3 orientation, vector3 velocity,
			         vector3 angularVelocity, vector3 acceleration, vector3 angularAcceleration);
			vector3 getPosition();
			void setVelocity(vector3 v);
			void setAngularVelocity(vector3 v);
			void localRotate(vector3 eulerRotation);
			void localRotateX(float angle);
			void localRotateY(float angle);
			void localRotateZ(float angle);
			void goTo(vector3 location);
			void localTranslate(vector3 displacement);
			void globalTranslate(vector3 displacement);
			void updatePosition(unsigned int deltaTicks);
	};
}
#endif //ENGINE_OBJECT_H
