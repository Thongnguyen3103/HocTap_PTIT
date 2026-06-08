#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    if (!(cin >> T))
        return 0;
    if (T < 1 || T > 100)
        return 0;

    while (T--) {
        long long n;
        cin >> n;
        if (n < 1 || n > 10000000)
            return 0;

        bool seen[10] = {false};
        string token;

        for (long long i = 0; i < n; ++i) {
            cin >> token;
            if (token.empty()) {
                --i;
                continue;
            }
            for (char c : token) {
                if (c >= '0' && c <= '9')
                    seen[c - '0'] = true;
            }
        }

        bool first = true;
        for (int d = 0; d < 10; ++d) {
            if (seen[d]) {
                if (!first) cout << ' ';
                cout << d;
                first = false;
            }
        }
        if (T > 0)
            cout << '\n';
    }

    return 0;
}
