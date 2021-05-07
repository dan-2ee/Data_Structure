///////////////////
// Name: 이다은
// Student ID: 20203112
// Program ID: LAB#04
//////////////////

#include <iostream>
#include <fstream>
using namespace std;

class Matrix {
public:
    int row, col, terms;
};

Matrix matrixB[24];    //row-major
Matrix Btrans[24];
Matrix reverTrans[24];

void transpose() {    //전치행렬
    int cnt = 0;
    int i = 0;
    for (int j = 0; j < 8; j++) {
        for (int r = 0; r < 8; r++) {
            if (matrixB[r].col == cnt) {
                Btrans[i].row = matrixB[r].col;
                Btrans[i].col = matrixB[r].row;
                Btrans[i].terms = matrixB[r].terms;
                i++;
            }
        }
        cnt++;
    }
}

void fastTransB() {   //Btrans -> matrixB
    int row_terms[10], starting_pos[10];
    int i, j;

    for (i = 0; i < 6; i++)
        row_terms[i] = 0; 

    for (i = 0; i < 8; i++)
        row_terms[Btrans[i].col]++; 

    starting_pos[0] = 0; 

    for (i = 1; i <= 6; i++)
        starting_pos[i] = starting_pos[i - 1] + row_terms[i - 1];

    for (i = 0; i < 8; i++) { 
        j = starting_pos[Btrans[i].col]++;
        reverTrans[j].row = Btrans[i].col; 
        reverTrans[j].col = Btrans[i].row;
        reverTrans[j].terms = Btrans[i].terms;
    }
}

int main() {
    int AMatrix[36];   //original
    int num, i = 0;

    ifstream text;
    text.open("lab4-1.txt");
    
    while (text >> num) {
        AMatrix[i] = num;
        i++;
    }
    cout << "1) Original Matrix : A" << endl;    //original matrix 출력
    for (int i = 0; i < 36; i++) {    //original matrix 출력
        cout << AMatrix[i] << " ";
            if (i % 6 == 5) cout << endl;
    }

    cout << endl;
    //row major
    int Bindex = 0;
    for (int r = 0; r < 6; r++) {
        for (int c = 0; c < 6; c++) {
            if (AMatrix[r * 6 + c] != 0) {
                matrixB[Bindex].row = r;
                matrixB[Bindex].col = c;
                matrixB[Bindex].terms = AMatrix[r * 6 + c];
                Bindex++;
            }
        }
    }

    cout << "2) (matrix B) - row major" << endl;
    for (int j = 0; j < 8; j++) {
        cout << matrixB[j].row << " " << matrixB[j].col << " " << matrixB[j].terms;
        cout << endl;
    }
    cout << endl;

    transpose();
    cout << "3) (Btrans) - Transposed matrix B, column major" << endl;
    for (int j = 0; j < 8; j++) {
        cout << Btrans[j].row << " " << Btrans[j].col << " " << Btrans[j].terms;
        cout << endl;
    }
    cout << endl;

    fastTransB();  
    cout << "4) (matrix B) - Fast transpose (Btrans -> B)" << endl;
    cout << endl;
    for (int j = 0; j < 8; j++) {
        cout << reverTrans[j].row << " " << reverTrans[j].col << " " << reverTrans[j].terms;
        cout << endl;
    }

}