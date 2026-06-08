#include "SmartCurtain.h"
#include <iostream>

using namespace std;

// Constructor khởi tạo Rèm cửa thông minh
SmartCurtain::SmartCurtain(int id, string name)
    : Device(id, name), openPercent(0) {}

// Hàm toggle để chuyển đổi nhanh đóng/mở rèm cửa
void SmartCurtain::toggle() {
    if (isError) {
        cout << "[!] " << name << " đang kẹt rãnh, không thể điều khiển rèm!" << endl;
        return;
    }
    isOn = !isOn;
    if (isOn) {
        openPercent = 100; // Mở rèm hoàn toàn
        cout << "[RÈM CỬA] " << name << " đã được MỞ hoàn toàn (100%)." << endl;
    } else {
        openPercent = 0;   // Đóng rèm hoàn toàn
        cout << "[RÈM CỬA] " << name << " đã được ĐÓNG hoàn toàn." << endl;
    }
}

// In trạng thái hoạt động của rèm cửa ra màn hình
void SmartCurtain::getStatus() {
    cout << "[RÈM CỬA] ID: " << id << " - Tên: " << name
         << " - Trạng thái: " << (isOn ? "MỞ (Hoạt động)" : "ĐÓNG (Chờ)")
         << " | Độ mở rèm: " << openPercent << "%"
         << " | " << (isError ? "[SỰ CỐ LỖI]" : "[ỔN ĐỊNH]") << endl;
}

// Thiết lập độ mở tùy chỉnh cho rèm
void SmartCurtain::setOpenPercent(int percent) {
    if (isError) return;
    openPercent = percent;
    if (openPercent < 0) openPercent = 0;
    if (openPercent > 100) openPercent = 100;
    
    // Nếu mở trên 0% thì coi như rèm đang mở/hoạt động
    isOn = (openPercent > 0);
    cout << "[RÈM CỬA] " << name << " điều chỉnh độ mở về: " << openPercent << "%" << endl;
}
