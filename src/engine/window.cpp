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

#include "window.h"

using namespace incarnadine;

Window::Window(std::string title)
{
   surface = SDL_SetVideoMode(640, 480, 16, SDL_OPENGL | SDL_HWSURFACE);
   SDL_WM_SetCaption(title.c_str(), title.c_str());
   if (!surface) throw 0;

   //require at least 5 bits per colour
   SDL_GL_SetAttribute(SDL_GL_RED_SIZE, 5);
   SDL_GL_SetAttribute(SDL_GL_GREEN_SIZE, 5);
   SDL_GL_SetAttribute(SDL_GL_BLUE_SIZE, 5);

   //require at least 2 byte depth buffer
   SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 16);

   //require double buffering
   SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
}

Window::~Window()
{
   if (surface)
      surface = 0;
}

//Show next frame
void Window::update()
{
   drawWidgets();
   glFlush();
   SDL_GL_SwapBuffers();
}

int Window::width()
{
   return surface->w;
}

int Window::height()
{
   return surface->h;
}

void Window::drawWidgets()
{
   glDisable(GL_DEPTH_TEST);
   glMatrixMode(GL_PROJECTION);
   glPushMatrix();
   glLoadIdentity();
   glOrtho(0.0, 1.0, 0.0, 1.0, -1.0, 1.0);
   glMatrixMode(GL_MODELVIEW);
   glPushMatrix();
   glLoadIdentity();
   std::vector<Widget*>::const_iterator i = widgets.begin();
   std::vector<Widget*>::const_iterator end = widgets.end();
   for(;i != end; i++) (*i)->draw();
   glMatrixMode(GL_PROJECTION);
   glPopMatrix();
   glMatrixMode(GL_MODELVIEW);
   glPopMatrix();
   glEnable(GL_DEPTH_TEST);
}

void Window::addWidget(Widget *widget)
{
  std::vector<Widget*>::const_iterator i = widgets.begin();
  std::vector<Widget*>::const_iterator end = widgets.end();
  for(;i != end; i++) if(widget == *i) return;
  widgets.push_back(widget);
}

void Window::removeWidget(Widget *widget)
{
  std::vector<Widget*>::iterator i = widgets.begin();
  std::vector<Widget*>::iterator end = widgets.end();
  for(;i != end; i++)
  {
    if(widget == *i)
    {
      widgets.erase(i);
      return;
    }
  }
}

