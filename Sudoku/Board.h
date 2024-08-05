#ifndef BOARD_H
#define BOARD_H
#include <vector>


class Board {
public:
    Board(int rows, int cols, const std::vector<std::vector<int>>& tiles);
    void setValue(int row, int col, int value);
    [[nodiscard]] int getValue(int row, int col) const;
    void display();
private:
    std::vector<std::vector<int>> tiles;
};



#endif
