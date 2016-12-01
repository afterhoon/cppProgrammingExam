/*
	문제 1. Circle 클래스 정의
		1) 원의 중심좌표와 반지름의 길이 저장 및 출력
	문제 2. Ring 클래스 정의
		1) 두개의 Circle클래스로 링 표현
	단, 캡슐화 고려
*/

#include <iostream>
using namespace std;

class Point {
private:
	int xpos;
	int ypos;
public:
	void Init(int x, int y) {
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
	void Init(int x, int y, int r) {
		cen.Init(x, y);
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
	void Init(int ix, int iy, int ir, int ox, int oy, int or ) {
		inner.Init(ix, iy, ir);
		outter.Init(ox, oy, or);
	}
	void ShowRingInfo() {
		cout << "Inner Circle Info..." << endl;
		inner.ShowCircleInfo();
		cout << "Outter Circle Info..." << endl;
		outter.ShowCircleInfo();
	}
};

int main() {
	Ring ring;
	ring.Init(1, 1, 4, 2, 2, 9);
	ring.ShowRingInfo();
	return 0;
}
