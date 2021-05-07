/*
Name : �̴���
Student ID : 20203112
Program ID : HW#3
Description : Doubly Linked List�� ���� �Լ����� �׽�Ʈ�Ѵ�.
Algorithm :
1. �������� ����Ͽ� ����ڿ��� �����ش�.
2. ȣ���� �Լ��� ����ڿ��� �Է¹޾Ƽ� choice�� �����Ѵ�.
3. choice�� 1�̸� insertAfter �Լ��� ȣ���Ͽ� �Է¹��� ���� current node �ڿ� insert�Ѵ�.
4. choice�� 2�̸� insertBefore �Լ��� ȣ���Ͽ� �Է¹��� ���� current node �տ� insert�Ѵ�.
5. choice�� 3�̸� insertFirst �Լ��� ȣ���Ͽ� �Է¹��� ���� ����Ʈ�� �� �տ� ��ġ��Ų��.
6. choice�� 4�̸� insertLast �Լ��� ȣ���Ͽ� �Է¹��� ���� ����Ʈ�� �� �ڿ� ��ġ��Ų��.
7. choice�� 5�̸� deleteCurrent �Լ��� ȣ���Ͽ� current node�� �����Ѵ�.
8. choice�� 6�̸� locateCurrent �Լ��� ȣ���Ͽ� current�� �Է¹��� ��ġ�� �ű� ��, current data�� ����Ѵ�.
9. choice�� 7�̸� updateCurrent �Լ��� ȣ���Ͽ� ���� current�� data ���� �Է¹��� ���� ��ü�Ѵ�.
10. choice�� 8�̸� displayList �Լ��� ȣ���Ͽ� ��ü ����Ʈ�� ����Ѵ�.
11. choice�� 9�̸� while���� �������ͼ� ������ �����Ѵ�.
Variables :
1. void insertAfter(int num): current node �ڿ� insert
2. void insertBefore(int num): current node �տ� insert
3. void insertFirst(int num): ����Ʈ�� �� �տ� insert
4. void insertLast(int num): ����Ʈ�� �� �ڿ� insert
5. void deleteCurrent(): current node ����
6. void LocateCurrent(int n): current�� �Է¹��� ��ġ�� �ű�, �ش� ������ ���
7. void updateCurrent(int newdata): ���� current�� ������ ���� newdata�� ��ü
8. void displayList(): ��ü ����Ʈ ���
9. int isEmpty(): ����Ʈ�� ����ִ��� Ȯ��
10. int Listlength(): ����Ʈ�� ���� ��ȯ
11. temp: ����ڿ��� �Է¹��� ���� �����Ͱ����� ���� ���ο� ���
12. int len: ����Ʈ�� ���� ����
13. class Node: ������ �ʵ�(data, next, prev)�� ������. 
14. class List: ���� ���� �Լ��� �ΰ��� �ʵ�(head, current)�� ������.
                head�� ���� ���� ��带, current�� ���� ��ġ�ϰ� �ִ� ��带 ��Ÿ����.
*/

#include <iostream>
#include <iomanip>
using namespace std;

class Node {
private:
	int data;  
	Node* next;
	Node* prev;
	Node(int num) { data = num; prev = 0; next = 0; }
	friend class List;
};

class List {
private:
	Node* head;   //���� ���� node
	Node* current;   //���� ��ġ node
public:
	List() { head = 0; current = 0; }   
	~List() {
		Node* p;
		while (head != 0) {
			p = head;
			head = head->next;
			delete p;
		}
	}
	void insertAfter(int num);   //current node �ڿ� insert
	void insertBefore(int num);  //current node �տ� insert
	void insertFirst(int num);    //����Ʈ�� �� �տ� insert
	void insertLast(int num);     //����Ʈ�� �� �ڿ� insert
	void deleteCurrent();   //current node ����
	void LocateCurrent(int n);  //current�� �Է¹��� ��ġ�� �ű�, �ش� ������ ���
	void updateCurrent(int newdata);  //���� current�� ������ �� ��ü
	void displayList();    //��ü ����Ʈ ���
	int isEmpty();    //����Ʈ�� ����ִ��� Ȯ��
	int Listlength();   //����Ʈ�� ���� ��ȯ
};

