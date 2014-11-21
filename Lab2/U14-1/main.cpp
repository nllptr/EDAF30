#include <iostream>
#include <iomanip>
#include <cstdlib>

#define SWAPS 100

using namespace std;

void findIndex(const int n,const  int matrix[4][4], int &x, int &y);
void printMatrix(int matrix[4][4]);
void randomizeMatrix(int matrix[4][4]);
void swap(int &a, int &b);

int main()
{
    // Init
    int matrix[4][4] = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}, {13, 14, 15, 0}};
    //int matrix[4][4] = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}, {0, 13, 14, 15}};
    //randomizeMatrix(matrix);
    int zeroX, zeroY;
    findIndex(0, matrix, zeroX, zeroY);

    cout << "Femtonspelet!" << endl;

    // Main loop
    while(true) {
        printMatrix(matrix);

        // Won game?
        int n = 1;
        for(int i = 0; i < 4; i++) {
            for(int j = 0; j < 4; j++) {
                if(matrix[i][j] == n)
                    n++;
                else
                    break;
            }
        }
        if(n == 16) {
            cout << "YOU WON THE GAME!" << endl;
            break;
        }

        cout << "Vilken bricka ska flyttas? ";
        int move;
        cin >> move;
        while(move < 1 || move > 15) {
            cout << "Felaktig inmatning. Heltal 1-15 krävs. ";
            cin >> move;
        }
        int moveX, moveY;
        findIndex(move, matrix, moveX, moveY);

        // Check if move is legal
        if(moveX == zeroX) {
            if(abs(moveY - zeroY) == 1) {
                swap(matrix[moveX][moveY], matrix[zeroX][zeroY]);
                zeroX = moveX;
                zeroY = moveY;
            } else
                cout << "Illegal move." << endl;
        } else if(moveY == zeroY) {
            if(abs(moveX - zeroX) == 1) {
                swap(matrix[moveX][moveY], matrix[zeroX][zeroY]);
                zeroX = moveX;
                zeroY = moveY;
            } else
                cout << "Illegal move." << endl;
        } else {
            cout << "Illegal move." << endl;
        }
    }

    return 0;
}

// Finds the number n in the matrix and returns its x and y coordinates (top left being 0,0).
void findIndex(const int n, const int matrix[4][4], int &x, int &y) {
    for(int i = 0; i < 4; i++)
        for(int j = 0; j < 4; j++)
            if(matrix[i][j] == n) {
                x = i;
                y = j;
            }
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
