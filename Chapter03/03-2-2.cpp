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
	void CopyString(char *s);
	void ShowString();
};

void Printer::CopyString(char *s) {
	strcpy_s(str, STR_CONST::STR_LEN, s);
}

void Printer::ShowString() {
	cout << str << endl;
}

int main() {
	Printer prt;
	prt.CopyString("Hello World");
	prt.ShowString();
	return 0;
}
