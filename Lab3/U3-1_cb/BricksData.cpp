#include "BricksData.h"
#include <iostream>

// Initialize data structures to the initial position:
//  1  2  3  4
//  5  6  7  8
//  9 10 11 12
// 13 14 15
BricksData::BricksData() : matrix {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}, {13, 14, 15, 0}}
{
    zeroX = zeroY = 3;
}


// If 'toMove' is a legal brick to move then update the data
// structures, add the moved bricks to 'brickList, and return the
// direction of the move
// Otherwise return the move direction 'None'
BricksData::Movement BricksData::Move(int toMove, std::vector<int>& brickList)
{
    // TO DO
    //int toMoveX = toMove / 4;
    //int toMoveY = toMove % 4;

    std::vector<int> temp(3);

    // Calculate two-dimensional indices for toMove
    int toMoveX = 0;
    int toMoveY = 0;
    for(int i = 0; i < 4; i++) {
        for(int j = 0; j < 4; j++) {
            if(matrix[i][j] == toMove) {
                toMoveX = i;
                toMoveY = j;
            }
        }
    }

    if(toMoveX == zeroX) {
        if(toMoveY < zeroY) {
            //direction = right
            for(int i = zeroY; i > toMoveY; i--) {
                //Swap 0 and the closest brick, add the moved brick to the list, then update the position of 0
                int tmp = matrix[zeroX][zeroY - 1];
                matrix[zeroX][zeroX - 1] = matrix[zeroX][zeroY];
                matrix[zeroX][zeroY] = tmp;
                temp.push_back(matrix[zeroX][zeroY]);
                zeroY--;
            }
            brickList = temp;
            return Right;
        } else if(toMoveY > zeroY) {
            //direction = left
            for(int i = zeroY; i < toMoveY; i++) {
                //Swap 0 and the closest brick, add the moved brick to the list, then update the position of 0
                int tmp = matrix[zeroX][zeroY + 1];
                matrix[zeroX][zeroX + 1] = matrix[zeroX][zeroY];
                matrix[zeroX][zeroY] = tmp;
                temp.push_back(matrix[zeroX][zeroY]);
                zeroY++;
            }
            brickList = temp;
            return Left;
        }
    } else if(toMoveY == zeroY) {
        if(toMoveX < zeroX) {
            //direction = down
            for(int i = zeroX; i > toMoveX; i--) {
                //Swap 0 and the closest brick, add the moved brick to the list, then update the position of 0
                int tmp = matrix[zeroX - 1][zeroY];
                matrix[zeroX - 1][zeroX] = matrix[zeroX][zeroY];
                matrix[zeroX][zeroY] = tmp;
                brickList.push_back(matrix[zeroX][zeroY]);
                zeroX--;
            }
            brickList = temp;
            return Down;
        } else if(toMoveX > zeroX) {
            //direction = up
            for(int i = zeroX; i < toMoveX; i++) {
                //Swap 0 and the closest brick, add the moved brick to the list, then update the position of 0
                int tmp = matrix[zeroX + 1][zeroY];
                matrix[zeroX + 1][zeroX] = matrix[zeroX][zeroY];
                matrix[zeroX][zeroY] = tmp;
                brickList.push_back(matrix[zeroX][zeroY]);
                zeroX++;
            }
            brickList = temp;
            return Up;
        }
    }
    return None;
}

// Add all brick numbers in according order to their current
// position (use '0' for the empty square)
// The order for the initial positions is:
// 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 0
void BricksData::Positions(std::vector<int>& brickList)
{
    std::vector<int> temp(16);
    for(int i = 0; i < 4; i++) {
        for(int j = 0; j < 4; j++) {
            temp.push_back(matrix[i][j]);
        }
    }
    std::cout << temp.size() << std::endl;
    brickList = temp;
}

// Reset the data structures to the initial position
void BricksData::Reset()
{
    int val = 1;
    for(int i = 0; i < 4; i++) {
        for(int j = 0; j < 4; j++) {
            if(i == 3 && j == 3)
                matrix[i][j] = 0;
            else
                matrix[i][j] = val;
            val++;
        }
    }
    zeroX = zeroY = 3;
}

// Shuffle the bricks to random positions
void BricksData::Shuffle()
{
    // TO DO
}

// Return 'true' if the puzzle is solved, i.e. all bricks are in
// their initial positions
bool BricksData::Check()
{
    int n = 1;
    for(int i = 0; i < 4; i++) {
        for(int j = 0; j < 4; j++) {
            if(matrix[i][j] == n)
                n++;
            else
                break;
        }
    }
    if(n == 16)
        return true;
    else
        return false;
}
