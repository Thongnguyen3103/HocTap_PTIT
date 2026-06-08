#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n; 
    int A[100];
    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }
    int k;
    cin >> k; 
    k = k % n;
    for (int i = 0; i < n; i++) {
        cout << A[(i + k) % n] << " ";
    }

    return 0;
}
