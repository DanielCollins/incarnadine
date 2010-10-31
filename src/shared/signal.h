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
