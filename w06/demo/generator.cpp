// generator.cpp
// Callum Howard, 2019

// To compile and run this code:
/*

rez env gcc
g++ -Wall -Wextra -pedantic -std=c++14 -g -o generator generator.cpp
./generator

*/

#include <iostream>


class Fib {
public:

    // `operator()`: any function parameters go in the second pair of brackets
    int operator()() {
        int temp = previous;
        previous = current;
        current += temp;
        return temp;
    }

private:
    int previous = 0;
    int current = 1;
};


int main() {

    Fib fib{};

    // print out 10 numbers from the Fibonacci sequence
    for (int i = 0; i < 10; ++i) {
        std::cout << fib() << ' ';
    }
    std::cout << '\n';

    return 0;
}

