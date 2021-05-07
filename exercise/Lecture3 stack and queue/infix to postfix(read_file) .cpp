#include <iostream>
#include <string>
#include <fstream>
using namespace std;

//infix to postfix conversion  
//중위표기 -> 후위표기
const int stackSize = 100;
int stack[stackSize];
int top;

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
	char token;
	stack[0] = '$';
	while ((token = exp[i])!='\0') {
		if (token == '(') {
			push(token);
		}
		else if (token == ')') {
			while (stack[top] != '(') cout << pop();
			pop();
		}
		else if (token == '*' || token == '/' || token == '+' || token == '-') {
			if ((oper_rank(stack[top]) < oper_rank(token))) push(token);
			else {
				cout << pop();
				push(token);
		    }
		}
		else cout << token;    //피연산자일때
		i++;
	}
	while ((token=pop())!='$') cout << token;
} 
int main() {
	char line[80];
	
	ifstream text;
	text.open("hw1.txt");

	while (!text.eof()) { text.getline(line, 80); }
	create_stack();
	postfix(line);

}