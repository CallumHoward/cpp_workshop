// function.cpp
// https://www.hackerrank.com/challenges/c-tutorial-functions/problem
// Callum Howard, 2019

#include <iostream>
#include <algorithm>
using namespace std;

int max_of_four(int a, int b, int c, int d);

int main() {
    int a, b, c, d;
    scanf("%d %d %d %d", &a, &b, &c, &d);
    int ans = max_of_four(a, b, c, d);
    printf("%d", ans);

    return 0;
}

int max_of_four(int a, int b, int c, int d) {
    return std::max({a, b, c, d});
}

