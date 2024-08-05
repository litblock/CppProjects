#include "Board.h"
#include <iostream>
#include <algorithm>

Board::Board(const int rows, const int cols, const std::vector<std::vector<int>>& tiles) : rows(rows), cols(cols), tiles(tiles) {}

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

bool Board::checkGrid() const {
    //column
    //std::cout << "column" << std::endl;
    for (int i = 0; i < 9; i++) {
        std::vector<int> c;
        for (int j = 0; j < 9; j++) {
            if (!contains(c, tiles[j][i])) {
                c.push_back(tiles[j][i]);
            } else {
                //std::cout << std::endl;
                return false;
            }
            //std::cout << tiles[j][i] << " ";
        }
        //std::cout << std::endl;
    }

    //std::cout << "row" << std::endl;
    //row
    for (int i = 0; i < 9; i++) {
        std::vector<int> r;
        for (int j = 0; j < 9; j++) {
            if (!contains(r, tiles[i][j])) {
                r.push_back(tiles[i][j]);
            } else {
                //std::cout << std::endl;
                return false;
            }
            //std::cout << tiles[i][j] << " ";
        }
        //std::cout << std::endl;
    }

    //std::cout << "3x3" << std::endl;
    //3x3
    for (int i = 0; i < 9; i += 3) {
        for (int j = 0; j < 9; j += 3) {
            std::vector<int> s;
            for (int k = i; k < i + 3; k++) {
                for (int l = j; l < j + 3; l++) {
                    if (!contains(s, tiles[k][l])) {
                        s.push_back(tiles[k][l]);
                    } else {
                        //std::cout << std::endl;
                        return false;
                    }
                    //std::cout << tiles[k][l] << " ";
                }
            }
            //std::cout << std::endl;
        }
    }

    //std::cout << "Valid" << std::endl;
    return true;
}

bool Board::contains(std::vector<int> vec, const int val) {
    if (val == 0) {
        return true;
    }
    if (std::find(vec.begin(), vec.end(), val) != vec.end()) {
        return true;
    }
    return false;
}

bool Board::isValid(const int row, const int col, const int val) const{
    //check col
    for (int i = 0; i < 9; i++) {
        if (tiles[i][col] == val) {
            return false;
        }
    }
    //check row
    for (int i = 0; i < 9; i++) {
        if (tiles[row][i] == val) {
            return false;
        }
    }
    //check 3x3
    const int start = (row / 3) * 3;
    const int end = (col / 3) * 3;

    for (int i = start; i < start + 3; i++) {
        for (int j = end; j < end + 3; j++) {
            if (tiles[i][j] == val) {
                return false;
            }
        }
    }

    return true;
}
//recursion
bool Board::solve(const int row, const int col) {
    if (row == rows) {
        return true;
    }

    if (col == cols) {
        return solve(row + 1, 0);
    }

    if (tiles[row][col] != 0) {
        return solve(row, col + 1);
    }

    for (int x = 1; x <= 9; x++) {
        if (isValid(row, col, x)) {
            tiles[row][col] = x;
            if (solve(row, col + 1)) {
                return true;
            }
            tiles[row][col] = 0;
        }
    }

    return false;
}