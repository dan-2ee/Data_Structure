/*
Name: 이다은
Student ID: 20203112
Program ID: Lab1-1
Description: Max, Min number(위치 포함) 찾아서 출력
*/

#include <iostream>
#include <fstream>
using namespace std;

int FindMin(int data[], int n) {
	int min = data[0];
	int minpos = 0;
	for (int i = 0; i < n; i++) {
		if (min > data[i]) {
			min = data[i];
			minpos = i;
		}
	}
	return minpos;
}

int FindMax(int data[], int n) {
	int max = data[0];
	int maxpos = 0;
	for (int i = 0; i < n; i++) {
		if (max < data[i]) {
			max = data[i];
			maxpos = i;
		}
	}
	return maxpos;
}

int main() {
	int minnum, maxnum;
	int size = 10;
	ifstream infile; int data[10];

	infile.open("lab1-1.txt");
	if (infile.fail()) {
		cout << "can't open the input file" << endl; exit(1);
	}
	for (int i = 0; i < size; i++) {
		infile >> data[i];
	}
	for (int i = 0; i < size; i++) {
		cout << "data[" << i << "]: " << data[i] << endl;
	}

	minnum = FindMin(data, size);
	cout << "Minimum number is " << data[minnum] << " at position " << minnum+1 << endl;

	maxnum = FindMax(data, size);
	cout << "Maximum number is " << data[maxnum] << " at position " << maxnum+1 << endl;
	
	infile.close();
	return 0;
}
