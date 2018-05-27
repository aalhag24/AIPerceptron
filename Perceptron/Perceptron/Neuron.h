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

template<class A, class B, class C>
struct Point {
	A Px, Py;
	B Label;
	C Value;
	float RPx, RPy;
	float CR, CG, CB;
	bool Active; 

	Point(){ SetState(false); }
	Point(A x, A y) :Px(x), Py(y) { SetState(false); }
	Point(A x, A y, bool correct): 
		Px(x), Py(y) { SetState(correct); }
	void SetState(bool correct){
		Active = correct;
		if (correct) { CR = 0.0f; CG = 1.0f; CB = 0.0f; }
		else{ CR = 1.0f; CG = 0.0f; CB = 0.0f; }
	}
	void SetRelative(int H, int V) {
		RPx = Px / (float)H; RPy = Py / (float)V;
	}
	void DetermineLabel(int m) {
		if (Px*m < Py)
			Label = -1;
		else
			Label = 1;
	}
	bool operator==(const Point& p)const {
		if (Px == p.Px && Py == p.Py)
			return true;
		else return false;
	}
	bool operator=(const Point& p) {
		Px = p.Px; Py = p.Py;
		SetState(p.Active);
	}
};

template<class A, class B, class C>
class Neuron {
private:
	std::vector<Point<A, B, C>*> List;
	static const int length = 2;
	float weight[length];
	float aa,bb;

	void drawAt(Point<A, B, C>*);
	void RandWeight();
	void calcLinearRegression();
	int guess(float[]);
	int sign(float);

public:
	//Constructor
	Neuron();
	Neuron(int,int,int);
	Neuron(const Neuron&);
	~Neuron();

	//Getters 
	float getSlope()const;
	float getYIntercept()const;

	//Functions
	void draw();
	void GeneratePoints(int, int, int);

	//Operator
	bool contains(Point<A, B, C>*);
	bool contains(A, A);
};

/** CONSTRUCTORS **/
template<class A, class B, class C>Neuron<A, B, C>::Neuron() {
	GeneratePoints(20, 16, 16);
	RandWeight();
	calcLinearRegression();
	std::cout << "New Defualt Neuron" << std::endl;
}
template<class A, class B, class C>Neuron<A, B, C>::Neuron(int a, int h, int v) {
	std::cout << "new Neuron" << std::endl;
	GeneratePoints(a, h, v);
	RandWeight();
	calcLinearRegression();
}
template<class A, class B, class C>Neuron<A, B, C>::Neuron(const Neuron &N) {
	List = N.List;
	RandWeight();
	std::cout << "New Copy Neuron" << std::endl;
}
template<class A, class B, class C>Neuron<A, B, C>::~Neuron() {
	for (std::vector<Point<A, B, C> *>::iterator it = List.begin(); it != List.end(); ++it)
		delete (*it);
	List.clear();
	std::cout << "~Point()" << std::endl;
}

template<class A, class B, class C>float Neuron<A, B, C>::getSlope() const {
	return aa;
}
template<class A, class B, class C>float Neuron<A, B, C>::getYIntercept() const {
	return bb;
}

