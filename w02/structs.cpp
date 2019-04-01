// structs.cpp
// https://www.hackerrank.com/challenges/c-tutorial-struct/problem
// Callum Howard, 2019

#include <iostream>

struct Student {
    std::string first_name;
    std::string last_name;
    int standard;
    int age;
};

int main() {
    Student st;

    std::cin >> st.age >> st.first_name >> st.last_name >> st.standard;
    std::cout << st.age << " " << st.first_name << " " << st.last_name << " " << st.standard;

    return 0;
}
