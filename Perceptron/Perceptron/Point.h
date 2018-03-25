#ifndef POINT_H
#define POINT_H

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <cmath> 
#include "freeglut\freeglut.h"

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif
/// REMOVE THIS LATTER
using namespace std;

class Point {
private:
	float Px, Py;
	float CR, CG;
	bool Active;

	void drawAt(float, float);

public:
	//Constructor
	Point();
	Point(float, float);
	Point(const Point&);
	~Point();

	//Getters and Setters
	float GetX()const;
	float GetY()const;

	void SetX(float);
	void SetY(float);
	void SetState(bool);

	//Functions
	void draw(int, int);
	void drawOffset(int, int);

	//Operator Overloading
	bool operator==(const Point&)const;
};

/** CONSTRUCTORS **/
Point::Point() {
	Px = Py = 0.0;
	CR = 1.0; CG = 0.0;
}

Point::Point(float x, float y) {
	Px = x; Py = y; 
	CR = 1.0; CG = 0.0;
}


Point::Point(const Point &p) {
	Px = p.Px; Py = p.Py;
	CR = 1.0; CG = 0.0;
}

Point::~Point() {
	cout << "~Point()" << endl;
}

/** GETTERS AND SETTERS **/
void Point::SetX(float x) { Px = x; }
void Point::SetY(float y) { Py = y; }
void Point::SetState(bool correct) { 
	if (correct) { CR = 0.0; CG = 1.0; }
	else { CR = 1.0; CG = 0.0; }
	Active = correct;
}

float Point::GetX()const { return Px; }
float Point::GetY()const { return Py; }

inline void Point::drawAt(float X, float Y){
	glColor3d(CR, CG, 0.0);
	float radius = 0.1;

	glBegin(GL_LINE_LOOP);
	for (int i = 0; i <= 30; i++) {
		float angle = 2.0 * M_PI * i / 30.0;
		float x = cos(angle)*radius;
		float y = sin(angle)*radius;
		glVertex2f(x+X, y+y);
	}
	glEnd();

}

void Point::draw(int h, int v) {
	drawAt(Px/(float)h, Py/(float)v);
}

void Point::drawOffset(int h, int v) {
	float Compression = 0.9;
	float Shift = 1.0 - Compression;

	float X = (float)((((Px + v) / 2) * Compression) + Shift);
	float Y = (float)((((Py + h) / 2) * Compression) + Shift);

	drawAt(X, Y);
}


/** Functions **/
bool Point::operator==(const Point &a)const {
	if (this->Px == a.Px && this->Py == a.Py)
		return true;
	return false;
}



class PointStash{
	std::vector<Point> List;
public:
	PointStash();
	~PointStash();

	void add(Point);
	void Draw(int, int);
	void DrawOffset(int, int);

	bool Contains(Point);
};

PointStash::PointStash(){
	List.clear();
}

PointStash::~PointStash(){
	cout << "~PointStash()" << endl;
}

void PointStash::add(Point a) {
	List.push_back(a);
}

inline void PointStash::Draw(int h, int v){
	for (std::vector<Point>::iterator it = List.begin(); it != List.end(); ++it)
		it->draw(h,v);
}

inline void PointStash::DrawOffset(int h, int v) {
	for (std::vector<Point>::iterator it = List.begin(); it != List.end(); ++it)
		it->drawOffset(h, v);
}

bool PointStash::Contains(Point a) {
	for (std::vector<Point>::iterator it = List.begin(); it != List.end(); ++it)
		if (*it == a) return true;
	return false;
}

#endif // !POINT_H
	