// Board.hpp
#ifndef BOARD_HPP
#define BOARD_HPP

#include <vector>
using namespace std;

class Board {
public:
    int numBins;                  // how many bins (minimum 5)
    int capacity;                 // max elements per bin (minimum 4)
    vector<vector<int>> grid;     // each bin holds a sequence of ints (0–3)

    Board();                      // default: numBins=6, capacity=4
    Board(int numBins, int capacity);
    ~Board() = default;

    void display() const;         // draw the board with Unicode shapes
    int add(int player);          // interactively choose a bin and push_back(player)
};

#endif // BOARD_HPP
