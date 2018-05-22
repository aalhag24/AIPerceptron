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

class Neuron {
private:
	float Px, Py;
	float APx, APy;
	float CR, CG, CB;
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
	