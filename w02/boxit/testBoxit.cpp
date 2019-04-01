// testBox.cpp
// https://www.hackerrank.com/challenges/box-it/problem
// Callum Howard, 2019

#include "Box.hpp"

void check2() {
    //NOTE this checking code is provided by HackerRank and isn't the best style
    int input;
    std::cin >> input;
    ch::Box temp;

    for (int i = 0; i < input; ++i) {
        int type;
        std::cin >> type;

        if (type == 1) { std::cout << temp << '\n'; }

        if (type == 2) {
            int l, b, h;
            std::cin >> l >> b >> h;
            ch::Box NewBox(l, b, h);
            temp = NewBox;
            std::cout << temp << '\n';
        }

        if (type == 3) {
            int l, b, h;
            std::cin >> l >> b >> h;
            ch::Box NewBox(l, b, h);
            if (NewBox < temp) {
                std::cout << "Lesser\n";
            } else {
                std::cout << "Greater\n";
            }
        }

        if (type == 4) {
            std::cout << temp.CalculateVolume() << '\n';
        }

        if (type == 5) {
            ch::Box NewBox(temp);
            std::cout << NewBox << '\n';
        }

    }
}

