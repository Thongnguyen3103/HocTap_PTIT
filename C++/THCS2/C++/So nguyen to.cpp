#include <iostream>
#include <cmath>
using namespace std;

bool isPrime(long long n) {
    if (n < 2) return false;
    if (n % 2 == 0) return n == 2;
    for (long long i = 3; i * i <= n; i += 2)
        if (n % i == 0) return false;
    return true;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        long long n;
        cin >> n;
        cout << (isPrime(n) ? "YES" : "NO") << "\n";
    }
    return 0;
}
