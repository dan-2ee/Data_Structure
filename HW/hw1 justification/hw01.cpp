/*
Name : �̴���
Student ID : 20203112
Program ID : HW#1
Description :
1. ������ ������ ��� �ؽ�Ʈ�� �д´�.
2. ���� ����� �����Ѵ�. (���� ���� or ������ ���� or ��� ����)
3. ������ ������� �����Ѵ�.
4. ���ĵ� ����� ����Ѵ�.
Algorithm :
1. �������� ����Ͽ� ����ڿ��� �����ش�.
2. ���ϴ� ���� ����� ����ڿ��� �Է¹޾Ƽ� select�� �����Ѵ�.
3. select�� 1�̸� Left_justification �Լ��� ȣ���Ͽ� �ؽ�Ʈ ������ ���� ������ �� ����Ѵ�.
4. select�� 2�̸� Right_justification �Լ��� ȣ���Ͽ� �ؽ�Ʈ ������ ������ ������ �� ����Ѵ�.
5. select�� 3�̸� Centered_justification �Լ��� ȣ���Ͽ� �ؽ�Ʈ ������ ��� ������ �� ����Ѵ�.
6. select�� 4�̸� while���� �������ͼ� ������ �����Ѵ�.
Variables :
1. void Left_justification() : �ؽ�Ʈ ������ ��� ���� ������ ����� ����ϴ� �Լ�
2. void Right_justification() : �ؽ�Ʈ ������ ��� ������ ������ ����� ����ϴ� �Լ�
3. void Centered_justification() : �ؽ�Ʈ ������ ��� ��� ������ ����� ����ϴ� �Լ�
4. newbuffer : ���ĵ� ���ڿ� ����
5. buffer : �ؽ�Ʈ ���Ͽ��� �о�� ���ڿ� ����
6. select : ����ڰ� ������ ��� ����
*/

#include <iostream>
#include <fstream>
#include <string>

using namespace std;
ifstream text;

/*
function : Left_justification
description : �ؽ�Ʈ ����("hw1.txt")���� �о�� ���ڿ��� ���� �����Ͽ� ����Ѵ�.
variables :
			1. int i : ������ �ƴ� �����Ͱ� ���۵Ǵ� ��ġ
			2. string newbuffer : buffer�� ���� ������ ���ڿ�
			3. string buffer : "hw1.txt" ���Ͽ��� �� �پ� �о�� ���ڿ�
*/

void Left_justification() {
	text.open("hw1.txt");   // "hw1.txt" ������ �ҷ���

	while (text.peek() != EOF) {   // ������ ���� ������ ����
		int i = 0;
		string newbuffer;          // ���ĵ� ���ڿ��� newbuffer�� ����
		string buffer;    // ������ �о�� ����
		getline(text, buffer);     // ���Ͽ��� 1������ ������ buffer�� ����

		while (buffer[i] == ' ') {   // ������ �ƴ� ������ ���������� �ε���(i) ����
			i++;
		}

		while (i < buffer.length()) {   // �����Ͱ� ���۵Ǵ� �ε���(i)���� ������, 
			newbuffer += buffer[i];     // ��¹���(newbuffer)�� ���ڿ� ����
			i++;
		}

		newbuffer += "\n";      // end-of-line �߰�
		cout << newbuffer;     // �������� ���ĵ� ���ڿ�(newbuffer) ���
	}
	text.close();   // "hw1.txt" ���� ����.
}

/*
function : Right_justification
description : �ؽ�Ʈ ����("hw1.txt")���� �о�� ���ڿ��� ������ �����Ͽ� ����Ѵ�.
variables :
			1. string buffer : "hw1.txt" ���Ͽ��� �� �پ� �о�� ���ڿ�
			2. string newbuffer : buffer�� ������ ������ ���ڿ�
			3. int size = buffer�� ����
*/

void Right_justification() {
	text.open("hw1.txt");        // "hw1.txt" ������ �ҷ���

	while (text.peek() != EOF) {     // ������ ���� ������ ����
		string buffer;
		string newbuffer;
		getline(text, buffer);     // ���Ͽ��� 1������ ������ buffer�� ����
		int size = buffer.length();     //buffer�� ���� ����

		for (int i = 0; i < 79 - size; i++) {    // ���ٿ� �ִ� 80�� ���� ��� ����, index: 0~79  
			newbuffer += ' ';   // ����� �������� �պκп� buffer�� ����(size)�� �����Ѹ�ŭ�� ���� ����
		}

		newbuffer += buffer;   // ��¹���(newbuffer)�� ���� ���� ���ʿ� ���ڿ� ����
		newbuffer += "\n";  // end - of - line �߰�
		cout << newbuffer;   // ������ ������ ���ڿ� ���
	}
	text.close();    // "hw1.txt" ���� ����.
}

/*
function : Centered_justification
description : �ؽ�Ʈ ����("hw1.txt")���� �о�� ���ڿ��� ��� �����Ͽ� ����Ѵ�.
variables :
			1. string newbuffer : buffer�� ��� ������ ���ڿ�
			2. string buffer : "hw1.txt" ���Ͽ��� �� �پ� �о�� ���ڿ�
			3. int blanksize : �յڷ� �߰��� ����� ���� �� ����
*/

void Centered_justification() {
	text.open("hw1.txt");       // "hw1.txt" ������ �ҷ���

	while (text.peek() != EOF) { // ������ ���� ������ ����
		string buffer;
		string newbuffer;
		getline(text, buffer);    // ���Ͽ��� 1������ ������ buffer�� ����
		int blanksize = (80 - buffer.length()) / 2;   // �տ� ������ ���� = (��ü ����� ���� ��)/2

		for (int i = 0; i < blanksize-1; i++) {
			newbuffer += ' ';    // ��¹���(newbuffer)�� ���� ��������
		}

		newbuffer += buffer;   // ��¹���(newbuffer)�� ��� ������ ���ڿ� ���� ����
		newbuffer += "\n";     // end-of-line �߰�
		cout << newbuffer;    // ��� ������ ���ڿ� ���
	}
	text.close();      // "hw1.txt" ���� ����.
}


int main() {
	int select;    // ����ڰ� ������ �ɼ� ����
	while (true) {    // select != 4�϶����� ����
		cout << "************************************" << endl;
		cout << "1. Left     Justification" << endl;    //�ɼ� ���
		cout << "2. Right    Justification" << endl;
		cout << "3. Centered Justification" << endl;
		cout << "4. Terminate" << endl << endl;
		cout << "Enter your choice : ";

		cin >> select;    //�ɼ� �Է� ����
		cout << endl;

		if (select == 1) {
			cout << "12345678901234567890123456789012345678901234567890123456789012345678901234567890" << endl;
			Left_justification();  // select == 1�� �� ���������Լ� ȣ��
			cout << endl << endl;
		}

		else if (select == 2) {
			cout << "12345678901234567890123456789012345678901234567890123456789012345678901234567890" << endl;
			Right_justification();   // select == 2�� �� ���������Լ� ȣ��
			cout << endl << endl;
		}

		else if (select == 3) {     // select == 3�� �� ���������Լ� ȣ��
			cout << "12345678901234567890123456789012345678901234567890123456789012345678901234567890" << endl;
			Centered_justification();
			cout << endl << endl;
		}

		else { break; }    // select == 4�� �� ���� ����
	}
}