// types.cpp
// Callum Howard, 2019

#include <iostream>

int main() {
    int tempInt;
    long tempLong;
    char tempChar;
    float tempFloat;
    double tempDouble;

    std::cin >> tempInt;
    std::cin >> tempLong;
    std::cin >> tempChar;
    std::cin >> tempFloat;
    std::cin >> tempDouble;

    std::cout << tempInt << '\n';
    std::cout << tempLong << '\n';
    std::cout << tempChar << '\n';
    std::cout.precision(2);
    std::cout << std::fixed << tempFloat << '\n';
    std::cout.precision(5);
    std::cout << std::fixed << tempDouble << '\n';

    return 0;
}

