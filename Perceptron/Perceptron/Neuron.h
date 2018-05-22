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
	float Px, Py;
	float APx, APy;
	float CR, CG, CB;
	Point() :Px(0.0f), Py(0.0f),
		APx(0.0f), APy(0.0f),
		CR(0.0f), CB(0.0f), CG(0.0f) {}
	Point(float x, float y): Px(x), Py(y),
		APx(0.0f), APy(0.0f),
		CR(0.0f), CB(0.0f), CG(0.0f) {}
	Point(float x, float y, float r, float g, float b): 
		Px(x), Py(y),
		APx(0.0f), APy(0.0f),
		CR(r), CB(b), CG(g) {}
	void SetAbs(float h, float v) {
		APx = Px + h; APy = Py + v;
	}
	void SetColor(float r, float g, float b){
		CR = r; CG = g; CB = b;
	}
};

class Neuron {
private:
	Point *P;
	float weight[2];
	int length;
	bool Active;

	void drawAt(float, float);
	void RandomizeWeight();
	int guess(float[]);
	int sign(float);

public:
	//Constructor
	Neuron();
	Neuron(float, float);
	Neuron(float, float, bool);
	Neuron(const Neuron&);
	~Neuron();

	//Getters and Setters
	float GetX()const;
	float GetY()const;
	bool GetState()const;
	int GetL()const;

	void SetX(float);
	void SetY(float);
	void SetState(bool);

	//Functions
	void draw(int, int);

	//Operator Overloading
	bool operator==(const Neuron&)const;
	bool contain(float, float);
};

class Stash {
	std::vector<Neuron*> List;
public:
	Stash();
	~Stash();

	void add(Neuron*);
	void Draw(int, int);

	bool Contains(Neuron*);
	bool Contains(float, float);
};


#endif // !NEURON_H
	