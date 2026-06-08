#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int T;
    cin >> T;
    
    while (T--) {
        int n, m;
        cin >> n >> m;
        
        vector<int> A(n), B(m);
        
        // Đọc mảng A
        for (int i = 0; i < n; i++) {
            cin >> A[i];
        }
        
        // Đọc mảng B
        for (int i = 0; i < m; i++) {
            cin >> B[i];
        }
        
        // Tìm Union (hợp)
        vector<int> unionSet;
        int i = 0, j = 0;
        
        while (i < n && j < m) {
            if (A[i] < B[j]) {
                unionSet.push_back(A[i]);
                i++;
            } else if (A[i] > B[j]) {
                unionSet.push_back(B[j]);
                j++;
            } else {
                // A[i] == B[j], thêm một lần
                unionSet.push_back(A[i]);
                i++;
                j++;
            }
        }
        
        // Thêm các phần tử còn lại
        while (i < n) {
            unionSet.push_back(A[i]);
            i++;
        }
        while (j < m) {
            unionSet.push_back(B[j]);
            j++;
        }
        
        // Tìm Intersection (giao)
        vector<int> intersectionSet;
        i = 0;
        j = 0;
        
        while (i < n && j < m) {
            if (A[i] < B[j]) {
                i++;
            } else if (A[i] > B[j]) {
                j++;
            } else {
                // A[i] == B[j]
                intersectionSet.push_back(A[i]);
                i++;
                j++;
            }
        }
        
        // In Union
        for (int k = 0; k < (int)unionSet.size(); k++) {
            cout << unionSet[k];
            if (k < (int)unionSet.size() - 1) cout << " ";
        }
        cout << "\n";
        
        // In Intersection
        for (int k = 0; k < (int)intersectionSet.size(); k++) {
            cout << intersectionSet[k];
            if (k < (int)intersectionSet.size() - 1) cout << " ";
        }
        cout << "\n";
    }
    
    return 0;
}
