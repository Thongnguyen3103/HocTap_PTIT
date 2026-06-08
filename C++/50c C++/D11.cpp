#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

int main() {
    // Tăng tốc nhập xuất
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;              // số lượng test
    cin >> T;

    vector<int> a(T);   // lưu các giá trị n
    int maxN = 0;       // lưu n lớn nhất

    // Nhập từng test
    for (int i = 0; i < T; i++) {
        cin >> a[i];

        // Kiểm tra điều kiện của đề
        if (a[i] < 2 || a[i] > 1000000) {
            cout << "Gia tri n khong hop le\n";
            return 0;   // dừng chương trình nếu sai
        }

        // Cập nhật giá trị lớn nhất
        if (a[i] > maxN) {
            maxN = a[i];
        }
    }

    // sum[i] sẽ lưu S(i) = 1 + 1/2 + ... + 1/i
    vector<double> sum(maxN + 1, 0.0);

    // Tiền xử lý các tổng từ 1 đến maxN
    for (int i = 1; i <= maxN; i++) {
        sum[i] = sum[i - 1] + 1.0 / i;
    }

    // In kết quả cho từng test
    for (int i = 0; i < T; i++) {
        cout << fixed << setprecision(5) << sum[a[i]] << '\n';
    }

    return 0;
}