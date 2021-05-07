//////////////////////
// Name: ¿Ã¥Ÿ¿∫
// Student ID: 20203112
// Program ID: Lab#02-1
//////////////////////

#include <iostream>

using namespace std;

//Addition of two numbers
int ADD(int n1, int n2) {
	if (n1 == 0) return n2;
	else return ADD(--n1, ++n2);
}

//Difference between two numbers
int DIFF(int n1, int n2) {
	if (n1 == 0) return n2;
	else if (n2 == 0) return n1;
	else return DIFF(--n1, --n2);
}

int sum(int num) {
	if (num != 0) return num + sum(num - 1);
	else return num;
}

void reverRecur(char text[], int size) {
	if (size == 0) { return; }
	else {
		cout << text[size - 1];
		reverRecur(text, size - 1);
	}
}


int main() {
	int num1, num2 , num3;
	char s1[80];
	int size;
	cout << "Enter number1 : ";
	cin >> num1;
	cout << "Enter number2 : ";
	cin >> num2;
	cout << "Sum is : " << ADD(num1, num2) << endl;

	cout << endl;

	cout << "Enter number1 : ";
	cin >> num1;
	cout << "Enter number2 : ";
	cin >> num2;
	cout << "Difference is : " << DIFF(num1, num2) << endl;

	cout << endl;

	cout << "Enter any positive Integer: ";
	cin >> num3;
	cout << "Sum of numbers : " << sum(num3) << endl;

	cout << endl;

	cout << "Enter String : ";
	cin >> s1;
	size = strlen(s1);
	cout << "Reverse of the string is: ";
	reverRecur(s1, size);


}
