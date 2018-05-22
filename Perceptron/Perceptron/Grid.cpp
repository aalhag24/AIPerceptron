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
	Perceptron = new Neuron(50, Horizontal, Vertical);
}
Grid::Grid(int a, int x, int y) {
	Horizontal = x;
	Vertical = y;

	Real = new Line(Vertical, true);
	Est = new Line(Vertical, false);
	Perceptron = new Neuron(a, Horizontal, Vertical);
}
Grid::Grid(const Grid & Old) {
	Vertical = Old.GetVertical();
	Horizontal = Old.GetHorizontal();
}
Grid::~Grid() {
	delete Perceptron;
	delete Real;
	delete Est;
	cout << " Deleting Grid" << endl;
}

/// Getters and Setters
int Grid::GetVertical()const { return Vertical; }
int Grid::GetHorizontal()const { return Horizontal; }

void Grid::SetVertical(int b) { Vertical = b; }
void Grid::SetHorizontal(int a) { Horizontal = a; }

void Grid::draw() {
	///DRAW POINTS as normal
	Perceptron->draw(Horizontal, Vertical);

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
void Grid::Setup(){
	
}
void Grid::Step(){
}
