#include "Grid.h"
#include <stdlib.h>
#include <freeglut.h>

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

int Grid::GetVertical()const { return Vertical; }
int Grid::GetHorizontal()const { return Horizontal; }

void Grid::SetVertical(int b) { Vertical = b; }
void Grid::SetHorizontal(int a) { Horizontal = a; }
void Grid::SetState(bool Origin) { State = Origin; }

inline void Grid::GeneratePoints(int n) {
	Point a;
	float v = GetVertical();
	float h = GetHorizontal();
	int i = 0;
	do {
		a.SetX((rand() % (int)(2 * h) - 9) / h);
		a.SetY((rand() % (int)(2 * v) - 9) / v);
		if (!Inventory.Contains(a)) { Inventory.add(a); i++; }
	} while (i < n);
}

void Grid::draw() {
	if (State) {
		drawOrigin();
	}
	else {
		drawCorner();
	}
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

	///DRAW POINTS as normal
	Inventory.Draw(Horizontal, Vertical);
}

void Grid::drawCorner() {
	///DRAW OFFSET GRID
	glBegin(GL_LINES);
	glVertex2f(-0.9, -1.0);
	glVertex2f(-0.9, 1.0);
	glEnd();

	glBegin(GL_LINES);
	glVertex2f(-1.0, -0.9);
	glVertex2f(1.0, -0.9);
	glEnd();

	///DRAW OFFSET POINTS
	Inventory.DrawOffset(Horizontal, Vertical);
}