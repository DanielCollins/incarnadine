//========================================================================
//
// Copyright (c) 2010 Daniel Collins, Daniel Flahive
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

#include "test.h"


const float targetTimePerFrame = 0.001;
const float mouseSensitivity = 0.001;

Incarnadine* engine;
Camera* camera;
Scene* scene;

Slot<Exiting>* ExitingSlot;
Slot<KeyEvent>* KeyEventSlot;
Slot<MouseMove>* MouseMoveSlot;

int main(int argc, char* argv[])
{	
	vector3 cameraPosition(0.0, 0.0, 0.0);
	vector3 cameraOrientation(0.0, 0.0, -180);
	vector3 cameraVelocity(0.0, 0.0, 0.0);
	vector3 cameraAngularVelocity(0.0, 0.0, 0.0);
		
	camera = new Camera(cameraPosition, cameraOrientation, cameraVelocity, cameraAngularVelocity, 90.0f);
	scene = new Scene();	
	engine = new Incarnadine(camera, scene);	
	
	vector3 mPosition(0.0, 0.0, -8000.0);
	vector3 mOrientation(0.0, 0.0, 0.0);
	vector3 mVelocity(0.0, 0.0, 0.0);
	vector3 mAngularVelocity(0.0, 0.0, 0.001);
	vector3 mScale(1.0, 1.0, 1.0);
	
	StaticMesh m(mPosition, mOrientation, mVelocity, mAngularVelocity, mScale, engine->loadModel("data/models/worker/worker_body.md2"));
	scene->addObject(&m);
		
	ExitingSlot = new Slot<Exiting>(handleExit);
	ExitingSlot->connect(&(engine->input->sExiting));
	KeyEventSlot = new Slot<KeyEvent>(handleKeyEvent);
	KeyEventSlot->connect(&(engine->input->sKeyEvent));
	MouseMoveSlot = new Slot<MouseMove>(handleMouseMove);
	MouseMoveSlot->connect(&(engine->input->sMouseMove));
		
	while(true) runTest();	
	exitTestApp();
	
	return EXIT_FAILURE;
}

void runTest() 
{
	static double timeAtLastCycle = 0.0;
	static double timeAtLastPhysicsUpdate = 0.0;
	try
	{
		double currentTime = engine->getTicks();		
		unsigned int delay = (unsigned int) targetFrameRate - (currentTime - timeAtLastCycle);
		timeAtLastCycle = currentTime;
		if(delay > 0) engine->getClock()->sleep(delay);
		engine->input->update();		
		currentTime = engine->getTicks();		
		scene->updateObjects(currentTime - timeAtLastPhysicsUpdate);
		timeAtLastPhysicsUpdate = currentTime;		
		engine->renderScene();
	}
	catch (int e)
	{
		exitTestApp();
	}
}

void handleExit(Exiting e)
{
	exitTestApp();
}

void handleKeyEvent(KeyEvent e)
{
	switch (e.key)
	{
		case INC_KEY_ESCAPE:
			exitTestApp();
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
}

void exitTestApp()
{
	cleanup();
	exit(EXIT_SUCCESS);
}
