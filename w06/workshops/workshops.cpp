// workshops.cpp
// Callum Howard, 2019

#include <cassert>
#include <iostream>
#include <vector>
#include <algorithm>

struct Workshop {
    int start_time;
    int duration;
    int end_time() const { return start_time + duration; }
};

struct Available_Workshops {
    std::vector<Workshop> workshops;
};

// function prototypes
Available_Workshops *initialize(int start_time[], int duration[], int n);
int CalculateMaxWorkshops(Available_Workshops *ptr);
bool overlapping(const Workshop& lhs, const Workshop& rhs);
void testOverlapping(void);


int main() {
    testOverlapping();

    int n;  // number of workshops
    std::cin >> n;
    // create arrays of unknown size n
    int *start_time = new int[n];
    int *duration = new int[n];

    for (int i = 0; i < n; i++) { std::cin >> start_time[i]; }
    for (int i = 0; i < n; i++) { std::cin >> duration[i]; }

    Available_Workshops *ptr;
    ptr = initialize(start_time, duration, n);
    std::cout << CalculateMaxWorkshops(ptr) << std::endl;
    return 0;
}

Available_Workshops *initialize(int start_time[], int duration[], int n) {
    auto availableWorkshops = new Available_Workshops{};
    for (int i = 0; i < n; ++i) {
        Workshop workshop = {start_time[i], duration[i]};
        availableWorkshops->workshops.push_back(workshop);
    }
    return availableWorkshops;
}

int CalculateMaxWorkshops(Available_Workshops *ptr) {
    // sort on duration, then on start time
    std::sort(std::begin(ptr->workshops), std::end(ptr->workshops),
            [] (const Workshop& lhs, const Workshop& rhs) {
                return lhs.end_time() < rhs.end_time();
            });

    // take as many as possible from the start
    auto taken = std::vector<Workshop>{};
    for (const auto& workshop : ptr->workshops) {
        if (taken.empty() or taken.back().end_time() <= workshop.start_time) {
            taken.push_back(workshop);
        }
    }

    return static_cast<int>(taken.size());
}

bool overlapping(const Workshop& lhs, const Workshop& rhs) {
    return not (lhs.end_time() <= rhs.start_time or
        lhs.start_time >= rhs.end_time());
}

void testOverlapping() {
    const auto w1 = Workshop{1, 1};
    const auto w2 = Workshop{3, 1};
    const auto w3 = Workshop{2, 1};
    assert(w1.start_time + w1.duration <= w2.start_time);
    assert(not overlapping(w1, w2));
    assert(not overlapping(w2, w1));
    assert(not overlapping(w1, w3));
    assert(not overlapping(w3, w1));
    assert(not overlapping(w2, w3));
    assert(not overlapping(w3, w2));
}
