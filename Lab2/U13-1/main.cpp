#include <iostream>
#include <iomanip>
#include <cstdlib>

#define SWAPS 100

using namespace std;

void printMatrix(int matrix[4][4]);
void randomizeMatrix(int matrix[4][4]);
void swap(int &a, int &b);

int main()
{
    int matrix[4][4] = {{0, 1, 2, 3}, {4, 5, 6, 7}, {8, 9, 10, 11}, {12, 13, 14, 15}};
    randomizeMatrix(matrix);
    printMatrix(matrix);
    return 0;
}

// Prints the matrix
void printMatrix(int matrix[4][4]) {
    for(int i = 0; i < 4; i++) {
        for(int j = 0; j < 4; j++)
            cout << setw(3) << matrix[i][j];
        cout << endl;
    }
}

// Swaps two elements in the matrix SWAPS times.
void randomizeMatrix(int matrix[4][4]) {
    srand(time(0));
    for(int i = 0; i < SWAPS; i++) {
        int rowA = rand() % 4;
        int colA = rand() % 4;
        int rowB = rand() % 4;
        int colB = rand() % 4;
        swap(matrix[rowA][colA], matrix[rowB][colB]);
    }

}

// The function created in assignment 11
void swap(int &a, int &b) {
    if(a > b) {
        int tmp = a;
        a = b;
        b = tmp;
    }
}
