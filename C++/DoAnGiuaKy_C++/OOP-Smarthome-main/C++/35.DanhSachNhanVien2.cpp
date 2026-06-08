#include <bits/stdc++.h>
using namespace std;

struct Student {
    string maSV;
    string hoTen;
    string lop;
    string ngaySinh;
    double diemGPA;
};

// So sánh sinh viên: sắp xếp theo Mã SV
bool compare(const Student &a, const Student &b) {
    return a.maSV < b.maSV;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N;
    cin >> N;
    cin.ignore(); // Bỏ ký tự '\n' sau N
    
    vector<Student> students(N);
    
    for (int i = 0; i < N; i++) {
        // Đọc Mã SV
        getline(cin, students[i].maSV);
        
        // Đọc Họ tên
        getline(cin, students[i].hoTen);
        
        if (students[i].hoTen.length() > 30) {
            students[i].hoTen = students[i].hoTen.substr(0, 30);
        }
        
        // Đọc Lớp
        getline(cin, students[i].lop);
        
        // Đọc Ngày sinh
        getline(cin, students[i].ngaySinh);
        
        // Đọc Điểm GPA
        cin >> students[i].diemGPA;
        cin.ignore();
    }
    
    // Sắp xếp theo Mã SV
    sort(students.begin(), students.end(), compare);
    
    // In danh sách sinh viên
    for (int i = 0; i < N; i++) {
        cout << students[i].maSV << " " 
             << students[i].hoTen << " " 
             << students[i].lop << " " 
             << students[i].ngaySinh << " " 
             << fixed << setprecision(2) << students[i].diemGPA << "\n";
    }
    
    return 0;
}
