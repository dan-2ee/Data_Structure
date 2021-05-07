//lecture1
//Addition of two numbers

#include <iostream>
#include <string>
using namespace std;

void reverIter(string text, int size) {
	for (int i = size-1; i >= 0; i--) {
		cout << text[i];
	}
}

void reverRecur(string text, int size) {
	if (size == 0) { return; }
	else {  
		cout << text[size - 1];
		reverRecur(text, size - 1);
	}
}

int main() {
	string text;
	getline(cin, text);
	int size = text.length();

	reverIter(text, size);
	cout << endl;

	reverRecur(text, size);
	cout << endl;
}

