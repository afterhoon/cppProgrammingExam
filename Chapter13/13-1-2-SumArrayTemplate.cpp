#include <iostream>
using namespace std;

template <class T>
T SumArray(T arr[], int len) {
	T sum = 0;
	for (int i = 0; i < len; i++)
		sum += arr[i];
	return sum;
}

int main() {
	int intArr[20];
	double doubleArr[20];

	for (int i = 0; i < 20; i++) {
		intArr[i] = i;
		doubleArr[i] = 0.321 * i;
	}
	cout << "intArr의 총합: " << SumArray(intArr, 20) << endl;
	cout << "doubleArr의 총합: " << SumArray(doubleArr, 20) << endl;
	return 0;
}
