/*
	문제 2. 이름과 전화번호 출력
*/

#include <iostream>

int main() {
	char name[100];
	char phoneNum[100];

	std::cout << "이    름 입력: ";
	std::cin >> name;

	std::cout << "전화번호 입력: ";
	std::cin >> phoneNum;

	std::cout << "이    름: " << name << std::endl;
	std::cout << "전화번호: " << phoneNum << std::endl;
	return 0;
}
