#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    if (!(cin >> T)) {
        return 0;
    }

    while (T--) {
        int n, d;
        cin >> n >> d;
        vector<int> a;
        a.reserve(n);
        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;
            a.push_back(x);
        }

        if (n > 0) {
            d %= n;
            if (d < 0) {
                d += n;
            }
            int start = d;
            for (int i = 0; i < n; i++) {
                if (i) cout << ' ';
                cout << a[(start + i) % n];
            }
        }

        if (T > 0) cout << '\n';
    }

    return 0;
}
