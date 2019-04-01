// Box.hpp
// https://www.hackerrank.com/challenges/box-it/problem
// Callum Howard, 2019

#ifndef BOX_HPP
#define BOX_HPP

#include <iostream>

namespace ch {

class Box {
public:
    // friends
    friend std::ostream& operator<<(std::ostream& out, Box& B);

    // default constructor
    Box() : Box{0, 0, 0} {}

    // constructor using "member initialiser list"
    Box(int length, int breadth, int height) :
            mLength{length}, mBreadth{breadth}, mHeight{height} {}

    //NOTE We use curly braces to initialise the variables.
    // Round braces would also work but in some situations
    // they are subject to the "Most Vexing Parse", meaning
    // they could be mistaken for function calls.  More info here:
    // https://www.fluentcpp.com/2018/01/30/most-vexing-parse/

    //TODO copy constructor (see "Rule of Five")
    //Box(const Box& b) : Box{b.mLength, b.mBreadth, b.mHeight} {}

    //NOTE Functions with trivial implementation (like getters and setters, or one line functions)
    // can be implemented "inline" along with the declaration here inside the class.

    // return box's length
    int getLength() const { return mLength; }

    // return box's breadth
    int getBreadth() const { return mBreadth; }

    // return box's height
    int getHeight() const { return mHeight; }

    // return the volume of the box
    long long CalculateVolume() const {
        return mLength * mBreadth * mHeight;
    }

    //NOTE the const here after the method name means:
    // "this method has read-only access to the member variables".

    bool operator<(Box& b) const;  // the method "declared" here is "defined" outside the class body

private:
    int mLength = 0;
    int mBreadth = 0;
    int mHeight = 0;

}; // class Box

} // namespace ch

#endif
