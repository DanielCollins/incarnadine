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
#include "panel.h"

using namespace incarnadine;

void runTest();
void exitTestApp();
void cleanup();

void handleExit(Exiting);
void handleKeyEvent(KeyEvent);
void handleMouseMove(MouseMove);

#endif //TEST_H
