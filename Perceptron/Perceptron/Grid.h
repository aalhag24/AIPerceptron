#ifndef GRID_H
#define GRID_H

#include "Neuron.h"
#include "Line.h"

class Grid {
	int Vertical;
	int Horizontal;

	Neuron<int, int, std::string> *Perceptron;
	Line *Real;
	Line *Est;

public:
	Grid();
	Grid(int, int, int);
	Grid(const Grid&);
	~Grid();

	int GetVertical()const;
	int GetHorizontal()const;

	void SetVertical(int);
	void SetHorizontal(int);

	void draw();
	void Setup();
	void Step();
};

#endif // !GRID_H
