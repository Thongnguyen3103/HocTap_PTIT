#include "WashingMachine.h"
#include <iostream>

using namespace std;

// Constructor định nghĩa máy giặt thông minh
WashingMachine::WashingMachine(int id, string name)
    : Device(id, name), washCycle("Cotton"), waterTemp(40), isRunning(false) {}

// Hàm toggle để bật/tắt hoạt động của máy giặt
void WashingMachine::toggle() {
    if (isError) {
        cout << "[!] " << name << " đang bị lỗi, không thể giặt đồ!" << endl;
        return;
    }
    isRunning = !isRunning;
    isOn = isRunning;
    cout << "[MÁY GIẶT] " << name << (isRunning ? " bắt đầu chạy chu trình giặt." : " tạm dừng chu trình giặt.") << endl;
}

// In thông tin trạng thái hoạt động của máy giặt ra màn hình
void WashingMachine::getStatus() {
    cout << "[MÁY GIẶT] ID: " << id << " - Tên: " << name
         << " - Trạng thái: " << (isRunning ? "Đang giặt" : "Tạm dừng/Chờ")
         << " | Chu trình: " << washCycle
         << " | Nhiệt độ nước: " << waterTemp << "°C"
         << " | " << (isError ? "[SỰ CỐ LỖI]" : "[ỔN ĐỊNH]") << endl;
}

// Thiết lập chu trình giặt (ví dụ: Cotton, Wool, Spin, Quick)
void WashingMachine::setCycle(const string& cycle) {
    if (isError) return;
    washCycle = cycle;
    cout << "[MÁY GIẶT] " << name << " thay đổi chu trình giặt sang: " << washCycle << endl;
}

// Thiết lập nhiệt độ nước (ví dụ: 20C, 30C, 40C, 60C)
void WashingMachine::setWaterTemp(int temp) {
    if (isError) return;
    waterTemp = temp;
    cout << "[MÁY GIẶT] " << name << " cài đặt nhiệt độ nước giặt: " << waterTemp << "°C" << endl;
}

// Bắt đầu giặt chủ động
void WashingMachine::startWash() {
    if (isError) return;
    isRunning = true;
    isOn = true;
    cout << "[MÁY GIẶT] " << name << " bắt đầu giặt đồ chủ động (" << washCycle << ", " << waterTemp << "°C)." << endl;
}
