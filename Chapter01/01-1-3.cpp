/*
	문제 3. 구구단 출력
*/

#include <iostream>

int main() {
	int num;

	std::cout << "정수 입력> ";
	std::cin >> num;

	for (int i = 1; i < 10; i++)
		std::cout << num << " x " << i << " = " << num*i << std::endl;
	return 0;
}
