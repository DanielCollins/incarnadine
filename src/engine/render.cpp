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

#include "render.h"

using namespace incarnadine;

RenderManager::RenderManager(Camera* newCamera, Scene* newScene, Display* newDisplay)
{
   camera = newCamera;
   scene = newScene;
   display = newDisplay;
   glShadeModel(GL_SMOOTH);
   glEnable(GL_TEXTURE_2D);
   glEnable(GL_DEPTH_TEST);
   glDepthMask(GL_TRUE);
   glEnable(GL_CULL_FACE);      
   glEnable(GL_BLEND); 
   glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
   glClearColor (1.0, 1.0, 1.0, 0.0);
}

void RenderManager::draw()
{
   camera->updateGL();
   glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
   scene->rasterize();
   std::vector<Panel*>::const_iterator i = panels.begin();
   std::vector<Panel*>::const_iterator end = panels.end();
   for(;i != end; i++) (*i)->draw();
   display->update();
}

void RenderManager::draw(float deltaTime)
{
   camera->updateGL();
   glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
   scene->rasterize(deltaTime);
   std::vector<Panel*>::const_iterator i = panels.begin();
   std::vector<Panel*>::const_iterator end = panels.end();
   for(;i != end; i++) (*i)->draw();
   display->update();
}

void RenderManager::setCamera(Camera* newCamera)
{
   camera = newCamera;
}

void RenderManager::addPanel(Panel* panel)
{
  std::vector<Panel*>::const_iterator i = panels.begin();
  std::vector<Panel*>::const_iterator end = panels.end();
  for(;i != end; i++) if(panel == *i) return;
  panels.push_back(panel);
}

void RenderManager::removePanel(Panel* panel)
{
  std::vector<Panel*>::iterator i = panels.begin();
  std::vector<Panel*>::iterator end = panels.end();
  for(;i != end; i++)
  {
    if(panel == *i)
    {
      panels.erase(i);
      return;
    }
  }
}
