// map.cpp
// Callum Howard, 2019

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <map>
#include <algorithm>

enum {
    ADD_ELEMENT = 1,
    REMOVE_ELEMENT = 2,
    FIND_ELEMENT = 3
};

int main() {
    int nQueries;
    std::cin >> nQueries;

    auto elements = std::map<std::string, int>{};

    for (int i = 0; i < nQueries; ++i) {
        int op, value;
        std::string name;
        std::cin >> op >> name;

        switch (op) {
            case REMOVE_ELEMENT: elements.erase(name); break;
            case FIND_ELEMENT: std::cout << elements[name] << '\n'; break;
            case ADD_ELEMENT:
                std::cin >> value;
                elements[name] += value;
                break;
        }
    }

    return 0;
}



