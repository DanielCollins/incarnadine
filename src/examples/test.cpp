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

#include "test.h"

using namespace incarnadine;

const int targetUpdateTimeDelta = 1000 / 50;
const int maximumFrameSkip = 10;
const float mouseSensitivity = 0.0001;

Incarnadine *engine;
RenderManager *renderer;
Camera *camera;
Scene *scene;
Window *window;
TrueTypeFont *font;
Label *tp;
Clock *timer;
InputManager *input;
FontManager *fonts;

Slot<Exiting> *ExitingSlot;
Slot<KeyUp> *KeyUpSlot;
Slot<MouseMove> *MouseMoveSlot;

int main(int argc, char *argv[])
{   
   camera = new Camera(90.0f);
   camera->setOrientation(vector3(0.0, 0.0, -180));

   scene = new Scene();   
   window = new Window("Incarnadine test");
   engine = new Incarnadine();
   renderer = new RenderManager(camera, scene, window);
   timer = new Clock();
   fonts = new FontManager();
   font = fonts->loadFont("data/fonts/bitstream/VeraMoBd.ttf", 12);
   input = new InputManager(window);
   Colour c = {0.0, 0.0, 0.0};
   tp = new Label(font, "fps: 0", c);
   window->addWidget(tp);

   StaticMesh worker(vector3(1.0, 1.0, 1.0), renderer->loadModel("data/models/worker/worker_body.md2"));
   worker.setPosition(vector3(0.0, 0.0, -8000.0));
   worker.setAngularVelocity(vector3(0.0, 0.0, 0.001));
   scene->addObject(&worker);

   StaticMesh axis(vector3(1.0, 1.0, 1.0), renderer->loadModel("data/models/axis/axis.obj"));
   axis.setPosition(vector3(0.0, 0.0, -8000.0));
   scene->addObject(&axis);
      
   ExitingSlot = new Slot<Exiting>(handleExit);
   ExitingSlot->connect(&(input->sExiting));
   KeyUpSlot = new Slot<KeyUp>(handleKeyUpEvent);
   KeyUpSlot->connect(&(input->sKeyUp));
   MouseMoveSlot = new Slot<MouseMove>(handleMouseMove);
   MouseMoveSlot->connect(&(input->sMouseMove));
      
   runTest();   
   
   return EXIT_FAILURE;
}

void runTest() 
{
   int skippedFrames = 0;
   int frames = 0;
   unsigned int nextCycle = 0;
   static unsigned int lastCycle = timer->getTicks(); 
   while(true)
   {
      skippedFrames = 0;
      while(timer->getTicks() >= nextCycle && skippedFrames <= maximumFrameSkip)
      {
         input->update();
         scene->updateObjects(timer->getTicks() - lastCycle);
         lastCycle = nextCycle;
         nextCycle += targetUpdateTimeDelta;
         ++skippedFrames;
      }
      while(nextCycle > timer->getTicks())
      {
         renderer->draw((nextCycle - timer->getTicks()) / targetUpdateTimeDelta);
         ++frames;
      }
      std::stringstream out;
      unsigned int x = (timer->getTicks() - lastCycle) / 1000;
      if(x > 1)
         out<<"fps: "<<(float) frames / x;
      else
         out<<"fps: out of range (high)";
      ((Label*)tp)->setText(out.str());
      if(timer->getTicks() < nextCycle) timer->sleep(nextCycle - timer->getTicks());
   }
}

void handleExit(Exiting e)
{
   exitTestApp();
}

void handleKeyUpEvent(KeyUp e)
{
   switch (e.key)
   {
      case INC_KEY_ESCAPE:
         exitTestApp();
      case INC_KEY_UP:
      case INC_KEY_W:
      {
         camera->translate(vector3(0.0, 0.0, -500.0));
         break;
      }
      case INC_KEY_S:
      case INC_KEY_DOWN:
      {
         camera->translate(vector3(0.0, 0.0, 500.0));
         break;
      }
      case INC_KEY_A:
      case INC_KEY_LEFT:
      {
         camera->translate(vector3(0.0, -50.0, 0.0));
         break;
      }
      case INC_KEY_D:
      case INC_KEY_RIGHT:
      {
         camera->translate(vector3(0.0, 50.0, 0.0));
         break;
      }
   }
}

void handleMouseMove(MouseMove e)
{
   float yAngle = -e.xrel * mouseSensitivity;
   float xAngle = -e.yrel * mouseSensitivity;
   if(yAngle != 0)
      camera->rotateY(yAngle);
   if(xAngle != 0)
      camera->rotateX(xAngle);
}

void exitTestApp()
{
   delete timer;
   delete ExitingSlot;
   delete MouseMoveSlot;
   delete engine;
   delete camera;
   delete scene;
   delete window;
   delete tp;
   delete renderer;
   delete input;
   delete fonts;
   exit(EXIT_SUCCESS);
}
