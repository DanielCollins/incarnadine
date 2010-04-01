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

#define MAXIMUM_FRAME_RATE 120
#define MINIMUM_FRAME_RATE 10
#define UPDATE_INTERVAL 1.0 / MAXIMUM_FRAME_RATE
#define MAX_CYCLES_PER_FRAME MAXIMUM_FRAME_RATE / MINIMUM_FRAME_RATE

Display* display;
InputManager* input;
Camera* camera;
SceneManager* scene;
RenderManager* renderer;

int main(int argc, char* argv[])
{
	display = new Display();
	if(!display->init()) return EXIT_FAILURE;
	
	input = new InputManager();
	
	vector3 cameraPosition(0.0, 0.0, 3.0);
	vector3 cameraForward(0.0, 0.0, -1.0);
	vector3 cameraUp(0.0, 1.0, 0.0);
	
	camera = new Camera(cameraPosition, cameraForward, cameraUp, 1.0);	
	scene = new SceneManager();
	renderer = new RenderManager(camera, scene, display);	
	
	while(true) runGame();

	delete display;
	display = 0;
	delete input;
	input = 0;
	delete camera;
	camera = 0;
	delete scene;
	scene = 0;
	delete renderer;
	renderer = 0;
	
	return EXIT_SUCCESS;
}

//Main Loop
void runGame() 
{
	static double timeAtLastFrame = 0.0;
	static double loopsRemaining = 0.0;
	double currentTime = SDL_GetTicks();
	double updateIterations = currentTime - timeAtLastFrame + loopsRemaining;
  
	if(updateIterations > MAX_CYCLES_PER_FRAME * UPDATE_INTERVAL)
		updateIterations = MAX_CYCLES_PER_FRAME * UPDATE_INTERVAL;
  
	while (updateIterations > UPDATE_INTERVAL)
	{
		updateIterations -= UPDATE_INTERVAL;    
		input->update();
	}
  
	loopsRemaining = updateIterations;
	timeAtLastFrame = currentTime;

	renderer->draw();
}
