//////////////////////
// Name: 이다은
// Student ID: 20203112
// Program ID: Lab#08
//////////////////////
#include <iostream>
using namespace std;

const char prec[4][2] = { {'*', 2}, {'/', 2}, {'+',1}, {'-', 1} };
int level = 0;

class Node {
private:
	char data;
	Node* left;
	Node* right;
	int prio;
	Node(char value) { data = value; left = 0; right = 0; prio = 4; }
	friend class Tree;
};

class Tree {
public:
	Node* root;
	Tree() { root = 0; }
	~Tree() { deleteTree(root); }
	void deleteTree(Node* p);
	void inorder(Node* p);
	void postorder(Node* p);
	void preorder(Node* p);
	void BuildTree(char data);
	void insertOperator(Node* node);
	void insertOperand(Node* node);
	int treeEval(Node* node);
	void printTree(Node* p, int level);
};

void Tree::deleteTree(Node* p) {
	if (p) {
		deleteTree(p->left);
		deleteTree(p->right);
		delete p;
	}
}

void Tree::inorder(Node* p) {
	if (p) {
		inorder(p->left);
		cout << p->data << " ";
		inorder(p->right);
	}
}

void Tree::postorder(Node* p) {
	if (p) {
		postorder(p->left);
		postorder(p->right);
		cout << p->data << " ";
	}
}

void Tree::preorder(Node* p) {
	if (p) {
		cout << p->data << " ";
		preorder(p->left);
		preorder(p->right);
	}
}

void Tree::BuildTree(char data) {
	Node* temp = new Node(data);
	int i;
	for (i = 0; i < 4; i++) {
		if (temp->data == prec[i][0]) {
			temp->prio = prec[i][1]; break;
		}
	}
	if (i == 4) insertOperand(temp);
	else insertOperator(temp);
}

void Tree::insertOperator(Node* node) {
	if (root->prio >= node->prio) {
		node->left = root;
		root = node;
	}
	else {
		node->left = root->right;
		root->right = node;
	}
}

void Tree::insertOperand(Node* node) {
	if (root == NULL) { root = node; return; }
	Node* p = root;
	while (p->right != NULL) p = p->right;
	p->right = node;
}

int Tree::treeEval(Node* node) {
	int value = 0;
	int left, right;
	if (node != NULL) {
		if (isdigit(node->data)) {
			value = node->data - '0';
		}
		else {
			left = treeEval(node->left);
			right = treeEval(node->right);
			switch (node->data) {
			case '+': value = left + right; break;
			case '-': value = left - right; break;
			case '*': value = left * right; break;
			case '/': value = left / right; break;
			}
		}
	}
	return value;
}

void Tree::printTree(Node *p, int level) {
	int j = 1;
	if (p!=NULL) {
		printTree(p->right, level + 1);
		while(j++ < level) cout << "    ";  
		cout << p->data;
		
		if (p->left !=0 && p->right !=0) cout << " <";
		else if (p->right!=0) cout << " /";
		else if (p->left!=0) cout << " \\";
		cout << endl;

		printTree(p->left, level + 1);
	}
}

int main() {
	int  i = 1;
	while (true) {
		Tree tree;
		char exp[100];

		cout << i << ". " << "Infix Expression" << i << " : ";
		i++;

		int idx = 0;
		cin >> exp;
		if (exp[0] == 'q' && exp[1] == 'u' && exp[2] == 'i' && exp[3] == 't') {  //quit 입력시 종료
			tree.~Tree();
			break;
		}

		while (exp[idx] != 0) {
			tree.BuildTree(exp[idx++]);
		}
		level = idx;
		cout << endl;

		cout << "InOrder : ";
		tree.inorder(tree.root);
		cout << endl;

		cout << "PostOrder : ";
		tree.postorder(tree.root);
		cout << endl;

		cout << "PreOrder : ";
		tree.preorder(tree.root);
		cout << endl;

		if (isdigit(exp[0])) cout << "Evaluation : " << tree.treeEval(tree.root);
		cout << endl << endl;
	
		tree.printTree(tree.root, level);
		
		cout << endl << endl;
	}
}