#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <limits>
using namespace std;

struct ThiSinh {
    int id;
    string ten, ns;
    double d1, d2, d3, tong;
};

struct CmpTongGiam {
    bool operator()(const ThiSinh &a, const ThiSinh &b) const {
        return a.tong > b.tong;
    }
};

int main() {
    int n;
    if (!(cin >> n)) return 0;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    vector<ThiSinh> a;
    a.reserve(n);

    for (int i = 0; i < n; ++i) {
        ThiSinh ts;
        ts.id = i + 1;
        getline(cin, ts.ten);
        getline(cin, ts.ns);
        cin >> ts.d1 >> ts.d2 >> ts.d3;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        ts.tong = ts.d1 + ts.d2 + ts.d3;
        a.push_back(ts);
    }

    stable_sort(a.begin(), a.end(), CmpTongGiam());

    cout.setf(ios::fixed);
    cout << setprecision(1);
    for (size_t i = 0; i < a.size(); ++i) {
        cout << a[i].id << " " << a[i].ten << " " << a[i].ns << " " << a[i].tong << "\n";
    }
    return 0;
}

