#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    int a[100];

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    for (int i = n - 1; i >= 0; i--) {
        cout << a[i];
        if (i > 0) cout << " ";
    }
    cout << "\n";

    int count_even = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] % 2 == 0) {
            count_even++;
        }
    }

    cout << count_even << "\n";

    return 0;
}

