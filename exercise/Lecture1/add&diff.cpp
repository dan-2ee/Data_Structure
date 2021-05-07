//lecture1
//calculate two numbers

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
int main() {
	int n1, n2;
	cin >> n1 >> n2;

	cout << "Addition of two numbers : " << ADD(n1, n2) << endl;
	cout << "Difference between two numbers : " << DIFF(n1, n2) << endl;
}