#ifndef BOARD_H
#define BOARD_H
#include <vector>


class Board {
public:
    Board(int rows, int cols, const std::vector<std::vector<int>>& tiles);
    void setValue(int row, int col, int value);
    [[nodiscard]] int getValue(int row, int col) const;
    void display();
    [[nodiscard]] bool checkGrid() const;
    static bool contains(std::vector<int> vec, int val);

    //solve
    [[nodiscard]] bool isValid(int row, int col, int value) const;
    bool solve(int row,int col);

private:
    int rows;
    int cols;
    std::vector<std::vector<int>> tiles;
};



#endif
