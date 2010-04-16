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

#ifndef SHARED_SLOT_H
#define SHARED_SLOT_H

#include "event.h"
#include "signal.h"

#include <vector>

template <Event event>
class Slot
{
	private:

		std::vector<Signal<event>*> signals;
		void (*handler)(*event);
		

	public:

		Slot(void (*newhandler)(*event))
		{
			handler = newhandler;
		};

		~Slot(){};

		void connect(Signal<event>* signal)
		{
			std::vector<Signal<event>*>::const_iterator i;
			for(i = signals.begin(); i != signals.end(); i++)
				if(signal == *i)
					return;
			signals.push_back(signal);
			signal->_acceptConnection(this);
		};

		void disconnect(Signal<event>* signal)
		{
			std::vector<Signal<event>*>::const_iterator i;
			for(i = signals.begin(); i != signals.end(); i++)
			{
				if(signal == *i)
				{
					signal->_disconnect(this);
					signals.erase(i);
					return;
				}
			}
		};

		void _fire(*event e)
		{
			handler(e);
		};
};

#endif //SHARED_SLOT_H
