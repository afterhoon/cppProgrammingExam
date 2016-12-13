/*
	문제 1. Chapter 07의 예제 HASComposite.cpp의 클래스 Gun과 Police중
	Police 클래스를 대상으로 깊은 복사가 이뤄지도록 정의
*/

#include <iostream>
using namespace std;

class Gun {
private:
	int bullet;
public:
	Gun(int bnum) : bullet(bnum) {

	}
	void Shut() {
		cout << "BBANG!" << endl;
		bullet--;
	}
	void ShowGunInfo() const {
		cout << "bullet: " << bullet << endl;
	}
};

class Police {
private:
	int handcuffs;
	Gun *pistol;
public:
	Police(int bnum, int bcuff)
		: handcuffs(bcuff) {
		if (bnum > 0)
			pistol = new Gun(bnum);
		else
			pistol = NULL;
	}
	Police(const Police& ref) 
		:handcuffs(ref.handcuffs){
		pistol = new Gun(*(ref.pistol));
	}
	Police &operator=(const Police &ref) {
		if (pistol != NULL)
			delete pistol;

		handcuffs = ref.handcuffs;
		pistol = new Gun(*(ref.pistol));
		return *this;
	}
	void PutHandcuff() {
		cout << "SNAP!" << endl;
		handcuffs--;
	}
	void Shut() {
		if (pistol == NULL)
			cout << "Hut BBANG!" << endl;
		else
			pistol->Shut();
	}
	void ShowPoliceInfo() const {
		if (pistol != NULL)
			pistol->ShowGunInfo();
		else
			cout << "bullet: 0" << endl;
		cout << "handcuffs: " << handcuffs << endl;
		cout << endl;
	}

	~Police() {
		if (pistol != NULL)
			delete pistol;
	}
};

int main() {
	Police pman1(5, 3);
	Police pman2(0, 0);

	pman1.ShowPoliceInfo();
	pman2.ShowPoliceInfo();

	pman2 = pman1;

	pman1.ShowPoliceInfo();
	pman2.ShowPoliceInfo();

	return 0;
}
