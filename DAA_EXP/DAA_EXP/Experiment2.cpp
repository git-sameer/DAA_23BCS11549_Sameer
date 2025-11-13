// Power function in O(logn) time complexity

#include <iostream>
using namespace std;

int power(int x, int y) {
    int result = 1;
    
    while (y > 0) {
        if (y % 2 == 1) {
            result *= x;
        }
        x = x * x;   // square base
        y = y / 2;   // halve exponent
    }
    
    return result;
}

int main() {
    int base, exponent, ans;

    cout << "Enter Base value: ";
    cin >> base;
    cout << "Enter Exponent value: ";
    cin >> exponent;

    ans = power(base, exponent);

    cout << "Result (base^exponent): " << ans << endl;

    return 0;
}
