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

#include "clock.h"

using namespace incarnadine;

unsigned int Clock::getTicks()
{
   return SDL_GetTicks();
}

void Clock::sleep(unsigned int delay)
{
   SDL_Delay(delay);
}
;
tm *Clock::getUTCTime()
{
   time_t ttime;
   time(&ttime);
   return gmtime(&ttime);
}

tm *Clock::getLocalTime()
{
   time_t ttime;
   time(&ttime);
   return localtime(&ttime);
}
