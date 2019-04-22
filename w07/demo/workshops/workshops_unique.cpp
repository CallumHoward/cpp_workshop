// workshops.cpp
// Callum Howard, 2019

#include <iostream>
#include <vector>
#include <algorithm>  // sort
#include <utility>  // unique_ptr
#include <memory>  // make_unique

struct Workshop {
    int startTime;
    int duration;
    int endTime() const { return startTime + duration; }
};

struct AvailableWorkshops {
    std::vector<Workshop> workshops;
};

using IA_UPTR = std::unique_ptr<int[]>;  // int array unique pointer

// function prototypes
AvailableWorkshops* initialize(int startTime[], int duration[], size_t n);
std::unique_ptr<AvailableWorkshops> initialize(IA_UPTR& startTime, IA_UPTR& duration, size_t n);
int CalculateMaxWorkshops(const std::unique_ptr<AvailableWorkshops>& ptr);


int main() {
    size_t n;  // number of workshops
    std::cin >> n;

    //std::unique_ptr<int[]> startTime{new int[n]};  // equivalent to below
    std::unique_ptr<int[]> startTime = std::unique_ptr<int[]>{new int[n]};

    //auto duration = std::unique_ptr<int[]>{new int[n]};  // equivalent to below
    auto duration = std::make_unique<int[]>(n);

    for (size_t i = 0; i < n; i++) { std::cin >> startTime[i]; }
    for (size_t i = 0; i < n; i++) { std::cin >> duration[i]; }

    auto ptr = initialize(startTime, duration, n);
    std::cout << CalculateMaxWorkshops(ptr) << std::endl;

    auto ptr2 = ptr;

    return 0;
}

std::unique_ptr<AvailableWorkshops> initialize(IA_UPTR& startTime, IA_UPTR& duration, size_t n) {
    auto availableWorkshops =
            std::make_unique<AvailableWorkshops>(AvailableWorkshops{});

    for (size_t i = 0; i < n; ++i) {
        Workshop workshop = {startTime[i], duration[i]};
        availableWorkshops->workshops.push_back(workshop);
    }
    return availableWorkshops;
}

int CalculateMaxWorkshops(const std::unique_ptr<AvailableWorkshops>& ptr) {
    // sort on workshop end time
    std::sort(std::begin(ptr->workshops), std::end(ptr->workshops),
            [] (const Workshop& lhs, const Workshop& rhs) {
                return lhs.endTime() < rhs.endTime();
            });

    // take as many as possible from the start
    auto taken = std::vector<Workshop>{};
    for (const auto& workshop : ptr->workshops) {
        if (taken.empty() or taken.back().endTime() <= workshop.startTime) {
            taken.push_back(workshop);
        }
    }

    return static_cast<int>(taken.size());
}
