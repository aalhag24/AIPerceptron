#ifndef LINE_H
#define LINE_H

class Line {
	float m, b, A, B;
	float CR, CB;
public:
	Line(bool);
	Line(float, float, bool);
	~Line();
	void draw();
	void setup(int);
	int random(int, int);
};
#endif // !LINE_H

