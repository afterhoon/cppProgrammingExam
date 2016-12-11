/*
	문제 1. 예제 GFunctionOverloading.cpp의 Point클래스를 
	대상으로 연산자 오버로딩
*/

#include <iostream>
using namespace std;

class Point {
private:
	int xpos, ypos;
public:
	Point(int x = 0, int y = 0) : xpos(x), ypos(y) {

	}
	void ShowPosition() const {
		cout << '[' << xpos << ", " << ypos << ']' << endl;
	}
	friend Point operator-(Point &pos1, Point &pos2);
};

Point operator-(Point &pos1, Point &pos2) {
	Point pos(pos1.xpos - pos2.xpos, pos1.ypos - pos2.ypos);
	return pos;
}

int main() {
	Point pos1(3, 4);
	Point pos2(10, 20);
	Point pos3 = pos2 - pos1;

	pos1.ShowPosition();
	pos2.ShowPosition();
	pos3.ShowPosition();
	return 0;
}
