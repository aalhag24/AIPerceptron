#ifndef STDAFX_H
#include "stdafx.h"
#endif // !STDAFX_H

#ifndef FREEGLUT_H
#include <freeglut.h>
#endif // !FREEGLUT_H

#ifndef GRID_H
#define GRID_H

class Grid {
	int Vertical;
	int Horizontal;
	bool State;

	void drawOrigin();
	void drawCorner();

public:
	Grid();
	Grid(int, int, bool);
	Grid(const Grid&);

	virtual int GetVertical()const;
	virtual int GetHorizontal()const;

	virtual void SetVertical(int);
	virtual void SetHorizontal(int);

	virtual void draw();
	virtual void Contain(int, int);
	virtual void SetState(bool);
};

Grid::Grid() {
	Horizontal = 16;
	Vertical = 16;
	State = false;
}

Grid::Grid(int x, int y, bool s) {
	Horizontal = x;
	Vertical = y;
	State = s;
}

Grid::Grid(const Grid & Old) {
	Vertical = Old.GetVertical();
	Horizontal = Old.GetHorizontal();
}

int Grid::GetVertical()const {
	return Vertical;
}

int Grid::GetHorizontal()const {
	return Horizontal;
}

void Grid::SetVertical(int b) {
	Vertical = b;
}

void Grid::SetHorizontal(int a) {
	Horizontal = a;
}

void Grid::SetState(bool) {

}

void Grid::draw() {
	if (State) {
		drawOrigin();
	}
	else {
		drawCorner();
	}
}

void Grid::Contain(int x, int y) {

}

void Grid::drawOrigin() {
	float Spread = (float)(1.0 / GetHorizontal());
	for (float i = -1.0; i <= 1.0; i = i + Spread) {
		glBegin(GL_LINES);
		glVertex2f(i, -1.0);
		glVertex2f(i, 1.0);
		glEnd();
	}

	Spread = (float)(1.0 / GetVertical());
	for (float i = -1.0; i <= 1.0; i = i + Spread) {
		glBegin(GL_LINES);
		glVertex2f(1.0, i);
		glVertex2f(-1.0, i);
		glEnd();
	}
}

void Grid::drawCorner() {

}
#endif // !GRID_H
