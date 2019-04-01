// classesAndObjects.cpp
// Callum Howard, 2019


#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cassert>

using namespace std;

// Write your Student class here
#include <numeric>

class Student {
public:
    void set_age(int age) { m_age = age; }
    void set_first_name(std::string name) { m_first_name = name; }
    void set_last_name(std::string name) { m_last_name = name; }
    void set_standard(int standard) { m_standard = standard; }

    int get_age() const { return m_age; }
    std::string get_first_name() const { return m_first_name; }
    std::string get_last_name() const { return m_last_name; }
    int get_standard() const { return m_standard; }

    int calculateTotalScore() const {
        return std::accumulate(std::cbegin(m_scores), std::cend(m_scores), 0);
    }

    std::string to_string() const {
        return std::to_string(m_age) + "," + m_first_name + "," + m_last_name +
                "," + std::to_string(m_standard);
    }

    void input() {
        int score;
        for (int i = 0; i < 5; ++i) {
            std::cin >> score;
            m_scores.push_back(score);
        }
    }

private:
    std::string m_first_name;
    std::string m_last_name;
    std::vector<int> m_scores;
    int m_standard;
    int m_age;
};


int main() {
    int n; // number of students
    cin >> n;
    Student *s = new Student[n]; // an array of n students

    for(int i = 0; i < n; i++){
        s[i].input();
    }

    // calculate kristen's score
    int kristen_score = s[0].calculateTotalScore();

    // determine how many students scored higher than kristen
    int count = 0;
    for(int i = 1; i < n; i++){
        int total = s[i].calculateTotalScore();
        if(total > kristen_score){
            count++;
        }
    }

    // print result
    cout << count;

    return 0;
}
