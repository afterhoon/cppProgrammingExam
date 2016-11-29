/*
	문제 2. 1~100 난수 만들기
*/

#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

int main() {
	srand((unsigned)time(NULL));

	for (int i = 0; i < 5; i++) {
		cout << i + 1 << "번째 난수: " << rand() % 99 + 1 << endl;
	}
	return 0;
}
