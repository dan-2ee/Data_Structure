#include <iostream>
using namespace std;
 //stack sample code 1
const int stacksize = 3;
int stack[stacksize];
int top;

void create_stack() {
	top = -1;
}

int isFull() {
	if (top == stacksize - 1) return 1;
	else return 0;
}

int isEmpty() {
	if (top == -1) return 1;
	else return 0;
}

void push(int num) {
	stack[++top] = num;
}

int pop() {
	return stack[top--];
}

void displayStack() {
	int sp;   //임시 포인터
	if (isEmpty()) cout << "Stack is empty!" << endl;
	else {
		sp = top;
		while (sp != -1) cout << stack[sp--] << " ";
		cout << endl;
	}
}

int main() {
	int num, choice;
	create_stack();

	while (1) {
		cout << "Enter command(1.push, 2.pop, 3.traverse, 4.exit) : ";
		cin >> choice;
		if (choice == 1) {
			if (!isFull()) {
				cout << "Enter an integer to push : ";
				cin >> num;
				push(num);
			}
			else cout << "Stack is full!\n";
		}

		else if (choice == 2) {
			if (!isEmpty()) {
				num = pop();
				cout << num << " is popped.\n";
			}
			else cout << "Stack is empty!\n";
		}

		else if (choice == 3) displayStack();
		else if (choice == 4) break;
		else cout << "Bad Command!\n";
	}
}