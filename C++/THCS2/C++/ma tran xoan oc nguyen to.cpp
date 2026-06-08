#include <iostream>
#include <vector>
#include <cmath>
using namespace std;


bool isPrime(int n) {
    if (n < 2) return false;
    if (n == 2 || n == 3) return true;
    if (n % 2 == 0) return false;
    for (int i = 3; i <= (int)sqrt(n); i += 2) {
        if (n % i == 0) return false;
    }
    return true;
}


vector<int> generatePrimes(int limit) {
    vector<int> primes;
    int num = 2;
    while ((int)primes.size() < limit) {
        if (isPrime(num)) primes.push_back(num);
        num++;
    }
    return primes;
}

int main() {
    int t;
    cin >> t;
    for (int tc = 1; tc <= t; tc++) {
        int n;
        cin >> n;

        int total = n * n;
        vector<int> primes = generatePrimes(total);

        vector<vector<int> > a(n, vector<int>(n, 0));  

        int top = 0, bottom = n - 1, left = 0, right = n - 1;
        int idx = 0;

        while (top <= bottom && left <= right) {
       
            for (int j = left; j <= right; j++) a[top][j] = primes[idx++];
            top++;
          
            for (int i = top; i <= bottom; i++) a[i][right] = primes[idx++];
            right--;
         
            if (top <= bottom) {
                for (int j = right; j >= left; j--) a[bottom][j] = primes[idx++];
                bottom--;
            }
          
            if (left <= right) {
                for (int i = bottom; i >= top; i--) a[i][left] = primes[idx++];
                left++;
            }
        }

      
        cout << "Test " << tc << ":\n";
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cout << a[i][j] << " ";
            }
            cout << "\n";
        }
    }
    return 0;
}

