#include <iostream>
using namespace std;

int main() {
    long long n;
    cin >> n;

    long long abs_n = (n < 0) ? -n : n;

    cout << abs_n << "\n";

    if (n % 2 == 0) {
        cout << "EVEN" << "\n";
    } else {
        cout << "ODD" << "\n";
    }

    long long sum_digits = 0;
    long long temp = abs_n;
    while (temp > 0) {
        sum_digits += temp % 10;
        temp /= 10;
    }

    cout << sum_digits << "\n";

    return 0;
}

