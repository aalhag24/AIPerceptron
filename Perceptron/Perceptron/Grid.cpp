#include "stdafx.h"
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

void Grid::GeneratePoints(int n) {
	cout << "Generating new Points" << endl;
	Point *a;
	float v = Vertical;
	float h = Horizontal;
	float x, y;
	int i = 0;
	do {
		y = (float)((rand() % (int)(2 * v)) - v);
		x = (float)((rand() % (int)(2 * h)) - h);
		cout << "At " << x << " " << y << endl;
		a = new Point(x, y);
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
	glColor3f(1.0, 0.0, 0.0);
	{
		glBegin(GL_LINES);
		glVertex2f(1.0, 0.0);
		glVertex2f(-1.0, 0.0);
		glEnd();

		glBegin(GL_LINES);
		glVertex2f(0.0, -1.0);
		glVertex2f(0.0, 1.0);
		glEnd();
	}

	glColor3f(1.0, 1.0, 1.0);
	float Spread = (float)(1.0 / Horizontal);
	for (float i = -1.0; i <= 1.0; i = i + Spread) {
		glBegin(GL_LINES);
			glVertex2f(i, -1.0);
			glVertex2f(i, 1.0);
		glEnd();
	}

	Spread = (float)(1.0 / Vertical);
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
		glVertex2f(-(GLfloat)0.9, -(GLfloat)1.0);
		glVertex2f(-(GLfloat)0.9, (GLfloat)1.0);
	glEnd();

	glBegin(GL_LINES);
		glVertex2f(-(GLfloat)1.0, -(GLfloat)0.9);
		glVertex2f((GLfloat)1.0, -(GLfloat)0.9);
	glEnd();

	///DRAW OFFSET POINTS
	//Inventory.DrawOffset(Horizontal, Vertical);
}