#include "stdafx.h"
#include "Grid.h"
#include <stdlib.h>
#include <freeglut.h>
#include <iostream>
#include <cstdlib>
#include <ctime>

/// Constructors
Grid::Grid() {
	Horizontal = 16;
	Vertical = 16;

	srand(time(0));
	Real = new Line(Vertical, true);
		Real->setup(Horizontal);
	Est = new Line(Vertical, false);
		Est->setup(Horizontal);
}
Grid::Grid(int x, int y) {
	Horizontal = x;
	Vertical = y;

	Real = new Line(Vertical, true);
	Est = new Line(Vertical, false);
}
Grid::Grid(const Grid & Old) {
	Vertical = Old.GetVertical();
	Horizontal = Old.GetHorizontal();
}
Grid::~Grid() {
	delete Real;
	delete Est;
	cout << " Deleting Grid" << endl;
}

/// Getters and Setters
int Grid::GetVertical()const { return Vertical; }
int Grid::GetHorizontal()const { return Horizontal; }

void Grid::SetVertical(int b) { Vertical = b; }
void Grid::SetHorizontal(int a) { Horizontal = a; }

void Grid::GeneratePoints(int n) {
	Point *a;
	int i = 0;
	a = new Point(0, 0, true);
	Inventory.add(a);
	float v = (float)Vertical, h = (float)Horizontal, x, y;
	do {
		y = (float)((rand() % (int)(2 * v)) - v);
		x = (float)((rand() % (int)(2 * h)) - h);
		//cout << "New Point: " << x << " " << y << endl;
		if (!Inventory.Contains(x,y)) { a = new Point(x, y);  Inventory.add(a); i++; }
	} while (i < n);
}
void Grid::draw() {
	///DRAW POINTS as normal
	Inventory.Draw(Horizontal, Vertical);
	
	///DRAW LINES
	Real->draw();
	Est->draw();

	///DRAW CENTERED GRID
	glColor3f(0.8, 0.8, 0.8);
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

	glColor3f(0.3, 0.3, 0.3);
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
}
