#include <iostream>
#include <string>
using namespace std;

bool isNonDecreasing(const string &s) {
    for (size_t i = 0; i + 1 < s.size(); i++) {
        if (s[i] > s[i+1]) return false;
    }
    return true;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        string n;
        cin >> n;
        cout << (isNonDecreasing(n) ? "YES" : "NO") << "\n";
    }
    return 0;
}

