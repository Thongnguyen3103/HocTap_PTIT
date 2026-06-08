#include <iostream>
using namespace std;

int main() {
    int T;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        int n, m;
        cin >> n >> m;
        int A[55][55];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> A[i][j];
            }
        }

        
        long long C[55][55];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                long long sum = 0;
                for (int k = 0; k < m; k++) {
                    sum += 1LL * A[i][k] * A[j][k];
                }
                C[i][j] = sum;
            }
        }

        cout << "Test " << t << ":\n";
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cout << C[i][j] << " ";
            }
            cout << "\n";
        }
    }
    return 0;
}

