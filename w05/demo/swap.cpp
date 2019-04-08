// swap.cpp
// Callum Howard, 2017

#include <iostream>
#include <cassert>

void swap(int first, int second);

int main() {

    int a = 55;
    int b = 77;

    std::cout << "a holds the number " << a << '\n';
    std::cout << "b holds the number " << b << '\n';

    std::cout << "swapping the numbers...\n";

    swap(a, b);

    std::cout << "now a holds the number " << a << '\n';
    std::cout << "now b holds the number " << b << '\n';

    assert(a == 77);
    assert(b == 55);

    return EXIT_SUCCESS;
}

void swap(int first, int second) {
    int temp = first;
    first = second;
    second = temp;
}

