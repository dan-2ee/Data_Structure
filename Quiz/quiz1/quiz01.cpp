/*
Name : 이다은
Student ID : 20203112
Program ID : Quiz#01
Description : (1) Linked Stack 과 Linked Queue의 데이터들을 Merge 하여,
                  Linked List 로 만들어 출력한다.
              (2) 데이터 파일을 읽고, 각 라인별로 문자열이 palindrome 인지 판단한다.
Algorithm :
1. 선택지를 출력하여 사용자에게 보여준다.
2. 호출할 함수를 사용자에게 입력받아서 choice에 저장한다.
3. choice가 1이면 push 함수를 호출하여 입력받은 수를 linkedStack에 insert한다.
4. choice가 2이면 enqueue 함수를 호출하여 입력받은 수를 linkedQueue에 insert한다.
6. choice가 3이면 merge 함수를 호출하여 linkedStack과 linkedQueue의 데이터들을 합친 뒤 저장한다.
7. choice가 4이면 invert 함수를 호출하여 리스트를 역순으로 변환한다.
8. choice가 5이면 FindMax 함수를 호출하여 Max값을 delete한다.
9. choice가 6이면 while문을 빠져나와서 실행을 종료한다.
10. while문이 종료되면 데이터 파일에서 한 라인씩 읽어온 뒤 읽어온 라인이 palindrome인지 판단하여 결과를 출력한다.
Variables :
1. void push(int num): stack의 top에 num을 삽입한다.
2. int pop(): stack의 top 원소를 제거해서 반환한다.
3. int isEmpty(): stack, queue, list가 비어있는지 확인한다.
4. void displayStack(): stack의 내용을 보여준다.
5. void enqueue(int num): queue의 rear에 num을 삽입한다.
6. int dequeue(): queue의 front에 있는 원소를 제거해서 반환한다.
7. void displayQueue(): queue의 내용을 보여준다.
8. void insert(int c): 입력받은 값을 리스트에 오름차순으로 삽입한다.
9. void merge(linkedStack& s, linkedQueue& q): stack의 데이터와 queue의 데이터를 합친다.
10. void displayList(): list의 내용을 보여준다.
11. void invert(): 리스트를 역순으로 변환한다.
12. int FindMax(): 리스트에서 가장 큰 데이터를 찾는다.
13. void deleteNode(int data): 입력받은 값을 리스트에서 제거한다.
14. temp: 사용자에게 입력받은 값을 데이터값으로 갖는 새로운 노드
15. char buffer[80]: 데이터파일에서 읽어온 문자열을 가지고 있다.

*/
#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;

class Node {
private:
	int data;
	Node* next;
	Node(int num) { data = num; next = 0; }
	friend class linkedStack;
	friend class linkedQueue;
	friend class linkedList;
};

class linkedStack {
private:
	Node* top;

public:
	linkedStack() { top = 0; }
	~linkedStack() {
		Node* p;
		while (top != 0) {
			p = top;
			top = top->next;
			delete p;
		}
	}
	void push(int num);
	int pop();
	int isEmpty();
	void displayStack();
};

/*
function : isEmpty
description : 스택이 비어있는지 확인한다.
*/
int linkedStack::isEmpty() {
	if (top == 0) return 1;
	else return 0;
}

/*
function : push
description : linkedStack의 top에 입력받은 값을 삽입한다.
variables :
			1. temp: 사용자에게 입력받은 값을 데이터값으로 갖는 새로운 노드
			2. int num: insert할 값
*/
void linkedStack::push(int num) {
	Node* temp = new Node(num);

	if (isEmpty()) top = temp;  //스택이 비어있으면 temp가 top이 된다.
	else {
		temp->next = top;  //스택이 비어있지않으면 temp를 삽입하고, temp와 top을 연결한다.
		top = temp;   
	}
}

/*
function : pop
description : linkedStack의 top의 원소를 제거하고 반환한다.
variables :
			1. Node *p: top의 위치를 가리킨다. 
			2. int num: 반환할 top의 data를 저장한다.
*/
int linkedStack::pop() {
	Node* p;
	int num;

	num = top->data;   //반환할 top의 값 저장
	p = top;           //top을 제거하기 위해 위치 저장
	top = top->next;   //top은 다음위치로 이동 
	delete p;   
	return num;   //top의 값 반환
}

/*
function : displayStack
description : linkedStack 전체를 출력한다.
variables :
			1. p: top부터 이동하기 시작하여 마지막 노드까지 이동한다.
			2. int cnt: stack의 data들의 번호를 표시한다.
*/
void linkedStack::displayStack() {
	Node* p;
	if (isEmpty()) { cout << "stack is empty\n"; return; }  //stack이 empty인 경우
	else {
		p = top;
		int cnt = 0;
		cout << "Stack:\n";
		while (p != 0) {  //스택의 마지막 노드에 도달할 때까지 이동
			cout << "   " << ++cnt << "  :  " << p->data << endl;
			p = p->next;
		}
	}
}

