/*
	문제 1. 문제 04-3-1의 NameCard 클래스 복사생성자
			(https://github.com/afterhoon/cppProgrammingExam/blob/master/Chapter04/04-3-2.cpp)
*/

#include <iostream>
using namespace std;

namespace COMP_POS {
	enum { CLERK, SENIOR, ASSIST, MANAGER };

	void ShowRank(int rk) {
		switch (rk) {
		case CLERK: cout << "사원" << endl; break;
		case SENIOR: cout << "주임" << endl; break;
		case ASSIST: cout << "대리" << endl; break;
		case MANAGER: cout << "과장" << endl; break;
		}
	}
}

class NameCard {
private:
	char *name;
	char *company;
	char *phoneNum;
	int rank;
public:
	NameCard(char *myName, char *myCom, char *myPNum, int myRank) {
		int nLen = strlen(myName) + 1;
		int cLen = strlen(myCom) + 1;
		int pLen = strlen(myPNum) + 1;
		name = new char[nLen];
		company = new char[cLen];
		phoneNum = new char[pLen];
		strcpy_s(name, nLen, myName);
		strcpy_s(company, cLen, myCom);
		strcpy_s(phoneNum, pLen, myPNum);
		rank = myRank;
	}
	NameCard(NameCard &copy) : rank(copy.rank) {
		int nLen = strlen(copy.name) + 1;
		int cLen = strlen(copy.company) + 1;
		int pLen = strlen(copy.phoneNum) + 1;
		name = new char[nLen];
		company = new char[cLen];
		phoneNum = new char[pLen];
		strcpy_s(name, nLen, copy.name);
		strcpy_s(company, cLen, copy.company);
		strcpy_s(phoneNum, pLen, copy.phoneNum);
	}
	void ShowNameCardInfo() const {
		cout << "이름: " << name << endl;
		cout << "회사: " << company << endl;
		cout << "전화번호: " << phoneNum << endl;
		cout << "직급: ";
		COMP_POS::ShowRank(rank);
		cout << endl;
	}
};

int main() {
	NameCard manClerk("Lee", "ABCEng", "010-1111-2222", COMP_POS::CLERK);
	NameCard copy1 = manClerk;
	NameCard manSENIOR("Hong", "OrangeEng", "010-3333-4444", COMP_POS::SENIOR);
	NameCard copy2 = manSENIOR;
	copy1.ShowNameCardInfo();
	copy2.ShowNameCardInfo();
	return 0;
}
