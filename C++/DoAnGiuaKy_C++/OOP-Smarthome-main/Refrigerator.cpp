#include "Refrigerator.h"
#include <iostream>

using namespace std;

// Constructor định nghĩa tủ lạnh thông minh
Refrigerator::Refrigerator(int id, string name, float fridge, float freezer)
    : Device(id, name), fridgeTemp(fridge), freezerTemp(freezer), superCool(false) {
    isOn = true; // Mặc định tủ lạnh luôn cắm điện và hoạt động
}

// Bật/tắt nguồn tủ lạnh
void Refrigerator::toggle() {
    if (isError) {
        cout << "[!] " << name << " đang gặp sự cố, không thể điều khiển!" << endl;
        return;
    }
    isOn = !isOn;
    cout << "[TỦ LẠNH] " << name << (isOn ? " đã BẬT (Hoạt động)" : " đã TẮT (Ngừng hoạt động)") << endl;
}

// In trạng thái hiện tại của tủ lạnh
void Refrigerator::getStatus() {
    cout << "[TỦ LẠNH] ID: " << id << " - Tên: " << name
         << " - Trạng thái: " << (isOn ? "BẬT" : "TẮT")
         << " | Ngăn mát: " << fridgeTemp << "°C"
         << " | Ngăn đông: " << freezerTemp << "°C"
         << " | Làm lạnh nhanh: " << (superCool ? "BẬT" : "TẮT")
         << " | " << (isError ? "[SỰ CỐ LỖI]" : "[ỔN ĐỊNH]") << endl;
}

// Điều chỉnh nhiệt độ ngăn mát
void Refrigerator::setFridgeTemp(float t) {
    if (!isOn) return;
    fridgeTemp = t;
    cout << "[TỦ LẠNH] " << name << ": Ngăn mát đặt ở " << fridgeTemp << " °C" << endl;
}

// Điều chỉnh nhiệt độ ngăn đông
void Refrigerator::setFreezerTemp(float t) {
    if (!isOn) return;
    freezerTemp = t;
    cout << "[TỦ LẠNH] " << name << ": Ngăn đông đặt ở " << freezerTemp << " °C" << endl;
}

// Bật hoặc tắt tính năng làm lạnh siêu tốc
void Refrigerator::setSuperCool(bool active) {
    if (!isOn) return;
    superCool = active;
    if (superCool) {
        fridgeTemp = 2.0f; // Tự động giảm sâu nhiệt độ ngăn mát để làm lạnh nhanh
        cout << "[TỦ LẠNH] " << name << ": Đã KÍCH HOẠT làm lạnh nhanh (Super Cool), đưa ngăn mát về 2.0 °C." << endl;
    } else {
        cout << "[TỦ LẠNH] " << name << ": Đã TẮT chế độ làm lạnh nhanh." << endl;
    }
}
