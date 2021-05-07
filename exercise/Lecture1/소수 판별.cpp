//lecture1
//소수 판별 & 다음 소수 찾기

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
	cout << "enter number : ";
	cin >> num;

	if (isPrime(num)) { cout << num << " is prime" << endl; }   //소수판별 출력
	else { cout << num << " is not prime" << endl; }

	cout << "next prime : " << nextPrime(num) << endl;     //다음 소수 출력

}