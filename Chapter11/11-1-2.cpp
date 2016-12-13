/*
	문제 2. Chapter07의 문제 07-2의 Book, EBook 클래스를
	깊은 복사가 진행되도록 정의
	07-2-2.cpp(https://github.com/afterhoon/cppProgrammingExam/blob/master/Chapter07/07-2-2.cpp)
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
	Book(const Book &ref) : price(ref.price) {
		title = new char[strlen(ref.title) + 1];
		isbn = new char[strlen(ref.isbn) + 1];
		strcpy_s(title, strlen(ref.title) + 1, ref.title);
		strcpy_s(isbn, strlen(ref.isbn) + 1, ref.isbn);
	}
	Book &operator=(Book &ref) {
		delete[]title;
		delete[]isbn;

		title = new char[strlen(ref.title) + 1];
		isbn = new char[strlen(ref.isbn) + 1];
		strcpy_s(title, strlen(ref.title) + 1, ref.title);
		strcpy_s(isbn, strlen(ref.isbn) + 1, ref.isbn);
		price = ref.price;
		return *this;
	}
	void ShowBookInfo() {
		cout << "제목: " << title << endl;
		cout << "ISBN: " << isbn << endl;
		cout << "가격: " << price << endl;
	}
	~Book() {
		delete[]title;
		delete[]isbn;
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
	EBook(const EBook &ref) : Book(ref) {
		DRMKey = new char[strlen(ref.DRMKey) + 1];
		strcpy_s(DRMKey, strlen(ref.DRMKey) + 1, ref.DRMKey);
	}
	EBook &operator=(EBook &ref) {
		Book::operator=(ref);
		delete[]DRMKey;
		
		DRMKey = new char[strlen(ref.DRMKey) + 1];
		strcpy_s(DRMKey, strlen(ref.DRMKey) + 1, ref.DRMKey);
		return *this;
	}
	void ShowEBookInfo() {
		ShowBookInfo();
		cout << "인증키: " << DRMKey << endl;
	}
	~EBook() {
		delete[]DRMKey;
	}
};

int main() {
	Book book("좋은 C++", "555-12345-890-0", 20000);
	book.ShowBookInfo();
	cout << endl;
	EBook ebook("좋은 C++ ebook", "555-12345-890-1", 10000, "fdx9w0i8kiw");
	ebook.ShowEBookInfo();
	cout << endl;

	Book book1("복사할 book", "555-1234-123-1", 10000);
	Book book2 = book1;

	book2.ShowBookInfo();
	cout << endl;

	EBook eb1("복사할 ebook", "555-1234-123-0", 2000, "5345435");
	EBook eb2 = eb1;

	eb2.ShowEBookInfo();
	cout << endl;
	return 0;
}
