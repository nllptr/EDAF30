#ifndef BRICKSDATA_H
#define BRICKSDATA_H

#include <vector>

class BricksData
{
    public:
        enum Movement {Up = -4, Left = -1, None = 0, Right = 1, Down = 4};

        // Initialize data structures to the initial position:
        //  1  2  3  4
        //  5  6  7  8
        //  9 10 11 12
        // 13 14 15
        BricksData();

        // If 'toMove' is a legal brick to move then update the data
        // structures, add the moved bricks to 'brickList', and return the
        // direction of the move
        // Otherwise return the move direction 'None'
        Movement Move(int toMove, std::vector<int> &brickList);

        // Add all brick numbers in order according to their current
        // position (use '0' for the empty square)
        // The order for the initial positions is:
        // 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 0
        void Positions(std::vector<int> &brickList);

        // Reset the data structures to the initial position
        void Reset();

        // Shuffle the bricks to random positions
        void Shuffle();

        // Return 'true' if the puzzle is solved, i.e. all bricks are in
        // their initial positions
        bool Check();

    private:
};

#endif // BRICKSDATA_H
