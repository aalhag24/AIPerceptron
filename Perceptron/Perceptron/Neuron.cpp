#include "stdafx.h"
#include "Neuron.h"

/** CONSTRUCTORS **/
Neuron::Neuron() {
	GeneratePoints(20,16,16);
	length = 2;
	RandWeight();
	cout << "New Defualt Neuron" << endl;
}
Neuron::Neuron(int a, int h, int v) {
	cout << "new Neuron" << endl;
	GeneratePoints(a,h,v);
	length = 2;
	RandWeight();
}
Neuron::Neuron(const Neuron &N) {
	List = N.List;
	length = 2;
	RandWeight();
	cout << "New Copy Neuron" << endl;
}
Neuron::~Neuron() {
	List.clear();
	cout << "~Point()" << endl;
}

/** FUNCTIONS **/
void Neuron::RandWeight() {
	for (int i = 0; i < length; i++) {
		weight[i] = (rand() % 200 - 100) / 100;
	}
}
int Neuron::guess(float inputs[]){
	float sum = 0.0;
	for (int i = 0; i < length; i++) {
		sum += inputs[i] * weight[i];
	}
	int output = sign(sum);
	return output;
}
int Neuron::sign(float s){
	if (s < 0)
		return -1;
	else
		return 1;
}

void Neuron::drawAt(Point *P) {
	float radius = 0.015f;
	float x = P->RPx, y = P->RPy;

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
void Neuron::draw() {
	for(std::vector<Point*>::iterator it = List.begin(); it != List.end(); ++it)
		drawAt((*it));
}

void Neuron::GeneratePoints(int n, int H, int V){
	cout << "GeneratingPoints" << endl;
	Point *a;
	int i = 0;
	float x, y;
	a = new Point(0, 0, true); a->SetRelative(H, V);
	List.push_back(a);
	do {
		y = (float)((rand() % (2 * V)) - V);
		x = (float)((rand() % (2 * H)) - H);
		if (!contains(x, y)) { 
			a = new Point(x, y);  
			List.push_back(a); 
			i++; 
			a->SetRelative(H, V);
		}
	} while (i < n);
}

bool Neuron::contains(Point * p){
	for (std::vector<Point*>::iterator it = List.begin(); it != List.end(); ++it)
		if ((*it) == p)
			return true;
	return false;
}
bool Neuron::contains(float x, float y) {
	for (std::vector<Point*>::iterator it = List.begin(); it != List.end(); ++it)
		if ((*it)->Px == x && (*it)->Py == y)
			return true;
	return false;
}
