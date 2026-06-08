#include <iostream>
#include <vector>
#include <cmath>
using namespace std;


bool isPrime(int n) {
    if (n < 2) return false;
    if (n == 2) return true;
    if (n % 2 == 0) return false;
    for (int i = 3; i <= sqrt(n); i += 2) {
        if (n % i == 0) return false;
    }
    return true;
}

int main() {
    int t;
    cin >> t; 
    while (t--) {
        int N;
        cin >> N; 
        vector<int> arr(N);
        for (int i = 0; i < N; i++) {
            cin >> arr[i];
        }
        
        for (int i = 0; i < N; i++) {
            if (isPrime(arr[i])) {
                cout << arr[i] << " ";
            }
        }
        cout << endl;
    }
    return 0;
}
