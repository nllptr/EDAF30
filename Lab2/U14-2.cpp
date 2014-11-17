#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

void randMat(int matrix[][4]);
void printMat(int matrix[][4]);
bool winCheck(int matrix[][4]);
void getIndex(int move, int matrix[][4], int &x, int &y);
void swap(int &a, int &b);

int main() {
    int matrix [4][4];
    randMat(matrix);
    int move;
    int x, y, zx, zy;

    while(!winCheck(matrix)) {
        printMat(matrix);
        cin >> move;
        while(move < 1 || move > 15) {
            cout << "Felaktig inmatning. Välj 1-15." << endl;
            cin >> move;
        }
        getIndex(move, matrix, x, y);
        getIndex(0, matrix, zx, zy);
        if(x == zx) {
            if(abs(y - zy) == 1) {
                swap(matrix[x][y], matrix[zx][zy]);
            } else {
                cout << "Felaktigt drag." << endl;
            }
        } else if(y == zy) {
            if(abs(x - zx) == 1) {
                swap(matrix[zx][zy], matrix[x][y]);
            } else {
                cout << "Felaktigt drag.," << endl;
            }
        }
        else {
            cout << "Felaktigt drag." << endl;
        }
    }
}

void randMat(int matrix[][4]) {
    srand(time(NULL));
    vector<int> vec (16);
    int pop;
    for(int i = 0; i < 16; i++) {
        vec[i] = i;
    }
    for(int a = 0; a < 4; a++) {
        for(int b = 0; b < 4; b++) {
            pop = rand() % vec.size();
            matrix[a][b] = vec[pop];
            vec.erase(vec.begin()+pop, vec.begin()+pop+1);
        }
    }
}

void printMat(int matrix[][4]) {
    for(int a = 0; a < 4; a++) {
        for(int b = 0; b < 4; b++) {
            cout << setw(3) << matrix[a][b];
        }
        cout << endl;
    }
}

bool winCheck(int matrix[][4]) {
    int n = 0;
        for(int a = 0; a < 4; a++) {
            for(int b = 0; b < 4; b++) {
                if(matrix[a][b] - n == 1) {
                    n++;
                } else {
                    break;
                }
            }
        }
        if(n == 15) {
            cout << "Du vann, grattis!" << endl;
            return true;
        }
        return false;
}

void getIndex(int move, int matrix[][4], int &x, int &y) {
    for(int a = 0; a < 4; a++) {
        for(int b = 0; b < 4; b++) {
            if(matrix[a][b] == move) {
                x = a;
                y = b;
            }
        }
    }
}

void swap(int &a, int &b) {
    int tmp = a;
    a = b;
    b = tmp;
}
