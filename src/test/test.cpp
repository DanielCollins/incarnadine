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


#include <GL/glfw.h>

int main()
{
	bool running = true;

	glfwInit();

	if(!glfwOpenWindow(800, 600, 0, 0, 0, 0, 0, 0, GLFW_FULLSCREEN))
	{
		glfwTerminate();
		return 0;
	}

	while(running)
	{
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		glLoadIdentity();
		glTranslatef(0.0f,0.0f,-6.0f);

		glBegin(GL_TRIANGLES);
		  glColor3f(1.0f,0.0f,0.0f);
		  glVertex3f(0.0f, 1.0f, 0.0f);
		  glColor3f(0.0f,1.0f,0.0f);
		  glVertex3f(-1.0f,-1.0f, 0.0f);
		  glColor3f(0.0f,0.0f,1.0f);
		  glVertex3f(1.0f,-1.0f, 0.0f);
		glEnd();

		glfwSwapBuffers();

		running = !glfwGetKey(GLFW_KEY_ESC)
					&& glfwGetWindowParam(GLFW_OPENED);
	}

	glfwTerminate();
	return 0;
}
