// vectorErase.cpp
// Callum Howard, 2019


#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <iterator>
using namespace std;


int main() {
    size_t nNums = 0;
    std::cin >> nNums;
    auto input = std::vector<int>(nNums);
    for (size_t i = 0; i < nNums; ++i) {
      std::cin >> input[i];
    }

    int removePosition;
    std::cin >> removePosition;

    input.erase(std::begin(input) + removePosition - 1);

    int removeRangeBegin;
    std::cin >> removeRangeBegin;

    int removeRangeEnd;
    std::cin >> removeRangeEnd;

    input.erase(std::begin(input) + removeRangeBegin - 1,
                std::begin(input) + removeRangeEnd - 1);

    std::cout << input.size() << '\n';
    std::copy(std::cbegin(input), std::cend(input),
            std::ostream_iterator<int>{std::cout, " "});
    std::cout << '\n';

  return 0;
}
