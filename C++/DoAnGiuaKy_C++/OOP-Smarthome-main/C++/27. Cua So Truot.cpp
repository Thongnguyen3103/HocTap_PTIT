#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N;
    cin >> N;
    
    // Đọc ma trận A (N x N)
    vector<vector<int>> A(N, vector<int>(N));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> A[i][j];
        }
    }
    
    int M;
    cin >> M;
    
    // Đọc ma trận B (M x M) - cửa sổ trượt
    vector<vector<int>> B(M, vector<int>(M));
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < M; j++) {
            cin >> B[i][j];
        }
    }
    
    // Ma trận kết quả (cùng kích thước với A)
    vector<vector<int>> result(N, vector<int>(N));
    
    // Áp dụng cửa sổ trượt B lên ma trận A
    // result[i][j] = A[i][j] * B[i % M][j % M]
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            result[i][j] = A[i][j] * B[i % M][j % M];
        }
    }
    
    // In kết quả
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << result[i][j];
            if (j < N - 1) cout << " ";
        }
        cout << "\n";
    }
    
    return 0;
}
