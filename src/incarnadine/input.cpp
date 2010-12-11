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
   SDL_Event event;
   static unsigned char ignored = 0;
   
   while(SDL_PollEvent(&event))
   {
      switch(event.type)
      {
         case SDL_KEYDOWN:
         {
            KeyDown e;
            e.key = (Key) event.key.keysym.sym;
            sKeyDown.fire(&e);
            break;
         }
         case SDL_KEYUP:
         {
            KeyUp e;
            e.key = (Key) event.key.keysym.sym;
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
               if(ignored < 5)
               {
                 ++ignored;
                 break;
               }    
               MouseMove e;
               e.x = event.motion.x;
               e.y = event.motion.y;
               e.xrel = event.motion.xrel;
               e.yrel = event.motion.yrel;
               sMouseMove.fire(&e);
            }
            break;
         }
         case SDL_JOYAXISMOTION:
         {
            if(event.jaxis.axis == 0)
            {
               HorizontalJoystickMotion e;
               e.position = event.jaxis.value;
               sHorizontalJoystickMotion.fire(&e);
            }
            else if(event.jaxis.axis == 1)
            {          
               VerticalJoystickMotion e;
               e.position = event.jaxis.value;
               sVerticalJoystickMotion.fire(&e);
            }
            break;
         }
         case SDL_JOYBUTTONDOWN:
         {
            JoystickButtonDown e;
            e.button = event.jbutton.button;
            sJoystickButtonDown.fire(&e);
            break;
         }
         case SDL_JOYBUTTONUP:
         {
            JoystickButtonUp e;
            e.button = event.jbutton.button;
            sJoystickButtonUp.fire(&e);
            break;
         }
         case SDL_JOYHATMOTION:
         {
            JoystickHatMotion e;
            e.hat = event.jhat.hat;
            e.position = (HatPosition) event.jhat.value;
            sJoystickHatMotion.fire(&e);
         }
         case SDL_JOYBALLMOTION:
         {
            JoystickBallMotion e;
            e.xrel = event.jball.xrel;
            e.yrel = event.jball.yrel;
            sJoystickBallMotion.fire(&e);
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

