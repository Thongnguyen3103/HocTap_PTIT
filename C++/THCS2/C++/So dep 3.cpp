#include <iostream>
#include <string>
using namespace std;

bool isPrimeDigit(char c) {
    return c == '2' || c == '3' || c == '5' || c == '7';
}

bool isPalindrome(const string& s) {
    int n = s.length();
    for (int i = 0; i < n / 2; i++) {
        if (s[i] != s[n - 1 - i])
            return false;
    }
    return true;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        string s;
        cin >> s;

        bool palindrome = isPalindrome(s);
        bool allPrimeDigits = true;

       for (size_t i = 0; i < s.size(); i++) {
    char c = s[i];
            if (!isPrimeDigit(c)) {
                allPrimeDigits = false;
                break;
            }
        }

        if (palindrome && allPrimeDigits) cout << "YES\n";
        else cout << "NO\n";
    }

    return 0;
}

