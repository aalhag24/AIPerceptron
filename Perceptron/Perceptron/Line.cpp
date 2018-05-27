#include "stdafx.h"
#include "Line.h"
#include <cstdlib>
#include <ctime>
#include <cmath>

Line::Line(bool s = false){
	if (s) { CB = 1.0; CR = 0.0; }
	else { CR = 1.0; CB = 0.0; }

	float w = random(1, 10);
	float z = random(1, 40);
	this->m = (float)w / (float)z;
		std::cout << "Slope " << this->m << std::endl;
	this->b = 0.0;
}
Line::Line(float m, float b, bool s = false){
	if (s) { CB = 1.0; CR = 0.0; }
	else { CR = 1.0; CB = 0.0; }
	this->m = m;
	this->b = b;
		std::cout << "Slope " << this->m << std::endl;
}
Line::~Line(){
}

void Line::draw(){
	glLineWidth(2.5); 
	glColor3f(CR, 0.0, CB);
	glBegin(GL_LINES);
		glVertex2f(-1.0, A + b);
		glVertex2f(1.0, B + b);
	glEnd();
}

void Line::setup(int h){
	A = m * (-(float)h);
	B = m * ((float)h);
}
int Line::random(int low, int high) {
	if (low > high) return high;
	return low + (std::rand() % (high - low + 1));
}
