/*
	문제 1. 입력을 위한 >> 연산자의 오버로딩
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
	friend ostream& operator<< (ostream&, const Point&);
	friend istream& operator>> (istream&, Point&);
};

ostream& operator<<(ostream& os, const Point& ref) {
	os << '[' << ref.xpos << ", " << ref.ypos << ']' << endl;
	return os;
}

istream& operator >> (istream& is, Point& ref) {
	is >> ref.xpos >> ref.ypos;
	return is;
}

int main() {
	Point pos1;
	cout << "x, y 좌표 순으로 입력: ";
	cin >> pos1;
	cout << pos1;

	Point pos2;
	cout << "x, y 좌표 순으로 입력: ";
	cin >> pos2;
	cout << pos2;
	return 0;
}
