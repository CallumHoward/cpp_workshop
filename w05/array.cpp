// array.cpp
// Callum Howard, 2019

#include <iostream>

int main() {

    std::cout << "hello, world!\n";

    int arr[] = {1, 2, 3, 4};

    for (int a : arr){
        std::cout << a;
        std::cout << std::endl;

    }

    return 0;
}
