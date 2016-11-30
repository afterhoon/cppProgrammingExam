/*
	문제 1. 계산기 기능의 Calculator 클래스 정의
*/

#include <iostream>
using namespace std;

class Calculator {
private:
	int add;
	int min;
	int mul;
	int div;
public:
	void Init();
	void ShowOpCount();
	double Add(double n1, double n2);
	double Min(double n1, double n2);
	double Mul(double n1, double n2);
	double Div(double n1, double n2);
};

void Calculator::Init() {
	add = 0, min = 0, mul = 0, div = 0;
}

void Calculator::ShowOpCount() {
	cout << "덧셈: " << add << " 뺄셈: " << min
		<< " 곱셈: " << mul << " 나눗셈: " << div << endl;
}

double Calculator::Add(double n1, double n2) {
	add++;
	return n1 + n2;
}

double Calculator::Min(double n1, double n2) {
	min++;
	return n1 - n2;
}

double Calculator::Mul(double n1, double n2) {
	mul++;
	return n1*n2;
}

double Calculator::Div(double n1, double n2) {
	div++;
	return n1 / n2;
}

int main() {
	Calculator cal;
	cal.Init();
	cout << "3.2 + 2.4 = " << cal.Add(3.2, 2.4) << endl;
	cout << "3.5 / 1.7 = " << cal.Div(3.5, 1.7) << endl;
	cout << "2.2 - 1.5 = " << cal.Min(2.2, 1.5) << endl;
	cout << "4.9 / 1.2 = " << cal.Div(4.9, 1.2) << endl;
	cal.ShowOpCount();
	return 0;
}
