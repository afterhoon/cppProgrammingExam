/*
  개설, 조회, 입금, 출금이 가능한
  계좌관리 프로그램 구현  
*/

#include <iostream>
using namespace std;

void MenuPrint();
void CreateAccount();
void Deposit();
void Withdraw();
void InformationPrint();

typedef struct client {
	int accID;
	char name[100];
	int money;
} CLIENT;

CLIENT ACC[100];
int accNum = 0;

int main() {
	int select = 0;
	int exit = 0;
	while (exit == 0) {
		MenuPrint();
		cout << "선택> ";
		cin >> select;
		switch (select) {
		case 1: CreateAccount(); break;
		case 2: Deposit(); break;
		case 3: Withdraw(); break;
		case 4: InformationPrint(); break;
		case 5: exit = 1; break;
		default: cout << "잘못된 선택입니다." << endl << endl;
		}
	}
	cout << "프로그램을 종료합니다." << endl;
	return 0;
}

void MenuPrint() {
	cout << "-----Menu------" << endl;
	cout << "1. 계좌개설" << endl;
	cout << "2. 입 금" << endl;
	cout << "3. 출 금" << endl;
	cout << "4. 계좌정보 전체 출력" << endl;
	cout << "5. 프로그램 종료" << endl;
}

void CreateAccount() {
	cout << "[ 1. 계좌개설 ]" << endl;
	cout << "계좌번호 입력> ";
	cin >> ACC[accNum].accID;
	cout << "이름 입력> ";
	cin >> ACC[accNum].name;
	cout << "입금액> ";
	cin >> ACC[accNum].money;
	accNum++;
	cout << "개설되었습니다." << endl << endl;
}

void Deposit() {
	int num, dep;
	cout << "[ 2. 입 금 ]" << endl;
	cout << "계좌번호 입력> ";
	cin >> num;
	cout << "입금액> ";
	cin >> dep;

	for (int i = 0; i < accNum; i++) {
		if (ACC[i].accID == num)
			ACC[i].money += dep;
	}
	cout << "입금 완료되었습니다." << endl;
}

void Withdraw() {
	int num, with;
	cout << "[ 3. 출 금 ]" << endl;
	cout << "계좌번호 입력> ";
	cin >> num;
	cout << "출금액> ";
	cin >> with;

	for (int i = 0; i < accNum; i++) {
		if (ACC[i].accID == num)
			ACC[i].money -= with;
	}
	cout << "출금 완료되었습니다." << endl;
}

void InformationPrint() {
	for (int i = 0; i < accNum; i++) {
		cout << "------------------" << endl;
		cout << "계좌번호: " << ACC[i].accID << endl;
		cout << "이    름: " << ACC[i].name << endl;
		cout << "잔    액: " << ACC[i].money << endl;
		cout << "------------------" << endl << endl;
	}
}
