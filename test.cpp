#include <iostream>

int main() {
    int x { 5 };
    int* ptr { &x };

    int y { 6 };
    ptr = &y;

    *ptr = 7;

    std::cout << y << std::endl;
    return 0;
}