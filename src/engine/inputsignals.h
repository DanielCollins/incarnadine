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

#ifndef ENGINE_INPUTSIGNALS_H
#define ENGINE_INPUTSIGNALS_H

#include "events.h"

Class MouseMove : public Event
{
	public:
		int x;
		int y;
		int xrel;
		int yrel;
};

Class MouseClick : public Event {}; 

Class KeyPress : public Event {};

class KeyRelease : public Event {};

Class Exiting : public Event {};

#endif //ENGINE_INPUTSIGNALS_H