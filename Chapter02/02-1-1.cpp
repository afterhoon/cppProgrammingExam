/*
	문제1. 참조자를 이용한 함수정의
		1) int형 변수값 1씩 증가
		2) int형 변수 부호 변경
*/

#include <iostream>
using namespace std;

void AddOne(int &num) {
	num = num + 1;
}

void NegativeSign(int &num) {
	num = -num;
}

int main() {
	int num;

	cout << "Input num> ";
	cin >> num;
	
	for (int i = 0; i < 3; i++) {
		AddOne(num);
		cout << i + 1 << "번 증가> " << num << endl;
	}

	NegativeSign(num);
	cout << "부호 바뀜> " << num << endl;
	return 0;
}
