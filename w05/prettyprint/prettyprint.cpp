// prettyprint.cpp
// Callum Howard, 2019

#include <iostream>
#include <iomanip> 
using namespace std;

int main() {
    int T; cin >> T;
    cout << setiosflags(ios::uppercase);
    cout << setw(0xf) << internal;
    while(T--) {
        double A; cin >> A;
        double B; cin >> B;
        double C; cin >> C;

        std::cout
                << setw(0)
                << std::hex
                << std::showbase
                << std::nouppercase
                << std::left
                << static_cast<long long>(A)
                << std::endl;

        std::cout
                << std::setw(15)
                << std::fixed
                << std::setfill('_')
                << std::right
                << std::showpos
                << std::setprecision(2)
                << B
                << std::endl;

        std::cout
                << std::noshowpos
                << std::scientific
                << std::uppercase
                << std::setprecision(9)
                << C
                << std::endl;

    }
    return 0;

}
