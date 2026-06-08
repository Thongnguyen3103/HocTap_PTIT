#include <iostream>
using namespace std;

int main() {
    int m, n;
    cin >> m >> n;
    int A[55][55];

    
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> A[i][j];
        }
    }

    int a, b;
    cin >> a >> b;
    
    a--; 
    b--;

    
    for (int j = 0; j < n; j++) {
        int tmp = A[a][j];
        A[a][j] = A[b][j];
        A[b][j] = tmp;
    }

    
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cout << A[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;
}

