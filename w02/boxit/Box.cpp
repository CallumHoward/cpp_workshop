// Box.cpp
// https://www.hackerrank.com/challenges/box-it/problem
// Callum Howard, 2019

#include "Box.hpp"

namespace ch {

//NOTE this operator method is scoped to the class with `Box::`
bool Box::operator<(Box& b) const {
    return (mLength < b.mLength) or
            (mBreadth < b.mBreadth and mLength == b.mLength) or
            (mHeight < b.mHeight and mLength == b.mLength and mBreadth == b.mBreadth);
}

//NOTE this operator method is not scoped to the class,
// so it is called a "free" function (not a method).
// It is still able to access the private member variables of Box
// because it is declared (above) as a "friend"
// and in C++ "friends can see each other's privates".
std::ostream& operator<<(std::ostream& out, Box& B) {
    out << B.mLength << ' ' << B.mBreadth << ' ' << B.mHeight;
    return out;
}

} // namespace ch
