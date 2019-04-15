// arrays.cpp
// https://www.hackerrank.com/challenges/arrays-introduction
// Callum Howard, 2019


#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <iterator>

//#define MAX_ARRAY_SIZE 10000;  // preprocessor macro
const int MAX_ARRAY_SIZE = 10000;  // global variable

using namespace std;


int main() {
    int nNums;
    std::cin >> nNums;

    //int nums[nNums];  // variable sized array
    int nums[MAX_ARRAY_SIZE];  // statically declared array

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
