/*
Name : �̴���
Student ID : 20203112
Program ID : Quiz#01
Description : (1) Linked Stack �� Linked Queue�� �����͵��� Merge �Ͽ�,
                  Linked List �� ����� ����Ѵ�.
              (2) ������ ������ �а�, �� ���κ��� ���ڿ��� palindrome ���� �Ǵ��Ѵ�.
Algorithm :
1. �������� ����Ͽ� ����ڿ��� �����ش�.
2. ȣ���� �Լ��� ����ڿ��� �Է¹޾Ƽ� choice�� �����Ѵ�.
3. choice�� 1�̸� push �Լ��� ȣ���Ͽ� �Է¹��� ���� linkedStack�� insert�Ѵ�.
4. choice�� 2�̸� enqueue �Լ��� ȣ���Ͽ� �Է¹��� ���� linkedQueue�� insert�Ѵ�.
6. choice�� 3�̸� merge �Լ��� ȣ���Ͽ� linkedStack�� linkedQueue�� �����͵��� ��ģ �� �����Ѵ�.
7. choice�� 4�̸� invert �Լ��� ȣ���Ͽ� ����Ʈ�� �������� ��ȯ�Ѵ�.
8. choice�� 5�̸� FindMax �Լ��� ȣ���Ͽ� Max���� delete�Ѵ�.
9. choice�� 6�̸� while���� �������ͼ� ������ �����Ѵ�.
10. while���� ����Ǹ� ������ ���Ͽ��� �� ���ξ� �о�� �� �о�� ������ palindrome���� �Ǵ��Ͽ� ����� ����Ѵ�.
Variables :
1. void push(int num): stack�� top�� num�� �����Ѵ�.
2. int pop(): stack�� top ���Ҹ� �����ؼ� ��ȯ�Ѵ�.
3. int isEmpty(): stack, queue, list�� ����ִ��� Ȯ���Ѵ�.
4. void displayStack(): stack�� ������ �����ش�.
5. void enqueue(int num): queue�� rear�� num�� �����Ѵ�.
6. int dequeue(): queue�� front�� �ִ� ���Ҹ� �����ؼ� ��ȯ�Ѵ�.
7. void displayQueue(): queue�� ������ �����ش�.
8. void insert(int c): �Է¹��� ���� ����Ʈ�� ������������ �����Ѵ�.
9. void merge(linkedStack& s, linkedQueue& q): stack�� �����Ϳ� queue�� �����͸� ��ģ��.
10. void displayList(): list�� ������ �����ش�.
11. void invert(): ����Ʈ�� �������� ��ȯ�Ѵ�.
12. int FindMax(): ����Ʈ���� ���� ū �����͸� ã�´�.
13. void deleteNode(int data): �Է¹��� ���� ����Ʈ���� �����Ѵ�.
14. temp: ����ڿ��� �Է¹��� ���� �����Ͱ����� ���� ���ο� ���
15. char buffer[80]: ���������Ͽ��� �о�� ���ڿ��� ������ �ִ�.

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
description : ������ ����ִ��� Ȯ���Ѵ�.
*/
int linkedStack::isEmpty() {
	if (top == 0) return 1;
	else return 0;
}

/*
function : push
description : linkedStack�� top�� �Է¹��� ���� �����Ѵ�.
variables :
			1. temp: ����ڿ��� �Է¹��� ���� �����Ͱ����� ���� ���ο� ���
			2. int num: insert�� ��
*/
void linkedStack::push(int num) {
	Node* temp = new Node(num);

	if (isEmpty()) top = temp;  //������ ��������� temp�� top�� �ȴ�.
	else {
		temp->next = top;  //������ ������������� temp�� �����ϰ�, temp�� top�� �����Ѵ�.
		top = temp;   
	}
}

/*
function : pop
description : linkedStack�� top�� ���Ҹ� �����ϰ� ��ȯ�Ѵ�.
variables :
			1. Node *p: top�� ��ġ�� ����Ų��. 
			2. int num: ��ȯ�� top�� data�� �����Ѵ�.
*/
int linkedStack::pop() {
	Node* p;
	int num;

	num = top->data;   //��ȯ�� top�� �� ����
	p = top;           //top�� �����ϱ� ���� ��ġ ����
	top = top->next;   //top�� ������ġ�� �̵� 
	delete p;   
	return num;   //top�� �� ��ȯ
}

