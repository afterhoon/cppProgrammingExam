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
};

template <class T>
void SwapData(T &data1, T &data2) {
	T temp = data1;
	data1 = data2;
	data2 = temp;
}

int main() {
	Point pos1(3, 7);
	Point pos2(10, 20);
	cout << "<변경전 좌표위치>" << endl;
	pos1.ShowPosition();
	pos2.ShowPosition();
	SwapData(pos1, pos2);
	cout << "<변경후 좌표위치>" << endl;
	pos1.ShowPosition();
	pos2.ShowPosition();
	return 0;
}
