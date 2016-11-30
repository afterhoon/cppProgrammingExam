/*
	문제 1. p142 의 FruitSaleSim1.cpp 를 정보은닉 하시오
		변경된 FruitSaleSim1.cpp
*/

#include <iostream>
using namespace std;

class FruitSeller {
private:
	int APPLE_PRICE;
	int numOfApples;
	int myMoney;

public:
	void InitMembers(int price, int num, int money) {
		APPLE_PRICE = price;
		numOfApples = num;
		myMoney = money;
	}
	int SaleApples(int money) {
		int num = money / APPLE_PRICE;
		numOfApples -= num;
		myMoney += money;
		return num;
	}
	void ShowSalesResult() const {
		cout << "남은 사과: " << numOfApples << endl;
		cout << "판매 수익: " << myMoney << endl << endl;
	}
};

class FruitBuyer {
private:
	int myMoney;
	int numOfApples;

public:
	void InitMembers(int money) {
		myMoney = money;
		numOfApples = 0;
	}
	bool BuyApples(FruitSeller &seller, int money) {
		if (money < 0) {
			cout << "사과를 구매하려면 0원 이상을 주어야 합니다." << endl;
			return false;
		}
			
		numOfApples += seller.SaleApples(money);
		myMoney -= money;
		return true;
	}
	void ShowBuyResult() const {
		cout << "현재 잔액: " << myMoney << endl;
		cout << "사과 개수: " << numOfApples << endl;
	}
};

int main() {
	FruitSeller seller;
	seller.InitMembers(1000, 20, 0);
	FruitBuyer buyer;
	buyer.InitMembers(5000);

	if (!buyer.BuyApples(seller, -1000))
		cout << "구매 실패" << endl;

	if(!buyer.BuyApples(seller, 2000))
		cout << "구매 실패" << endl;
	
	cout << "과일 판매자의 현황" << endl;
	seller.ShowSalesResult();
	cout << "과일 구매자의 현황" << endl;
	buyer.ShowBuyResult();
	return 0;
}
