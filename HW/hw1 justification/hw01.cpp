/*
Name : 이다은
Student ID : 20203112
Program ID : HW#1
Description :
1. 데이터 파일을 열어서 텍스트를 읽는다.
2. 정렬 방법을 선택한다. (왼쪽 정렬 or 오른쪽 정렬 or 가운데 정렬)
3. 선택한 방법으로 정렬한다.
4. 정렬된 결과를 출력한다.
Algorithm :
1. 선택지를 출력하여 사용자에게 보여준다.
2. 원하는 정렬 방식을 사용자에게 입력받아서 select에 저장한다.
3. select가 1이면 Left_justification 함수를 호출하여 텍스트 파일을 왼쪽 정렬한 뒤 출력한다.
4. select가 2이면 Right_justification 함수를 호출하여 텍스트 파일을 오른쪽 정렬한 뒤 출력한다.
5. select가 3이면 Centered_justification 함수를 호출하여 텍스트 파일을 가운데 정렬한 뒤 출력한다.
6. select가 4이면 while문을 빠져나와서 실행을 종료한다.
Variables :
1. void Left_justification() : 텍스트 파일을 열어서 왼쪽 정렬한 결과를 출력하는 함수
2. void Right_justification() : 텍스트 파일을 열어서 오른쪽 정렬한 결과를 출력하는 함수
3. void Centered_justification() : 텍스트 파일을 열어서 가운데 정렬한 결과를 출력하는 함수
4. newbuffer : 정렬된 문자열 저장
5. buffer : 텍스트 파일에서 읽어온 문자열 저장
6. select : 사용자가 선택한 기능 저장
*/

#include <iostream>
#include <fstream>
#include <string>

using namespace std;
ifstream text;

/*
function : Left_justification
description : 텍스트 파일("hw1.txt")에서 읽어온 문자열을 왼쪽 정렬하여 출력한다.
variables :
			1. int i : 공백이 아닌 데이터가 시작되는 위치
			2. string newbuffer : buffer를 왼쪽 정렬한 문자열
			3. string buffer : "hw1.txt" 파일에서 한 줄씩 읽어온 문자열
*/

void Left_justification() {
	text.open("hw1.txt");   // "hw1.txt" 파일을 불러옴

	while (text.peek() != EOF) {   // 파일이 끝날 때까지 실행
		int i = 0;
		string newbuffer;          // 정렬된 문자열을 newbuffer에 저장
		string buffer;    // 라인을 읽어올 변수
		getline(text, buffer);     // 파일에서 1라인을 읽은뒤 buffer에 저장

		while (buffer[i] == ' ') {   // 공백이 아닌 데이터 만날때까지 인덱스(i) 증가
			i++;
		}

		while (i < buffer.length()) {   // 데이터가 시작되는 인덱스(i)부터 끝까지, 
			newbuffer += buffer[i];     // 출력버퍼(newbuffer)에 문자열 저장
			i++;
		}

		newbuffer += "\n";      // end-of-line 추가
		cout << newbuffer;     // 왼쪽으로 정렬된 문자열(newbuffer) 출력
	}
	text.close();   // "hw1.txt" 파일 닫음.
}

/*
function : Right_justification
description : 텍스트 파일("hw1.txt")에서 읽어온 문자열을 오른쪽 정렬하여 출력한다.
variables :
			1. string buffer : "hw1.txt" 파일에서 한 줄씩 읽어온 문자열
			2. string newbuffer : buffer를 오른쪽 정렬한 문자열
			3. int size = buffer의 길이
*/

void Right_justification() {
	text.open("hw1.txt");        // "hw1.txt" 파일을 불러옴

	while (text.peek() != EOF) {     // 파일이 끝날 때까지 실행
		string buffer;
		string newbuffer;
		getline(text, buffer);     // 파일에서 1라인을 읽은뒤 buffer에 저장
		int size = buffer.length();     //buffer의 길이 저장

		for (int i = 0; i < 79 - size; i++) {    // 한줄에 최대 80개 문자 출력 가능, index: 0~79  
			newbuffer += ' ';   // 출력할 데이터의 앞부분에 buffer의 길이(size)를 제외한만큼의 공백 삽입
		}

		newbuffer += buffer;   // 출력버퍼(newbuffer)의 공백 문자 뒤쪽에 문자열 저장
		newbuffer += "\n";  // end - of - line 추가
		cout << newbuffer;   // 오른쪽 정렬한 문자열 출력
	}
	text.close();    // "hw1.txt" 파일 닫음.
}

/*
function : Centered_justification
description : 텍스트 파일("hw1.txt")에서 읽어온 문자열을 가운데 정렬하여 출력한다.
variables :
			1. string newbuffer : buffer를 가운데 정렬한 문자열
			2. string buffer : "hw1.txt" 파일에서 한 줄씩 읽어온 문자열
			3. int blanksize : 앞뒤로 추가할 빈공간 계산된 값 저장
*/

void Centered_justification() {
	text.open("hw1.txt");       // "hw1.txt" 파일을 불러옴

	while (text.peek() != EOF) { // 파일이 끝날 때까지 실행
		string buffer;
		string newbuffer;
		getline(text, buffer);    // 파일에서 1라인을 읽은뒤 buffer에 저장
		int blanksize = (80 - buffer.length()) / 2;   // 앞에 삽입할 공백 = (전체 빈공간 계산된 값)/2

		for (int i = 0; i < blanksize-1; i++) {
			newbuffer += ' ';    // 출력버퍼(newbuffer)에 계산된 공간삽입
		}

		newbuffer += buffer;   // 출력버퍼(newbuffer)로 가운데 정렬한 문자열 저장 복사
		newbuffer += "\n";     // end-of-line 추가
		cout << newbuffer;    // 가운데 정렬한 문자열 출력
	}
	text.close();      // "hw1.txt" 파일 닫음.
}


int main() {
	int select;    // 사용자가 선택한 옵션 저장
	while (true) {    // select != 4일때까지 실행
		cout << "************************************" << endl;
		cout << "1. Left     Justification" << endl;    //옵션 출력
		cout << "2. Right    Justification" << endl;
		cout << "3. Centered Justification" << endl;
		cout << "4. Terminate" << endl << endl;
		cout << "Enter your choice : ";

		cin >> select;    //옵션 입력 받음
		cout << endl;

		if (select == 1) {
			cout << "12345678901234567890123456789012345678901234567890123456789012345678901234567890" << endl;
			Left_justification();  // select == 1일 때 왼쪽정렬함수 호출
			cout << endl << endl;
		}

		else if (select == 2) {
			cout << "12345678901234567890123456789012345678901234567890123456789012345678901234567890" << endl;
			Right_justification();   // select == 2일 때 왼쪽정렬함수 호출
			cout << endl << endl;
		}

		else if (select == 3) {     // select == 3일 때 왼쪽정렬함수 호출
			cout << "12345678901234567890123456789012345678901234567890123456789012345678901234567890" << endl;
			Centered_justification();
			cout << endl << endl;
		}

		else { break; }    // select == 4일 때 실행 종료
	}
}