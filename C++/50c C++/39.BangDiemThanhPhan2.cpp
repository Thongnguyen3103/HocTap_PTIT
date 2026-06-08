#include <bits/stdc++.h>
using namespace std;

struct Student {
    string maSV;
    string hoTen;
    string lop;
    double diem1, diem2, diem3;
};

// So sánh sinh viên: sắp xếp theo Họ tên
bool compare(const Student &a, const Student &b) {
    return a.hoTen < b.hoTen;
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
        
        // Đọc Lớp
        getline(cin, students[i].lop);
        
        // Đọc Điểm 1, Điểm 2, Điểm 3
        cin >> students[i].diem1 >> students[i].diem2 >> students[i].diem3;
        cin.ignore(); // Bỏ ký tự '\n' sau điểm
    }
    
    // Sắp xếp theo Họ tên
    sort(students.begin(), students.end(), compare);
    
    // In danh sách sinh viên đã sắp xếp
    for (int i = 0; i < N; i++) {
        cout << i + 1 << " " 
             << students[i].maSV << " " 
             << students[i].hoTen << " " 
             << students[i].lop << " " 
             << fixed << setprecision(1) << students[i].diem1 << " " 
             << fixed << setprecision(1) << students[i].diem2 << " " 
             << fixed << setprecision(1) << students[i].diem3 << "\n";
    }
    
    return 0;
}
