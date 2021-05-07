#include <iostream>
#include<iomanip>
using namespace std;

struct Node {
	int data;
	Node* next;
};

class linkedQueue {
private:
	Node* front;
	Node* rear;
public:
	linkedQueue() { front = 0; rear = 0; }
	~linkedQueue() {
		Node* p;
		while (front != 0) {
			p = front;
			front = front->next;
			delete p;
		}
	}
	void createQueue();
	void enqueue(int num);
	int dequeue();
	int isEmpty();
	void displayQueue();
	void searchQueue(int num);
};

void linkedQueue::createQueue() { front = 0; rear = 0; }
void linkedQueue::enqueue(int num) {
	Node* temp = new Node;
	temp->data = num;
	temp->next = 0;

	if (isEmpty()) { front = temp; rear = temp; }
	else {
		rear->next = temp;
		rear = temp;
	}
}

int linkedQueue::dequeue() {
	Node* p;
	int num;

	p = front;
	num = front->data;
	if (front == rear) { front = 0; rear = 0; } //node가 하나인 경우
	else front = front->next;
	
	delete p;
	return num;
}

int linkedQueue::isEmpty() {
	if (front == 0) return 1;
	else return 0;
}

void linkedQueue::displayQueue() {
	Node* p;
	if (isEmpty()) {cout << "Queue is empty\n"; return;}
	else {
		p = front;
		while (p != 0) {
			cout << setw(8) << p->data;
			p = p->next;
		}
		cout << endl;
	}
}

void linkedQueue::searchQueue(int num) {
	Node* p;
	if (isEmpty()) { cout << "Queue is Empty\n"; return; }
	else {
		p = front;
		while (p != 0 && p->data != num) {
			p = p->next;
		}
		if (p != 0) cout << num << " is in the Queue\n";
		else cout << num << " is not in the Queue\n";
	}
}

int main() {
	linkedQueue Q;
	int num, choice;
	Q.createQueue();

	while (true) {
		cout << "input a number : 1.enqueue, 2.dequeue, 3.search, 4.display, 5.quit => ";
		cin >> choice;
		switch (choice) {
		case 1: {
			cout << "input a number => ";
			cin >> num;
			Q.enqueue(num);
			Q.displayQueue(); break;
		}
		case 2: {
			if (Q.isEmpty()) {
				cout << "Queue is empty\n"; break;
			}
			else {
				num = Q.dequeue();
				cout << num << " has been dequeue\n"; break;
			}
		}
		case 3: {
			cout << "Enter a number => ";
			cin >> num;
			Q.searchQueue(num); break;
		}
		case 4: {Q.displayQueue(); break; }
		case 5: {Q.~linkedQueue();  return 0; }
		default: {cout << "Bad command\n"; break; }
		}
	}
}