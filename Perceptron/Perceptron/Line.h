#ifndef LINE_H
#define LINE_H

class Line {
	float m, A, B;
	float CR, CB;
public:
	Line(int, bool);
	Line(float, float);
	~Line();
	void draw();
	void setup(int);
	int random(int, int );
};
#endif // !LINE_H

