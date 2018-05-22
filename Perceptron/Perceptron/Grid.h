#ifndef GRID_H
#define GRID_H

#include "Neuron.h"
#include "Line.h"

class Grid {
	int Vertical;
	int Horizontal;
	float inputs[2] = { -1.0, 0.5 };

	Stash Inventory;
	Line *Real;
	Line *Est;

public:
	Grid();
	Grid(int, int);
	Grid(const Grid&);
	~Grid();

	int GetVertical()const;
	int GetHorizontal()const;

	void SetVertical(int);
	void SetHorizontal(int);

	void draw();
	void GeneratePoints(int);
	void Setup();
	void Step();
};


#endif // !GRID_H
