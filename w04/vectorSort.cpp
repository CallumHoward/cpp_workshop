// vectorSort.cpp
// https://www.hackerrank.com/challenges/vector-sort/problem
// Callum Howard, 2019


#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <iterator> // ostream_iterator
#include <algorithm>
//using namespace std;


int main() {
    int numNumbers;
    std::cin >> numNumbers;

    auto numbers = std::vector<int>{};
    for (int i = 0; i < numNumbers; ++i) {
        int temp;
        std::cin >> temp;
        numbers.push_back(temp);
    }

    std::sort(std::begin(numbers), std::end(numbers));

    std::copy(std::cbegin(numbers), std::cend(numbers),
            std::ostream_iterator<int>(std::cout, " "));

    return 0;
}
