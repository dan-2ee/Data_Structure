#include <iostream>
using namespace std;
const int Queuesize = 10;

class Queue {
private:
	int front, rear;
	int flag;
	int queue[Queuesize];

public:
	Queue() { front = 0, rear = 0, flag = 0; }
	void enqueue(int val);
	int dequeue();
	void displayQueue();
};

void Queue::enqueue(int val) {
	rear = (rear + 1) % Queuesize;
	if ((front == rear) && (flag == 1)) {
		cout << "Queue is Full" << endl;
	}
	else {
		queue[rear] = val;
		flag = 1;
	}
}

int Queue::dequeue() {
	int item;
	if ((front == rear) && (flag == 0)) {
		item = 0;
	}
	else {
		front = (front + 1) % Queuesize;
		item = queue[front];
		flag = 0;
	}
	return item;
}

void Queue::displayQueue() {
	if ((rear == front) && (flag == 0)) {
		cout << "Queue is empty" << endl;
	}
	else {
		int qp;
		qp = front+1;
		while (qp <= rear) {
			cout << queue[qp++] << " ";
		}
		cout << endl;
	}
}

int main() {
	Queue q1;
	int num, choice;

	while (1) {
		cout << "Enter command(1.enqueue, 2.dequeue, 3.display, 4.exit) : ";
		cin >> choice;
		if (choice == 1) {
			cout << "Enter an integer to insert : ";
			cin >> num;
			q1.enqueue(num);
		}

		else if (choice == 2) {
			num = q1.dequeue();
			if (num==0) cout << "Queue is empty!\n";
			else cout << num << " is deleted.\n";
		}
		else if (choice == 3) q1.displayQueue();
		else if (choice == 4) break;
		else cout << "Bad Command!\n";
	}
}