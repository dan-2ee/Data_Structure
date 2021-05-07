////////////////////
// Name: 이다은
// Student ID: 20203112
// Program ID: Lab#03
////////////////////
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void swap(int* a, int* b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}

void selsort(int list[], int size) {    //리스트 정렬
	for (int i = 0; i < size - 1; i++) {
		int min = i;
		for (int j = i + 1; j < size; j++) {
			if (list[min] > list[j]) { min = j; }
		}
		swap(&list[i], &list[min]);

	}
}

int Iter_binsrch(int list[], int left, int right, int srchnum) {
	//position return, 반복문
	int middle;
	while (left <= right) {
		middle = (right + left) / 2;
		if (srchnum == list[middle]) return middle + 1;
		else if (srchnum > list[middle]) left = middle + 1;
		else right = middle - 1;
	} 
	return -1;     //찾는 숫자가 리스트에 없을 때
}

int Re_binsrch(int list[], int left, int right, int srchnum) {  //순환문
	if (left > right) return -1;
	int middle;
	middle = (left + right) / 2;
	if (list[middle] == srchnum) return middle + 1;
	else if (list[middle] < srchnum) return Re_binsrch(list, middle + 1, right, srchnum);
	else return Re_binsrch(list, left, middle - 1, srchnum);
}

int Seq_Search(int list[], int srhnum, int size) {   //순차탐색
	for (int i = 0; i < size; i++) {
		if (srhnum == list[i]) return i+1; // i는 position
	}
	return -1;
}

int main() {
	int list[10];
	int size = 10;
	int select = 0;
	int srchnum, position;    //목표 숫자, 위치

	ifstream text;
	text.open("lab3-1.txt");
	for (int i = 0; i < 10; i++) {
		text >> list[i];
	}

	cout << "Numbers in the Data File : " << endl;
	cout << endl;

	cout << "before sort : ";   //정렬 전 리스트 출력
	for (int i = 0; i < 10; i++) { cout << list[i] << " "; }
	cout << endl << endl;

	selsort(list, size);    //정렬 함수 호출
	cout << "Sorted array : ";   //정렬 후 리스트 출력 
	for (int i = 0; i < 10; i++) { cout << list[i] << " "; }
	cout << endl << endl;

	while (true) {
		cout << "Enter methods of Search : 1. Bin-search 2. Recursive search 3. Sequential search 4. Exit : ";
		cin >> select;

		if (select == 4) break;

		cout << "Enter an integer to search : ";
		cin >> srchnum;

		if (select == 1) position = Iter_binsrch(list, 0, size - 1, srchnum);
		else if (select == 2) position = Re_binsrch(list, 0, size - 1, srchnum);
		else if (select == 3) position = Seq_Search(list, srchnum, size);

		if (position == -1) cout << srchnum << " is not in the list" << endl;
		else cout << srchnum << " is at position " << position << endl;

		cout << endl;
	}
}






