#include <iostream>
using namespace std;

const int stacksize = 5;

class Stack {
private:
	int stack[stacksize];
	int top;

public:
	Stack() { top = -1; }  //top을 -1로 초기화하여 스택 생성
	void push(int val) { stack[++top] = val; }
	int pop() { return stack[top--]; }
	int isFull() {
		if (top == stacksize - 1) return 1;
		else return 0;
	}
	int isEmpty() {
		if (top == -1) return 1;
		else return 0;
	}
	void displaystack();
};

void Stack::displaystack() {
	int sp;
	sp = top;
	while (sp != -1) {
		if (isEmpty()) cout << "StackEmpty" << endl;
		else {
			while (sp != -1) {
				cout << "Stack: ";
				cout << stack[sp--] << " ";
			}
			cout << endl;
		}
	}
}

int main() {
	Stack s1;
	int num, choice;

	while (1) {
		cout << "Enter command(1.push, 2.pop, 3.traverse, 4.exit) : ";
		cin >> choice;
		if (choice == 1) {
			if (!s1.isFull()) {
				cout << "Enter an integer to push : ";
				cin >> num;
				s1.push(num);
			}
			else cout << "Stack is full!\n";
		}

		else if (choice == 2) {
			if (!s1.isEmpty()) {
				num = s1.pop();
				cout << num << " is popped.\n";
			}
			else cout << "Stack is empty!\n";
		}

		else if (choice == 3) s1.displaystack();
		else if (choice == 4) break;
		else cout << "Bad Command!\n";
	}
}