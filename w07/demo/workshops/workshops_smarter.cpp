// workshops.cpp
// Callum Howard, 2019

#include <iostream>
#include <vector>
#include <algorithm>  // sort

struct Workshop {
    int startTime;
    int duration;
    int endTime() const { return startTime + duration; }
};

struct AvailableWorkshops {
    std::vector<Workshop> workshops;
};

template <typename T>
struct SmarterPointer {
    SmarterPointer(T* pointer) : p{pointer} {}
    SmarterPointer(const SmarterPointer<T>& rhs) : SmarterPointer{rhs.p} {}
    ~SmarterPointer() { delete p; }
    T* operator->() { return p; }
    T* p;
};

template <typename T>
struct SmarterArray {
    SmarterArray(T* pointer) : p{pointer} {}
    ~SmarterArray() { delete[] p; }
    T& operator[](size_t i) { return p[i]; }
    T* p;
};

// function prototypes
AvailableWorkshops* initialize(int startTime[], int duration[], int n);
SmarterPointer<AvailableWorkshops> initialize(SmarterArray<int>& startTime,
        SmarterArray<int>& duration, size_t n);
int CalculateMaxWorkshops(AvailableWorkshops* ptr);
int CalculateMaxWorkshops(SmarterPointer<AvailableWorkshops> ptr);


int main() {
    size_t n;  // number of workshops
    std::cin >> n;

    SmarterArray<int> startTime{new int[n]};
    SmarterArray<int> duration{new int[n]};

    for (size_t i = 0; i < n; i++) { std::cin >> startTime[i]; }
    for (size_t i = 0; i < n; i++) { std::cin >> duration[i]; }

    SmarterPointer<AvailableWorkshops> ptr = initialize(startTime, duration, n);
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

SmarterPointer<AvailableWorkshops> initialize(SmarterArray<int>& startTime,
        SmarterArray<int>& duration, size_t n) {

    auto availableWorkshops = SmarterPointer<AvailableWorkshops>{
            new AvailableWorkshops{}};

    for (size_t i = 0; i < n; ++i) {
        Workshop workshop = {startTime[i], duration[i]};
        availableWorkshops->workshops.push_back(workshop);
    }
    return availableWorkshops;
}

int CalculateMaxWorkshops(AvailableWorkshops *ptr) {
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
