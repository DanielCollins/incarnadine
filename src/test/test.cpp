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

Incarnadine* engine;
Camera* camera;
Scene* scene;
Window* window;
TrueTypeFont* font;
Widget* tp;

Slot<Exiting>* ExitingSlot;
Slot<KeyUp>* KeyUpSlot;
Slot<MouseMove>* MouseMoveSlot;

int main(int argc, char* argv[])
{   
   vector3 cameraPosition(0.0, 0.0, 0.0);
   vector3 cameraOrientation(0.0, 0.0, -180);
   vector3 cameraVelocity(0.0, 0.0, 0.0);
   vector3 cameraAngularVelocity(0.0, 0.0, 0.0);
   vector3 cameraAcceleration(0.0, 0.0, 0.0);
   vector3 cameraAngularAcceleration(0.0, 0.0, 0.0);
      
   camera = new Camera(cameraPosition, cameraOrientation, cameraVelocity, cameraAngularVelocity, cameraAcceleration, cameraAngularAcceleration, 90.0f);
   scene = new Scene();   
   window = new Window("Incarnadine test");
   engine = new Incarnadine(camera, scene, window);
   font = engine->loadFont("data/fonts/bitstream/VeraMoBd.ttf", 12);
   Colour c = {0.0, 0.0, 0.0};
   tp = new Label(font, "fps: 0", c, window);
   engine->addWidget(tp);

   vector3 mPosition(0.0, 0.0, -8000.0);
   vector3 mOrientation(0.0, 0.0, 0.0);
   vector3 mVelocity(0.0, 0.0, 0.0);
   vector3 mAngularVelocity(0.0, 0.0, 0.01);
   vector3 mAcceleration(0.0, 0.0, 0.0);
   vector3 mAngularAcceleration(0.0, 0.0, 0.0);
   vector3 mScale(1.0, 1.0, 1.0);

   StaticMesh m(mPosition, mOrientation, mVelocity, mAngularVelocity, mAcceleration, mAngularAcceleration, mScale, engine->loadModel("data/models/worker/worker_body.md2"));
   scene->addObject(&m);

   vector3 m2Position(0.0, 0.0, -8000.0);
   vector3 m2Orientation(0.0, 0.0, 0.0);
   vector3 m2Velocity(0.0, 0.0, 0.0);
   vector3 m2AngularVelocity(0.0, 0.0, 0.0);
   vector3 m2Acceleration(0.0, 0.0, 0.0);
   vector3 m2AngularAcceleration(0.0, 0.0, 0.0);
   vector3 m2Scale(1.0, 1.0, 1.0);

   StaticMesh m2(m2Position, m2Orientation, m2Velocity, m2AngularVelocity, m2Acceleration, m2AngularAcceleration, m2Scale, engine->loadModel("data/models/axis.obj"));
   scene->addObject(&m2);
      
   ExitingSlot = new Slot<Exiting>(handleExit);
   ExitingSlot->connect(&(engine->input->sExiting));
   KeyUpSlot = new Slot<KeyUp>(handleKeyUpEvent);
   KeyUpSlot->connect(&(engine->input->sKeyUp));
   MouseMoveSlot = new Slot<MouseMove>(handleMouseMove);
   MouseMoveSlot->connect(&(engine->input->sMouseMove));
      
   runTest();   
   
   return EXIT_FAILURE;
}

void runTest() 
{
   int skippedFrames = 0;
   int frames = 0;
   unsigned int nextCycle = 0;
   static unsigned int lastCycle = engine->getTicks(); 
   while(true)
   {
      skippedFrames = 0;
      while(engine->getTicks() >= nextCycle && skippedFrames <= maximumFrameSkip)
      {
         engine->input->update();
         scene->updateObjects(engine->getTicks() - lastCycle);
         lastCycle = nextCycle;
         nextCycle += targetUpdateTimeDelta;
         ++skippedFrames;
      }
      while(nextCycle > engine->getTicks())
      {
         engine->renderScene((nextCycle - engine->getTicks()) / targetUpdateTimeDelta);
         ++frames;
      }
      std::stringstream out;
      int fps = (float) (frames * 1000) / (engine->getTicks() - lastCycle);
      if(fps < 1000)
         out<<"fps: "<<fps;
      else
         out<<"fps: out of range (high)";
      ((Label*)tp)->setText(out.str());
      if(engine->getTicks() < nextCycle) engine->getClock()->sleep(nextCycle - engine->getTicks());
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
      case INC_KEY_w:
      {
         camera->localTranslate(vector3(0.0, 0.0, -500.0));
         break;
      }
      case INC_KEY_s:
      case INC_KEY_DOWN:
      {
         camera->localTranslate(vector3(0.0, 0.0, 500.0));
         break;
      }
      case INC_KEY_a:
      case INC_KEY_LEFT:
      {
         camera->localTranslate(vector3(0.0, -50.0, 0.0));
         break;
      }
      case INC_KEY_d:
      case INC_KEY_RIGHT:
      {
         camera->localTranslate(vector3(0.0, 50.0, 0.0));
         break;
      }
   }
}

void handleMouseMove(MouseMove e)
{
   float yAngle = -e.xrel * mouseSensitivity;
   float xAngle = -e.yrel * mouseSensitivity;
   if(yAngle != 0)
      camera->localRotateY(yAngle);
   if(xAngle != 0)
      camera->localRotateX(xAngle);
}

void cleanup()
{
   delete ExitingSlot;
   ExitingSlot = 0;
   delete MouseMoveSlot;
   MouseMoveSlot = 0;
   delete engine;
   engine = 0;
   delete camera;
   camera = 0;
   delete scene;
   scene = 0;
   delete window;
   window = 0;
   delete tp;
   tp = 0;
}

void exitTestApp()
{
   cleanup();
   exit(EXIT_SUCCESS);
}
