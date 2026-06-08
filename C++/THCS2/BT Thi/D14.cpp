#include <bits/stdc++.h>
using namespace std;

struct ThiSinh {
    int id;
    string ten;
    string ngaysinh;
    double d1, d2, d3;
    double tong;
};

bool cmp(const ThiSinh &a, const ThiSinh &b) {
    return a.tong > b.tong;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    cin.ignore();

    vector<ThiSinh> ds;
    for (int i = 0; i < n; i++) {
        ThiSinh ts;
        ts.id = i + 1;
        getline(cin, ts.ten);
        getline(cin, ts.ngaysinh);

        cin >> ts.d1 >> ts.d2 >> ts.d3;
        cin.ignore();

        // Kiểm tra điều kiện điểm trong khoảng [0,10]
        if (ts.d1 < 0 || ts.d1 > 10 ||
            ts.d2 < 0 || ts.d2 > 10 ||
            ts.d3 < 0 || ts.d3 > 10) {
            cerr << "Loi: Diem thi phai nam trong khoang [0,10]\n";
            return 1; // kết thúc chương trình nếu dữ liệu sai
        }

        ts.tong = ts.d1 + ts.d2 + ts.d3;
        ds.push_back(ts);
    }

    stable_sort(ds.begin(), ds.end(), cmp);

    for (auto &ts : ds) {
        cout << ts.id << " "
             << ts.ten << " "
             << ts.ngaysinh << " "
             << fixed << setprecision(1) << ts.tong << "\n";
    }

    return 0;
}
