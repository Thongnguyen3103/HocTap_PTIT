#include <iostream>
using namespace std;

int main() {
    int N, M; 
    cin >> N >> M;   

    int a[10][10];  
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> a[i][j];
        }
    }

    for (int j = 0; j < M; j++) {
        for (int i = 0; i < N; i++) {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}

