/*
	문제 2. 생성자와 소멸자 정의
*/

#include <iostream>
using namespace std;

class MyFriendInfo {
private:
	char *name;
	int age;
public:
	MyFriendInfo(char *myname, int myage) : age(myage) {
		name = new char[strlen(myname) + 1];
		strcpy_s(name, strlen(myname) + 1, myname);
	}
	void ShowMyFriendInfo() {
		cout << "이름: " << name << endl;
		cout << "나이: " << age << endl;
	}
	~MyFriendInfo() {
		delete[]name;
	}
};

class MyFriendDetailInfo : public MyFriendInfo {
private:
	char *addr;
	char *phone;
public:
	MyFriendDetailInfo(char *myname, int myage, char *myaddr, char *myphone)
		: MyFriendInfo(myname, myage) {
		addr = new char[strlen(myaddr) + 1];
		phone = new char[strlen(myphone) + 1];
		strcpy_s(addr, strlen(myaddr) + 1, myaddr);
		strcpy_s(phone, strlen(myphone) + 1, myphone);
	}
	void ShowMyFriendDetailInfo() {
		ShowMyFriendInfo();
		cout << "주소 : " << addr << endl;
		cout << "전화 : " << phone << endl;
	}
	~MyFriendDetailInfo() {
		delete[]addr;
		delete[]phone;
	}
};

int main() {
	MyFriendDetailInfo fdi("Kim", 24, "광주 동구", "010-1234-5678");
	fdi.ShowMyFriendDetailInfo();
	return 0;
}
