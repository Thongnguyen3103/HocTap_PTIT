#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
using namespace std;

struct ThiSinh {
    int id;
    string ten;
    string ns;
    double d1, d2, d3;
    double tong;
};

int main() {
    int n;
    cin >> n;
    cin.ignore();
    vector<ThiSinh> ds(n);
    for (int i = 0; i < n; i++) {
        ds[i].id = i + 1;
        getline(cin, ds[i].ten);
        getline(cin, ds[i].ns);
        cin >> ds[i].d1 >> ds[i].d2 >> ds[i].d3;
        cin.ignore();
        ds[i].tong = ds[i].d1 + ds[i].d2 + ds[i].d3;
    }

    double maxTong = ds[0].tong;
    for (int i = 1; i < n; i++) {
        if (ds[i].tong > maxTong) maxTong = ds[i].tong;
    }

    for (int i = 0; i < n; i++) {
        if (ds[i].tong == maxTong) {
            cout << ds[i].id << " " << ds[i].ten << " " << ds[i].ns 
                 << " " << fixed << setprecision(1) << ds[i].tong << endl;
        }
    }

    return 0;
}

