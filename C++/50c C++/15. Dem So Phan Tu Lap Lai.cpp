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

    const int MAXA = 1000000;
    static int freq[MAXA + 1];
    vector<int> used;
    used.reserve(1000000);

    while (T--) {
        int N;
        if (!(cin >> N))
            return 0;
        if (N < 1 || N > 1000000)
            return 0;
        used.clear();

        for (int i = 0; i < N; ++i) {
            int x;
            cin >> x;
            if (x < 1 || x > MAXA)
                continue;
            if (freq[x] == 0)
                used.push_back(x);
            ++freq[x];
        }

        long long result = 0;
        for (int x : used) {
            if (freq[x] > 1)
                result += freq[x];
            freq[x] = 0;
        }

        cout << result;
        if (T > 0)
            cout << '\n';
    }

    return 0;
}
