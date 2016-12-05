/*
	문제 1. Square 클래스와 Rectangle 클래스 상속관계 구현
*/

#include <iostream>
using namespace std;

class Rectangle {
private:
	int width;
	int height;
public:
	Rectangle(int w, int h)
		: width(w), height(h) {

	}
	void ShowAreaInfo() {
		cout << "면적: " << width*height << endl;
	}
};

class Square : public Rectangle {
public:
	Square(int l) : Rectangle(l, l) {
		
	}
};

int main() {
	Rectangle rec(4, 3);
	rec.ShowAreaInfo();

	Square sqr(7);
	sqr.ShowAreaInfo();
	return 0;
}
