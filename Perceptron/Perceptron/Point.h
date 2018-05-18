#ifndef POINT_H
#define POINT_H

#include "stdafx.h"
#include "freeglut\freeglut.h"
#include "TexRect.h"

#include <iostream>
#include <vector>
#include <cmath> 

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif
/// REMOVE THIS LATTER
using namespace std;

class Point {
private:
	float Px, Py;
	TexRect *Image;
	bool Active;

	float Compression = 0.9f;
	float Shift = 1.0f - Compression;

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
	bool GetState()const;

	//Functions
	void draw(int, int);
	void drawOffset(int, int);

	//Operator Overloading
	bool operator==(const Point&)const;
};


class PointStash {
	std::vector<Point*> List;
public:
	PointStash();
	~PointStash();

	void add(Point*);
	void Draw(int, int);
	void DrawOffset(int, int);

	bool Contains(Point*);
};


#endif // !POINT_H
	