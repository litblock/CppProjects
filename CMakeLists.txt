cmake_minimum_required(VERSION 3.28)
project(CppProjects)

set(CMAKE_CXX_STANDARD 17)

add_executable(CppProjects test/calc.cpp
        test/test.cpp
        Sudoku/Sudoku.cpp
        Sudoku/Board.cpp
        Sudoku/Board.h)
