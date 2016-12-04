/*
	BankingSystemVer03을 const선언을 통해 업그레이드
	(https://github.com/afterhoon/cppProgrammingExam/blob/master/Chapter05/05-Project(BankingSystemVer03).cpp)
*/

#include <iostream>
using namespace std;

void ShowMenu();
void CreateAccount();
void Deposit();
void Withdraw();
void ShowAccountInfo();

class Account {
private:
	int accID;
	char *name;
	int money;
public:
	Account(int myID, char *myName, int myMoney)
		: accID(myID), money(myMoney) {
		name = new char[strlen(myName) + 1];
		strcpy_s(name, strlen(myName) + 1, myName);
	}
	Account(const Account &copy) : accID(copy.accID), money(copy.money) {
		name = new char[strlen(copy.name) + 1];
		strcpy_s(name, strlen(copy.name) + 1, copy.name);
	}
	int GetAccID() const{
		return accID;
	}
	char *GetName() const{
		return name;
	}
	int GetMoney() const{
		return money;
	}
	void SetAccID(int myID) {
		accID = myID;
	}
	void SetName(char *myName) {
		name = new char[strlen(myName) + 1];
		strcpy_s(name, strlen(myName) + 1, myName);
	}
	void SetMoney(int myMoney) {
		money = myMoney;
	}
	void DepositMoney(int myMoney) {
		money += myMoney;
	}
	void WithdrawMoney(int myMoney) {
		money -= myMoney;
	}
	void ShowAccountInfo() const {
		cout << "------------------" << endl;
		cout << "계좌번호: " << accID << endl;
		cout << "이    름: " << name << endl;
		cout << "잔    액: " << money << endl;
		cout << "------------------" << endl << endl;
	}
	~Account() {
		delete[]name;
	}
};

Account * accArr[100];
int accCount = 0;

int main() {

	int select = 0;
	int exit = 0;

	while (exit == 0) {
		ShowMenu();
		cout << "선택> ";
		cin >> select;
		switch (select) {
		case 1: CreateAccount(); break;
		case 2: Deposit(); break;
		case 3: Withdraw(); break;
		case 4: ShowAccountInfo(); break;
		case 5: exit = 1; break;
		default: cout << "잘못된 선택입니다." << endl << endl;
		}
	}
	cout << "프로그램을 종료합니다." << endl;
	return 0;
}

void ShowMenu() {
	cout << "-----Menu------" << endl;
	cout << "1. 계좌개설" << endl;
	cout << "2. 입 금" << endl;
	cout << "3. 출 금" << endl;
	cout << "4. 계좌정보 전체 출력" << endl;
	cout << "5. 프로그램 종료" << endl;
}

void CreateAccount() {
	int accnum;			// 계좌번호
	char namestr[100];	// 이름
	int mon;			// 금액
	cout << "[ 1. 계좌개설 ]" << endl;
	cout << "계좌번호 입력> ";
	cin >> accnum;
	cout << "이름 입력> ";
	cin >> namestr;
	cout << "입금액> ";
	cin >> mon;
	accArr[accCount++] = new Account(accnum, namestr, mon);
	cout << "개설되었습니다." << endl << endl;
}

void Deposit() {
	int num, dep;
	cout << "[ 2. 입 금 ]" << endl;
	cout << "계좌번호 입력> ";
	cin >> num;
	cout << "입금액> ";
	cin >> dep;

	for (int i = 0; i < accCount; i++) {
		if (accArr[i]->GetAccID() == num)
			accArr[i]->DepositMoney(dep);
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

	for (int i = 0; i < accCount; i++) {
		if (accArr[i]->GetAccID() == num)
			accArr[i]->WithdrawMoney(with);
	}
	cout << "출금 완료되었습니다." << endl;
}

void ShowAccountInfo() {
	for (int i = 0; i < accCount; i++) {
		accArr[i]->ShowAccountInfo();
	}
}
