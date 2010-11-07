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

#include "label.h"

using namespace incarnadine;

Label::Label(TrueTypeFont *t, std::string s, Colour tc) : Widget(0.0, 0.0, 0.0, 0.0)
{
   setText(s);
   setFont(t);
   setTextColour(tc);
}

std::string Label::getText()
{
   return text;
}

void Label::setText(std::string s)
{
   text = s;
}

TrueTypeFont* Label::getFont()
{
   return font;
}

void Label::setFont(TrueTypeFont *t)
{
   font = t;
}

Colour Label::getTextColour()
{
   return textColour;
}

void Label::setTextColour(Colour tc)
{
   textColour = tc;
}

void Label::updateTexture()
{
   if(texture) delete texture;
   texture = font->renderText(text, textColour.r, textColour.g, textColour.b);
   resize((float) texture->getWidth() / window->width(), (float) texture->getHeight() / window->height());
}

