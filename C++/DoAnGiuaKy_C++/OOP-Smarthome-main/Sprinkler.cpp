#include "Sprinkler.h"
#include <iostream>

using namespace std;

// Constructor khởi tạo vòi tưới cây
Sprinkler::Sprinkler(int id, string name)
    : Device(id, name), waterFlow(0), durationMinutes(0), isWatering(false) {}

// Hàm toggle để bật/tắt tưới cây nhanh
void Sprinkler::toggle() {
    if (isError) {
        cout << "[!] " << name << " đang bị sự cố, nguồn nước khóa!" << endl;
        return;
    }
    isWatering = !isWatering;
    isOn = isWatering;
    if (isWatering) {
        waterFlow = 10;
        durationMinutes = 15;
        cout << "[TƯỚI CÂY] " << name << " đã MỞ vòi tưới trong 15 phút." << endl;
    } else {
        waterFlow = 0;
        durationMinutes = 0;
        cout << "[TƯỚI CÂY] " << name << " đã KHÓA vòi tưới." << endl;
    }
}

// In trạng thái hệ thống tưới cây
void Sprinkler::getStatus() {
    cout << "[TƯỚI CÂY] ID: " << id << " - Tên: " << name
         << " - Trạng thái: " << (isWatering ? "Đang hoạt động" : "Đã dừng")
         << " | Lưu lượng: " << waterFlow << " L/phút"
         << " | Hẹn giờ: " << durationMinutes << " phút"
         << " | " << (isError ? "[SỰ CỐ LỖI]" : "[ỔN ĐỊNH]") << endl;
}

// Lệnh bắt đầu tưới có hẹn giờ chủ động
void Sprinkler::startWatering(int minutes, int flow) {
    if (isError) return;
    isWatering = true;
    isOn = true;
    durationMinutes = minutes;
    waterFlow = flow;
    cout << "[TƯỚI CÂY] " << name << " bắt đầu tưới: " << durationMinutes 
         << " phút | Lưu lượng: " << waterFlow << " L/phút." << endl;
}

// Lệnh dừng tưới chủ động
void Sprinkler::stopWatering() {
    isWatering = false;
    isOn = false;
    waterFlow = 0;
    durationMinutes = 0;
    cout << "[TƯỚI CÂY] " << name << " dừng tưới nước chủ động." << endl;
}
