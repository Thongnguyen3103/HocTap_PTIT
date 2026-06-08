#include "SmartTV.h"
#include <iostream>

using namespace std;

// Constructor khởi tạo SmartTV
SmartTV::SmartTV(int id, string name)
    : Device(id, name), channel(1), volume(20), inputSource("HDMI1") {}

// Hàm toggle để bật/tắt Tivi
void SmartTV::toggle() {
    if (isError) {
        cout << "[!] " << name << " gặp sự cố, không thể bật tivi!" << endl;
        return;
    }
    isOn = !isOn;
    cout << "[TIVI] " << name << (isOn ? " đã BẬT." : " đã TẮT.") << endl;
}

// In trạng thái tivi
void SmartTV::getStatus() {
    cout << "[TIVI] ID: " << id << " - Tên: " << name
         << " - Trạng thái: " << (isOn ? "BẬT" : "TẮT")
         << " | Kênh: " << channel
         << " | Âm lượng: " << volume
         << " | Nguồn vào: " << inputSource
         << " | " << (isError ? "[SỰ CỐ LỖI]" : "[ỔN ĐỊNH]") << endl;
}

// Chuyển kênh tivi
void SmartTV::setChannel(int ch) {
    if (!isOn || isError) return;
    channel = ch;
    cout << "[TIVI] " << name << " chuyển sang Kênh: " << channel << endl;
}

// Điều chỉnh âm lượng tivi
void SmartTV::setVolume(int vol) {
    if (!isOn || isError) return;
    volume = vol;
    cout << "[TIVI] " << name << " điều chỉnh âm lượng: " << volume << "%" << endl;
}

// Đổi cổng kết nối / ứng dụng đầu vào
void SmartTV::setInputSource(const string& source) {
    if (!isOn || isError) return;
    inputSource = source;
    cout << "[TIVI] " << name << " chuyển chế độ sang: " << inputSource << endl;
}
