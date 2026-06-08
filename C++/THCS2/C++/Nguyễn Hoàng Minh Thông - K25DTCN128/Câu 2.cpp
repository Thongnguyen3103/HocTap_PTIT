#include <iostream>
#include <climits>
using namespace std;

int main() {
    int n;
    cin >> n;
    int a[n];

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    long long sum = 0;
    int min_val = INT_MAX;
    int max_val = INT_MIN;

    for (int i = 0; i < n; i++) {
        sum += a[i];
        if (a[i] < min_val) min_val = a[i];
        if (a[i] > max_val) max_val = a[i];
    }

    cout << sum << "\n";
    cout << min_val << " " << max_val << "\n";

    return 0;
}

