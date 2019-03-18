// conditionals.cpp
// Callum Howard, 2019

#include <iostream>
#include <cassert>
#include <limits>
#include <vector>
#include <string>

int main()
{
    int n;
    std::cin >> n;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    assert(n >= 1);

    if (n == 1) {
        std::cout << "one\n";
    } else if (n == 2) {
        std::cout << "two\n";
    } else if (n == 3) {
        std::cout << "three\n";
    } else if (n == 4) {
        std::cout << "four\n";
    } else if (n == 5) {
        std::cout << "five\n";
    } else if (n == 6) {
        std::cout << "six\n";
    } else if (n == 7) {
        std::cout << "seven\n";
    } else if (n == 8) {
        std::cout << "eight\n";
    } else if (n == 9) {
        std::cout << "nine\n";
    } else if (n > 9) {
        std::cout << "Greater than 9\n";
    }

    ////////

    auto numberWords = std::vector<std::string>{
        "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"
    };
    assert(n >= 1);
    if (n > 9) {
        std::cout << "Greater than 9\n";
    } else {
        std::cout << numberWords.at(n) << '\n';
    }

    ////////

    auto numberWords = std::vector<std::string>{
        "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"
    };
    assert(n >= 1);
    std::cout << ((n > 9) ? "Greater than 9" : numberWords[static_cast<size_t>(n)]) << '\n';

    return 0;
}
