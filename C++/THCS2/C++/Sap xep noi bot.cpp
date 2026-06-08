#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    int a[105];
    for (int i = 0; i < n; i++) cin >> a[i];

    int step = 1;
    for (int i = 0; i < n - 1; i++) {
        bool swapped = false;
        for (int j = 0; j < n - i - 1; j++) {
            if (a[j] > a[j + 1]) {
                int tmp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = tmp;
                swapped = true;
            }
        }
        if (swapped) {
            cout << "Buoc " << step << ": ";
            for (int k = 0; k < n; k++) cout << a[k] << " ";
            cout << endl;
            step++;
        } else {
            break; 
        }
    }

    return 0;
}

