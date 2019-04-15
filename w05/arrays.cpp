// arrays.cpp
// Callum Howard, 2019


#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <iterator>

using namespace std;


int main() {
    int nNums;
    std::cin >> nNums;
    int nums[nNums];
    for (int i = nNums - 1; i >= 0; --i) {
        int temp;
        std::cin >> temp;
        nums[i] = temp;
    }

    for (const auto& n : nums) {
        std::cout << n << " ";
    }
    std::cout << '\n';

    return 0;
}
