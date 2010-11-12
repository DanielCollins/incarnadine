/* 
   Copyright (c) 2010 Daniel Collins, Daniel Flahive

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

#include "input.h"

using namespace incarnadine;

InputManager::InputManager(Window *d)
{
   window = d;
   ignoreNextMouseMove = false;
   SDL_ShowCursor(SDL_DISABLE);
   SDL_WM_GrabInput(SDL_GRAB_ON);
   resetMousePosition();
}

InputManager::~InputManager()
{
   SDL_WM_GrabInput(SDL_GRAB_OFF);
   SDL_ShowCursor(SDL_ENABLE);
}

void InputManager::update()
{
   SDL_Event Event;
   
   while(SDL_PollEvent(&Event))
   {
      switch(Event.type)
      {
         case SDL_KEYDOWN:
         {
            KeyDown e;
            e.key = (Key) Event.key.keysym.sym;
            sKeyDown.fire(&e);
            break;
         }
         case SDL_KEYUP:
         {
            KeyUp e;
            e.key = (Key) Event.key.keysym.sym;
            sKeyUp.fire(&e);
            break;
         }
         case SDL_MOUSEMOTION:
         {
            if (ignoreNextMouseMove)
            {
               ignoreNextMouseMove = false;
            }
            else
            {
               MouseMove e;
               e.x = Event.motion.x;
               e.y = Event.motion.y;
               e.xrel = Event.motion.xrel;
               e.yrel = Event.motion.yrel;

               sMouseMove.fire(&e);
            }
            break;
         }   
         case SDL_QUIT:
         {
            Exiting e;
            sExiting.fire(&e);
         }
      }
   }
}

void InputManager::resetMousePosition()
{
   ignoreNextMouseMove = true;
   SDL_WarpMouse(window->width() / 2, window->height() / 2);
}
