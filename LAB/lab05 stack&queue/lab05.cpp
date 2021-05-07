//////////////////////
// Name: 이다은
// Student ID: 20203112
// Program ID: Lab#05
//////////////////////
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

const int stackSize = 100;
int stack[stackSize];
int top;
char arr[80];
void create_stack() { top = 0; }

void push(char val) {
	stack[++top] = val;
}

char pop() {
	return stack[top--];
}

int oper_rank(char c) {
	if (c == ')') return 3;
	else if (c == '*' || c == '/') return 2;
	else if (c == '+' || c == '-') return 1;
	else if (c == '(') return 0;
	else return -1;
}

int isEmpty() {
	if (top == 0) return 1;
	else return 0;
}

void postfix(char exp[]) {
	int i = 0;
	int j = 0;
	char token;
	char popdata;
	stack[0] = '$';
	while ((token = exp[i]) != '\0') {
		if (token == '(') {
			push(token);
		}
		else if (token == ')') {
			while (stack[top] != '(') { 
			    popdata = pop();
				cout << popdata;
				arr[j++] = popdata;
			}
			popdata = pop();
		}
		else if (token == '*' || token == '/' || token == '+' || token == '-') {
			if ((oper_rank(stack[top]) < oper_rank(token))) push(token);
			else {
				popdata = pop();
				cout << popdata;
				arr[j++] = popdata;
				push(token);
			}
		}
		else {
			cout << token;
			arr[j++] = token;
		}
		i++;
	}
	while ((token = pop()) != '$') {
		arr[j++] = token;
		cout << token;
	}
	arr[j++] = '\0';
}

void eval(char exp[]) {
	int op1, op2;
	int i = 0;
	char token;

	while (((token = exp[i]) != '\0')) {
		if (token == ' ') {   //공백 들어오면 넘어감
			i++;
			continue;
		}
		else if (token == '+' || token == '-' || token == '*' || token == '/') {  //token = 연산자
			op2 = pop();

			op1 = pop();
			switch (token) {
			case '+': push(op1 + op2); break;
			case '-': push(op1 - op2); break;
			case '*': push(op1 * op2); break;
			case '/': push(op1 / op2); break;
			}
		}
		else {   //token = 피연산자
			push(token - '0');
		}
		i++;
	}
	int finaldata = pop();
	cout << finaldata << endl;;
}

int main() {
	char line[80];

	ifstream text;
	text.open("lab5.txt");

	while (text.getline(line, 80)) {
		create_stack();
		cout << "Infix expression : " << line << "  ";
		cout << "The Postfix conversion: ";
		postfix(line);
		cout << endl << endl;

		cout << "The final result : ";
		eval(arr);
		cout << endl;
	}

}