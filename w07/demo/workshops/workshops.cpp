// workshops.cpp
// Callum Howard, 2019

#include <iostream>
#include <vector>
#include <algorithm>

struct Workshop {
    int startTime;
    int duration;
    int end_time() const { return startTime + duration; }
};

struct AvailableWorkshops {
    std::vector<Workshop> workshops;
};

// function prototypes
AvailableWorkshops *initialize(int startTime[], int duration[], int n);
int CalculateMaxWorkshops(AvailableWorkshops *ptr);


int main() {
    size_t n;  // number of workshops
    std::cin >> n;

    // create arrays of unknown size n
    int *startTime = new int[n];
    int *duration = new int[n];

    for (size_t i = 0; i < n; i++) { std::cin >> startTime[i]; }
    for (size_t i = 0; i < n; i++) { std::cin >> duration[i]; }

    AvailableWorkshops *ptr;
    ptr = initialize(startTime, duration, static_cast<int>(n));
    std::cout << CalculateMaxWorkshops(ptr) << std::endl;

    return 0;
}

AvailableWorkshops *initialize(int startTime[], int duration[], int n) {
    auto availableWorkshops = new AvailableWorkshops{};
    for (int i = 0; i < n; ++i) {
        Workshop workshop = {startTime[i], duration[i]};
        availableWorkshops->workshops.push_back(workshop);
    }
    return availableWorkshops;
}

int CalculateMaxWorkshops(AvailableWorkshops *ptr) {
    // sort on workshop end time
    std::sort(std::begin(ptr->workshops), std::end(ptr->workshops),
            [] (const Workshop& lhs, const Workshop& rhs) {
                return lhs.end_time() < rhs.end_time();
            });

    // take as many as possible from the start
    auto taken = std::vector<Workshop>{};
    for (const auto& workshop : ptr->workshops) {
        if (taken.empty() or taken.back().end_time() <= workshop.startTime) {
            taken.push_back(workshop);
        }
    }

    return static_cast<int>(taken.size());
}
