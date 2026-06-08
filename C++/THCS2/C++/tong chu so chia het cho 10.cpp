#include <iostream>
#include <string>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        string n;
        cin >> n;
        int sum = 0;
        for (int i = 0; i < (int)n.size(); i++) {
            sum += n[i] - '0';
        }
        if (sum % 10 == 0) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}
