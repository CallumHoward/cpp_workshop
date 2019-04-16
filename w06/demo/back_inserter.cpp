// back_inserter.cpp
// Callum Howard, 2019

// To compile and run this code:
/*

rez env gcc
g++ -Wall -Wextra -pedantic -std=c++14 -g -o back_inserter back_inserter.cpp
./back_inserter

*/

#include <iostream>
#include <iterator>
#include <vector>


int main() {
    std::vector<int> numbers;

    // back_inserter_iterator and ostream_iterator are both "OutputIterator"s
    // Output Iterators are a way to provide write only behaviour.
    // An OutputIterator will do something when it is assigned to (`operator=`)

    // The following 3 lines are equivalent. We are making an OutputIterator that
    // calls the `.push_back()` method every time it is assigned to
    std::back_insert_iterator<std::vector<int> > backInserter1 =
            std::back_insert_iterator<std::vector<int> >(numbers);

    // std::back_inserter is a convenience wrapper that constructs a
    // back_insert_iterator and automatically deduces the container type
    std::back_insert_iterator<std::vector<int> > backInserter2 =
            std::back_inserter(numbers);

    // using `auto` makes this a lot easier to type and read, just be sure to use
    // a descriptive variable name
    auto backInserter3 = std::back_inserter(numbers);

    backInserter1 = 1;
    backInserter1 = 4;

    backInserter2 = 1;
    backInserter2 = 5;

    backInserter3 = 9;
    backInserter3 = 2;

    // we can use `auto` here as well to make this nicer
    std::ostream_iterator<int> osIt = std::ostream_iterator<int>(std::cout, ", ");

    // whenever an ostream_iterator is assigned, it puts that value on the
    // stream it was constructed with (`std::cout` in this case) using the
    // stream operator (`operator<<`)
    osIt = 3;

    // the copy algorithm takes an InputIterator (read) to the beginning and end,
    // and an OutputIterator (write) to "copy" to.
    std::copy(std::cbegin(numbers), std::cend(numbers), osIt);

    std::cout << '\n';

    return 0;
}
