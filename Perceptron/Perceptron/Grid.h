#ifndef GRID_H
#define GRID_H

#include "Point.h"

class Grid {
	int Vertical;
	int Horizontal;
	bool State;

	void drawOrigin();
	void drawCorner();

	PointStash Inventory;

public:
	Grid();
	Grid(int, int, bool);
	Grid(const Grid&);

	int GetVertical()const;
	int GetHorizontal()const;

	void SetVertical(int);
	void SetHorizontal(int);

	void draw();
	void SetState(bool);

	void GeneratePoints(int);
};


#endif // !GRID_H
