////////////////////
// Name: ¿Ã¥Ÿ¿∫
// Student ID: 20203112
// Program ID: Lab#03-1
////////////////////
#include<iostream>

using namespace std;

int main(void) {
    int n;
    cout << "Enter number of square : ";
    cin >> n;
    int square[21][21] = { 0 };
    int i, j;
    int row, col;

    i = 0; j = n / 2;
    square[i][j] = 1;

    int key = 2;
    //i = 0, j = (n - 1) / 2;

    while (key <= n * n) {
        if (i - 1 < 0) row = n - 1;
        else row = i - 1;
        if (j - 1 < 0) col = n - 1;
        else col = j - 1;
        if (square[row][col]) i = (i + 1) % n;
        else { i = row; j = col; }
        square[i][j] = key;
        key++;
    }

    cout << "magic square size is : " << n << endl;;
    
    cout << endl;

    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            cout << square[i][j] << ' ';
        }
        cout << endl;
    }
}



