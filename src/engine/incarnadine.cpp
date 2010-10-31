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

#include "incarnadine.h"

using namespace incarnadine;

Incarnadine::Incarnadine(Camera* newCamera, Scene* newScene, Display* newDisplay)
{
   SDL_Init(SDL_INIT_VIDEO);

   int imgFlags = IMG_INIT_PNG | IMG_INIT_JPG;
   int imgStatus = IMG_Init(imgFlags);
   if ((imgStatus & imgFlags) != imgFlags) throw 0;
   
   display = newDisplay;

   if(TTF_Init() == -1) throw 0;
   
   input = new InputManager(display);
   
   renderer = new RenderManager(newCamera, newScene, display);

   GLenum errorNum = glewInit();
   if (errorNum != GLEW_OK) throw 0;

}

Incarnadine::~Incarnadine()
{
   renderables.clear();

   if (input)
   {
      delete input;
      input = 0;
   }

   IMG_Quit();
   
   SDL_Quit();
}

void Incarnadine::renderScene()
{
   renderer->draw();
   GLenum errorCode = glGetError();
   if(errorCode != GL_NO_ERROR) throw 0;
}

void Incarnadine::renderScene(float timeDelta)
{
   renderer->draw(timeDelta);
   GLenum errorCode = glGetError();
   if(errorCode != GL_NO_ERROR) throw 0;
}

Renderable* Incarnadine::loadModel(std::string uri)
{
   Renderable* r;
   std::map<std::string, Renderable*>::iterator i = renderables.find(uri);
   if(i != renderables.end()) return i->second;

   std::string::size_type pos = uri.find_last_of('.');
   if (pos != std::string::npos && (uri.length() - pos - 1) > 0)
   {
      std::string extension;
      extension = uri.substr(pos + 1, uri.length() - pos - 1);

      if (extension.compare("md2") == 0)
         r = new Md2Model(uri);
      else if (extension.compare("obj") == 0)
         r = new ObjModel(uri);
      else
         throw 0;
   }

   renderables.insert(std::pair<std::string, Renderable*>(uri, r));
   return r;
}

TrueTypeFont* Incarnadine::loadFont(std::string uri, int size)
{
   TrueTypeFont* f;
   std::map<std::string, TrueTypeFont*>::iterator i = fonts.find(uri);
   if(i != fonts.end()) return i->second;
   f = new TrueTypeFont(uri, size);
   fonts.insert(std::pair<std::string, TrueTypeFont*>(uri, f));
   return f;
}

unsigned int Incarnadine::getTicks()
{
   return clock.getTicks();
}

Clock* Incarnadine::getClock()
{
   return (Clock*)&clock;
}

void Incarnadine::addPanel(Panel* p)
{
   renderer->addPanel(p);
}

void Incarnadine::removePanel(Panel* p)
{
   renderer->removePanel(p);
}
