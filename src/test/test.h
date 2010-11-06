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

#ifndef TEST_H
#define TEST_H

#include <stdlib.h>

#include "incarnadine.h"
#include "scene.h"
#include "tools.h"
#include "input.h"
#include "camera.h"
#include "object.h"
#include "md2.h"
#include "staticm.h"
#include "label.h"
#include "vertex.h"
#include "clock.h"
#include "render.h"

using namespace incarnadine;

void runTest();
void exitTestApp();
void cleanup();

void handleExit(Exiting);
void handleKeyUpEvent(KeyUp);
void handleMouseMove(MouseMove);

#endif //TEST_H

