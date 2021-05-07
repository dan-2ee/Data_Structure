////////////////////
// Name: �̴���
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

void selsort(int list[], int size) {    //����Ʈ ����
	for (int i = 0; i < size - 1; i++) {
		int min = i;
		for (int j = i + 1; j < size; j++) {
			if (list[min] > list[j]) { min = j; }
		}
		swap(&list[i], &list[min]);

	}
}

int Iter_binsrch(int list[], int left, int right, int srchnum) {
	//position return, �ݺ���
	int middle;
	while (left <= right) {
		middle = (right + left) / 2;
		if (srchnum == list[middle]) return middle + 1;
		else if (srchnum > list[middle]) left = middle + 1;
		else right = middle - 1;
	} 
	return -1;     //ã�� ���ڰ� ����Ʈ�� ���� ��
}

int Re_binsrch(int list[], int left, int right, int srchnum) {  //��ȯ��
	if (left > right) return -1;
	int middle;
	middle = (left + right) / 2;
	if (list[middle] == srchnum) return middle + 1;
	else if (list[middle] < srchnum) return Re_binsrch(list, middle + 1, right, srchnum);
	else return Re_binsrch(list, left, middle - 1, srchnum);
}

int Seq_Search(int list[], int srhnum, int size) {   //����Ž��
	for (int i = 0; i < size; i++) {
		if (srhnum == list[i]) return i+1; // i�� position
	}
	return -1;
}

int main() {
	int list[10];
	int size = 10;
	int select = 0;
	int srchnum, position;    //��ǥ ����, ��ġ

	ifstream text;
	text.open("lab3-1.txt");
	for (int i = 0; i < 10; i++) {
		text >> list[i];
	}

	cout << "Numbers in the Data File : " << endl;
	cout << endl;

	cout << "before sort : ";   //���� �� ����Ʈ ���
	for (int i = 0; i < 10; i++) { cout << list[i] << " "; }
	cout << endl << endl;

	selsort(list, size);    //���� �Լ� ȣ��
	cout << "Sorted array : ";   //���� �� ����Ʈ ��� 
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






