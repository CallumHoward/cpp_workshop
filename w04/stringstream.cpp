// stringstream.cpp
// https://www.hackerrank.com/challenges/c-tutorial-stringstream/problem
// Callum Howard, 2019


#include <sstream>
#include <vector>
#include <iostream>

using namespace std;

vector<int> parseInts(string str) {
    std::stringstream ss{str};
    std::vector<int> results;
    while (ss) {
        int temp;
        char delim;
        ss >> temp;
        if (ss) { ss >> delim; }
        results.push_back(temp);
    }
    return results;
}

int main() {
    string str;
    cin >> str;
    vector<int> integers = parseInts(str);
    for (size_t i = 0; i < integers.size(); i++) {
        cout << integers[i] << "\n";
    }

    return 0;
}

