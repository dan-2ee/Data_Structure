#include <iostream>
using namespace std;

void swap(int* ptr_a, int* ptr_b) {
	int tmp;
	tmp = *ptr_a;   //tmp = a
	*ptr_a = *ptr_b;  //*ptr_a = b
	*ptr_b = tmp;     //*ptr_b = a
}

int iterGCD(int a, int b) {
	int tmp;
	if (a < b) swap(&a, &b);
	while (b != 0) {
		tmp = a;
		a = b;
		b = tmp % b;
	}
	return a;
}

int recurGCD(int a, int b) {
	if (a < b) swap(&a, &b);
	if (b == 0) return a;
	recurGCD(b, a % b);
}

int main() {
	int a, b;
	cout << "Enter numbers : ";
	cin >> a >> b;
	cout << "recursive GCD: " << recurGCD(a, b) << endl;
	cout << "iterative GCD: " << iterGCD(a, b) << endl;

}





