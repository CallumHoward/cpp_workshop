// total.cpp
// Callum Howard, 2019

#include <iostream>

int main() {
    int temp;
    int total = 0;
    while (std::cin >> temp) {
        total += temp;
    }
    std::cout << total << '\n';
    return 0;
}
