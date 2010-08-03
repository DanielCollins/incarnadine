#include "texture.h"

Texture::Texture()
{
	initialized = false;
	surface = NULL;
}

Texture::~Texture()
{
	cleanup();
}

void Texture::load(std::string filename)
{
	if (initialized)
		cleanup();

	surface = IMG_Load(filename.c_str());
	if (surface == NULL)
		throw 0;

	glGenTextures(1, &id);

	glBindTexture(GL_TEXTURE_2D, id);
	//glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	//glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_DECAL);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, surface->w, surface->h, 0, GL_RGB, GL_UNSIGNED_BYTE, surface->pixels);

	initialized = true;
}

void Texture::cleanup()
{
	if (initialized)
	{
		// Delete the texture.
		glDeleteTextures(1, &id);
		id = 0;

		// Free the surface.
		SDL_FreeSurface(surface);
		surface = NULL;

		initialized = false;
	}
}

void Texture::bind()
{
	glBindTexture(GL_TEXTURE_2D, id);
}
