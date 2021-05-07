/*
Name : 이다은
Student ID : 20203112
Program ID : HW#2
Description :
1. 데이터 파일을 열어서 텍스트를 읽는다.
2. 파일 안에 있는 표현식이 괄호의 균형을 맞추었는지, 스택을 이용하여 테스트한다.
3. 데이터 파일의 각 줄마다 테스트한 결과를 출력한다.
Algorithm :
1. createStack 함수를 호출하여 스택을 생성한다.
2. 데이터 파일을 한 줄씩 읽어와서 출력한다.
3. check_paren 함수를 호출하여, 읽어온 문자열이 올바른 표현식인지 확인한다.
4. 올바른 표현식이라면 "The Expression is Valid" 문자를 출력한다.
5. 올바른 표현식이 아니라면 "The Expression is Invalid" 문자를 출력한다.
6. 데이터 파일의 끝에 도달하면 while문을 빠져나온다.
7. 데이터 파일 속에 있는 괄호의 균형이 맞는 식의 개수와 맞지 않는 식의 개수를 출력한뒤 실행을 종료한다. 
Variables :
1. void push() : 문자를 받아서 스택에 저장하는 함수
2. char pop() : top이 가리키고 있는 스택 속의 문자를 반환하는 함수
3. void createStack() : 스택을 생성하는 함수
4. int isEmpty() : 스택이 비어있는지 확인하는 함수
5. int match() : 문자 두개가 균형을 이루는지 확인하는 함수
6. int check_paren() : 표현식의 좌우 괄호가 균형을 맞추었는지 확인하는 함수
7. StackSize : 스택의 최대 크기 지정
8. top : 스택의 최상위 원소를 가리키는 포인터
9. balanced : 올바른 식의 개수
10. Unbalanced : 괄호의 개수가 틀린 식의 개수
11. mismatched : 괄호의 종류가 틀린 식의 개수
12. validity : 표현식의 테스트 결과 저장
13. buffer : 텍스트 파일에서 읽어온 문자열 저장
*/

#include <iostream>
#include <fstream>
using namespace std;

const int StackSize = 100;   //stack의 최대 사이즈
int top;     //stack의 최상위 원소를 가리키는 포인터
int stack[StackSize];
int balanced = 0;     // 올바른 식 
int Unbalanced = 0;    // Parentheses 개수가 틀린 경우
int mismatched = 0;    // Parentheses 종류가 틀린 경우

/*
function : push
description : 스택에 문자 삽입
variables :
			1. char data : 삽입할 문자
*/
void push(char data) {
	stack[++top] = data;
}

/*
function : pop
description : 스택의 최상위 원소 반환
*/

char pop() {
	return stack[top--];
}

/*
function : createStack
description : 스택(stack) 생성
variables :
			1. int top : 스택의 최상위 원소를 가리키는 포인터
*/

void createStack() { top = -1; }

/*
function : isEmpty
description : 스택의 원소수가 0이면 True(1), 아니면 False(0) 반환
*/

int isEmpty() {
	if (top == -1) return 1;
	else return 0;
}

/*
function : match
description : 문자 두개(a, b)가 균형을 이루는지 확인하는 함수
              균형을 이룬다면 True(1), 아니면 False(0) 반환
*/

int match(char a, char b) {
	// 문자가 균형을 이루는 경우
	if (a == '[' && b == ']') return 1;   
	else if (a == '(' && b == ')') return 1;
	else if (a == '{' && b == '}') return 1;
	// 문자가 균형을 이루지 않는 경우
	else return 0;
}

/*
function : check_paren
description : 파일에서 읽어온 표현식의 좌우 괄호가 균형을 맞추었는지 확인하는 함수
variables :
			1. char exp[] : 데이터 파일에서 읽어온 문자열
			2. char temp : pop 함수의 반환값(스택의 최상위 원소)
			3. int balanced : 올바른 식의 개수
            4. int Unbalanced : 괄호의 개수가 틀린 식의 개수
            5. int mismatched : 괄호의 종류가 틀린 식의 개수
*/

int check_paren(char exp[]) {
	char temp;
	for (int i = 0; i < strlen(exp); i++) {  // 읽어온 문자열이 끝날 때까지 실행
		if (exp[i] == '(' || exp[i] == '{' || exp[i] == '[') push(exp[i]);  // 좌괄호인 경우
		if (exp[i] == ')' || exp[i] == ']' || exp[i] == '}') {  // 우괄호인 경우
			if (isEmpty()) {  // Parentheses 개수가 틀린 경우
				cout << "The Expression has unbalanced parentheses" << endl;
				Unbalanced++;
				return 0;   // return false
			}
			else {
				temp = pop();   // stack의 최상위 원소(좌괄호) 반환
				if (!match(temp, exp[i])) { // Parentheses 종류가 틀린 경우
					// 틀린 Parentheses 출력
					cout << " The Mismatched Parenthes in the Expression are " << temp << " and " << exp[i] << endl;
					mismatched++;
					return 0; // return false
				}
			}
		}
	}

	//stack에 아직 괄호가 남아있으면 개수가 맞지 않는 것임
	if (isEmpty()) { balanced++;  return 1; }  // return true
	else { Unbalanced++; return 0; }  // return false;
}

int main() {
	char text[80];
	int validity;   // 표현식의 테스트 결과 저장
	ifstream buffer;
	buffer.open("hw2.txt");  // "hw2.txt" 파일을 불러옴

	cout << "<< Hw2: Balanced Parentheses >> " << endl << endl;

	while (buffer.getline(text, 80)) {  // 파일에서 1라인을 읽은뒤 text에 저장
		createStack();    //stack 생성
		cout << "Input Data " << text << endl;   // 읽어온 라인 출력
		validity = check_paren(text);   // 표현식의 테스트 결과 저장
		if (validity) cout << "The Expression is Valid" << endl << endl; // validity is true
		else cout << "The Expression is Invalid" << endl << endl;   // validity is false
	}

	// 괄호의 균형이 맞는 경우(balanced), 개수가 틀린 경우(Unbalanced), 종류가 틀린 경우(Mismatched) 출력
	cout << " Total:  Balanced :" << balanced << " Unbalanced :" << Unbalanced << " Mismatched :" << mismatched;

}