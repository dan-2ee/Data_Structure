#include <iostream>
using namespace std;

void towerHanoi(char from, char to, char aux, int n) {
	if (n == 1) cout << "move disk 1 from peg " << from << " to peg " << to << endl;
	else {
		towerHanoi(from, aux, to, n - 1);
		cout << "move disk " << n << " from peg " << from << " to peg " << to << endl;
		towerHanoi(aux, to, from, n - 1);
	}
}

int main() {
	int num;
	cout << "Enter number : ";
	cin >> num;

	towerHanoi('A', 'C', 'B', num);
}