class linkedQueue {
private:
	Node* front;
	Node* rear;
public:
	linkedQueue() { front = 0; rear = 0; }
	~linkedQueue() {
		Node* p;
		while (front != 0) {
			p = front;
			front = front->next;
			delete p;
		}
	}
	void enqueue(int num);
	int dequeue();
	int isEmpty();
	void displayQueue();
};

/*
function : enqueue
description : linkedQueue에 입력받은 값을 삽입한다.
variables :
			1. temp: 사용자에게 입력받은 값을 데이터값으로 갖는 새로운 노드
			2. int num: insert할 값
*/
void linkedQueue::enqueue(int num) {
	Node* temp = new Node(num);

	if (isEmpty()) { front = temp; rear = temp; }  //Queue가 empty인 경우, temp가 front와 rear이 된다.
	else {
		rear->next = temp;   
		rear = temp;
	}
}

/*
function : dequeue
description : linkedQueue의 front에 있는 원소를 제거해서 반환한다.
variables :
			1. Node* p: front의 위치 저장
			2. int num: 반환할 front의 값
*/
int linkedQueue::dequeue() {
	Node* p;
	int num;

	p = front;
	num = front->data;
	if (front == rear) { front = 0; rear = 0; } //node가 하나인 경우
	else front = front->next;   //node가 두개 이상인 경우, front의 위치를 next로 옮김
	delete p;
	return num;  //front의 값 반환
}

/*
function : isEmpty
description : linkedQueue가 비어있는지 확인한다.
*/
int linkedQueue::isEmpty() {
	if (front == 0) return 1;
	else return 0;
}

/*
function : displayQueue
description : linkedQueue 전체를 출력한다.
variables :
			1. p: front부터 이동하기 시작하여 마지막 노드까지 이동한다.
*/
void linkedQueue::displayQueue() {
	Node* p;
	if (isEmpty()) { cout << "Queue is empty\n"; return; }  //queue가 empty인 경우
	else {    
		p = front;
		cout << "Queue:";
		while (p != 0) {   //queue의 마지막 노드에 도달할 때까지 이동
			cout << setw(8) << p->data;
			p = p->next;
		}
		cout << endl;
	}
}


class linkedList {
private:
	Node* head;
public:
	linkedList() { head = 0; }
	~linkedList() {
		Node* p;
		while (head != 0) {
			p = head;
			head = head->next;
			delete p;
		}
	}
	int isEmpty();
	void insert(int c);
	void merge(linkedStack& s, linkedQueue& q);
	void displayList();
	void invert();
	int FindMax();
	void deleteNode(int data);
};

/*
function : deleteNode
description : 입력받은 값을 리스트에서 제거한다.
variables :
			1. Node* p: 삭제할 노드
			2. int data: 제거할 값
*/
void linkedList::deleteNode(int data) {
	Node* p, * q;
	if (isEmpty()) { cout << "List is Empty" << endl; return; }  //list가 비어있을 때
	else if (head->data == data) {   //data == head->data 일 때, delete head
		p = head;
		head = head->next;
		delete p;
	}
	else {    //delete middle node
		p = head; q = head;
		while (p != 0 && p->data != data) {
			q = p;
			p = p->next;
		}
		if (p != 0) {   //p->data == data일 때 
			q->next = p->next;
			delete p;
		}
		else { cout << "not found" << endl; }  //p==0일 때까지 data를 찾지 못한 경우(=data가 리스트에 없을 경우)
	}
}

/*
function : FindMax
description : linkedList에서 가장 큰 원소를 찾아서 반환한다.
variables :
			1. Node *max: 가장 큰 데이터를 가지는 노드
*/
int linkedList::FindMax() {
	Node* p, * max;
	if (isEmpty()) { cout << "List is empty" << endl; return 0; }  //list가 empty인 경우
	else {
		p = head;
		max = head;
		while (p->next != 0) {  //p가 마지막 노드일 때까지
			p = p->next;
			if (max->data < p->data) { max = p; }  //p의 data가 더 크면 max = p
		}
		return max->data;  //가장 큰 원소를 반환한다.
	}
}

/*
function : isEmpty
description : linkedList가 비어있는지 확인한다.
*/
int linkedList::isEmpty() {
	if (head == 0) return 1;
	else return 0;
}

/*
function : insert
description : 입력받은 값을 리스트에 오름차순으로 삽입한다. 
variables :
			1. temp: 사용자에게 입력받은 값을 데이터값으로 갖는 새로운 노드
*/
void linkedList::insert(int c) {
	Node* temp = new Node(c);

	if (isEmpty()) { head = temp; }  //list가 empty인 경우
	else if (temp->data < head->data) {   //temp의 데이터가 head의 데이터보다 작은 경우
		temp->next = head;              //head앞에 temp삽입
		head = temp;
	}
	else {    //temp의 데이터가 head의 데이터보다 큰 경우
		Node* p, * q;
		p = head;
		q = head;
		while (p != 0 && temp->data > p->data) {
			q = p;
			p = p->next;
		}
		if (p != 0) { q->next = temp; temp->next = p; }  //temp의 데이터가 p의 데이터보다 작은 경우, p앞에 삽입
		else {
			q->next = temp;  //마지막 노드 다음에 temp 삽입
		}
	}
}

