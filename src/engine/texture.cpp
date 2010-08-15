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

#include "texture.h"

Texture::Texture()
{
	initialized = false;
	surface = 0;
}

Texture::~Texture()
{
	cleanup();
}

void Texture::load(std::string filename)
{
	SDL_Surface* textureSurface;

	if(initialized) cleanup();

	textureSurface = IMG_Load(filename.c_str());
	if(textureSurface == 0) throw 0;

	load(textureSurface, GL_RGB);
}

void Texture::load(SDL_Surface* textureSurface, GLint format)
{
	surface = textureSurface;

	glGenTextures(1, &id);

	glBindTexture(GL_TEXTURE_2D, id);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexImage2D(GL_TEXTURE_2D, 0, format, surface->w, surface->h, 0, format, GL_UNSIGNED_BYTE, surface->pixels);

	initialized = true;
}

void Texture::cleanup()
{
	if(initialized)
	{
		glDeleteTextures(1, &id);
		id = 0;
		SDL_FreeSurface(surface);
		surface = 0;
		initialized = false;
	}
}

void Texture::bind()
{
	glBindTexture(GL_TEXTURE_2D, id);
}
