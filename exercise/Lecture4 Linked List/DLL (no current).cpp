#include <iostream>
#include <iomanip>
using namespace std;

struct Node {
	int data;
	Node* next;
	Node* prev;
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
	void insertList(int num);
	void deleteList(int num);
	void forwardList();
	void backwardList();
	void searchList(int num);
	int isEmpty();
};

int List::isEmpty() {
	if (head == 0) return 1;
	else return 0;
}

void List::insertList(int num) {  //오름차순으로 삽입
	Node* temp = new Node;
	temp->data = num;
	temp->next = 0;
	temp->prev = 0;
	Node* p, * q;

	if (isEmpty()) head = temp;   //첫 노드일 때
	else if (temp->data < head->data) {   //head node 앞에 삽입
		temp->next = head;
		head->prev = temp;
		head = temp;
	}
	else {
		p = head;
		while (p != 0 && (p->data < temp->data)) {
			q = p;
			p = p->next;
		}
		if (p != 0) {   //중간에 삽입
			q->next = temp;
			temp->prev = q;
			temp->next = p;
			p->prev = temp;
		}
		else {   //마지막에 삽입
			q->next = temp;
			temp->prev = q;
		}
	}
}

void List::deleteList(int num) {   //노드 삭제
	Node* p, * q;
	if (isEmpty()) { cout << "List is empty\n"; return; }
	else if (head->data == num) {  //삭제될 노드가 head인 경우
		p = head;
		head = head->next;
		head->prev = 0;
		delete p;
	}
	else {
		p = head;
		while (p != 0 && (p->data != num)) {
			q = p;
			p = p->next;
		}
		if (p != 0) {
			q->next = p->next;
			if (p->next != 0) p->next->prev = q;
			delete p;
		}
		else cout << num << " is not in the list\n";
	}
}

void List::forwardList() {
	Node* p;
	if (!isEmpty()) {
		p = head;
		cout << "----- Forward List -----\n";
		while (p != 0) {
			cout << setw(8) << p->data;
			p = p->next;
		}
		cout << endl;
	}
	else cout << "List is empty\n";
}

void List::backwardList() {
	Node* p;
	if (!isEmpty()) {
		p = head;
		while (p->next != 0) p = p->next;
		cout << "----- Backward List -----\n";
		while (p != 0) {
			cout << setw(8) << p->data;
			p = p->prev;
		}
		cout << endl;
	}
	else cout << "List is empty\n";
}

void List::searchList(int num) {
	Node* p;
	if (!isEmpty()) {
		p = head;
		while (p != 0 && (p->data != num)) {
			p = p->next;
		}
		if (p != 0) cout << num << " is in the list\n";
		else cout << num << " is not in the list\n";
	}
	else cout << "List is empty\n";
}

int main() {
	List L;
	int num, choice;

	while (true) {
		cout << "input a number : 1.insert, 2.delete, 3.forward, 4.backward, 5.search, 6.quit => ";
		cin >> choice;
		switch (choice) {
		case 1: {
			cout << "input a number => ";
			cin >> num;
			L.insertList(num);
			L.forwardList(); break;
		}
		case 2: {
			cout << "input a number => ";
			cin >> num;
			L.deleteList(num); break;
		}
		case 3: {L.forwardList(); break; }
		case 4: {L.backwardList(); break; }
		case 5: {
			cout << "Enter a number => ";
			cin >> num;
			L.searchList(num); break;
		}
		case 6: {
			L.~List();
			return 0;
		}
		default: {cout << "Bad command\n"; break; }
		}
	}
}