int len = 0;
/*
function : Listlength
description : ����Ʈ�� ���̸� ��ȯ�Ѵ�.
variables :
			1. int len : ����Ʈ�� ���� ����
*/
int List::Listlength() { return len; }

/*
function : isEmpty
description : ����Ʈ�� ����ִ��� Ȯ���Ѵ�.
*/
int List::isEmpty() {
	if (head == 0) return 1;
	else return 0;
}
//��� actrion ���Ŀ� �ش� ��尡 current position�� ��

/*
function : insertAfter
description : current��� �ڿ� �Է¹��� ��(num)�� insert�Ѵ�.
variables :
			1. temp: ����ڿ��� �Է¹��� ���� �����Ͱ����� ���� ���ο� ���
			2. int num: insert�� ��
*/
void List::insertAfter(int num) {
	Node* temp = new Node(num);  //���ο� ��� ����

	if (isEmpty()) head = temp;   //empty list�� ���
	else if (current->next != 0) {   //current�� ������ node�� �ƴϸ�
		temp->prev = current;
		temp->next = current->next;
		current->next->prev = temp;
		current->next = temp;
	}
	else {   //current�� ������ ����� ��, current�ڿ� (������ ��� �ڿ�) insert
		current->next = temp;
		temp->prev = current;
	}
	current = temp;   //insert�� ��尡 current node
	len += 1;   //����Ʈ ���� +=1
}

/*
function : insertBefore
description : current��� �տ� �Է¹��� ��(num)�� insert�Ѵ�.
variables :
			1. temp: ����ڿ��� �Է¹��� ���� �����Ͱ����� ���� ���ο� ���
			2. int num: insert�� ��
*/
void List::insertBefore(int num) {
	Node* temp = new Node(num);   //���ο� ��� ����

	if (isEmpty()) head = temp;  //empty list�� ���
	else if (current == head) {  //current�� head�� ��, head node �տ� insert
		head->prev = temp;
		temp->next = head;
		head = temp;
	}
	else {    //current�� head�� �ƴ� ��, insert middle
		temp->next = current;
		temp->prev = current->prev;
		current->prev->next = temp;
		current->prev = temp;
	}
	current = temp;  //insert�� ��尡 current node
	len += 1;    //����Ʈ ���� +=1
}

/*
function : insertFirst
description : ����Ʈ�� �� �տ� �Է¹��� ��(num)�� insert�Ѵ�.
variables :
			1. temp: ����ڿ��� �Է¹��� ���� �����Ͱ����� ���� ���ο� ���
			2. int num: insert�� ��
*/
void List::insertFirst(int num) {
	Node* temp = new Node(num);   //���ο� ��� ����

	if (isEmpty()) head = temp;   //empty list�� ���
	else {     //head node �տ� temp insert
		temp->next = head;
		head->prev = temp;
		head = temp;
	}
	current = temp;    //insert�� ��尡 current node
	len += 1;   //����Ʈ�� ���� +=1
}

/*
function : insertLast
description : ����Ʈ�� �� �ڿ� �Է¹��� ���� insert�Ѵ�.
variables :
			1. temp: ����ڿ��� �Է¹��� ���� �����Ͱ����� ���� ���ο� ���
			2. p: head�� ��ġ���� �̵��ϱ� �����Ͽ�, ������ ��带 ã�Ƴ�
			3. int num: insert�� ��
*/
void List::insertLast(int num) {
	Node* temp = new Node(num);   //��� ����
	Node* p;
	if (isEmpty()) head = temp;   //empty list�� ���
	else {
		p = head;   //p�� head�� ��ġ���� ����
		while (p->next != 0) {   //p�� ������ ��尡 �ƴϸ� 
			p = p->next;    //p �̵�
		}
		p->next = temp;   //�� �ڿ� temp insert
		temp->prev = p;
	}
	current = temp;  //insert�� ��尡 current node
	len += 1;     //����Ʈ�� ���� +=1
}

/*
function : deleteCurrent
description : current node�� �����Ѵ�.
variables :
			1. p: ������ ���
*/
void List::deleteCurrent() {
	Node* p;
	if (isEmpty()) {cout << "List is empty\n"; return;}  //empty list�� ���
	else if (head == current) {   //current�� head�� ��
		head = head->next;
		current = current->next;
		current->prev = 0;
		delete current;
	}
	else if (current->next == 0) {  //current�� ������ ����� ��, ������ ���(current node) ����
		p = current;
		current->prev->next = 0;
		current = head;
		delete p;
	}
	else {   //current�� �߰��� ��ġ�� ��, middle ���(current node) ����
		p = current;
		current->prev->next = current->next;
		current->next->prev = current->prev;
		current = current->next;
		delete p;
	}
	len -= 1;   //current node�� �����Ǿ����Ƿ�, ����Ʈ�� ���� -=1
}

