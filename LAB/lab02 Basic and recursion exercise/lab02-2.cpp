//////////////////////
// Name: ¿Ã¥Ÿ¿∫
// Student ID: 20203112
// Program ID: Lab#02-2
//////////////////////

#include <iostream>

using namespace std;

bool isPrime(int num) {
	for (int i = 2; i < num; i++) {
		if (num % i == 0) { return false; }
	}
	return true;
}

int nextPrime(int num) {
	int next = num + 1;
	while (!isPrime(next)) {
		next += 1;
	}
	return next;
}

int main() {
	int num;
	while (true) {
		cout << "Enter any number : ";
		cin >> num;

		if (isPrime(num)) { cout << num << " is prime number" << endl; }
		else { cout << num << " is not a prime number" << endl; }

		cout << "prime number larger than given number : " << nextPrime(num) << endl;

		cout << endl;
	}

    

}

