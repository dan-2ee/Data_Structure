//lecture1
//�Ҽ� �Ǻ� & ���� �Ҽ� ã��

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

	if (isPrime(num)) { cout << num << " is prime" << endl; }   //�Ҽ��Ǻ� ���
	else { cout << num << " is not prime" << endl; }

	cout << "next prime : " << nextPrime(num) << endl;     //���� �Ҽ� ���

}