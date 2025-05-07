// Board.cpp
#include "Board.hpp"
#include <iostream>
#include <limits>
#include <string>
using namespace std;


static const string mapping[] = {
        "\033[31m\u2b24\033[0m",   // red ball
        "\033[34m\u2b1f\033[0m",   // blue pentagon
        "\033[31m\u25c9\033[0m",   // red double-circle
        "\033[34m\u2b54\033[0m"    // blue empty pentagon
};

static void print(int numBins) {
    cout << "+";
    for (int i = 0; i < numBins; ++i) cout << "---+";
    cout << "\n";
}

Board::Board()
        : numBins(6), capacity(4), grid(vector<vector<int>>(numBins))
{}

Board::Board(int nb, int cap)
        : numBins(nb < 5 ? 5 : nb),
          capacity(cap < 4 ? 4 : cap),
          grid(vector<vector<int>>(numBins))
{}

void Board::display() const {
    print(numBins);

    for (int lvl = capacity - 1; lvl >= 0; --lvl) {
        for (int i = 0; i < numBins; ++i) {cout << "| ";
            if (lvl < (int)grid[i].size()) {
                int v = grid[i][lvl];
                if (v >= 0 && v < 4) cout << mapping[v];
                else cout << ' ';}
            else {cout << ' ';}
            cout << " ";}
        cout << "|" << "\n";
        print(numBins);}

    cout << " ";
    for (int i = 0; i < numBins; ++i) {cout << " " << i << "  ";}
    cout << "\n";
}

int Board::add(int player) {
    int bin;
    while (true) {
        cout << "Enter a bin index in [0, " << numBins << ") that is not full: ";
        if (!(cin >> bin)) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }
        if (bin < 0 || bin >= numBins) {
            cout << "invalid bin index, needs to be in [0 , " << numBins << ")\n";
            continue;
        }
        if ((int)grid[bin].size() >= capacity) {
            cout << "the bin is full\n";
            continue;
        }
        break;
    }
    grid[bin].push_back(player);
    return bin;
}
