// hello.hpp
// Callum Howard, 2019

#define GREETING "Hello World from macro\n"

// function prototype
void foo();

// function definition
void foo() {
    std::cout << "I am a function defined in the header file\n";
}
