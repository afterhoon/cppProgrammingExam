/*
	문제 2. NameCard클래스 정의
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
	NameCard manSENIOR("Hong", "OrangeEng", "010-3333-4444", COMP_POS::SENIOR);
	NameCard manAssist("Kim", "SoGoodComp", "010-5555-6666", COMP_POS::ASSIST);
	manClerk.ShowNameCardInfo();
	manSENIOR.ShowNameCardInfo();
	manAssist.ShowNameCardInfo();
	return 0;
}
