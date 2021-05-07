//////////////////////
// Name: 이다은
// Student ID: 20203112
// Program ID: Lab#06
//////////////////////
#include <iostream>
using namespace std;

struct Node {
	int data;
	Node* next;
};

class List {
private:
	Node* head;

public:
	List() { head = 0; }    
	~List() {    
		Node* p;
		while (head != 0) {
			p = head;
			head = head->next;
			delete p;
		}
	}
	void insertNode(int data);  //오름차 순으로 list에 data추가
	void deleteNode(int data); //해당 data값을 찾아서 삭제
	void display();      //리스트의 전체 node 출력
	bool isEmpty();      //리스트가 비어있는지 확인
	void search(int data);   //data의 존재 여부 확인
	void findMax();  //리스트에서 가장 큰 숫자 출력
};

void List::insertNode(int data) {
	Node* temp = new Node;
	temp->data = data;
	temp->next = 0;
	Node* p, * q;

	if (isEmpty()) head = temp;  //리스트가 비어있으면
	else if (temp->data < head->data) {  // temp의data가 head보다 작을 때
		temp->next = head;              // head 앞에 삽입
		head = temp;
	}
	else {
		p = head;
		while ((p != 0) && (p->data < temp->data)) {
			q = p;
			p = p->next;
		}
		if (p != 0) {   //오름차 순으로 알맞은 위치에 temp 삽입
			q->next = temp;
			temp->next = p;
		}
		else q->next = temp;   //맨 뒤에 insert
	}
}

void List::deleteNode(int data) {
	Node* p, * q;
	if (isEmpty()) { cout << "List is Empty" << endl; return; }  //list가 비어있을 때
	else if (head->data == data) {   //data == head->data 일 때, delete head
		p = head;
		head = head->next;
		delete p;
	}
	else {    //delete middle node
		p = head;
		while (p != 0 && p->data != data) {
			q = p;
			p = p->next;
		}
		if (p != 0) {   //p->data == data
			q->next = p->next;
			delete p;
		}
		else { cout << "not found" << endl; }
	}
}

bool List::isEmpty() {
	if (head == 0) return true;
	else return false;
}

void List::display() {
	Node* p;
	if (isEmpty()) { cout << "List is empty" << endl; return; }
	else {
		p = head;
		cout << "---List---" << endl;
		for (int i = 1; p != 0; i++) {
			cout << "   " << i << " : " << p->data << endl;
			p = p->next;
		}
	}
}

void List::search(int data) {
	Node* p;
	if (isEmpty()) { cout << "List is empty" << endl; return; }
	else {
		p = head;
		while (p != 0 && p->data != data) p = p->next;
		if (p != 0) cout << data << " is found" << endl;
		else cout << data << " is not in the list" << endl;
	}
}

void List::findMax() {
	Node* p, *max;
	if(isEmpty()) { cout << "List is empty" << endl; return; }
	else {
		p = head;
		max = head;
		while (p->next != 0) {
			p = p->next;
			if (max->data < p->data) { max = p; }
		}
		cout << "Max number is : " << max->data << endl;
	}
}

int main() {
	List L;
	int select;
	while (true) {
		int n;
		cout << "Command : 1)insert, 2)delete, 3)search, 4)findMax, 5)quit => ";
		cin >> select;
		switch (select) {
		case 1: {     //insert
			cout << "Input a number => ";
			cin >> n;
			L.insertNode(n); 
			L.display();  break;
		}
		case 2: {   //delete
			cout << "Input a number => ";
			cin >> n;
			L.deleteNode(n);
			L.display();  break;
		}
		case 3: {   //search
			cout << "Enter a number => ";
			cin >> n;
			L.search(n);
			L.display();  break;
		}
		case 4: {   //findMax
			L.findMax(); 
			L.display();  break;
		}
		case 5: {   //quit
			L.~List();
			return 0;
		}
		}
	}
}