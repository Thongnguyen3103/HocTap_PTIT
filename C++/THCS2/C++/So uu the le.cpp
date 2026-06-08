#include <iostream>
#include <string>
using namespace std;

bool isOddDominant(string num) {
    int oddCount = 0, evenCount = 0;

    for (int i = 0; i < num.size(); i++) {
        int d = num[i] - '0';
        if (d % 2 == 0) evenCount++;
        else oddCount++;
    }

    int lastDigit = num[num.size() - 1] - '0';
    if (lastDigit % 2 == 1 && oddCount > evenCount)
        return true;
    return false;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        string n;
        cin >> n;
        if (isOddDominant(n)) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}
