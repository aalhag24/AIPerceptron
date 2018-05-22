#ifndef POINT_H
#define POINT_H

#include "stdafx.h"
#include "freeglut\freeglut.h"
#include "TexRect.h"

#include <iostream>
#include <vector>
#include <stdlib.h>
#include <freeglut.h>
#include <cmath> 

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif
/// REMOVE THIS LATTER
using namespace std;

class Point {
private:
	float Px, Py;
	float APx, APy;
	float CR, CG, CB;
	float weight[2];
	bool Active;

	void drawAt(float, float);
	void RandomizeWeight();
	int guess(float[]);
	int sign(float);

public:
	//Constructor
	Point();
	Point(float, float);
	Point(float, float, bool);
	Point(const Point&);
	~Point();

	//Getters and Setters
	float GetX()const;
	float GetY()const;
	bool GetState()const;

	void SetX(float);
	void SetY(float);
	void SetState(bool);

	//Functions
	void draw(int, int);

	//Operator Overloading
	bool operator==(const Point&)const;
	bool contain(float, float);
};

class PointStash {
	std::vector<Point*> List;
public:
	PointStash();
	~PointStash();

	void add(Point*);
	void Draw(int, int);

	bool Contains(Point*);
	bool Contains(float, float);
};


#endif // !POINT_H
	