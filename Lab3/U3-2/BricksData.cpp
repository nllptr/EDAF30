#include "BricksData.h"
#include <vector>
using namespace std;

// Initialize data structures to the initial position:
//  1  2  3  4
//  5  6  7  8
//  9 10 11 12
// 13 14 15

BricksData::BricksData()
{
    // TO DO
}


// If 'toMove' is a legal brick to move then update the data
// structures, add the moved bricks to 'brickList, and return the
// direction of the move
// Otherwise return the move direction 'None'
BricksData::Movement BricksData::Move(int toMove, std::vector<int>& brickList)
{
    // TO DO
    return None;
}

// Add all brick numbers in according order to their current
// position (use '0' for the empty square)
// The order for the initial positions is:
// 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 0
void BricksData::Positions(std::vector<int>& brickList)
{
    // TO DO
}

// Reset the data structures to the initial position
void BricksData::Reset()
{
    // TO DO
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
    // TO DO
    return true;
}
