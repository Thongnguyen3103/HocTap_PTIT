#include <iostream>
#include <string>
using namespace std;

bool isPalindrome(const string &s) {
    int l = 0, r = s.size() - 1;
    while (l < r) {
        if (s[l] != s[r]) return false;
        l++; r--;
    }
    return true;
}

int main() {
    int t;
    cin >> t;
    cin.ignore(); 

    while (t--) {
        string n;
        cin >> n;

        bool ok = true;

        if (!isPalindrome(n)) ok = false;

        if (n[0] != '8' || n[n.size()-1] != '8') ok = false;

        int sum = 0;
        for (size_t i = 0; i < n.size(); i++) {
            sum += (n[i] - '0');
        }
        if (sum % 10 != 0) ok = false;

        cout << (ok ? "YES" : "NO") << endl;
    }

    return 0;
}

