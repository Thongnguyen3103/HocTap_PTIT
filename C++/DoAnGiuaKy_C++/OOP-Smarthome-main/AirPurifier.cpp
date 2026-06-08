#include "AirPurifier.h"
#include <iostream>

using namespace std;

// Constructor khởi tạo máy lọc không khí
AirPurifier::AirPurifier(int id, string name)
    : Device(id, name), fanSpeed(1), aqiLevel(45), filterLife(98) {}

// Hàm toggle để bật/tắt máy lọc không khí
void AirPurifier::toggle() {
    if (isError) {
        cout << "[!] " << name << " gặp sự cố, không thể lọc không khí!" << endl;
        return;
    }
    isOn = !isOn;
    if (isOn) {
        cout << "[MÁY LỌC] " << name << " đã được BẬT." << endl;
    } else {
        cout << "[MÁY LỌC] " << name << " đã được TẮT." << endl;
    }
}

// In trạng thái hoạt động của máy lọc không khí
void AirPurifier::getStatus() {
    cout << "[MÁY LỌC] ID: " << id << " - Tên: " << name
         << " - Trạng thái: " << (isOn ? "BẬT (Đang lọc)" : "TẮT")
         << " | Tốc độ quạt: " << fanSpeed
         << " | Chất lượng AQI: " << aqiLevel << " (PM2.5)"
         << " | Tuổi thọ màng lọc: " << filterLife << "%"
         << " | " << (isError ? "[SỰ CỐ LỖI]" : "[ỔN ĐỊNH]") << endl;
}

// Đặt tốc độ quạt lọc gió
void AirPurifier::setFanSpeed(int speed) {
    if (!isOn || isError) return;
    fanSpeed = speed;
    if (fanSpeed < 1) fanSpeed = 1;
    if (fanSpeed > 3) fanSpeed = 3;
    cout << "[MÁY LỌC] " << name << " đặt tốc độ quạt lọc gió về: " << fanSpeed << endl;
}

// Cập nhật chỉ số AQI
void AirPurifier::updateAQI(int aqi) {
    aqiLevel = aqi;
    cout << "[MÁY LỌC] " << name << " nhận tín hiệu cảm biến: AQI đạt mức " << aqiLevel << endl;
    
    // Nếu chỉ số bụi quá cao, tự động tăng tốc độ lọc
    if (isOn && aqiLevel > 100) {
        fanSpeed = 3;
        cout << "[CẢNH BÁO BỤI MỊN] " << name << " tự động tăng tốc độ lọc quạt lên 3!" << endl;
    }
}
