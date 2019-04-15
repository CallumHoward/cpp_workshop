// preprocessor.cpp
// Callum Howard, 2019

#define INF 10000000
#define foreach(v, i) for (int i = 0; i < static_cast<int>(v.size()); ++i)
#define FUNCTION(func, op) inline void func(int& a, int b) { a = a op b ? a : b; }
#define io(v) std::cin >> v
#define toStr(input) #input

#include <iostream>
#include <vector>
using namespace std;

#if !defined toStr || !defined io || !defined FUNCTION || !defined INF
#error Missing preprocessor definitions
#endif

FUNCTION(minimum, <)
FUNCTION(maximum, >)

int main(){
    int n; cin >> n;
    vector<int> v(n);
    foreach(v, i) {
        io(v)[i];
    }
    int mn = INF;
    int mx = -INF;
    foreach(v, i) {
        minimum(mn, v[i]);
        maximum(mx, v[i]);
    }
    int ans = mx - mn;
    cout << toStr(Result =) <<' '<< ans;
    return 0;

}
