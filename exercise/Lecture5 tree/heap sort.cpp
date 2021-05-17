#include <iostream>
using namespace std;

#define MAX_SIZE 11

class MaxHeap {
private:
	int n = 0;
public:
	int heap[MAX_SIZE+1];
	void Create(int item);
	int heapFull();
	int heapEmpty();
	void insertItem(int item);
	void deleteItem();
	int searchItem(int item);
	void printHeap();
	void adjust(int i, int n);
	void heapSort();
	void makeHeap();
};


void MaxHeap::Create(int num)
{
	heap[++n] = num;
}

int MaxHeap::heapFull() {
	if (n == MAX_SIZE) return 1;
	else return 0;
}

int MaxHeap::heapEmpty() {
	if (n == 0) return 1;
	else return 0;
}

void MaxHeap::insertItem(int item) {
	if (heapFull()) cout << "heap is full\n";
	else {
		int i;
		i = ++n; //item추가하기위해 사이즈 키움
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

int MaxHeap::searchItem(int item)
{
	for (int i = 1; i <= n; i++)
	{
		if (item == heap[i])
			return 1;
	}
	return 0;
}

void MaxHeap::printHeap()
{
	if (heapEmpty()) cout << "Heap is empty!!" << endl;
	else
	{
		for (int i = 1; i <= n; i++)
		{
			cout << heap[i] << " ";
		}
		cout << endl;
	}
}

void MaxHeap::makeHeap()
{
	for (int i = n / 2; i > 0; i--)
	{
		adjust(i, n);
	}
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

void MaxHeap::heapSort()
{
	for (int i = n / 2; i > 0; i--)
		adjust(i, n);

	for (int i = n - 1; i > 0; i--) {
		swap(heap[1], heap[i + 1]);
		adjust(1, i);
		printHeap();
	}
	cout << "Sort결과 : ";
	printHeap();
	cout << endl;
}


int main() {
	MaxHeap m;
	m.Create(26); m.Create(5); m.Create(77); 
	m.Create(1); m.Create(61); m.Create(11); 
	m.Create(59); m.Create(15); m.Create(48); m.Create(19);

	int flag = 1;
	while (flag) {
		cout << "Enter Command: (1.Insert, " << "2.Delete, " << "3.search, " << "4.print, "
			<< "5.heap sort, " << "6.make heap" << "7.Quit) : ";
		int sel;
		cin >> sel;

		switch (sel) {
		case 1:
			int a;
			cout << "Enter a number to insert : ";
			cin >> a;
			m.insertItem(a);
			m.printHeap();
			break;
		case 2:
			m.deleteItem();
			m.printHeap();
			break;
		case 3:
			if (m.heapEmpty())
				cout << "Heap is Empty" << endl;
			else {
				cout << "Enter a number to search : ";
				int a;
				cin >> a;
				if (m.searchItem(a))
					cout << a << "is found";
				else cout << a << " is not found";
				cout << endl;
			}
			break;
		case 4:
			m.printHeap();
			break;
		case 5:
			m.heapSort();
			break;
		case 6:
			m.makeHeap();
			m.printHeap();
			break;
		case 7:
			flag = 0;
		}
	}
}


