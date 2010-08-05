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
	if(textureSurface == 0)
		throw 0;

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
