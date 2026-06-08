#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int T;
    cin >> T;
    
    while (T--) {
        string S;
        cin >> S;
        
        // Dùng stack (hoặc string) để loại bỏ "100"
        string result = "";
        
        for (int i = 0; i < (int)S.length(); i++) {
            // Thêm ký tự vào result
            result += S[i];
            
            // Kiểm tra liên tục xem 3 ký tự cuối có phải "100" không
            // Nếu có, loại bỏ và kiểm tra lại (để xử lý trường hợp "100" mới tạo ra)
            while (result.length() >= 3) {
                int n = result.length();
                if (result[n-3] == '1' && result[n-2] == '0' && result[n-1] == '0') {
                    // Loại bỏ 3 ký tự cuối ("100")
                    result.erase(n-3, 3);
                } else {
                    // Nếu không tìm thấy "100", dừng kiểm tra
                    break;
                }
            }
        }
        
        // Nếu kết quả trống, in 0; ngược lại in độ dài kết quả
        cout << result.length() << "\n";
    }
    
    return 0;
}
