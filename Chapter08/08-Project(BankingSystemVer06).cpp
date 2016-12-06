/*
	BankingSystemVer05의 Account 클래스를 상속을 통해
	NormalAccount 보통예금계좌와 HighCreditAccount 신용신뢰계좌
	로 추가 정의를 하여 업그레이드
	(https://github.com/afterhoon/cppProgrammingExam/blob/master/Chapter07/07-Project(BankingSystemVer05).cpp)
*/

#include <iostream>
using namespace std;

namespace CREDIT_GRADE {
	enum {
		CREDIT_A = 1, CREDIT_B, CREDIT_C
	};
}

namespace ACCOUNT_TYPE {
	enum { NORMAL_TYPE = 1, CREDIT_TYPE};
}
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
	int GetAccID() const {
		return accID;
	}
	char *GetName() const {
		return name;
	}
	int GetMoney() const {
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
	virtual void ShowAccountInfo() const = 0;
	virtual ~Account() {
		delete[]name;
	}
};

class NormalAccount : public Account {
private:
	int rateOfInterest; // 이자율
public:
	NormalAccount(int myID, char *myName, int myMoney, int rate)
		: Account(myID, myName, myMoney), rateOfInterest(rate) {

	}
	int GetRate() const {
		return rateOfInterest;
	}
	void SetRate(int r) {
		rateOfInterest += r;
	}
	void ShowAccountInfo() const {
		cout << "------------------" << endl;
		cout << "계좌종류: 보통예금계좌" << endl;
		cout << "계좌번호: " << GetAccID() << endl;
		cout << "이    름: " << GetName() << endl;
		cout << "잔    액: " << GetMoney() << endl;
		cout << "이 자 율: " << GetRate() << endl;
		cout << "------------------" << endl << endl;
	}
	virtual ~NormalAccount() {
		
	}
};

class HighCreditAccount : public NormalAccount {
private:
	int credit;
public:
	HighCreditAccount(int myID, char *myName, int myMoney, int rate, int myCredit)
		:NormalAccount(myID, myName, myMoney, rate), credit(myCredit) {
		switch (credit) {
		case CREDIT_GRADE::CREDIT_A: SetRate(7); return;
		case CREDIT_GRADE::CREDIT_B: SetRate(4); return;
		case CREDIT_GRADE::CREDIT_C: SetRate(2); return;
		}
	}
	void ShowAccountInfo() const {
		cout << "------------------" << endl;
		cout << "계좌종류: 신용신뢰계좌" << endl;
		cout << "계좌번호: " << GetAccID() << endl;
		cout << "이    름: " << GetName() << endl;
		cout << "잔    액: " << GetMoney() << endl;
		cout << "이 자 율: " << GetRate() << endl;
		cout << "신용등급: ";
		switch (credit) {
		case CREDIT_GRADE::CREDIT_A: cout << "A" << endl; break;
		case CREDIT_GRADE::CREDIT_B: cout << "B" << endl; break;
		case CREDIT_GRADE::CREDIT_C: cout << "C" << endl; break;
		default: cout << "오류발생(알수없는 등급)" << endl;
		}
		cout << "------------------" << endl << endl;
	}
	virtual ~HighCreditAccount() {

	}

};

class AccountHandler {
private:
	Account *accArr[100];
	int accCount = 0;
public:
	AccountHandler() : accCount(0) {
		cout << "계좌 저장공간 생성" << endl;
	}
	int GetCount() {
		return accCount;
	}
	void ShowMenu() {
		cout << "-----Menu------" << endl;
		cout << "1. 계좌개설" << endl;
		cout << "2. 입 금" << endl;
		cout << "3. 출 금" << endl;
		cout << "4. 계좌정보 전체 출력" << endl;
		cout << "5. 프로그램 종료" << endl;
	}
	void SetAccount() {
		int type;
		cout << "[계좌종류선택]" << endl;
		cout << "1. 보통예금계좌 2. 신용신뢰계좌" << endl;
		
		while (1) {
			cout << "선택: ";
			cin >> type;
			switch (type) {
			case ACCOUNT_TYPE::NORMAL_TYPE: SetNormalAccount(); return;
			case ACCOUNT_TYPE::CREDIT_TYPE: SetCreditAccount(); return;
			default: cout << "잘못된 선택입니다." << endl << endl;
			}
		}
		
	}
	void SetNormalAccount() {
		int accnum;			// 계좌번호
		char namestr[100];	// 이름
		int mon;			// 금액
		int rate;			// 이자율

		cout << "[ 보통예금계좌 개설 ]" << endl;
		cout << "계좌ID: ";		cin >> accnum;
		cout << "이  름: ";		cin >> namestr;
		cout << "입금액: ";		cin >> mon;
		cout << "이자율: ";		cin >> rate;
		accArr[accCount++] = new NormalAccount(accnum, namestr, mon, rate);
		
	}
	void SetCreditAccount() {
		int accnum;			// 계좌번호
		char namestr[100];	// 이름
		int mon;			// 금액
		int rate;
		int grade;

		cout << "[ 신용신뢰계좌 개설 ]" << endl;
		cout << "계좌ID: ";		cin >> accnum;
		cout << "이  름: ";		cin >> namestr;
		cout << "입금액: ";		cin >> mon;
		cout << "이자율: ";		cin >> rate;
		cout << "신용등급(1toA, 2toB, 3toC): "; cin >> grade;
		
		accArr[accCount++] = new HighCreditAccount(accnum, namestr, mon, rate, grade);
		
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

	void ShowAllAccountInfo() {
		for (int i = 0; i < accCount; i++) {
			accArr[i]->ShowAccountInfo();
		}
	}
};

int main() {
	AccountHandler handler;
	int select = 0;
	int exit = 0;

	while (exit == 0) {
		handler.ShowMenu();
		cout << "선택> ";
		cin >> select;
		switch (select) {
		case 1: handler.SetAccount(); break;
		case 2: handler.Deposit(); break;
		case 3: handler.Withdraw(); break;
		case 4: handler.ShowAllAccountInfo(); break;
		case 5: exit = 1; break;
		default: cout << "잘못된 선택입니다." << endl << endl;
		}
	}
	cout << "프로그램을 종료합니다." << endl;
	return 0;
}
