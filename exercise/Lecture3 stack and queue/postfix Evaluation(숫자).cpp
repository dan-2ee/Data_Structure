#include <iostream>
#include <string>
using namespace std;

//postfix evaluation 
//후위표기 계산
const int MaxstackSize = 100;
int stack[MaxstackSize];
int top;

void create_stack() { top = -1; }

void push(char val) {
	stack[++top] = val;
}

int pop() {
	return stack[top--];
}

int eval(char exp[]) {
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
	return pop();
}

int main() {
	char line[80];
	cout << "Enter Expression : ";
	cin.getline(line, 80);   //공백 포함 저장
	create_stack();
	cout << eval(line);
}