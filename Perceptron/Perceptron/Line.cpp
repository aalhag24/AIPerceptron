#include "stdafx.h"
#include "Line.h"
#include <cstdlib>
#include <ctime>
#include <cmath>

using namespace std;

Line::Line(int v, bool s = false){
	if (s) { CB = 1.0; CR = 0.0; }
	else { CR = 1.0; CB = 0.0; }

	float w = random(1, 10);
	float z = random(1, 40);
	this->m = (float)w / (float)z;
	//this->b = (rand() % (2 * v)) - (float)v;
		cout << this->m << endl;
}

Line::Line(float m, float b){
	this->m = m;
	//this->b = b;
}

Line::~Line(){
}

void Line::draw(){
	glLineWidth(2.5); 
	glColor3f(CR, 0.0, CB);
	glBegin(GL_LINES);
		glVertex2f(-1.0, A);
		glVertex2f(1.0, B);
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
