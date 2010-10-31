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
