#include <iostream>

using namespace std;

// Time
double myPow(int x, int n) {
    if (n == 0) return 1;
    int binForm = n;
    double ans = 1;
    if (n < 0) {
        x = (1/x);
        binForm *= -1;
    }
    while (binForm > 0) {
        if (binForm % 2 == 1) ans *= x;
        x *= x;
        binForm /= 2;
    }
    return ans;
}

int main() {
    int x = 2.00000;
    int n = 10;
    cout << x << "^" << n << ": " << myPow(x, n) << "\n";
    return 0;
}