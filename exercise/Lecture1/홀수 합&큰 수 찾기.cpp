#include <iostream>
using namespace std;
//lecture1
//n���� Ȧ���� �� ���ϱ�
int sum(int num) {
	int sum = 0;
	for (int i = 1; i <= num; i += 2) {
		sum += i;
	}
	return sum;
}

//lecture1
//3 ���� �� ���� ū �� ã��
int findMax(int a, int b, int c) {
	int max = a;
	if (max < b) { max = b; }
	if (max < c) { max = c; }
	return max;
}

int main() {
	int num;
	int n1, n2, n3;
    
	cout << "n�� �Է��Ͻÿ� : ";
	cin >> num;
	cout << "n������ Ȧ���� : " << sum(num) << endl;

	cout << "n1, n2, n3�� �Է��Ͻÿ� : ";
	cin >> n1>> n2>> n3;
	cout << n1 << n2 << n3 << "�� ���� ū ��: " << findMax(n1, n2, n3) << endl;
}
