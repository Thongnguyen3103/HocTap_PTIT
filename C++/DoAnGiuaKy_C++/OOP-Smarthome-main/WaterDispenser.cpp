#include "WaterDispenser.h"
#include <iostream>

using namespace std;

// Constructor khởi tạo máy lọc nước nóng lạnh
WaterDispenser::WaterDispenser(int id, string name)
    : Device(id, name), hotWaterTemp(85.0f), coldWaterTemp(8.0f), uvSterilizing(true) {
    isOn = true; // Máy lọc nước mặc định cắm điện hoạt động liên tục
}

// Bật/Tắt nguồn máy lọc nước nóng lạnh
void WaterDispenser::toggle() {
    if (isError) {
        cout << "[!] " << name << " đang lỗi hệ thống lọc, ngừng cấp nước!" << endl;
        return;
    }
    isOn = !isOn;
    cout << "[MÁY NƯỚC] " << name << (isOn ? " đã BẬT nguồn hoạt động." : " đã TẮT nguồn.") << endl;
}

// In trạng thái hoạt động máy lọc nước
void WaterDispenser::getStatus() {
    cout << "[MÁY NƯỚC] ID: " << id << " - Tên: " << name
         << " - Trạng thái: " << (isOn ? "ĐANG ĐIỆN" : "ĐÃ NGẮT ĐIỆN")
         << " | Ngăn nóng: " << hotWaterTemp << "°C"
         << " | Ngăn lạnh: " << coldWaterTemp << "°C"
         << " | Diệt khuẩn UV: " << (uvSterilizing ? "BẬT" : "TẮT")
         << " | " << (isError ? "[SỰ CỐ LỖI]" : "[ỔN ĐỊNH]") << endl;
}

// Thiết lập nhiệt độ bên ngăn nước nóng
void WaterDispenser::setHotTemp(float temp) {
    if (!isOn || isError) return;
    hotWaterTemp = temp;
    if (hotWaterTemp < 40.0f) hotWaterTemp = 40.0f;
    if (hotWaterTemp > 95.0f) hotWaterTemp = 95.0f;
    cout << "[MÁY NƯỚC] " << name << " đặt nhiệt độ ngăn nước nóng: " << hotWaterTemp << "°C" << endl;
}

// Thiết lập nhiệt độ bên ngăn nước lạnh
void WaterDispenser::setColdTemp(float temp) {
    if (!isOn || isError) return;
    coldWaterTemp = temp;
    if (coldWaterTemp < 4.0f) coldWaterTemp = 4.0f;
    if (coldWaterTemp > 15.0f) coldWaterTemp = 15.0f;
    cout << "[MÁY NƯỚC] " << name << " đặt nhiệt độ ngăn nước lạnh: " << coldWaterTemp << "°C" << endl;
}

// Bật/Tắt đèn khử trùng UV trong bình lọc nước
void WaterDispenser::toggleUV(bool active) {
    if (!isOn || isError) return;
    uvSterilizing = active;
    cout << "[MÁY NƯỚC] " << name << " đã " << (uvSterilizing ? "BẬT" : "TẮT") << " hệ thống diệt khuẩn UV tự động." << endl;
}
