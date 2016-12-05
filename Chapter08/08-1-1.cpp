/*
	문제 1. EmployeeManager4.cpp에 ForeignSalesWorker클래스 추가
*/

#include <iostream>
#include <cstring>
using namespace std;

namespace RISK_LEVEL {
	enum {
		RISK_A, RISK_B, RISK_C
	};
};

class Employee {
private:
	char name[100];
public:
	Employee(char *name) {
		strcpy_s(this->name, sizeof(this->name) / sizeof(char), name);
	}
	void ShowYourName() const {
		cout << "name: " << name << endl;
	}
	virtual int GetPay() const = 0;
	virtual void ShowSalaryInfo() const = 0;
};

class PermanentWorker : public Employee {
private:
	int salary;
public:
	PermanentWorker(char *name, int money)
		: Employee(name), salary(money) {

	}
	int GetPay() const {
		return salary;
	}
	void ShowSalaryInfo() const {
		ShowYourName();
		cout << "salary: " << GetPay() << endl << endl;
	}
};

class TemporaryWorker : public Employee {
private:
	int workTime;
	int payPerHour;
public:
	TemporaryWorker(char *name, int pay)
		: Employee(name), workTime(0), payPerHour(pay) {

	}
	void AddWorkTime(int time) {
		workTime += time;
	}
	int GetPay() const {
		return workTime*payPerHour;
	}
	void ShowSalaryInfo() const {
		ShowYourName();
		cout << "salary: " << GetPay() << endl << endl;
	}
};

class SalesWorker : public PermanentWorker {
private:
	int salesResult;
	double bonusRatio;
public:
	SalesWorker(char *name, int money, double ratio)
		: PermanentWorker(name, money), salesResult(0), bonusRatio(ratio) {

	}
	void AddSalesResult(int value) {
		salesResult += value;
	}
	int GetPay() const {
		return PermanentWorker::GetPay() + (int)(salesResult*bonusRatio);
	}
	void ShowSalaryInfo() const {
		ShowYourName();
		cout << "salary: " << GetPay() << endl;
	}
};

class ForeignSalesWorker : public SalesWorker {
private:
	int risk;
public:
	ForeignSalesWorker(char *name, int money, double ratio, int risky)
		: SalesWorker(name, money, ratio), risk(risky) {

	}
	int GetRiskPay() const{
		switch (risk) {
		case RISK_LEVEL::RISK_A: return 0.3 * GetPay();
		case RISK_LEVEL::RISK_B: return 0.2 * GetPay();
		case RISK_LEVEL::RISK_C: return 0.1 * GetPay();
		}
	}
	void ShowSalaryInfo() const {
		SalesWorker::ShowSalaryInfo();
		cout << "risk pay: " << GetRiskPay() << endl;
		cout << "salary: " << GetPay() + GetRiskPay() << endl << endl;
	}
};

class EmployeeHandler {
private:
	Employee *empList[50];
	int empNum;
public:
	EmployeeHandler() : empNum(0) {

	}
	void AddEmployee(Employee* emp) {
		empList[empNum++] = emp;
	}
	void ShowAllSalaryInfo() const {
		for (int i = 0; i < empNum; i++)
			empList[i]->ShowSalaryInfo();

	}
	void ShowTotalSalary() {
		int sum = 0;
		for (int i = 0; i < empNum; i++)
			sum += empList[i]->GetPay();
		cout << "salary sum: " << sum << endl;
	}
	~EmployeeHandler() {
		for (int i = 0; i < empNum; i++)
			delete empList[i];
	}
};

int main() {
	EmployeeHandler handler;

	ForeignSalesWorker *fseller1 = new ForeignSalesWorker("Hong", 1000, 0.1, RISK_LEVEL::RISK_A);
	fseller1->AddSalesResult(7000);
	handler.AddEmployee(fseller1);

	ForeignSalesWorker *fseller2 = new ForeignSalesWorker("Yoon", 1000, 0.1, RISK_LEVEL::RISK_B);
	fseller2->AddSalesResult(7000);
	handler.AddEmployee(fseller2);

	ForeignSalesWorker *fseller3 = new ForeignSalesWorker("Lee", 1000, 0.1, RISK_LEVEL::RISK_C);
	fseller3->AddSalesResult(7000);
	handler.AddEmployee(fseller3);

	handler.ShowAllSalaryInfo();
	return 0;
}