/*
function : merge
description : linkedStack과 linkedQueue의 데이터를 합친다.
*/
void linkedList::merge(linkedStack& s, linkedQueue& q) {    //s와 q 합침
	while (!s.isEmpty()) insert(s.pop());  //스택이 비어있을때까지 데이터를 꺼내서 리스트에 넣는다.
	while (!q.isEmpty()) insert(q.dequeue());  //큐가 비어있을때까지 데이터를 꺼내서 리스트에 넣는다.
}

/*
function : displayList
description : linkedList 전체를 출력한다.
variables :
			1. p: head부터 이동하기 시작하여 마지막 노드까지 이동한다.
*/
void linkedList::displayList() {
	if (isEmpty()) { cout << "List is empty\n"; return; }  //list가 empty인 경우
	else {
		Node* p;
		p = head;
		cout << "List:";
		while (p != 0) {  //리스트의 마지막 노드에 도달할 때까지 이동
			cout << setw(8) << p->data;
			p = p->next;
		}
		cout << endl;
	}
}

/*
function : invert
description : linkedList를 역순으로 변환한다.
*/
void linkedList::invert() {   
	Node* p, * q, * r;
	p = head;
	q = 0;
	while (p) {
		r = q;  //r은 q를 따라간다
		q = p;  //q는 p를 따라간다
		p = p->next;   //p가 다음 노드로 옮겨 간다
		q->next = r;  //q에 이전 노드를 연결한다
	}
	head = q;
}

class Stack {
private:
	char stack[80];
public:
	int top;
	void createStack() {   //stack create
		top = -1;
	}
	void push(char val) {  //stack의 top에 아이템 삽입
		if (top == 79) exit(-1);  //stack이 full인 경우
		stack[++top] = val;
	}
	char pop() {   //stack의 top원소를 제거하고 반환
		if (top == -1) exit(-1);  //stack이 empty인 경우
		return stack[top--];
	}
};

int main() {
	linkedStack L1;
	linkedQueue L2;
	linkedList L3;

	int choice = 0;  //choice: 사용자의 선택 저장
	int n;

	cout << "<< quiz1-1: Linked Stack and Queue >>\n\n";

	while (choice!=6) { // choice != 6일때까지 실행
		cout << "MENU: (1.Push, 2.Enqueue, 3.Merge, 4.Invert, 5.RemoveMax, 6.Quit) : ";
		cin >> choice;
		switch (choice) {
		case 1: {
			cout << "Enter an integer to push => ";
			cin >> n;
			L1.push(n);
			L1.displayStack(); break;
		}
		case 2: {
			cout << "Enter an integer to enqueue => ";
			cin >> n;
			L2.enqueue(n);
			L2.displayQueue(); break;
		}
		case 3: {
			L3.merge(L1, L2);
			L3.displayList(); break;
		}
		case 4: {
			L3.invert();
			L3.displayList(); break;
		}
		case 5: {
			n = L3.FindMax();  //n: max데이터 
			L3.deleteNode(n);  //max 데이터 삭제
			L3.displayList(); break;
		}
		case 6: {
			L1.~linkedStack();
			L2.~linkedQueue();
			L3.~linkedList(); break;
		}
		}
	}

	cout << endl << endl;

	Stack s;
	s.createStack();
	cout << "<< quiz1-2: Palindrome using Stack >>\n\n";

	ifstream text;
	text.open("quiz1.txt");   //"quiz1.txt" 파일을 불러옴
	if (!text.is_open()) {   
		cout << "error: quiz1.txt can't open." << endl; return -1;
	}

	char buffer[80];  //파일에서 읽어온 라인을 저장함

	while (text.getline(buffer, 80)) {  // 파일이 끝날 때까지 실행
		int length = strlen(buffer);  //length: 읽어온 라인의 길이(글자수) 저장
		int i = 0;
		int check = 1;  //각 라인이 팰린드롬인지 저장
		if (length % 2 == 0) {  //length가 짝수이면
			while (i < (length / 2)) {
				s.push(buffer[i]);  ///length의 반만큼 PUSH
				i++; 
			}
		}
		else {   //length가 홀수이면
			while (i < (length / 2)) {
				s.push(buffer[i]); // length의 반만큼 PUSH
				i++; 
			}
			i++;  //가운데 원소 건너뜀
		}

		while (buffer[i] != '\0') {  //stack 에서 pop한 데이터와, buffer(읽어온 줄) 비교
			if (buffer[i] != s.pop()) {
				check = 0;  //다르다면, 팰린드롬이 아니므로 check=0으로 바꿔줌
			}
			i++;  //다음 글자 비교
		}

		if (check == 1) {  //check가 1이라면 palindrome
			cout << "Palindrome\n";
		}  
		else cout << "Not Palindrome\n"; //check가 0이라면 not palindrome
	}
}