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

#include "input.h"

InputManager::InputManager()
{
	//We can poll more intelligently then the default, disable it
	glfwDisable(GLFW_AUTO_POLL_EVENTS);
	
	//hide the curser, confine the curser to the window, don't confine the curser coordinates to the window size
	glfwDisable(GLFW_MOUSE_CURSOR);
	
	resetMousePosition();
}

void InputManager::update()
{
	//poll over mouse and keyboard (joystick is async)
	glfwPollEvents();
}

//Key event callback shall take int key, int press/release
void InputManager::setKeyCallback(GLFWkeyfun callback)
{
	glfwSetKeyCallback(callback);
}

void InputManager::setMousePositionCallback(GLFWmouseposfun callback)
{
	glfwSetMousePosCallback(callback);
}

void InputManager::setMouseButtonCallback(GLFWmousebuttonfun callback)
{
	glfwSetMouseButtonCallback(callback);
}

void InputManager::setMouseWheelCallback(GLFWmousewheelfun callback)
{
	glfwSetMouseWheelCallback(callback);
}

void InputManager::resetMousePosition()
{
	//for simplicity of calculations define upper left corner as mouse starting point
	glfwSetMousePos(0, 0);
}

