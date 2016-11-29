/*
#include <iostream>
#include <cstring>
using namespace std;

char *MakeStr(int len) {
char *str = new char[len];
return str;
}

int main() {
char *str1 = MakeStr(100);
char *str2 = MakeStr(100);
char str3[50];
strcpy_s(str2, 100, "I'm happy");
strcpy_s(str2, 100, "I'm sad");
cout << "strlen(str1): " << strlen(str1) << endl;
cout << "strlen(str2): " << strlen(str2) << endl;
strcat_s(str1, 100, " but, I'm BEST!");
cout << "str1: " << str1 << endl;
cout << "str2: " << str2 << endl;
cout << "strcmp: " << strcmp(str1, str2) << endl;
return 0;
}
*/

#include <iostream>
#include <cstring>
using namespace std;

int main() {
	char *str1 = "ABC 123 ";
	char *str2 = "DEF 456 ";
	char str3[50];

	cout << "strlen(str1): " << strlen(str1) << endl;
	cout << "strlen(str2): " << strlen(str2) << endl;

	strcpy_s(str3, 50, str1);
	strcat_s(str3, 50, str2);

	cout << "str3: " << str3 << endl;

	if (strcmp(str1, str2) == 0)
		cout << "문자열이 같다." << endl;
	else
		cout << "문자열이 같지않다." << endl;
	return 0;
}
