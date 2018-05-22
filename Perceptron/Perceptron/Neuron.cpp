#include "stdafx.h"
#include "Neuron.h"

/** CONSTRUCTORS **/
Neuron::Neuron() {
	P = new Point(0.0f, 0.0f);
	P->SetColor(1.0f, 0.0f, 0.0f);

	Active = false; length = 2;
	cout << "New Defualt Point" << endl;
}
Neuron::Neuron(float x, float y) {
	P = new Point(x, y);
	P->SetColor(1.0f, 0.0f, 0.0f);
	Active = false; length = 2;
}
Neuron::Neuron(float x, float y, bool correct) {
	P = new Point(x, y);
	if (correct) { P->SetColor(0.0f, 1.0f, 0.0f); }
	else { P->SetColor(1.0f, 0.0f, 0.0f); }
	Active = correct; length = 2;
}
Neuron::Neuron(const Neuron &N) {
	P = N.P;
	P->SetColor(N.P->CR, N.P->CG, N.P->CB);

	if (N.GetState()) { P->SetColor(0.0f, 1.0f, 0.0f); }
	else { P->SetColor(1.0f, 0.0f, 0.0f); }
	length = N.GetL();

	cout << "New Copy Point" << endl;
}
Neuron::~Neuron() {
	//delete Image;
	cout << "~Point()" << endl;
}

/** GETTERS AND SETTERS **/
float Neuron::GetX()const { return P->Px; }
float Neuron::GetY()const { return P->Py; }
bool Neuron::GetState()const { return Active; }
int Neuron::GetL() const { return length; }

void Neuron::SetX(float x) { P->Px = x; }
void Neuron::SetY(float y) { P->Py = y; }
void Neuron::SetState(bool correct) {
	Active = correct;
	if (correct) { P->SetColor(0.0f, 1.0f, 0.0f); }
	else { P->SetColor(1.0f, 0.0f, 0.0f); }
}

void Neuron::RandomizeWeight() {
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

void Neuron::drawAt(float X, float Y) {
	glColor3f(P->CR, P->CG, P->CB);
	glBegin(GL_POINTS);
	glVertex3f(X, Y, 0.0);
	glEnd();

	float radius = 0.015f;
	float x = X, y = Y;

	glColor3f(0.3, 0.3, 0.5);
	glBegin(GL_LINE_LOOP);
	for (int i = 0; i <= 300; i++) {
		float angle = 2.0f * M_PI * i / 300.0;
		float xx = (float)radius*cos(angle) + X;
		float yy = (float)radius*sin(angle) + Y;
		glVertex2f(xx, yy);
	}
	glEnd();
}
void Neuron::draw(int h, int v) {
	drawAt(P->Px / (float)h, P->Py / (float)v);
}

bool Neuron::operator==(const Neuron &a)const {
	if (this->P->Px == a.P->Px && this->P->Py == a.P->Py)
		return true;
	return false;
}
bool Neuron::contain(float x, float y){
	if (this->P->Px == x && this->P->Py == y)
		return true;
	return false;
}

/** PointStash Functions **/
Stash::Stash() {
	List.clear();
}
Stash::~Stash() {
	cout << "~PointStash()" << endl;
}
void Stash::add(Neuron *a) {
	List.push_back(a);
}
void Stash::Draw(int h, int v) {
	for (std::vector<Neuron*>::iterator it = List.begin(); it != List.end(); ++it)
		(*it)->draw(h, v);
}

bool Stash::Contains(Neuron *a) {
	for (std::vector<Neuron*>::iterator it = List.begin(); it != List.end(); ++it)
		if ((*it) == a) return true;
	return false;
}
bool Stash::Contains(float x, float y){
	for (std::vector<Neuron*>::iterator it = List.begin(); it != List.end(); ++it)
		if ((*it)->contain(x,y)) return true;
	return false;
}