/*
function : LocateCurrent
description : �Է¹��� ��ġ(n)�� current�� �̵���Ű��, �ش� �����͸� ����Ѵ�.
variables :
			1. p: n��°�� current�� ��ġ��Ű�� ���� �̵��� ���
			2. int n: current�� �̵��� ��ġ
*/
void List::LocateCurrent(int n) {
	Node* p;
	if (isEmpty()) { cout << "List is empty\n"; return; }   //empty list�� ���
	else if (Listlength() >= n) {  //��ü ����Ʈ�� ���� >= ���ϴ� ��ġ
		p = head;   //p�� head�� ��ġ���� �̵��ϱ� ������
		for (int i = 1; i < n; i++) p = p->next;   //p�� n��° ��ġ�� �̵���Ŵ
		current = p;      //current�� ���ο� ��ġ(n)�� �̵���Ŵ
		cout << n << "*" << setw(8) << current->data << endl;   //�ش� ��� ������ ���
	}
	else {
		cout << "No such a line\n";  //��ü ����Ʈ�� ���� < ���ϴ� ��ġ
	}
}

/*
function : updateCurrent
description : �Է¹��� ��(newdata)���� ���� current�� ������ ���� ��ü�Ѵ�.
variables :
			1. int newdata: �Է¹��� ��
*/
void List::updateCurrent(int newdata) {
	if (isEmpty()) { cout << "List is empty\n"; return; }  //empty list�� ���
	else {
		current->data = newdata;   //current ������ �� ��ü
	}
}

/*
function : displayList
description : ��ü ����Ʈ�� ����Ѵ�.
variables :
			1. p: head���� �̵��ϱ� �����Ͽ� ������ ������ �̵��Ѵ�.
*/
void List::displayList() {
	Node* p;
	if (isEmpty()) { cout << "List is empty\n"; return; }   //empty list�� ���
	else {
		p = head;
		cout << "--- List ---\n";
		for (int i = 1; i <= Listlength(); i++) {  //list�� ������ ��忡 ������ ������ �̵�
			if (p == current) cout << "    " << i << "  *  " << current->data << endl;
			else cout << "    " << i << "  :  " << p->data << endl;
			p = p->next;
		}
	}
}

int main() {
	List L;
	int choice, num;   //choice: ������� ���� ����
	while (true) {
		cout << "Command: (1)insertAfter   (2)insertBefore   (3)insertFirst   (4)insertLast   (5)deleteCurrent" << endl;
		cout << "         (6)locateCurrent (7)updateCurrent  (8)displayList   (9)quit\n";
		cout << " ==> ";
		cin >> choice;
		switch (choice) {
		case 1: {   
			cout << "Enter a data to insert => ";
			cin >> num;   //num: insert�� ��
			L.insertAfter(num);
			L.displayList();
			break;
		}
		case 2: {
			cout << "Enter a data to insert => ";
			cin >> num;  //num: insert�� ��
			L.insertBefore(num);
			L.displayList();
			break;
		}
		case 3: {
			cout << "Enter a data to insert => ";
			cin >> num;  //num: insert�� ��
			L.insertFirst(num);
			L.displayList();
			break;
		}
		case 4: {
			cout << "Enter a data to insert => ";
			cin >> num;   //num: insert�� ��
			L.insertLast(num);
			L.displayList();
			break;
		}
		case 5: {
			L.deleteCurrent();
			L.displayList();
			break;
		}
		case 6: {
			cout << "Enter a position to locate => ";
			cin >> num;  //num: current�� ���ο� ��ġ
			L.LocateCurrent(num);
			break;
		}
		case 7: {
			cout << "Enter a data to update => ";
			cin >> num;   //num: current�� ���ο� ������ ��
			L.updateCurrent(num);
			L.displayList();
			break;
		}
		case 8: {
			L.displayList();
			break;
		}
		case 9: {
			L.~List();
			return 0;
		}
		}
	}
}