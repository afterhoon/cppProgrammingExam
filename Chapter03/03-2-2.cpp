/*
문제 2. 문자열 정보를 내부에 저장하는 Printer 클래스 정의
*/

#include <iostream>
#include <cstring>
using namespace std;

namespace STR_CONST {
	enum {
		STR_LEN = 50
	};
}

class Printer {
private:
	char str[STR_CONST::STR_LEN];
public:
	void SetString(char *s);
	void ShowString();
};

void Printer::SetString(char *s) {
	strcpy_s(str, STR_CONST::STR_LEN, s);
}

void Printer::ShowString() {
	cout << str << endl;
}

int main() {
	Printer pnt;
	pnt.SetString("Hello World!");
	pnt.ShowString();

	pnt.SetString("I love C++");
	pnt.ShowString();
	return 0;
}
