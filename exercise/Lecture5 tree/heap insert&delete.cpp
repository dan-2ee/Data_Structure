#include <iostream>
using namespace std;

#define MAX_SIZE 8

int heap[MAX_SIZE];
int tree[MAX_SIZE];
int level = 0;  //tree
int n = 0;   //heap

void Create(int item) {
	tree[level++] = item;
}

int heapFull() {
	if (n == MAX_SIZE) return 1;
	else return 0;
}

int heapEmpty() {
	if (n == 0) return 1;
	else return 0;
}

void insertItem(int item) {
	int i;
	if (heapFull()) cout << "heap is full\n";
	else {
		i = ++n; //item추가하기위해 사이즈 키움
		while ((i != 1) && (item > heap[i / 2])) {
			heap[i] = heap[i / 2];
			i /= 2;
		}
		heap[i] = item;
	}
}

void deleteItem() {
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

void printheap() {
	for (int i = 1; i <= n; i++)
		cout << heap[i] << " ";
	cout << endl;
}

int main() {
	Create(8); Create(6); Create(4); Create(2); Create(5); Create(3);
	for (int i = 0; i < 6; i++) insertItem(tree[i]);

    int num;
    while (1) {
        cout << "Enter Command: (1.Insert, " << "2.Delete, " << "3.Print, " << "4.is_Empty, " << "5.is_Full, "
            << "6.Quit) : ";
        int sel;
        cin >> sel;

        switch (sel) {
        case 1:
            cout << "Enter a number to insert : ";
            cin >> num;
            insertItem(num);
            printheap();
            break;
        case 2:
            deleteItem();
            printheap();
            break;
        case 3:
            printheap();
            break;
        case 4:
            if (heapEmpty())
                cout << "Heap is Empty" << endl;
            else
                cout << "Heap is not Empty" << endl;
            break;
        case 5:
            if (heapFull())
                cout << "Heap is Full" << endl;
            else
                cout << "Heap is not Full" << endl;
            break;
        case 6:
            return 0;
        }
    }
}