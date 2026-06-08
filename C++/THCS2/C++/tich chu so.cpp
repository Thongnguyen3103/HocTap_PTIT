#include <iostream>
using namespace std;

int main() {
    long long n;
    cin >> n;
    long long product = 1;
    while (n > 0) {
        product *= (n % 10);
        n /= 10;
    }
    cout << product;
    return 0;
}

