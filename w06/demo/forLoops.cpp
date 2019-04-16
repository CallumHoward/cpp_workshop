
// first preference, use an STL algorithm.
// There are many algorithms that can handle most cases
// Some examples are: for_each, transform, accumulate, lower_bound, any
// STL Algorithms listed here: https://devdocs.io/cpp/header/algorithm
std::copy(std::cbegin(numbers), std::cend(numbers),
        std::ostream_iterator(std::cout, "\n"));

// otherwise use a "range-based for loop"
for (const auto& number : numbers) {
    std::cout << number << '\n';
}

// otherwise use an "iterator based loop"
for (auto it = std::cbegin(numbers); it != std::cend(numbers); ++it) {
    std::cout << *it << '\n';
}

// if you have to, use a "c-style for loop" but be careful to only access
// indexes that are within the size of the `numbers` container
for (int i = 0; i < numbers.size(); ++i) {
    std::cout << numbers[i] << '\n';
}
