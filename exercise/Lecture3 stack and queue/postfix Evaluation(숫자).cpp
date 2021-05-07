#include <iostream>
#include <string>
using namespace std;

//postfix evaluation 
//����ǥ�� ���
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
		if (token == ' ') {   //���� ������ �Ѿ
			i++;
			continue;
		}
		else if (token == '+' || token == '-' || token == '*' || token == '/') {  //token = ������
			op2 = pop();

			op1 = pop();
			switch (token) {
			case '+': push(op1 + op2); break;
			case '-': push(op1 - op2); break;
			case '*': push(op1 * op2); break;
			case '/': push(op1 / op2); break;
			}
		}
		else {   //token = �ǿ�����
			push(token - '0');
		}
		i++;
	}
	return pop();
}

int main() {
	char line[80];
	cout << "Enter Expression : ";
	cin.getline(line, 80);   //���� ���� ����
	create_stack();
	cout << eval(line);
}