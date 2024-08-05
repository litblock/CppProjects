#include <iostream>

double operation(const int num1, const int num2, const char op) {
    double out;
    switch (op) {
        case '+':
            out = num1 + num2;
        break;
        case '-':
            out = num1 - num2;
        break;
        case '*':
            out = num1 * num2;
        break;
        case '/':
            if (num2 == 0) {
                std::cout << "Cannot divide by zero" << std::endl;
                return 1;
            }
        //result = num1 * 1.00 / num2 * 1.00;
        out = static_cast<double>(num1) / num2;
        break;
        default:
            std::cout << "Invalid operator" << std::endl;
        return 1;
    }
    return out;
}

int main() {
    std::cout << "Simple Calculator" << std::endl;

    int num1, num2;
    char op;

    std::cout << "Enter your first number: " << std::endl;
    std::cin >> num1;

    std::cout << "Enter your second number: " << std::endl;
    std::cin >> num2;

    std::cout << "Enter your operator: " << std::endl;
    std::cin >> op;

    const double result = operation(num1, num2, op);

    if (result == 1 && (op == '/' && num2 == 0 || op != '+' && op != '-' && op != '*' && op != '/')) {
        return 1;
    }

    std::cout << std::to_string(num1) + " " + op + " " + std::to_string(num2) + " = " + std::to_string(result) << std::endl;
    return 0;
}

