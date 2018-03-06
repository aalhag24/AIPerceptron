#include "stdafx.h"
#include <iostream>

#ifndef VECTOR_H
#include <vector>
#endif // !VECTOR_H

#ifndef POINT_H
#define POINT_H

/// REMOVE THIS LATTER
using namespace std;

class Point {
private:
	float Px, Py;
	float CR, CG;
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
	void SetRBG(bool);

	//Functions

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
void Point::SetRBG(bool correct) { 
	if (correct) { CR = 0.0; CG = 1.0; }
	else { CR = 1.0; CG = 0.0; }
}

float Point::GetX()const { return Px; }
float Point::GetY()const { return Py; }


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

bool PointStash::Contains(Point a) {
	for (std::vector<Point>::iterator it = List.begin(); it != List.end(); ++it)
		if (*it == a) return true;
	return false;
}

#endif // !POINT_H
	