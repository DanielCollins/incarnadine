/* 
   Copyright (c) 2010 Daniel Flahive, Daniel Collins

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

#include "texture.h"

using namespace incarnadine;

Texture::Texture(std::string filename)
{
   surface = 0;
   SDL_Surface *s = IMG_Load(filename.c_str());
   if(s == 0) throw 0;
   load(s, GL_RGB);
}

Texture::Texture(SDL_Surface* textureSurface, GLint format)
{
   surface = 0;
   load(textureSurface, format);
}

void Texture::load(SDL_Surface* textureSurface, GLint format)
{
   surface = textureSurface;
   if(surface->format->BytesPerPixel < 2) throw 1;
   glGenTextures(1, &id);
   glBindTexture(GL_TEXTURE_2D, id);
   glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
   glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
   glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
   glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
   glTexImage2D(GL_TEXTURE_2D, 0, format, surface->w, surface->h, 0, format, GL_UNSIGNED_BYTE, surface->pixels);
}

Texture::~Texture()
{
   cleanup();
}

void Texture::cleanup()
{
   glDeleteTextures(1, &id);
   id = 0;
   if(surface)
   {
      SDL_FreeSurface(surface);
      surface = 0;
   }
}

void Texture::bind()
{
   glBindTexture(GL_TEXTURE_2D, id);
}

int Texture::getWidth()
{
   return surface->w;
}

int Texture::getHeight()
{
   return surface->h;
}

