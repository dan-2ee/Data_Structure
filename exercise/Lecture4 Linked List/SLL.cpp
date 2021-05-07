#include <iostream>
#include <iomanip>
using namespace std;

class Node {
public:
	int data;
	Node* next;
	Node(int val) { data = val; next = 0; }
	friend class List;
};

class List {
private:
	Node* head;

public:
	List() { head = 0;}
	~List() {
		Node* p;
		while (head != 0) {
			p = head;
			head = head->next;
			delete p;
		}
	}
	int isEmpty();
	void displayList();
	void insertNode(int val);
	void deleteNode(int num);
	void searchNode(int num);
	void findMax();
};

int List::isEmpty() {
	if (head == 0) return 1;
	else return 0;
}

void List::displayList() {
	Node* p;
	if (isEmpty()) {cout << "List is empty\n"; return;}
	else {
		p = head;
		cout << "---List---" << endl;
		for (int i = 1; p != 0; i++) {
			cout << "   " << i << " : " << p->data << endl;
			p = p->next;
		}
	}
}

void List::insertNode(int val) {
	Node* temp = new Node(val);
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

void List::deleteNode(int num) {
	Node* p, *q;
	if (isEmpty()) cout << "List is empty\n";
	else if (head->data == num) {
		p = head;
		head = head->next;
		delete p;
	}
	else {
		p = head;
		while ((p->data != num) && p != 0) {
			q = p;
			p = p->next;
		}
		if (p != 0) { q->next = p->next; delete p; }
		else { cout << num << " is not in the list\n"; }
	}
}

void List::searchNode(int num) {
	Node* p;
	if (isEmpty()) cout << "List is empty\n";
	else {
		p = head;
		while (p!= 0 && p->data != num) {
			p = p->next;
		}
		if (p != 0) cout << num << " is found\n";
		else cout << num << " is not found\n";
	}
}

void List::findMax() {
	Node* p, *max;
	if (isEmpty()) cout << "List is empty\n";
	else {
		p = head; max = head;
		while (p->next != 0) {
			p = p->next;
			if (p->data > max->data) max = p;
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
			L.displayList();  break;
		}
		case 2: {   //delete
			cout << "Input a number => ";
			cin >> n;
			L.deleteNode(n);
			L.displayList();  break;
		}
		case 3: {   //search
			cout << "Enter a number => ";
			cin >> n;
			L.searchNode(n);
			L.displayList();  break;
		}
		case 4: {   //findMax
			L.findMax();
			L.displayList();  break;
		}
		case 5: {   //quit
			L.~List();
			return 0;
		}
		}
	}
}







