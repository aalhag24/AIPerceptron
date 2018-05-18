#include "stdafx.h"
#include "Point.h"
#include <stdlib.h>
#include <freeglut.h>

/** CONSTRUCTORS **/
Point::Point() {
	Px = Py = 0.0;
	Image = new TexRect("Green.png", "Red.png", Px, Py, 0.05, 0.05);
	cout << "New Defualt Point" << endl;
}

Point::Point(float x, float y) {
	Px = x; Py = y;
	Image = new TexRect("Green.png", "Red.png", Px, Py, 0.05, 0.05);
	cout << "New Paramarized Point" << endl;
}

Point::Point(const Point &p) {
	Px = p.Px; Py = p.Py;
	Image = new TexRect("Green.png", "Red.png", Px, Py, 0.05, 0.05);
	cout << "New Copy Point" << endl;
}

Point::~Point() {
	cout << "~Point()" << endl;
}

/** GETTERS AND SETTERS **/
void Point::SetX(float x) { Px = x; }
void Point::SetY(float y) { Py = y; }
void Point::SetState(bool correct) {
	Active = correct;
}
bool Point::GetState()const {
	return Active;
}

float Point::GetX()const { return Px; }
float Point::GetY()const { return Py; }

void Point::drawAt(float X, float Y) {
	Image->setX(X);
	Image->setY(Y);
	Image->drawPoint(Active);
}

void Point::draw(int h, int v) {
	drawAt(Px / (float)h, Py / (float)v);
}

void Point::drawOffset(int h, int v) {
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

PointStash::PointStash() {
	List.clear();
}

PointStash::~PointStash() {
	cout << "~PointStash()" << endl;
}

void PointStash::add(Point *a) {
	List.push_back(a);
}

void PointStash::Draw(int h, int v) {
	for (std::vector<Point*>::iterator it = List.begin(); it != List.end(); ++it)
		(*it)->draw(h, v);
}

void PointStash::DrawOffset(int h, int v) {
	for (std::vector<Point*>::iterator it = List.begin(); it != List.end(); ++it)
		(*it)->drawOffset(h, v);
}

bool PointStash::Contains(Point *a) {
	for (std::vector<Point*>::iterator it = List.begin(); it != List.end(); ++it)
		if ((*it) == a) return true;
	return false;
}
