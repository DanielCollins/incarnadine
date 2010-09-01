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

template <class EventType>
class Signal
{
	private:
		std::vector<Slot<EventType>*> slots;
		bool enabled;

	public:

		Signal()
		{
			enabled = true;
		}

		~Signal()
		{
		}

		void fire(EventType* e)
		{
			if(enabled)
			{
				typename std::vector<Slot<EventType>*>::const_iterator i;
				for(i = slots.begin(); i != slots.end(); i++)
					(*i)->_fire(e);
			}
		}

		void _acceptConnection(Slot<EventType>* newSlot)
		{
			typename std::vector<Slot<EventType>*>::const_iterator i;
			for(i = slots.begin(); i != slots.end(); i++)
				if(newSlot == *i)
					return;
			slots.push_back(newSlot);
		}

		void _disconnect(Slot<EventType>* oldSlot)
		{
			typename std::vector<Slot<EventType>*>::const_iterator i;
			for (i = slots.begin(); i != slots.end(); i++)
			{
				if(oldSlot == *i)
				{
					slots.erase(i);
					return;
				}
			}
		}

		bool isEnabled()
		{
			return enabled;
		}

		void setEnabled(bool newState)
		{
			enabled = newState;
		}
};

#endif //SHARED_SIGNAL_H
