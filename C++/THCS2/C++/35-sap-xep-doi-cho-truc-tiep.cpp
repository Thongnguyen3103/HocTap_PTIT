#include <iostream>
using namespace std;

int main() {
    int n;
    int a[105];
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];

    int step = 1;
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (a[i] > a[j]) {
 
                int temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }

        cout << "Buoc " << step++ << ": ";
        for (int k = 0; k < n; k++) cout << a[k] << " ";
        cout << endl;
    }

    return 0;
}

