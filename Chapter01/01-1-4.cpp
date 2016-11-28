/*
	문제 4. 급여계산 프로그램
*/

#include <iostream>

int main() {
	int defWage = 50;
	double perSell = 0.12;
	int num = 0;

	while (1) {
		int wage = 0;
		std::cout << "판매 금액을 만원 단위로 입력(-1 to end): ";
		std::cin >> num;
		if (num == -1) break;

		wage = defWage + num*perSell;
		std::cout << "이번 달 급여: " << wage << "만원" << std::endl;
	}
	std::cout << "프로그램을 종료합니다." << std::endl;
	return 0;
}
