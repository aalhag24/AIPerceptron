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
	GLuint texture_id;
	GLuint Green;
	GLuint Red;


    TexRect (const char*, float, float, float, float);
	TexRect(const char*, const char*, float, float, float, float);
    
    void draw();
	void drawPoint(bool);
    
    bool contains(float, float);
    
    void moveUp(float rate=0.01);
    void moveDown(float rate=0.01);
    void moveLeft(float rate=0.01);
    void moveRight(float rate=0.01);

	void setX(float);
	void setY(float);
    
    void jump();
    
    bool rising;
    bool movingLeft;
   
    float xinc;
    float yinc;
};

#endif
