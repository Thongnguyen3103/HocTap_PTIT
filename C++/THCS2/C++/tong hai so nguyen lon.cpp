#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string addBig(string a, string b) {
    while (a.size() < b.size()) a = "0" + a;
    while (b.size() < a.size()) b = "0" + b;

    int carry = 0;
    string res = "";
    for (int i = (int)a.size()-1; i >= 0; i--) {
        int x = (a[i]-'0') + (b[i]-'0') + carry;
        res += char(x%10 + '0');
        carry = x/10;
    }
    if (carry) res += char(carry+'0');
    reverse(res.begin(), res.end());
    return res;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        string a, b;
        cin >> a >> b;
        cout << addBig(a,b) << "\n";
    }
    return 0;
}

