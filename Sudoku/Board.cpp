#include "Board.h"
#include <iostream>

Board::Board(const int rows, const int cols, const std::vector<std::vector<int>>& tiles) : tiles(tiles) {}

void Board::setValue(const int row, const int col, const int value) {
    tiles[row][col] = value;
}

int Board::getValue(const int row, const int col) const {
    return tiles[row][col];
}

void Board::display() {
    int hcount = 0;
    int ccount = 0;
    std::cout << "-------------------------" << std::endl;
    for (const auto& row : tiles) {
        std::cout << "| ";
        for (const auto& col : row) {
            std::cout << col << " ";
            ccount++;
            if (ccount > 2) {
                std::cout << "| ";
                ccount = 0;
            }
        }
        std::cout << std::endl;

        hcount++;
        if (hcount > 2) {
            std::cout << "-------------------------" << std::endl;
            hcount = 0;
        }
    }
}
