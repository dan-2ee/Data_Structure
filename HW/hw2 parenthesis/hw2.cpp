/*
Name : �̴���
Student ID : 20203112
Program ID : HW#2
Description :
1. ������ ������ ��� �ؽ�Ʈ�� �д´�.
2. ���� �ȿ� �ִ� ǥ������ ��ȣ�� ������ ���߾�����, ������ �̿��Ͽ� �׽�Ʈ�Ѵ�.
3. ������ ������ �� �ٸ��� �׽�Ʈ�� ����� ����Ѵ�.
Algorithm :
1. createStack �Լ��� ȣ���Ͽ� ������ �����Ѵ�.
2. ������ ������ �� �پ� �о�ͼ� ����Ѵ�.
3. check_paren �Լ��� ȣ���Ͽ�, �о�� ���ڿ��� �ùٸ� ǥ�������� Ȯ���Ѵ�.
4. �ùٸ� ǥ�����̶�� "The Expression is Valid" ���ڸ� ����Ѵ�.
5. �ùٸ� ǥ������ �ƴ϶�� "The Expression is Invalid" ���ڸ� ����Ѵ�.
6. ������ ������ ���� �����ϸ� while���� �������´�.
7. ������ ���� �ӿ� �ִ� ��ȣ�� ������ �´� ���� ������ ���� �ʴ� ���� ������ ����ѵ� ������ �����Ѵ�. 
Variables :
1. void push() : ���ڸ� �޾Ƽ� ���ÿ� �����ϴ� �Լ�
2. char pop() : top�� ����Ű�� �ִ� ���� ���� ���ڸ� ��ȯ�ϴ� �Լ�
3. void createStack() : ������ �����ϴ� �Լ�
4. int isEmpty() : ������ ����ִ��� Ȯ���ϴ� �Լ�
5. int match() : ���� �ΰ��� ������ �̷���� Ȯ���ϴ� �Լ�
6. int check_paren() : ǥ������ �¿� ��ȣ�� ������ ���߾����� Ȯ���ϴ� �Լ�
7. StackSize : ������ �ִ� ũ�� ����
8. top : ������ �ֻ��� ���Ҹ� ����Ű�� ������
9. balanced : �ùٸ� ���� ����
10. Unbalanced : ��ȣ�� ������ Ʋ�� ���� ����
11. mismatched : ��ȣ�� ������ Ʋ�� ���� ����
12. validity : ǥ������ �׽�Ʈ ��� ����
13. buffer : �ؽ�Ʈ ���Ͽ��� �о�� ���ڿ� ����
*/

#include <iostream>
#include <fstream>
using namespace std;

const int StackSize = 100;   //stack�� �ִ� ������
int top;     //stack�� �ֻ��� ���Ҹ� ����Ű�� ������
int stack[StackSize];
int balanced = 0;     // �ùٸ� �� 
int Unbalanced = 0;    // Parentheses ������ Ʋ�� ���
int mismatched = 0;    // Parentheses ������ Ʋ�� ���

/*
function : push
description : ���ÿ� ���� ����
variables :
			1. char data : ������ ����
*/
void push(char data) {
	stack[++top] = data;
}

/*
function : pop
description : ������ �ֻ��� ���� ��ȯ
*/

char pop() {
	return stack[top--];
}

/*
function : createStack
description : ����(stack) ����
variables :
			1. int top : ������ �ֻ��� ���Ҹ� ����Ű�� ������
*/

void createStack() { top = -1; }

/*
function : isEmpty
description : ������ ���Ҽ��� 0�̸� True(1), �ƴϸ� False(0) ��ȯ
*/

int isEmpty() {
	if (top == -1) return 1;
	else return 0;
}

/*
function : match
description : ���� �ΰ�(a, b)�� ������ �̷���� Ȯ���ϴ� �Լ�
              ������ �̷�ٸ� True(1), �ƴϸ� False(0) ��ȯ
*/

int match(char a, char b) {
	// ���ڰ� ������ �̷�� ���
	if (a == '[' && b == ']') return 1;   
	else if (a == '(' && b == ')') return 1;
	else if (a == '{' && b == '}') return 1;
	// ���ڰ� ������ �̷��� �ʴ� ���
	else return 0;
}

/*
function : check_paren
description : ���Ͽ��� �о�� ǥ������ �¿� ��ȣ�� ������ ���߾����� Ȯ���ϴ� �Լ�
variables :
			1. char exp[] : ������ ���Ͽ��� �о�� ���ڿ�
			2. char temp : pop �Լ��� ��ȯ��(������ �ֻ��� ����)
			3. int balanced : �ùٸ� ���� ����
            4. int Unbalanced : ��ȣ�� ������ Ʋ�� ���� ����
            5. int mismatched : ��ȣ�� ������ Ʋ�� ���� ����
*/

int check_paren(char exp[]) {
	char temp;
	for (int i = 0; i < strlen(exp); i++) {  // �о�� ���ڿ��� ���� ������ ����
		if (exp[i] == '(' || exp[i] == '{' || exp[i] == '[') push(exp[i]);  // �°�ȣ�� ���
		if (exp[i] == ')' || exp[i] == ']' || exp[i] == '}') {  // ���ȣ�� ���
			if (isEmpty()) {  // Parentheses ������ Ʋ�� ���
				cout << "The Expression has unbalanced parentheses" << endl;
				Unbalanced++;
				return 0;   // return false
			}
			else {
				temp = pop();   // stack�� �ֻ��� ����(�°�ȣ) ��ȯ
				if (!match(temp, exp[i])) { // Parentheses ������ Ʋ�� ���
					// Ʋ�� Parentheses ���
					cout << " The Mismatched Parenthes in the Expression are " << temp << " and " << exp[i] << endl;
					mismatched++;
					return 0; // return false
				}
			}
		}
	}

	//stack�� ���� ��ȣ�� ���������� ������ ���� �ʴ� ����
	if (isEmpty()) { balanced++;  return 1; }  // return true
	else { Unbalanced++; return 0; }  // return false;
}

int main() {
	char text[80];
	int validity;   // ǥ������ �׽�Ʈ ��� ����
	ifstream buffer;
	buffer.open("hw2.txt");  // "hw2.txt" ������ �ҷ���

	cout << "<< Hw2: Balanced Parentheses >> " << endl << endl;

	while (buffer.getline(text, 80)) {  // ���Ͽ��� 1������ ������ text�� ����
		createStack();    //stack ����
		cout << "Input Data " << text << endl;   // �о�� ���� ���
		validity = check_paren(text);   // ǥ������ �׽�Ʈ ��� ����
		if (validity) cout << "The Expression is Valid" << endl << endl; // validity is true
		else cout << "The Expression is Invalid" << endl << endl;   // validity is false
	}

	// ��ȣ�� ������ �´� ���(balanced), ������ Ʋ�� ���(Unbalanced), ������ Ʋ�� ���(Mismatched) ���
	cout << " Total:  Balanced :" << balanced << " Unbalanced :" << Unbalanced << " Mismatched :" << mismatched;

}