// stdafx.h : include file for standard system include files,
// or project specific include files that are used frequently, but
// are changed infrequently
//

#pragma once

#include "targetver.h"

#include "Grid.h"
#include "Neuron.h"
#include "App.h"
#include "GlutApp.h"

#include <stdlib.h>
#include <stdio.h>
#include <tchar.h>
#include <cstring>
#include <iostream>
#include <cmath>
#include <iostream>

#if defined WIN32
#include <freeglut.h>
#elif defined __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/freeglut.h>
#endif


// TODO: reference additional headers your program requires here
