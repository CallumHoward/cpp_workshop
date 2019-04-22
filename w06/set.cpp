// set.cpp
// Callum Howard, 2019

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <set>
#include <algorithm>

enum {
    ADD_ELEMENT = 1,
    REMOVE_ELEMENT = 2,
    FIND_ELEMENT = 3
};

int main() {
    int nQueries;
    std::cin >> nQueries;

    auto elements = std::set<int>{};

    for (int i = 0; i < nQueries; ++i) {
        int op, value;
        std::cin >> op >> value;

        switch (op) {
            case ADD_ELEMENT: elements.insert(value); break;
            case REMOVE_ELEMENT: elements.erase(value); break;
            case FIND_ELEMENT:
                const auto found = elements.find(value);
                std::cout << (found != std::cend(elements) ? "Yes\n" : "No\n");
                break;
        }
    }

    return 0;
}