/** FUNCTIONS **/
template<class A, class B, class C>void Neuron<A, B, C>::RandWeight() {
	for (int i = 0; i < length; i++) {
		weight[i] = (rand() % 200 - 100) / 100;
	}
}
template<class A, class B, class C>void Neuron<A, B, C>::calcLinearRegression() {
	float SumX = 0.0f, SumY = 0.0f;
	float StdX = 0.0f, StdY = 0.0f;
	float MeanX, MeanY, MXSquared = 0.0f, MYSquared = 0.0f;
	float r, H = 0.0f, N = List.size();
	float Top, BX, BY, Bottom;

	for (std::vector<Point<A, B, C>*>::iterator it = List.begin(); it != List.end(); ++it) {
		SumX += (*it)->Px;
		SumY += (*it)->Py;
		MXSquared += pow((*it)->Px, 2);
		MYSquared += pow((*it)->Py, 2);
		H += ((*it)->Px) * ((*it)->Py);
		//std::cout << (*it)->Px << " " << (*it)->Py << std::endl;
	}

	MeanX = SumX / N;
	MeanY = SumY / N;
	H = H * N;
	Top = H - (MeanX * MeanY);
	BX = (N*MXSquared) - pow(MeanX, 2);
	BY = (N*MYSquared) - pow(MeanY, 2);
	Bottom = sqrt(BX * BY);
	r = Top / Bottom;

	for (std::vector<Point<A, B, C>*>::iterator it = List.begin(); it != List.end(); ++it) {
		StdX += pow((*it)->Px - MeanX, 2);
		StdY += pow((*it)->Py - MeanY, 2);
	}
	StdX = sqrt(StdX / N);
	StdY = sqrt(StdY / N);

	aa = r * StdX / StdY;
	bb = MeanY - aa * MeanX;

	std::cout << "MeanX: " << MeanX << " MeanY: " << MeanY << std::endl;
	std::cout << "StdX: " << StdX << " StdY: " << StdY << std::endl;
	std::cout << "aa: " << aa << " bb: " << bb << std::endl;
}
template<class A, class B, class C>int Neuron<A, B, C>::guess(float inputs[]) {
	float sum = 0.0;
	for (int i = 0; i < length; i++) {
		sum += inputs[i] * weight[i];
	}
	int output = sign(sum);
	return output;
}
template<class A, class B, class C>int Neuron<A, B, C>::sign(float s) {
	if (s < 0)
		return -1;
	else
		return 1;
}

template<class A, class B, class C>void Neuron<A, B, C>::drawAt(Point<A, B, C>  *P) {
	float radius = 0.015f;
	float x = P->RPx, y = P->RPy;
	//std::cout << "Point " << P->RPx << " " << P->RPy << " Being drawn" << std::endl;

	glColor3f(P->CR, P->CG, P->CB);
	glBegin(GL_POINTS);
	glVertex2f(x, y);
	glEnd();

	glColor3f(0.3, 0.3, 0.5);
	glBegin(GL_LINE_LOOP);
	for (int i = 0; i <= 300; i++) {
		float angle = 2.0f * M_PI * i / 300.0;
		float xx = (float)radius*cos(angle) + x;
		float yy = (float)radius*sin(angle) + y;
		glVertex2f(xx, yy);
	}
	glEnd();
}
template<class A, class B, class C>void Neuron<A, B, C>::draw() {
	for (std::vector<Point<A, B, C> *>::iterator it = List.begin(); it != List.end(); ++it)
		drawAt((*it));
}
template<class A, class B, class C>void Neuron<A, B, C>::GeneratePoints(int n, int H, int V) {
	std::cout << "GeneratingPoints" << std::endl;
	Point<A, B, C> *a;
	int i = 0;
	float x, y;
	a = new Point<A, B, C>(0, 0, true); a->SetRelative(H, V);
	List.push_back(a);
	do {
		y = (float)((rand() % (2 * V)) - V);
		x = (float)((rand() % (2 * H)) - H);
		if (!contains(x, y)) {
			a = new Point<A, B, C>(x, y);
			List.push_back(a);
			i++;
			a->SetRelative(H, V);
		}
	} while (i < n);
}

template<class A, class B, class C>bool Neuron<A, B, C>::contains(Point<A, B, C> * p) {
	for (std::vector<Point<A, B, C> *>::iterator it = List.begin(); it != List.end(); ++it)
		if ((*it) == p)
			return true;
	return false;
}
template<class A, class B, class C>bool Neuron<A, B, C>::contains(A x, A y) {
	for (std::vector<Point<A, B, C> *>::iterator it = List.begin(); it != List.end(); ++it)
		if ((*it)->Px == x && (*it)->Py == y)
			return true;
	return false;
}


#endif // !NEURON_H
	