#include "App.h"
#include "stdafx.h"

static App* MF;

void app_timer(int value) {
	
	MF->redraw();
	glutTimerFunc(32, app_timer, value);
}

App::App(const char* label, int x, int y, int w, int h) : GlutApp(label, x, y, w, h) {
	// Initialize state variables
	MF = this;

	mx = 0.0;
	my = 0.0;

	Layout = new Grid(50,16,16);

	//Apply Timing For AI
	app_timer(1);
}
void App::specialKeyPress(int key) {
	///Layout->specialKeyPressHandle(key);
}
void App::specialKeyUp(int key) {
}

void App::draw() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	//	glClear(GL_COLOR_BUFFER_BIT);
	glClearColor(0.0, 0.0, 0.0, 1.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glColor3d(1.0, 1.0, 1.0);

	Layout->draw();

	glFlush();
	glutSwapBuffers();
}

void App::mouseDown(float x, float y) {
	mx = x;
	my = y;

	std::cout << mx << " " << my << std::endl;

	///MainFrame->Handle(x, y);
	// Redraw the scene
	redraw();
}
void App::mouseDrag(float x, float y) {
	mx = x;
	my = y;

	// Redraw the scene
	redraw();
}
void App::keyPress(unsigned char key) {
	///MainFrame->keyPressHandle(key);
}
void App::idle() {
	redraw();
}