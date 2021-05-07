//lecture1
//sorting

#include <iostream>
using namespace std;

void swap(int* a, int* b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}

void selsort(int list[], int size) {
	for (int i = 0; i < size - 1; i++) {
		int min = i;
		for (int j = i + 1; j < size; j++) {
			if (list[min] > list[j]) { min = j; }
		}
		swap(&list[i], &list[min]);
		
	}
}

int main() {
	int list[] = { 13, 2, 4, 90, 22, 34, 6 };
	int size = sizeof(list) / sizeof(int);
	
	cout << " Original array : ";
	for (int i = 0; i < size; i++) {
		cout << list[i] << " ";
	}
	selsort(list, size);

	cout << endl;

	cout << " Sorted array : ";
	for (int i = 0; i < size; i++) {
		cout << list[i] << " ";
	}
}