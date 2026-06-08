#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        long long n;
        cin >> n;

        // Ràng buộc: n > 1 và n <= 999999
        if (n <= 1 || n > 999999) {
            cout << "Gia tri nhap khong hop le\n";
            continue;
        }

        double S = 0.0;
        for (long long i = 1; i <= n; i++) {
            S += 1.0 / (2 * i - 1);
        }

        cout << fixed << setprecision(5) << S << "\n";
    }

    return 0;
}
