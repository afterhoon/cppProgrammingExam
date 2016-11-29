/*
	문제 1. const 포인터와 const 참조자 사용
*/

#include <iostream>
using namespace std;

int main() {
	const int num = 12;
	const int *ptr = &num;
	const int &ref = *ptr;

	cout << "num: " << num << endl;
	cout << "ptr: " << *ptr << endl;
	cout << "ref: " << ref << endl;
	return 0;
}
