#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    int a[105];
    for (int i = 0; i < n; i++) cin >> a[i];

    for (int i = 0; i < n - 1; i++) {
        int min = a[i];
        int pos = i;

        // tìm ph?n t? nh? nh?t trong do?n [i+1..n-1]
        for (int k = i + 1; k < n; k++) {
            if (a[k] < min) {
                min = a[k];
                pos = k;
            }
        }

        // n?u tìm th?y nh? hon thì d?i ch?
        if (pos != i) {
            a[pos] = a[i];
            a[i] = min;
        }

        // in ra bu?c i+1
        cout << "Buoc " << i + 1 << ": ";
        for (int inra = 0; inra < n; inra++) {
            cout << a[inra];
            if (inra < n - 1) cout << " ";
        }
        cout << endl;
    }

    return 0;
}

