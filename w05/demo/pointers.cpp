// pointers.cpp
// Callum Howard, 2017

#include <iostream>

int main() {

    int myNumber = 42;

    // print out the int stored in `myNumber`
    std::cout << myNumber << '\n';

    // print out the address of `myNumber` (which is on the stack)
    std::cout << &myNumber << '\n';

    // store the address of `myNumber` in a variable
    // (the type is "pointer to an int")
    int *pointerToMyNumber = &myNumber;

    // print out the address stored in `pointerToMyNumber`
    std::cout << pointerToMyNumber << '\n';

    return EXIT_SUCCESS;
}
