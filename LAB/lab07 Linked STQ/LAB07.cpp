//////////////////////
// Name: 이다은
// Student ID: 20203112
// Program ID: Lab#07
//////////////////////
#include <iostream>
#include<iomanip>
using namespace std;

class Node {
private:
	int data;
	Node* next;
	Node(int num) { data = num; next = 0; }
	friend class linkedStack;
	friend class linkedQueue;
	friend class linkedList;
};

class linkedStack {
private:
	Node* top;

public:
	linkedStack() { top = 0; }
	~linkedStack() {
		Node* p;
		while (top != 0) {
			p = top;
			top = top->next;
			delete p;
		}
	}
	void push(int num);
	int pop();
	int isEmpty();
	void displayStack();
};

int linkedStack::isEmpty() {
	if (top == 0) return 1;
	else return 0;
}

void linkedStack::push(int num) {
	Node* temp = new Node(num);

	if (isEmpty()) top = temp;
	else {
		temp->next = top;
		top = temp;
	}
}

int linkedStack::pop() {
	Node* p;
	int num;

	num = top->data;   //반환할 top의 값 저장
	p = top;
	top = top->next;   //top은 다음위치로 이동 
	delete p;
	return num;
}

void linkedStack::displayStack() {
	Node* p;
	if (isEmpty()) { cout << "stack is empty\n"; return; }
	else {
		p = top;
		cout << "Stack:";
		while (p != 0) {
			cout << setw(8) << p->data;
			p = p->next;
		}
		cout << endl;
	}
}

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
	void enqueue(int num);
	int dequeue();
	int isEmpty();
	void displayQueue();
};

void linkedQueue::enqueue(int num) {
	Node* temp = new Node(num);

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
	if (isEmpty()) { cout << "Queue is empty\n"; return; }
	else {
		p = front;
		cout << "Queue:";
		while (p != 0) {
			cout << setw(8) << p->data;
			p = p->next;
		}
		cout << endl;
	}
}

class linkedList {
private:
	Node* head;
public:
	linkedList() { head = 0; }
	~linkedList() {
		Node* p;
		while (head != 0) {
			p = head;
			head = head->next;
			delete p;
		}
	}
	int isEmpty();
	void insert(int c);
	void merge(linkedStack& s, linkedQueue& q);
	void displayList();
};

int linkedList::isEmpty() {
	if (head == 0) return 1;
	else return 0;
}

void linkedList::insert(int c) {
	Node* temp = new Node(c);

	if (isEmpty()) { head = temp; }
	else if (temp->data < head->data) {
		temp->next = head;
		head = temp;
	}
	else {    //오름차순으로 삽입
		Node* p, * q;
		p = head;
		while (p != 0 && temp->data > p->data) {
			q = p;
			p = p->next;
		}
		if (p != 0) { q->next = temp; temp->next = p; }
		else {
			q->next = temp;
		}
	}
}

void linkedList::merge(linkedStack& s, linkedQueue& q) {    //s와 q 합침
	while (!s.isEmpty()) insert(s.pop());
	while (!q.isEmpty()) insert(q.dequeue());
}

void linkedList::displayList() {
	if (isEmpty()) { cout << "List is empty\n"; return; }
	else {
		Node* p;
		p = head;
		cout << "List:";
		while (p != 0) {
			cout << setw(8) << p->data;
			p = p->next;
		}
		cout << endl;
	}
}

int main() {
	linkedStack L1;
	linkedQueue L2;
	linkedList L3;

	int choice;
	int n;

	while (true) {
		cout << "MENU: (1.push, 2.pop, 3.enqueue, 4.dequeue, 5.Makelist, 6.quit) : ";
		cin >> choice;
		switch (choice) {
		case 1: {
			cout << "Enter an integer to push => ";
			cin >> n;
			L1.push(n);
			L1.displayStack(); break;
		}
		case 2: {
			if (L1.isEmpty()) { cout << "Stack is empty\n"; break; }
			else {
				n = L1.pop();
				cout << n << " ==> is popped!\n";
				L1.displayStack(); break;
			}
		}
		case 3: {
			cout << "Enter an integer to enque => ";
			cin >> n;
			L2.enqueue(n);
			L2.displayQueue();  break;
		}
		case 4: {
			if (L2.isEmpty()) { cout << "Queue is empty\n"; break; }
			else {
				n = L2.dequeue();
				cout << n << " ==> is dequed!\n";
				L2.displayQueue();  break;
			}
		}
		case 5: {
			L3.merge(L1, L2);
			L3.displayList(); break;
		}
		case 6: {
			L1.~linkedStack();
			L2.~linkedQueue();
			L3.~linkedList();
			return 0;
		}
		}
	}
}