/*
	문제 2. Book 클래스와 EBook 클래스의 클래스 완성
*/

#include <iostream>
#include <cstring>
using namespace std;

class Book {
private:
	char *title;
	char *isbn;
	int price;
public:
	Book(char *t, char *i, int p) : price(p) {
		title = new char[strlen(t) + 1];
		isbn = new char[strlen(i) + 1];
		strcpy_s(title, strlen(t) + 1, t);
		strcpy_s(isbn, strlen(i) + 1, i);
	}
	void ShowBookInfo() {
		cout << "제목: " << title << endl;
		cout << "ISBN: " << isbn << endl;
		cout << "가격: " << price << endl;
	}
};

class EBook : public Book {
private:
	char *DRMKey;
public:
	EBook(char *t, char *i, int p, char *d)
		: Book(t, i, p) {
		DRMKey = new char[strlen(d) + 1];
		strcpy_s(DRMKey, strlen(d) + 1, d);
	}
	void ShowEBookInfo() {
		ShowBookInfo();
		cout << "인증키: " << DRMKey << endl;
	}
};

int main() {
	Book book("좋은 C++", "555-12345-890-0", 20000);
	book.ShowBookInfo();
	cout << endl;
	EBook ebook("좋은 C++ ebook", "555-12345-890-1", 10000, "fdx9w0i8kiw");
	ebook.ShowEBookInfo();
	return 0;
}
