#include "SmartOven.h"
#include <iostream>

using namespace std;

// Constructor khởi tạo lò nướng thông minh
SmartOven::SmartOven(int id, string name)
    : Device(id, name), ovenTemp(0), timerMinutes(0), cookingMode("Bake") {}

// Hàm toggle nguồn bật/tắt của lò nướng
void SmartOven::toggle() {
    if (isError) {
        cout << "[!] " << name << " gặp sự cố bộ gia nhiệt, không thể nấu!" << endl;
        return;
    }
    isOn = !isOn;
    if (isOn) {
        ovenTemp = 180;        // Mặc định bật lên thì đặt nhiệt độ nóng 180°C
        timerMinutes = 30;      // Mặc định hẹn giờ 30 phút
        cout << "[LÒ NƯỚNG] " << name << " đã BẬT. Đặt mặc định 180°C, 30 phút." << endl;
    } else {
        ovenTemp = 0;
        timerMinutes = 0;
        cout << "[LÒ NƯỚNG] " << name << " đã TẮT." << endl;
    }
}

// In trạng thái lò nướng
void SmartOven::getStatus() {
    cout << "[LÒ NƯỚNG] ID: " << id << " - Tên: " << name
         << " - Trạng thái: " << (isOn ? "BẬT (Đang hoạt động)" : "TẮT")
         << " | Nhiệt độ: " << ovenTemp << "°C"
         << " | Hẹn giờ: " << timerMinutes << " phút"
         << " | Chế độ: " << cookingMode
         << " | " << (isError ? "[SỰ CỐ LỖI]" : "[ỔN ĐỊNH]") << endl;
}

// Thiết lập thông số nướng chi tiết
void SmartOven::setOven(int temp, int minutes, const string& mode) {
    if (isError) return;
    ovenTemp = temp;
    timerMinutes = minutes;
    cookingMode = mode;
    cout << "[LÒ NƯỚNG] " << name << " thiết lập: " << ovenTemp << "°C | " 
         << timerMinutes << " phút | Chế độ: " << cookingMode << endl;
}

// Bắt đầu nướng đồ ăn chủ động
void SmartOven::startCooking() {
    if (isError) return;
    isOn = true;
    if (ovenTemp == 0) {
        ovenTemp = 180;
        timerMinutes = 30;
    }
    cout << "[LÒ NƯỚNG] " << name << " bắt đầu nướng đồ ăn (" << ovenTemp << "°C, Chế độ " << cookingMode << ")." << endl;
}
