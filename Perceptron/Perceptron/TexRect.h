#ifndef TexRect_h
#define TexRect_h

#if defined WIN32
#include <freeglut.h>
#include "../windows/SOIL.h"
#elif defined __APPLE__
#include <GLUT/glut.h>
#include <SOIL.h>
#else
#include <GL/freeglut.h>
#include <SOIL.h>
#endif

class TexRect {
public:
    float x;
    float y;
    float w;
    float h;

	const char* Red;
	const char* Green;

	GLuint Color;


    TexRect (const char*, float, float, float, float);
	TexRect(const char*, const char*, float, float, float, float);
    
    void draw();
	void drawPoint(bool);
    
    bool contains(float, float);

	void setX(float);
	void setY(float);
};

#endif
