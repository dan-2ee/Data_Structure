/*
Name : 이다은
Student ID : 20203112
Program ID : HW#3
Description : Doubly Linked List의 여러 함수들을 테스트한다.
Algorithm :
1. 선택지를 출력하여 사용자에게 보여준다.
2. 호출할 함수를 사용자에게 입력받아서 choice에 저장한다.
3. choice가 1이면 insertAfter 함수를 호출하여 입력받은 수를 current node 뒤에 insert한다.
4. choice가 2이면 insertBefore 함수를 호출하여 입력받은 수를 current node 앞에 insert한다.
5. choice가 3이면 insertFirst 함수를 호출하여 입력받은 수를 리스트의 맨 앞에 위치시킨다.
6. choice가 4이면 insertLast 함수를 호출하여 입력받은 수를 리스트의 맨 뒤에 위치시킨다.
7. choice가 5이면 deleteCurrent 함수를 호출하여 current node를 삭제한다.
8. choice가 6이면 locateCurrent 함수를 호출하여 current를 입력받은 위치로 옮긴 뒤, current data를 출력한다.
9. choice가 7이면 updateCurrent 함수를 호출하여 현재 current의 data 값을 입력받은 수로 교체한다.
10. choice가 8이면 displayList 함수를 호출하여 전체 리스트를 출력한다.
11. choice가 9이면 while문을 빠져나와서 실행을 종료한다.
Variables :
1. void insertAfter(int num): current node 뒤에 insert
2. void insertBefore(int num): current node 앞에 insert
3. void insertFirst(int num): 리스트의 맨 앞에 insert
4. void insertLast(int num): 리스트의 맨 뒤에 insert
5. void deleteCurrent(): current node 삭제
6. void LocateCurrent(int n): current를 입력받은 위치로 옮김, 해당 데이터 출력
7. void updateCurrent(int newdata): 현재 current의 데이터 값을 newdata로 교체
8. void displayList(): 전체 리스트 출력
9. int isEmpty(): 리스트가 비어있는지 확인
10. int Listlength(): 리스트의 길이 반환
11. temp: 사용자에게 입력받은 값을 데이터값으로 갖는 새로운 노드
12. int len: 리스트의 길이 저장
13. class Node: 세개의 필드(data, next, prev)를 가진다. 
14. class List: 여러 가지 함수와 두개의 필드(head, current)를 가진다.
                head는 가장 앞의 노드를, current는 현재 위치하고 있는 노드를 나타낸다.
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
	Node* head;   //가장 앞의 node
	Node* current;   //현재 위치 node
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
	void insertAfter(int num);   //current node 뒤에 insert
	void insertBefore(int num);  //current node 앞에 insert
	void insertFirst(int num);    //리스트의 맨 앞에 insert
	void insertLast(int num);     //리스트의 맨 뒤에 insert
	void deleteCurrent();   //current node 삭제
	void LocateCurrent(int n);  //current를 입력받은 위치로 옮김, 해당 데이터 출력
	void updateCurrent(int newdata);  //현재 current의 데이터 값 교체
	void displayList();    //전체 리스트 출력
	int isEmpty();    //리스트가 비어있는지 확인
	int Listlength();   //리스트의 길이 반환
};

int len = 0;
/*
function : Listlength
description : 리스트의 길이를 반환한다.
variables :
			1. int len : 리스트의 길이 저장
*/
int List::Listlength() { return len; }

/*
function : isEmpty
description : 리스트가 비어있는지 확인한다.
*/
int List::isEmpty() {
	if (head == 0) return 1;
	else return 0;
}
//모든 actrion 이후에 해당 노드가 current position이 됨

/*
function : insertAfter
description : current노드 뒤에 입력받은 값(num)을 insert한다.
variables :
			1. temp: 사용자에게 입력받은 값을 데이터값으로 갖는 새로운 노드
			2. int num: insert할 값
*/
void List::insertAfter(int num) {
	Node* temp = new Node(num);  //새로운 노드 생성

	if (isEmpty()) head = temp;   //empty list인 경우
	else if (current->next != 0) {   //current가 마지막 node가 아니면
		temp->prev = current;
		temp->next = current->next;
		current->next->prev = temp;
		current->next = temp;
	}
	else {   //current가 마지막 노드일 때, current뒤에 (마지막 노드 뒤에) insert
		current->next = temp;
		temp->prev = current;
	}
	current = temp;   //insert된 노드가 current node
	len += 1;   //리스트 길이 +=1
}

/*
function : insertBefore
description : current노드 앞에 입력받은 값(num)을 insert한다.
variables :
			1. temp: 사용자에게 입력받은 값을 데이터값으로 갖는 새로운 노드
			2. int num: insert할 값
*/
void List::insertBefore(int num) {
	Node* temp = new Node(num);   //새로운 노드 생성

	if (isEmpty()) head = temp;  //empty list인 경우
	else if (current == head) {  //current가 head일 때, head node 앞에 insert
		head->prev = temp;
		temp->next = head;
		head = temp;
	}
	else {    //current가 head가 아닐 때, insert middle
		temp->next = current;
		temp->prev = current->prev;
		current->prev->next = temp;
		current->prev = temp;
	}
	current = temp;  //insert된 노드가 current node
	len += 1;    //리스트 길이 +=1
}

