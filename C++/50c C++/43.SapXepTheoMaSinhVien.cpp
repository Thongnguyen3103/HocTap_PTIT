#include <bits/stdc++.h>
using namespace std;

struct Student {
    string maSV;
    string hoTen;
    string lop;
    string email;
};

// So sánh sinh viên: sắp xếp theo Mã SV tăng dần (thứ tự từ điển)
bool compare(const Student &a, const Student &b) {
    return a.maSV < b.maSV;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    vector<Student> students;
    string maSV;
    
    // Đọc sinh viên cho đến khi hết dữ liệu (không quá 1000)
    while (getline(cin, maSV)) {
        Student sv;
        sv.maSV = maSV;
        
        // Đọc Họ tên
        getline(cin, sv.hoTen);
        
        // Đọc Lớp
        getline(cin, sv.lop);
        
        // Đọc Email
        getline(cin, sv.email);
        
        students.push_back(sv);
    }
    
    // Sắp xếp theo Mã SV tăng dần
    sort(students.begin(), students.end(), compare);
    
    // In danh sách sinh viên đã sắp xếp
    for (int i = 0; i < (int)students.size(); i++) {
        cout << students[i].maSV << " " 
             << students[i].hoTen << " " 
             << students[i].lop << " " 
             << students[i].email << "\n";
    }
    
    return 0;
}
