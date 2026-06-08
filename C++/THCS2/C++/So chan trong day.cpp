#include <iostream>
using namespace std;

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N;
        cin >> N;
        int a[105];
        for (int i = 0; i < N; i++) {
            cin >> a[i];
        }
        // In các s? ch?n
        for (int i = 0; i < N; i++) {
            if (a[i] % 2 == 0) {
                cout << a[i] << " ";
            }
        }
        cout << endl;
    }
    return 0;
}
