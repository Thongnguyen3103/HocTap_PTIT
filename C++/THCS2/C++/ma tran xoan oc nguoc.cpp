#include <iostream>
using namespace std;

int main() {
    int t, n;
    cin >> t;   
    for (int tc = 1; tc <= t; tc++) {
        cin >> n;
        int a[25][25];  

        int top = 0, bottom = n - 1, left = 0, right = n - 1;
        int num = n * n;

        while (top <= bottom && left <= right) {
           
            for (int i = left; i <= right; i++) a[top][i] = num--;
            top++;

          
            for (int i = top; i <= bottom; i++) a[i][right] = num--;
            right--;

          
            if (top <= bottom) {
                for (int i = right; i >= left; i--) a[bottom][i] = num--;
                bottom--;
            }

            
            if (left <= right) {
                for (int i = bottom; i >= top; i--) a[i][left] = num--;
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

