//lecture1
//Fibonacci
#include <iostream>
using namespace std;

int iterFibo(int num) {
	int f0 = 0;
	int sum = 0;
	int f1 = 1;
	if (num == 0 || num == 1) { return num; }
	else {  
		for (int i = 2; i <= num; i++) {
			sum = f0 + f1;
			f0 = f1;
			f1 = sum;
		}
	}
	return sum;
}

int recurFibo(int num) {  
	if (num == 0 || num == 1) { return num; }
	return recurFibo(num - 1) + recurFibo(num - 2 );
}

int main() {
	int num;
	cin >> num;

	cout << "iterative Fibonacci : " << iterFibo(num) << endl;
	cout << "recursive Fibonacci : " << recurFibo(num) << endl;
}

