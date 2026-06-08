#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    string s;
    cin >> s;

    while (s.length() > 1) {
        int n = s.length();
        int half = n / 2;

        string leftPart = s.substr(0, half);
        string rightPart = s.substr(half);

        string sum = "";
        int carry = 0;

        string leftRev = string(leftPart.rbegin(), leftPart.rend());
        string rightRev = string(rightPart.rbegin(), rightPart.rend());

        int maxLen = max(leftRev.size(), rightRev.size());
        for (int i = 0; i < maxLen; i++) {
            int digitLeft = i < (int)leftRev.size() ? leftRev[i] - '0' : 0;
            int digitRight = i < (int)rightRev.size() ? rightRev[i] - '0' : 0;

            int digitSum = digitLeft + digitRight + carry;
            carry = digitSum / 10;
            sum.push_back((digitSum % 10) + '0');
        }
        if (carry > 0) {
            sum.push_back(carry + '0');
        }

        reverse(sum.begin(), sum.end());
        cout << sum << endl;

        s = sum;
    }

    return 0;
}

