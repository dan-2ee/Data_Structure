//////////////////////
// Name: 이다은
// Student ID: 20203112
// Program ID: Lab#09
//////////////////////
#include <iostream>
using namespace std;

#define MAX_SIZE 11

class MaxHeap {
private:
	int n = 10;
public:
	int heap[MAX_SIZE + 1] = { 0, 26,5,77,1,61,11, 59, 15, 48, 19 };  //맨 앞 쓰지않음
	int heapFull();
	int heapEmpty();
	void levelTest();
	void insertItem(int item);
	void deleteItem();
	int searchItem(int item);
	void printHeap();
	void adjust(int i, int n);
	void heapSort();
	void makeHeap();
};

int MaxHeap::heapFull() {
	if (n == MAX_SIZE) return 1;
	else return 0;
}

int MaxHeap::heapEmpty() {
	if (n == 0) return 1;
	else return 0;
}

void MaxHeap::levelTest() {
	int level = 0;
	for (int i = 1; i <= n; i *= 2) level++;

	cout << "Level of Heap is " << level << endl;
}
void MaxHeap::insertItem(int item) {
	if (heapFull()) cout << "heap is full\n";
	else {
		int i;
		i = ++n; //item추가, 사이즈 +=1
		while ((i != 1) && (item > heap[i / 2])) {
			heap[i] = heap[i / 2];
			i /= 2;
		}
		heap[i] = item;
	}
}

void MaxHeap::deleteItem() {
	int parent, child;
	int temp;
	int item;

	item = heap[1];  //삭제할 데이터
	temp = heap[n--];  //맨 마지막 원소
	parent = 1; child = 2;

	while (child <= n) {
		if ((child <= n) && (heap[child] < heap[child + 1])) child++;
		if (temp >= heap[child]) break;
		heap[parent] = heap[child];
		parent = child;
		child *= 2;
	}
	heap[parent] = temp;
}

int MaxHeap::searchItem(int item){
	for (int i = 1; i <= n; i++) {
		if (item == heap[i])
			return 1;
	}
	return 0;
}

void MaxHeap::printHeap() {
	if (heapEmpty()) cout << "Heap is empty!!" << endl;
	else {
		cout << "Heap:  ";
		for (int i = 1; i <= n; i++) cout << heap[i] << " ";
		cout << endl << endl;
	}
}

void MaxHeap::makeHeap() {
	for (int i = n / 2; i > 0; i--) adjust(i, n);
}

void MaxHeap::adjust(int i, int n) {  //make MaxHeap
	int child;
	int temp;
	child = 2 * i;
	temp = heap[i];

	while (n >= child) {
		if (n > child && heap[child] < heap[child + 1]) child += 1;
		if (temp >= heap[child]) break;
		heap[child / 2] = heap[child];
		child *= 2;
	}
	heap[child / 2] = temp;
}

void MaxHeap::heapSort() {
	for (int i = n / 2; i > 0; i--) adjust(i, n);

	for (int i = n - 1; i > 0; i--) {
		swap(heap[1], heap[i + 1]);
		adjust(1, i);
	}
}

int main() {
	MaxHeap m;

	int flag = 1;
	int item;
	while (flag) {
		cout << "Enter Command: (1.print  " << "2.search  " << "3.leveltest  " << "4.makeheap  "
			<< "5.heapsort  " << "6.delete  " << "7.insert  " << "8.quit) ";
		
		int choice;
		cin >> choice;

		switch (choice) {
		case 1:
			m.printHeap();
			break;
		case 2:
			if (m.heapEmpty())
				cout << "Heap is Empty" << endl;
			else {
				cout << "Enter a number to search: ";
				cin >> item;
				if (m.searchItem(item)) cout << item << " is found\n";
				else cout << item << " is not found\n";
			}
			break;
		case 3:
			m.levelTest();
			break;
		case 4:
			cout << "heap 변환:  ";
			m.makeHeap();
			m.printHeap();
			break;
		case 5:
			cout << "Sort 결과:  ";
			m.heapSort();
			m.printHeap();
			break;
		case 6:
			m.deleteItem();
			m.printHeap();
			break;
		case 7:
			cout << "Enter a number to insert : ";
			cin >> item;
			m.insertItem(item);
			m.printHeap();
			break;
		case 8:
			flag = 0;
		}
	}
}


