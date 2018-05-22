#ifndef NEURON_H
#define NEURON_H

#include "stdafx.h"
#include "freeglut\freeglut.h"

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

struct Point {
	float Px, Py, RPx, RPy;
	float CR, CG, CB;
	bool Active;
	Point() :Px(0.0f), Py(0.0f) { SetState(false); }
	Point(float x, float y) :Px(x), Py(y) { SetState(false); }
	Point(float x, float y, bool correct): 
		Px(x), Py(y) { SetState(correct); }
	void SetState(bool correct){
		Active = correct;
		if (correct) { CR = 0.0f; CG = 1.0f; CB = 0.0f; }
		else{ CR = 1.0f; CG = 0.0f; CB = 0.0f; }
	}
	void SetRelative(int H, int V) {
		RPx = Px / H; RPy = Py / V;
	}
	bool operator==(const Point& p)const {
		if (Px == p.Px && Py == p.Py)
			return true;
		else return false;
	}
	bool operator=(const Point& p) {
		Px = p.Px; Py = p.Py;
		SetState(p.Active);
	}
};

class Neuron {
private:
	std::vector<Point*> List;
	float weight[2];
	int length;

	void drawAt(Point*);
	void RandWeight();
	int guess(float[]);
	int sign(float);

public:
	//Constructor
	Neuron();
	Neuron(int,int,int);
	Neuron(const Neuron&);
	~Neuron();

	//Functions
	void draw();
	void GeneratePoints(int, int, int);

	//Operator Overloading
	bool contains(Point*);
	bool contains(float, float);
};

#endif // !NEURON_H
	