// strings.cpp
// https://www.hackerrank.com/challenges/c-tutorial-strings/problem
// Callum Howard, 2019


#include <iostream>
#include <string>
#include <algorithm> // swap
using namespace std;

int main() {
    // read input strings
    std::string a, b;
    std::cin >> a >> b;

    // print length of a and b respectively
    std::cout << a.size() << ' ' << b.size() << '\n';

    // print a and b concatenated
    std::cout << a + b << '\n';

    // print two strings separated by a space, a' and b'. a' and b' are the same
    // as a and b respectively, except that their first characters are swapped
    std::swap(a.at(0), b.at(0));
    std::cout << a << ' ' << b << '\n';

    return 0;
}

