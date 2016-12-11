/*
	OneOpndOverloading.cpp의 Point 클래스의 연산자 오버로딩
	문제 1. 멤버함수의 형태로 오버로딩
	문제 2. 전역함수의 형태로 오버로딩
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
	Point operator-() {
		Point pos(-xpos, -ypos);
		return pos;
	}
	friend Point operator~(const Point& ref);
};

Point operator~(const Point& ref) {
	Point pos(ref.ypos, ref.xpos);
	return pos;
}

int main() {
	Point pos1(3, 4);
	Point pos2 = -pos1;
	Point pos3 = ~pos1;

	pos1.ShowPosition();
	pos2.ShowPosition();
	pos3.ShowPosition();
	return 0;
}
