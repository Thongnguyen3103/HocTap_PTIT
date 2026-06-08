#include <iostream>
using namespace std;

int main() {
    int T;
    cin >> T;

    if (T < 1 || T > 100) return 0;

    while (T--) {
        long long N;
        cin >> N;

        if (N < 2 || N > 10000000000LL) {
            cout << "Gia tri N khong hop le";
            if (T) cout << endl;
            continue;
        }

        bool first = true;

        for (long long i = 2; i * i <= N; i++) {
            while (N % i == 0) {
                if (!first) cout << " ";
                cout << i;
                first = false;
                N /= i;
            }
        }

        if (N > 1) {
            if (!first) cout << " ";
            cout << N;
        }

        if (T) cout << endl;
    }

    return 0;
}