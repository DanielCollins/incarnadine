/* 
   Copyright (c) 2010 Daniel Collins, David Forrest, Daniel Flahive

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

#ifndef INCARNADINE_INPUTSIGNALS_H_
#define INCARNADINE_INPUTSIGNALS_H_

#include "dispatch.h"
#include "keydef.h"
#include "hatdef.h"

namespace incarnadine
{
   class MouseMove
   {
      public:
         int x;
         int y;
         int xrel;
         int yrel;
   };

   class MouseClick{};

   class KeyUp
   {
      public:
         Key key;
   };
   
   class KeyDown
   {
      public:
         Key key;
   };

   class HorizontalJoystickMotion
   {
      public:
         int position;
   };

   class VerticalJoystickMotion
   {
      public:
         int position;
   };

   class JoystickButtonUp
   {
      public:
         unsigned char button;
   };

   class JoystickButtonDown
   {
      public:
         unsigned char button;
   };
   
   class JoystickHatMotion
   {
      public:
         unsigned char hat;
         HatPosition position;
   };
   
   class Exiting{};
}

#endif //INCARNADINE_INPUTSIGNALS_H_

