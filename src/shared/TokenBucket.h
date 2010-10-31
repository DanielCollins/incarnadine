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

#ifndef SHARED_TOKENBUCKET_H
#define SHARED_TOKENBUCKET_H

template <class Packet>
class TokenBucket
{
   private:
      int tokens;
      int fillRate;
      int capacity;
      int lastTime;

   public:
   
      TokenBucket(int t=0, int f=1, int c=1, int ti=0) : tokens(t), fillrate(f), capacity(c), time(ti) {}
     
      bool consume(Packet packet, int time)
      {
         tokens += (time - lastTime) * fillrate;
         if(tokens > capacity) tokens = capacity;
         if(tokens > 0)
         {
            //Some code to let the packet through goes here!
            tokens--;
            return true;
         }
         return false
      }
};

#endif //SHARED_TOKENBUCKET_H