/*
function : insertFirst
description : 리스트의 맨 앞에 입력받은 값(num)을 insert한다.
variables :
			1. temp: 사용자에게 입력받은 값을 데이터값으로 갖는 새로운 노드
			2. int num: insert할 값
*/
void List::insertFirst(int num) {
	Node* temp = new Node(num);   //새로운 노드 생성

	if (isEmpty()) head = temp;   //empty list인 경우
	else {     //head node 앞에 temp insert
		temp->next = head;
		head->prev = temp;
		head = temp;
	}
	current = temp;    //insert된 노드가 current node
	len += 1;   //리스트의 길이 +=1
}

/*
function : insertLast
description : 리스트의 맨 뒤에 입력받은 값을 insert한다.
variables :
			1. temp: 사용자에게 입력받은 값을 데이터값으로 갖는 새로운 노드
			2. p: head의 위치부터 이동하기 시작하여, 마지막 노드를 찾아냄
			3. int num: insert할 값
*/
void List::insertLast(int num) {
	Node* temp = new Node(num);   //노드 생성
	Node* p;
	if (isEmpty()) head = temp;   //empty list인 경우
	else {
		p = head;   //p는 head의 위치부터 시작
		while (p->next != 0) {   //p가 마지막 노드가 아니면 
			p = p->next;    //p 이동
		}
		p->next = temp;   //맨 뒤에 temp insert
		temp->prev = p;
	}
	current = temp;  //insert된 노드가 current node
	len += 1;     //리스트의 길이 +=1
}

/*
function : deleteCurrent
description : current node를 삭제한다.
variables :
			1. p: 삭제할 노드
*/
void List::deleteCurrent() {
	Node* p;
	if (isEmpty()) {cout << "List is empty\n"; return;}  //empty list인 경우
	else if (head == current) {   //current가 head일 때
		head = head->next;
		current = current->next;
		current->prev = 0;
		delete current;
	}
	else if (current->next == 0) {  //current가 마지막 노드일 때, 마지막 노드(current node) 삭제
		p = current;
		current->prev->next = 0;
		current = head;
		delete p;
	}
	else {   //current가 중간에 위치할 때, middle 노드(current node) 삭제
		p = current;
		current->prev->next = current->next;
		current->next->prev = current->prev;
		current = current->next;
		delete p;
	}
	len -= 1;   //current node가 삭제되었으므로, 리스트의 길이 -=1
}

/*
function : LocateCurrent
description : 입력받은 위치(n)로 current를 이동시키고, 해당 데이터를 출력한다.
variables :
			1. p: n번째로 current를 위치시키기 위해 이동할 노드
			2. int n: current를 이동할 위치
*/
void List::LocateCurrent(int n) {
	Node* p;
	if (isEmpty()) { cout << "List is empty\n"; return; }   //empty list인 경우
	else if (Listlength() >= n) {  //전체 리스트의 길이 >= 원하는 위치
		p = head;   //p는 head의 위치부터 이동하기 시작함
		for (int i = 1; i < n; i++) p = p->next;   //p를 n번째 위치로 이동시킴
		current = p;      //current를 새로운 위치(n)로 이동시킴
		cout << n << "*" << setw(8) << current->data << endl;   //해당 노드 데이터 출력
	}
	else {
		cout << "No such a line\n";  //전체 리스트의 길이 < 원하는 위치
	}
}

/*
function : updateCurrent
description : 입력받은 값(newdata)으로 현재 current의 데이터 값을 교체한다.
variables :
			1. int newdata: 입력받은 값
*/
void List::updateCurrent(int newdata) {
	if (isEmpty()) { cout << "List is empty\n"; return; }  //empty list인 경우
	else {
		current->data = newdata;   //current 데이터 값 교체
	}
}

/*
function : displayList
description : 전체 리스트를 출력한다.
variables :
			1. p: head부터 이동하기 시작하여 마지막 노드까지 이동한다.
*/
void List::displayList() {
	Node* p;
	if (isEmpty()) { cout << "List is empty\n"; return; }   //empty list인 경우
	else {
		p = head;
		cout << "--- List ---\n";
		for (int i = 1; i <= Listlength(); i++) {  //list의 마지막 노드에 도달할 때까지 이동
			if (p == current) cout << "    " << i << "  *  " << current->data << endl;
			else cout << "    " << i << "  :  " << p->data << endl;
			p = p->next;
		}
	}
}

int main() {
	List L;
	int choice, num;   //choice: 사용자의 선택 저장
	while (true) {
		cout << "Command: (1)insertAfter   (2)insertBefore   (3)insertFirst   (4)insertLast   (5)deleteCurrent" << endl;
		cout << "         (6)locateCurrent (7)updateCurrent  (8)displayList   (9)quit\n";
		cout << " ==> ";
		cin >> choice;
		switch (choice) {
		case 1: {   
			cout << "Enter a data to insert => ";
			cin >> num;   //num: insert할 값
			L.insertAfter(num);
			L.displayList();
			break;
		}
		case 2: {
			cout << "Enter a data to insert => ";
			cin >> num;  //num: insert할 값
			L.insertBefore(num);
			L.displayList();
			break;
		}
		case 3: {
			cout << "Enter a data to insert => ";
			cin >> num;  //num: insert할 값
			L.insertFirst(num);
			L.displayList();
			break;
		}
		case 4: {
			cout << "Enter a data to insert => ";
			cin >> num;   //num: insert할 값
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
			cin >> num;  //num: current의 새로운 위치
			L.LocateCurrent(num);
			break;
		}
		case 7: {
			cout << "Enter a data to update => ";
			cin >> num;   //num: current의 새로운 데이터 값
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