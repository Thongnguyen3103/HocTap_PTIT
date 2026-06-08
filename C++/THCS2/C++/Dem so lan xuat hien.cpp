#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    int a[100];
    bool visited[100] = {false}; 
    
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    for (int i = 0; i < n; i++) {
        if (!visited[i]) { 
            int count = 1;
            for (int j = i + 1; j < n; j++) {
                if (a[j] == a[i]) {
                    count++;
                    visited[j] = true; 
                }
            }
            cout << a[i] << " " << count << endl;
        }
    }

    return 0;
}
