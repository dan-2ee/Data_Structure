//lecture1
//factorial

#include <iostream>
using namespace std;

int iterFact(int n) {
	int result = 1;
	for(int i = 1; i <= n; i++) {
		result *= i;
	}
	return result;
}

int recurFact(int n) {
	if (n == 0) return 1;
	return n * recurFact(n - 1);
}

int main() {
	int num;
	cin >> num;

	cout << "--non-recursive factorial--" << endl;
	cout << num << "! : " << iterFact(num) << endl;

	cout << "--recursive factorial--" << endl;
	cout << num << "! : " << recurFact(num);
}