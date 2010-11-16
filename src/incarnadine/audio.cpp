/* 
   Copyright (c) 2010 Daniel Collins

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

#include "audio.h"

using namespace incarnadine;

AudioManager::AudioManager()
{
   int rate = 22050;
   Uint16 audio_format = AUDIO_S16SYS;
   int channels = 2;
   int buffers = 4096;
   if(Mix_OpenAudio(rate, audio_format, channels, buffers) < 0) throw 1;
   Mix_AllocateChannels(1);
}

AudioManager::~AudioManager()
{
   sounds.clear();
   Mix_CloseAudio();
}

Sound *AudioManager::loadSound(std::string uri)
{
   Sound *s;
   std::map<std::string, Sound*>::iterator i = sounds.find(uri);
   if(i != sounds.end()) return i->second;
   s = new Sound(uri);
   sounds.insert(std::pair<std::string, Sound*>(uri, s));
   return s;
}

