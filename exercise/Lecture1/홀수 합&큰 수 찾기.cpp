#include <iostream>
using namespace std;
//lecture1
//n까지 홀수의 합 구하기
int sum(int num) {
	int sum = 0;
	for (int i = 1; i <= num; i += 2) {
		sum += i;
	}
	return sum;
}

//lecture1
//3 숫자 중 가장 큰 수 찾기
int findMax(int a, int b, int c) {
	int max = a;
	if (max < b) { max = b; }
	if (max < c) { max = c; }
	return max;
}

int main() {
	int num;
	int n1, n2, n3;
    
	cout << "n을 입력하시오 : ";
	cin >> num;
	cout << "n까지의 홀수합 : " << sum(num) << endl;

	cout << "n1, n2, n3을 입력하시오 : ";
	cin >> n1>> n2>> n3;
	cout << n1 << n2 << n3 << "중 가장 큰 수: " << findMax(n1, n2, n3) << endl;
}
