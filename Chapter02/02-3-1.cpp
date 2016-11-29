/*
	문제 1. 구조체에 대한 new & delete 연산
*/

#include <iostream>
using namespace std;

typedef struct __Point {
	int xpos;
	int ypos;
} Point;

Point& PntAdder(const Point &p1, const Point &p2) {
	Point *pptr = new Point;
	pptr->xpos = p1.xpos + p2.xpos;
	pptr->ypos = p1.ypos + p2.ypos;
	return *pptr;
}

int main() {
	Point p1 = { 1,2 };
	Point p2 = { 3,4 };
	Point addPoint = PntAdder(p1, p2);

	cout << "xpos: " << addPoint.xpos << endl;
	cout << "ypos: " << addPoint.ypos << endl;
	return 0;
}
