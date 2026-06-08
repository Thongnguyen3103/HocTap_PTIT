#include <iostream>
using namespace std;

int main() {
    int N;
    cin >> N;
    int a[100];
    for (int i = 0; i < N; i++) {
        cin >> a[i];
    }

    for (int i = 0; i < N - 1; i++) {
        int min_idx = i;
        for (int j = i + 1; j < N; j++) {
            if (a[j] < a[min_idx]) {
                min_idx = j;
            }
        }
        if (min_idx != i) {
            swap(a[i], a[min_idx]);
        }
        
       
        cout << "Buoc " << i + 1 << ": ";
        for (int k = 0; k < N; k++) {
            cout << a[k];
            if (k != N - 1) cout << " ";
        }
        cout << "\n";
    }

    return 0;
}

