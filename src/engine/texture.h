//========================================================================
//
// Copyright (c) 2010 Daniel Flahive
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

#ifndef ENGINE_TEXTURE_H
#define ENGINE_TEXTURE_H

#include <fstream>
#include <string>
#include <map>
#include "renderable.h"
#include "vbo.h"
#include "vertex.h"
#include "GL/glew.h"
#include "SDL.h"
#include "SDL_image.h"

class Texture
{
public:
	Texture();
	~Texture();

	void load(std::string filename);
	void load(SDL_Surface* textureSurface, GLint format);
	void cleanup();
	void bind();

private:
	bool initialized;
	GLuint id;
	SDL_Surface* surface;
};

#endif
