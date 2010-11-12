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

#ifndef ENGINE_RENDER_H
#define ENGINE_RENDER_H

#include <map>
#include "SDL.h"
#include "GL/glew.h"
#include "tools.h"
#include "camera.h"
#include "window.h"
#include "scene.h"
#include "renderable.h"
#include "md2.h"
#include "obj.h"

namespace incarnadine
{
   class RenderManager
   {
      public:
         RenderManager(Camera *newCamera, Scene *newScene, Window *newWindow);
         ~RenderManager();
         void draw();
         void draw(float);
         void setCamera(Camera *newCamera);
         Renderable *loadModel(std::string uri);

      private:
         Camera *camera;
         Window *window;
         Scene *scene;
         std::vector<Widget*> widgets;
         std::map<std::string, Renderable*> renderables;
   };
}

#endif //ENGINE_RENDER_H
