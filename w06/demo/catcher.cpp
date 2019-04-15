#include <iostream>
#include <csignal>

[[noreturn]] void catcher(int a);
void printme(int a);

int main() {
    void (* fptr)(int) = printme;
    fptr(3);

    //void (* fptrr)(int) = &printme;
    //(*fptrr)(10);

    // store callback function
    //void (*CBFunction)(int) = catcher;

    // Will call whatever CBFunction is when you press ctrl+c
    std::signal(SIGINT, catcher); // create a callback

    while(true) { // infinite loop

    }

    return 0;
}

//sigfpe occurs when you tried to divide by zero or numeric overflow
void catcher(int a) {

    std::cout << "Caught!\n" << '\n';

    //do some more handling
    exit(0);
}

void printme(int a) {
    std::cout << "You passed: " << a << '\n';
}

