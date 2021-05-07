#include <iostream>
#include<iomanip>
using namespace std;

struct Node {
	int data;
	Node* next;
};

class linkedStack {
private:
	Node* head;

public:
	linkedStack() { head = 0; }
	~linkedStack() {
		Node* p;
		while (head != 0) {
			p = head;
			head = head->next;
			delete p;
		}
	}
	void createStack();
	void push(int num);
	int pop();
	int isEmpty();
	void displayStack();
	void searchStack(int num);
};

void linkedStack::createStack() {
	head = 0;
}

int linkedStack::isEmpty() {
	if (head == 0) return 1;
	else return 0;
}

void linkedStack::push(int num) {
	Node* temp = new Node;
	temp->data = num;
	temp->next = 0;

	if (isEmpty()) head = temp;
	else {
		temp->next = head;
		head = temp;
	}
}

int linkedStack::pop() {
	Node* p;
	int num;
    
	num = head->data;   //반환할 head의 값 저장
	p = head;
	head = head->next;   //head는 다음위치로 이동 
	delete p;
	return num;	
}

void linkedStack::displayStack() {
	Node* p;
	if (isEmpty()) { cout << "stack is empty\n"; return; }
	else {
		p = head;
		while (p != 0) {
			cout << setw(8) << p->data;
			p = p->next;
		}
		cout << endl;
	}
}

void linkedStack::searchStack(int num) {
	Node* p;
	if (isEmpty()) { cout << "stack is Empty\n"; return; }
	else {
		p = head;
		while (p != 0 && p->data != num) {
			p = p->next;
		}
		if (p != 0) cout << num << " is in the list\n";
		else cout << num << " is not in the list\n";
	}
}

int main() {
	linkedStack L;
	int choice, num;
	L.createStack();
	while (true) {
		cout << "input a number : 1.push, 2.pop, 3.search, 4.display, 5.quit => ";
		cin >> choice;
		switch (choice) {
		case 1: {
			cout << "input a number => ";
			cin >> num;
			L.push(num);
			L.displayStack(); break;
		}
		case 2: {
			if (L.isEmpty()) {
				cout << "Stack is empty\n"; break;
			}
			else {
				num = L.pop();
				cout << num << " has been poped\n"; break;
			}
		}
		case 3: {
			cout << "Enter a number => ";
			cin >> num;
			L.searchStack(num); break;
		}
		case 4: {L.displayStack(); break; }
		case 5: {L.~linkedStack();  return 0; }
		default: {cout << "Bad command\n"; break; }
		}
	}
}