#include "WaterHeater.h"
#include <iostream>

using namespace std;

// Constructor khởi tạo bình nước nóng lạnh
WaterHeater::WaterHeater(int id, string name, float target)
    : Device(id, name), waterTemp(25.0f), targetTemp(target), isHeating(false) {}

// Hàm toggle để bật/tắt bình nóng lạnh
void WaterHeater::toggle() {
    if (isError) {
        cout << "[!] " << name << " đang báo lỗi phần cứng!" << endl;
        return;
    }
    isOn = !isOn;
    isHeating = isOn;
    if (isOn) {
        waterTemp = targetTemp; // Mô phỏng nước nóng nhanh đạt mục tiêu khi bật
        cout << "[BÌNH NÓNG LẠNH] " << name << " đã BẬT. Đang làm nóng nước." << endl;
    } else {
        cout << "[BÌNH NÓNG LẠNH] " << name << " đã TẮT." << endl;
    }
}

// In trạng thái bình nóng lạnh
void WaterHeater::getStatus() {
    cout << "[BÌNH NÓNG LẠNH] ID: " << id << " - Tên: " << name
         << " - Trạng thái: " << (isOn ? "ĐANG HOẠT ĐỘNG" : "ĐÃ TẮT")
         << " | Nhiệt độ nước: " << waterTemp << "°C"
         << " | Nhiệt độ mục tiêu: " << targetTemp << "°C"
         << " | " << (isError ? "[SỰ CỐ LỖI]" : "[ỔN ĐỊNH]") << endl;
}

// Đặt nhiệt độ đích cho nước nóng
void WaterHeater::setTargetTemp(float temp) {
    if (isError) return;
    targetTemp = temp;
    cout << "[BÌNH NÓNG LẠNH] " << name << " đặt nhiệt độ mục tiêu: " << targetTemp << "°C" << endl;
}

// Bật bình và làm nóng nước chủ động
void WaterHeater::startHeating() {
    if (isError) return;
    isOn = true;
    isHeating = true;
    waterTemp = targetTemp;
    cout << "[BÌNH NÓNG LẠNH] " << name << " đã bật chủ động, nước đang đạt " << targetTemp << "°C." << endl;
}
