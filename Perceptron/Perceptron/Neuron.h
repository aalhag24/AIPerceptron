#include "Point.h"

#ifndef NEURON_H
#define NEURON_H

class Neuron : public Point {

private:
	bool Selected;

public:
	//Constructor
	Neuron();
	Neuron(float, float);
	Neuron(const Neuron&);
	~Neuron();

	//Getters and Setters

	//Functions

	//Operator Overloading
};

Neuron::Neuron() {

}

Neuron::Neuron(float x, float y) {

}

Neuron::Neuron(const Neuron &N) {

}

Neuron::~Neuron() {

}

#endif // !NEURON_H

