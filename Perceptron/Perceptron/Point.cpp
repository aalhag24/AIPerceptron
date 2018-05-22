#include "stdafx.h"
#include "Point.h"

/** CONSTRUCTORS **/
Point::Point() {
	Px = Py = APx = APy = 0.0;
	CR = 1.0f; CG = CB = 0.0f;
	//Image = new TexRect("Green.png", "Red.png", Px, Py, 0.05, 0.05);
	cout << "New Defualt Point" << endl;
}
Point::Point(float x, float y) {
	Px = x; Py = y;
	CR = 1.0f; CG = CB = 0.0f;
	//Image = new TexRect("Green.png", "Red.png", Px, Py, 0.05, 0.05);
}
Point::Point(float x, float y, bool correct) {
	Px = x; Py = y;
	if (correct) { CG = 1.0f; CR = CB = 0.0f; }
	else { CR = 1.0f; CG = CB = 0.0f; }
	//Image = new TexRect("Green.png", "Red.png", Px, Py, 0.05, 0.05);
}
Point::Point(const Point &p) {
	Px = p.Px; Py = p.Py;
	APx = p.APx; APy = p.APy;
	CR = p.CR; CG = CB = p.CG;
	//Image = new TexRect("Green.png", "Red.png", Px, Py, 0.05, 0.05);
	cout << "New Copy Point" << endl;
}
Point::~Point() {
	//delete Image;
	cout << "~Point()" << endl;
}

/** GETTERS AND SETTERS **/
float Point::GetX()const { return Px; }
float Point::GetY()const { return Py; }
bool  Point::GetState()const { return Active; }

void Point::SetX(float x) { Px = x; }
void Point::SetY(float y) { Py = y; }
void Point::SetState(bool correct) {
	Active = correct;
	if (correct) { CR = 0.0f; CG = 1.0f; }
	else { CG = 0.0f; CR = 1.0f; }
}

void Point::RandomizeWeight() {
	for (int i = 0; i < 2; i++) {
		weight[i] = (rand() % 200 - 100) / 100;
	}
}
int Point::guess(float inputs[]){
	float sum = 0.0;
	for (int i = 0; i < 2; i++) {
		sum += inputs[i] * weight[i];
	}
	int output = sign(sum);
	return output;
}
int Point::sign(float s){
	if (s < 0)
		return -1;
	else
		return 1;
}

void Point::drawAt(float X, float Y) {
	glColor3f(CR, CG, CB);
	glBegin(GL_POINTS);
	glVertex3f(X, Y, 0.0);
	glEnd();

	float radius = 0.015f;
	float x = X, y = Y;

	glColor3f(0.2, 0.2, 0.6);
	glBegin(GL_LINE_LOOP);
	for (int i = 0; i <= 300; i++) {
		float angle = 2.0f * M_PI * i / 300.0;
		float xx = (float)radius*cos(angle) + X;
		float yy = (float)radius*sin(angle) + Y;
		glVertex2f(xx, yy);
	}
	glEnd();
}
void Point::draw(int h, int v) {
	drawAt(Px / (float)h, Py / (float)v);
}

bool Point::operator==(const Point &a)const {
	if (this->Px == a.Px && this->Py == a.Py)
		return true;
	return false;
}
bool Point::contain(float x, float y){
	if (this->Px == x && this->Py == y)
		return true;
	return false;
}

/** PointStash Functions **/
PointStash::PointStash() {
	List.clear();
}
PointStash::~PointStash() {
	cout << "~PointStash()" << endl;
}
void PointStash::add(Point *a) {
	List.push_back(a);
}
void PointStash::Draw(int h, int v) {
	for (std::vector<Point*>::iterator it = List.begin(); it != List.end(); ++it)
		(*it)->draw(h, v);
}

bool PointStash::Contains(Point *a) {
	for (std::vector<Point*>::iterator it = List.begin(); it != List.end(); ++it)
		if ((*it) == a) return true;
	return false;
}
bool PointStash::Contains(float x, float y){
	for (std::vector<Point*>::iterator it = List.begin(); it != List.end(); ++it)
		if ((*it)->contain(x,y)) return true;
	return false;
}
