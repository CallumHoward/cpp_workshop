// boxit.cpp
// Callum Howard, 2019

#include <iostream>

//using namespace std;

// function prototype(s)
void check2();

class Box {
public:
    // friends
    friend std::ostream& operator<<(std::ostream& out, Box& B);

    // default constructor
    Box() : Box{0, 0, 0} {}

    // constructor using "member initialiser list"
    Box(int length, int breadth, int height) : mLength{length}, mBreadth{breadth}, mHeight{height} {}

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
};


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

void check2() {
    //NOTE this checking code is provided by HackerRank and isn't the best style
    int input;
    std::cin >> input;
    Box temp;

    for (int i = 0; i < input; ++i) {
        int type;
        std::cin >> type;

        if (type == 1) { std::cout << temp << '\n'; }

        if (type == 2) {
            int l, b, h;
            std::cin >> l >> b >> h;
            Box NewBox(l, b, h);
            temp = NewBox;
            std::cout << temp << '\n';
        }

        if (type == 3) {
            int l, b, h;
            std::cin >> l >> b >> h;
            Box NewBox(l, b, h);
            if (NewBox < temp) {
                std::cout << "Lesser\n";
            } else {
                std::cout << "Greater\n";
            }
        }

        if (type == 4) {
            std::cout << temp.CalculateVolume() << '\n';
        }

        if (type == 5) {
            Box NewBox(temp);
            std::cout << NewBox << '\n';
        }

    }
}

int main() {
    check2();
    return 0;
}