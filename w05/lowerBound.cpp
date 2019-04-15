// lowerBound.cpp
// Callum Howard, 2019


#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>


int main() {
    int nNums;
    std::cin >> nNums;

    auto nums = std::vector<int>(nNums);
    for (int i = 0; i < nNums; ++i) {
        std::cin >> nums[i];
    }
    std::sort(std::begin(nums), std::end(nums));

    int nQueries;
    std::cin >> nQueries;

    for (int i = 0; i < nQueries; ++i) {
        int query;
        std::cin >> query;
        const auto result = std::lower_bound(std::cbegin(nums), std::cend(nums), query);
        std::cout << ((*result == query) ? "Yes " : "No ")
                << std::distance(std::cbegin(nums), result) + 1 << '\n';
    }

    return 0;
}
