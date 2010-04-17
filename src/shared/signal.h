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

#ifndef SHARED_SIGNAL_H
#define SHARED_SIGNAL_H

#include "event.h"
#include "slot.h"

#include <vector>

template <Event event>
class Signal
{
	private:
		std::vector<Slot<event>*> slots;

	public:

		Signal(){};

		~Signal(){};

		void fire(*event e)
		{
			std::vector<Slot<event>*>::const_iterator i;
			for(i = slots.begin(); i != slots.end(); i++)
				*i->_fire(e);
		};

		void _acceptConnection(Slot<event>* newSlot)
		{
			std::vector<Slot<event>*>::const_iterator i;
			for(i = slots.begin(); i != slots.end(); i++)
				if(newSlot == *i)
					return;
			slots.push_back(newSlot);	
		};

		void _disconnect(Slot<event>* oldSlot)
		{
			std::vector<Slot<event>*>::const_iterator i;
			for (i = slots.begin(); i != slots.end(); i++)
			{
				if(oldSlot == *i)
				{
					slots.erase(i);
					return;
				}
			}
		};
};

#endif //SHARED_SIGNAL_H
