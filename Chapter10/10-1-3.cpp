/*
	문제 3. == 연산자와 != 연산자 오버로딩
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
	friend bool operator==(Point &pos1, Point &pos2);
	friend bool operator!=(Point &pos1, Point &pos2);
};

bool operator==(Point &pos1, Point &pos2) {
	if (pos1.xpos == pos2.xpos)
		if (pos1.ypos == pos2.ypos)
			return 1;
	return 0;
}

bool operator!=(Point &pos1, Point &pos2) {
	if (pos1.xpos != pos2.xpos)
		if (pos1.ypos != pos2.ypos)
			return 1;
	return 0;
}

void ShowBool(bool b) {
	if (b == true)
		cout << "TRUE" << endl;
	else
		cout << "FALSE" << endl;
}

int main() {
	Point pos1(3, 4);
	Point pos2(3, 5);
	Point pos3(3, 4);

	ShowBool(pos1 == pos2);
	ShowBool(pos1 == pos3);
	ShowBool(pos1 != pos2);
	ShowBool(pos1 != pos3);
	return 0;
}
