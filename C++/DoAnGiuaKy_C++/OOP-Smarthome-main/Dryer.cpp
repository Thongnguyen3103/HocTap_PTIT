#include "Dryer.h"
#include <iostream>

using namespace std;

// Constructor khởi tạo máy sấy quần áo
Dryer::Dryer(int id, string name)
    : Device(id, name), dryTime(45), dryMode("Eco"), isRunning(false) {}

// Hàm toggle để bật/tắt máy sấy
void Dryer::toggle() {
    if (isError) {
        cout << "[!] " << name << " đang bị lỗi phần cứng!" << endl;
        return;
    }
    isRunning = !isRunning;
    isOn = isRunning;
    cout << "[MÁY SẤY] " << name << (isRunning ? " bắt đầu sấy quần áo." : " dừng sấy quần áo.") << endl;
}

// Hàm lấy thông tin chi tiết trạng thái máy sấy
void Dryer::getStatus() {
    cout << "[MÁY SẤY] ID: " << id << " - Tên: " << name
         << " - Trạng thái: " << (isRunning ? "Đang sấy" : "Tạm dừng/Chờ")
         << " | Chế độ: " << dryMode
         << " | Hẹn giờ: " << dryTime << " phút"
         << " | " << (isError ? "[SỰ CỐ LỖI]" : "[ỔN ĐỊNH]") << endl;
}

// Cài đặt chế độ sấy (ví dụ: Eco, Iron, Cupboard)
void Dryer::setDryMode(const string& mode) {
    if (isError) return;
    dryMode = mode;
    cout << "[MÁY SẤY] " << name << " thiết lập chế độ sấy: " << dryMode << endl;
}

// Cài đặt thời gian sấy bằng phút
void Dryer::setDryTime(int minutes) {
    if (isError) return;
    dryTime = minutes;
    cout << "[MÁY SẤY] " << name << " đặt thời gian sấy: " << dryTime << " phút" << endl;
}

// Bắt đầu sấy chủ động
void Dryer::startDry() {
    if (isError) return;
    isRunning = true;
    isOn = true;
    cout << "[MÁY SẤY] " << name << " bắt đầu sấy ở chế độ " << dryMode << " trong " << dryTime << " phút." << endl;
}
