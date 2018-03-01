#include "stdafx.h"
#include <iostream>

#ifndef POINT_H
#define POINT_H

using namespace std;

class Point {
private:
	float Px, Py, Size;
	float Cr, Cg, Cb;

public:
	//Constructor
	Point();
	Point(float, float, float);
	Point(float, float, float, float, float, float);
	Point(const Point&);
	~Point();

	//Getters and Setters
	float GetX()const;
	float GetY()const;
	float GetSize()const;

	void SetX(float);
	void SetY(float);
	void SetSize(float);
	void SetRBG(float, float, float);

	//Functions
	void Draw();

	//Operator Overloading
};

/** CONSTRUCTORS **/
Point::Point() {

}

Point::Point(float x, float y, float s) {
	Px = x; Py = y; Size = s;
}
Point::Point(float x, float y, float s, float r, float b, float g) {
	Px = x; Py = y; Size = s;
	Cr = r; Cb = b; Cg = g;
}

Point::Point(const Point &p) {
	Px = p.Px; Py = p.Py; Size = p.Size;
	Cr = p.Cr; Cb = p.Cb; Cg = p.Cg;
}

Point::~Point() {
	cout << "~Point()" << endl;
}

/** GETTERS AND SETTERS **/
void Point::SetX(float x) { Px = x; }
void Point::SetY(float y) { Py = y; }
void Point::SetSize(float s) { Size = s; }
void Point::SetRBG(float r, float b, float g) { Cr = r; Cb = b; Cg = g; }

float Point::GetX()const { return Px; }
float Point::GetY()const { return Py; }
float Point::GetSize()const { return Size; }

/** Functions **/
void Point::Draw() {

}
#endif // !POINT_H
	