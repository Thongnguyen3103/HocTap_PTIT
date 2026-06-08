#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    ifstream fin("VANBAN.in");
    
    // Dùng set<string> để tự động:
    // 1. Loại bỏ các từ trùng lặp
    // 2. Sắp xếp các từ theo thứ tự từ điển
    set<string> words;
    
    string word = "";
    char c;
    
    // Đọc file ký tự từng ký tự
    while (fin.get(c)) {
        // Nếu gặp khoảng trắng, tab, hoặc newline -> từ kết thúc
        if (c == ' ' || c == '\t' || c == '\n') {
            // Thêm từ vào set nếu không rỗng
            if (!word.empty()) {
                words.insert(word);
                word = "";
            }
        } else {
            // Thêm ký tự vào từ hiện tại
            word += c;
        }
    }
    
    // Xử lý từ cuối cùng (nếu file không kết thúc bằng khoảng trắng)
    if (!word.empty()) {
        words.insert(word);
    }
    
    fin.close();
    
    // In danh sách các từ khác nhau (đã sắp xếp theo thứ tự từ điển)
    for (const string& w : words) {
        cout << w << "\n";
    }
    
    return 0;
}
