// hello.hpp
// Callum Howard, 2019

#define GREETING "Hello World from macro\n"

//#define DEBUG

// function prototype
void foo();

// function definition
void foo() {
    std::cout << "I am a function defined in the header file\n";

#ifdef DEBUG
    std::cout << "Doing some debug logging!" << '\n';
#else
    std::cout << "Release version!" << '\n';
#endif
}
