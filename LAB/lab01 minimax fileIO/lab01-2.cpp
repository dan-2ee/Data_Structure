/*
Name: 이다은
Student ID: 20203112
Program ID: Lab1-2
Description: 각 라인의 단어 개수 출력
*/

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int WordCount(string line) {   //문장 안의 단어 개수 세기
	int WC = 0;
	if (line[0] != ' ') {
		WC++;
	}
	for (int i = 1; i < line.length()-1; i++) {
		if (line[i] != ' ' && line[i - 1] == ' ') {
			WC++;
		}
	}
	return WC;
}

int main() {
	string buffer;
	ifstream text;
	int sum = 0;
	text.open("lab1-2.txt");

	if (text.fail()) { cout << "can't open file" << endl; exit(1); }

	while (text.peek() != EOF) {  //while(!text.eof())
		getline(text, buffer);    //한줄 가져오기
		cout << buffer << endl;   //문장 한 줄씩 출력
		
		int WC = WordCount(buffer);
		cout << "The number of words : " << WC << endl;
		sum += WC;
	}

	cout << "Total Number of Words: " << sum << endl;

	text.close();
}

