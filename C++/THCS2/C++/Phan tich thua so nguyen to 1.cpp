#include <iostream>
using namespace std;

void factorize(long long n) {
    for (long long i = 2; i * i <= n; i++) {
        while (n % i == 0) {
            cout << i << " ";
            n /= i;
        }
    }
    if (n > 1) cout << n; 
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        long long n;
        cin >> n;
        factorize(n);
        cout << "\n";
    }
    return 0;
}