/*
function : displayStack
description : linkedStack ��ü�� ����Ѵ�.
variables :
			1. p: top���� �̵��ϱ� �����Ͽ� ������ ������ �̵��Ѵ�.
			2. int cnt: stack�� data���� ��ȣ�� ǥ���Ѵ�.
*/
void linkedStack::displayStack() {
	Node* p;
	if (isEmpty()) { cout << "stack is empty\n"; return; }  //stack�� empty�� ���
	else {
		p = top;
		int cnt = 0;
		cout << "Stack:\n";
		while (p != 0) {  //������ ������ ��忡 ������ ������ �̵�
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
description : linkedQueue�� �Է¹��� ���� �����Ѵ�.
variables :
			1. temp: ����ڿ��� �Է¹��� ���� �����Ͱ����� ���� ���ο� ���
			2. int num: insert�� ��
*/
void linkedQueue::enqueue(int num) {
	Node* temp = new Node(num);

	if (isEmpty()) { front = temp; rear = temp; }  //Queue�� empty�� ���, temp�� front�� rear�� �ȴ�.
	else {
		rear->next = temp;   
		rear = temp;
	}
}

/*
function : dequeue
description : linkedQueue�� front�� �ִ� ���Ҹ� �����ؼ� ��ȯ�Ѵ�.
variables :
			1. Node* p: front�� ��ġ ����
			2. int num: ��ȯ�� front�� ��
*/
int linkedQueue::dequeue() {
	Node* p;
	int num;

	p = front;
	num = front->data;
	if (front == rear) { front = 0; rear = 0; } //node�� �ϳ��� ���
	else front = front->next;   //node�� �ΰ� �̻��� ���, front�� ��ġ�� next�� �ű�
	delete p;
	return num;  //front�� �� ��ȯ
}

/*
function : isEmpty
description : linkedQueue�� ����ִ��� Ȯ���Ѵ�.
*/
int linkedQueue::isEmpty() {
	if (front == 0) return 1;
	else return 0;
}

/*
function : displayQueue
description : linkedQueue ��ü�� ����Ѵ�.
variables :
			1. p: front���� �̵��ϱ� �����Ͽ� ������ ������ �̵��Ѵ�.
*/
void linkedQueue::displayQueue() {
	Node* p;
	if (isEmpty()) { cout << "Queue is empty\n"; return; }  //queue�� empty�� ���
	else {    
		p = front;
		cout << "Queue:";
		while (p != 0) {   //queue�� ������ ��忡 ������ ������ �̵�
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
description : �Է¹��� ���� ����Ʈ���� �����Ѵ�.
variables :
			1. Node* p: ������ ���
			2. int data: ������ ��
*/
void linkedList::deleteNode(int data) {
	Node* p, * q;
	if (isEmpty()) { cout << "List is Empty" << endl; return; }  //list�� ������� ��
	else if (head->data == data) {   //data == head->data �� ��, delete head
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
		if (p != 0) {   //p->data == data�� �� 
			q->next = p->next;
			delete p;
		}
		else { cout << "not found" << endl; }  //p==0�� ������ data�� ã�� ���� ���(=data�� ����Ʈ�� ���� ���)
	}
}

/*
function : FindMax
description : linkedList���� ���� ū ���Ҹ� ã�Ƽ� ��ȯ�Ѵ�.
variables :
			1. Node *max: ���� ū �����͸� ������ ���
*/
int linkedList::FindMax() {
	Node* p, * max;
	if (isEmpty()) { cout << "List is empty" << endl; return 0; }  //list�� empty�� ���
	else {
		p = head;
		max = head;
		while (p->next != 0) {  //p�� ������ ����� ������
			p = p->next;
			if (max->data < p->data) { max = p; }  //p�� data�� �� ũ�� max = p
		}
		return max->data;  //���� ū ���Ҹ� ��ȯ�Ѵ�.
	}
}

/*
function : isEmpty
description : linkedList�� ����ִ��� Ȯ���Ѵ�.
*/
int linkedList::isEmpty() {
	if (head == 0) return 1;
	else return 0;
}

/*
function : insert
description : �Է¹��� ���� ����Ʈ�� ������������ �����Ѵ�. 
variables :
			1. temp: ����ڿ��� �Է¹��� ���� �����Ͱ����� ���� ���ο� ���
*/
void linkedList::insert(int c) {
	Node* temp = new Node(c);

	if (isEmpty()) { head = temp; }  //list�� empty�� ���
	else if (temp->data < head->data) {   //temp�� �����Ͱ� head�� �����ͺ��� ���� ���
		temp->next = head;              //head�տ� temp����
		head = temp;
	}
	else {    //temp�� �����Ͱ� head�� �����ͺ��� ū ���
		Node* p, * q;
		p = head;
		q = head;
		while (p != 0 && temp->data > p->data) {
			q = p;
			p = p->next;
		}
		if (p != 0) { q->next = temp; temp->next = p; }  //temp�� �����Ͱ� p�� �����ͺ��� ���� ���, p�տ� ����
		else {
			q->next = temp;  //������ ��� ������ temp ����
		}
	}
}

/*
function : merge
description : linkedStack�� linkedQueue�� �����͸� ��ģ��.
*/
void linkedList::merge(linkedStack& s, linkedQueue& q) {    //s�� q ��ħ
	while (!s.isEmpty()) insert(s.pop());  //������ ������������� �����͸� ������ ����Ʈ�� �ִ´�.
	while (!q.isEmpty()) insert(q.dequeue());  //ť�� ������������� �����͸� ������ ����Ʈ�� �ִ´�.
}

/*
function : displayList
description : linkedList ��ü�� ����Ѵ�.
variables :
			1. p: head���� �̵��ϱ� �����Ͽ� ������ ������ �̵��Ѵ�.
*/
void linkedList::displayList() {
	if (isEmpty()) { cout << "List is empty\n"; return; }  //list�� empty�� ���
	else {
		Node* p;
		p = head;
		cout << "List:";
		while (p != 0) {  //����Ʈ�� ������ ��忡 ������ ������ �̵�
			cout << setw(8) << p->data;
			p = p->next;
		}
		cout << endl;
	}
}

/*
function : invert
description : linkedList�� �������� ��ȯ�Ѵ�.
*/
void linkedList::invert() {   
	Node* p, * q, * r;
	p = head;
	q = 0;
	while (p) {
		r = q;  //r�� q�� ���󰣴�
		q = p;  //q�� p�� ���󰣴�
		p = p->next;   //p�� ���� ���� �Ű� ����
		q->next = r;  //q�� ���� ��带 �����Ѵ�
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
	void push(char val) {  //stack�� top�� ������ ����
		if (top == 79) exit(-1);  //stack�� full�� ���
		stack[++top] = val;
	}
	char pop() {   //stack�� top���Ҹ� �����ϰ� ��ȯ
		if (top == -1) exit(-1);  //stack�� empty�� ���
		return stack[top--];
	}
};

int main() {
	linkedStack L1;
	linkedQueue L2;
	linkedList L3;

	int choice = 0;  //choice: ������� ���� ����
	int n;

	cout << "<< quiz1-1: Linked Stack and Queue >>\n\n";

	while (choice!=6) { // choice != 6�϶����� ����
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
			n = L3.FindMax();  //n: max������ 
			L3.deleteNode(n);  //max ������ ����
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
	text.open("quiz1.txt");   //"quiz1.txt" ������ �ҷ���
	if (!text.is_open()) {   
		cout << "error: quiz1.txt can't open." << endl; return -1;
	}

	char buffer[80];  //���Ͽ��� �о�� ������ ������

	while (text.getline(buffer, 80)) {  // ������ ���� ������ ����
		int length = strlen(buffer);  //length: �о�� ������ ����(���ڼ�) ����
		int i = 0;
		int check = 1;  //�� ������ �Ӹ�������� ����
		if (length % 2 == 0) {  //length�� ¦���̸�
			while (i < (length / 2)) {
				s.push(buffer[i]);  ///length�� �ݸ�ŭ PUSH
				i++; 
			}
		}
		else {   //length�� Ȧ���̸�
			while (i < (length / 2)) {
				s.push(buffer[i]); // length�� �ݸ�ŭ PUSH
				i++; 
			}
			i++;  //��� ���� �ǳʶ�
		}

		while (buffer[i] != '\0') {  //stack ���� pop�� �����Ϳ�, buffer(�о�� ��) ��
			if (buffer[i] != s.pop()) {
				check = 0;  //�ٸ��ٸ�, �Ӹ������ �ƴϹǷ� check=0���� �ٲ���
			}
			i++;  //���� ���� ��
		}

		if (check == 1) {  //check�� 1�̶�� palindrome
			cout << "Palindrome\n";
		}  
		else cout << "Not Palindrome\n"; //check�� 0�̶�� not palindrome
	}
}