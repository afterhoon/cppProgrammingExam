/*
	문제 1. 04-2-1(https://github.com/afterhoon/cppProgrammingExam/blob/master/Chapter04/04-2-1.cpp) 에 생성자 정의
*/

#include <iostream>
using namespace std;

class Point {
private:
	int xpos;
	int ypos;
public:
	Point(int x, int y){
		xpos = x;
		ypos = y;
	}
	void ShowPointInfo() {
		cout << "[" << xpos << ", " << ypos << "]" << endl;
	}
};

class Circle {
private:
	Point cen;
	int rad;
public:
	Circle(int x, int y, int r) : cen(x, y) {
		rad = r;
	}
	void ShowCircleInfo() {
		cout << "radius: " << rad << endl;
		cen.ShowPointInfo();
	}
};

class Ring {
private:
	Circle inner;
	Circle outter;
public:
	Ring(int ix, int iy, int ir, int ox, int oy, int or )
		:inner(ix, iy, ir), outter(ox, oy, or ) {
	}
	void ShowRingInfo() {
		cout << "Inner Circle Info..." << endl;
		inner.ShowCircleInfo();
		cout << "Outter Circle Info..." << endl;
		outter.ShowCircleInfo();
	}
};

int main() {
	Ring ring(1, 1, 4, 2, 2, 9);
	ring.ShowRingInfo();
	return 0;
}
