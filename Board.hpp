// Board.hpp
#ifndef BOARD_HPP
#define BOARD_HPP

#include <vector>
using namespace std;

class Board {
public:
    int numBins;
    int capacity;
    vector<vector<int>> grid;

    Board();
    Board(int numBins, int capacity);
    ~Board() = default;

    void display() const;
    int add(int player);
};

#endif
