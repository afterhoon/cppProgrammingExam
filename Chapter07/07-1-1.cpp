  /*
	문제 1. Car, HybridCar, HybridWaterCar 클래스에 생성자 삽입
*/

#include <iostream>
using namespace std;

class Car {
private:
	int gasolineGauge;
public:
	Car(int g) : gasolineGauge(g) {

	}
	int GetGasGauge() {
		return gasolineGauge;
	}
};

class HybridCar : public Car {
private:
	int electricGauge;
public:
	HybridCar(int e, int g) : electricGauge(e), Car(g) {

	}
	int GetElecGauge() {
		return electricGauge;
	}
};

class HybridWaterCar : public HybridCar {
private:
	int waterGauge;
public:
	HybridWaterCar(int w, int e, int g)
		: waterGauge(w), HybridCar(e, g) {

	}
	void ShowCurrentGauge() {
		cout << "잔여 가솔린: " << GetGasGauge() << endl;
		cout << "잔여 전기량: " << GetElecGauge() << endl;
		cout << "잔여 워터량: " << waterGauge << endl;
	}
};

int main() {
	HybridWaterCar bwc(100, 50, 70);
	bwc.ShowCurrentGauge();
	return 0;
}
