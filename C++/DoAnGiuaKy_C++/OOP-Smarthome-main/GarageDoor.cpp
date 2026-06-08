#include "GarageDoor.h"
#include <iostream>

using namespace std;

// Constructor định nghĩa Cửa cuốn Garage
GarageDoor::GarageDoor(int id, string name)
    : Device(id, name), isOpened(false) {}

// Hàm toggle chuyển trạng thái đóng/mở cửa cuốn
void GarageDoor::toggle() {
    if (isError) {
        cout << "[!] " << name << " gặp sự cố motor, cửa cuốn ngừng hoạt động an toàn!" << endl;
        return;
    }
    isOpened = !isOpened;
    isOn = isOpened;
    cout << "[GARAGE] " << name << " đã được " << (isOpened ? "MỞ" : "ĐÓNG") << "." << endl;
}

// In trạng thái cửa cuốn garage ra console
void GarageDoor::getStatus() {
    cout << "[GARAGE] ID: " << id << " - Tên: " << name
         << " - Cửa cuốn đang: " << (isOpened ? "MỞ" : "ĐÓNG")
         << " | " << (isError ? "[SỰ CỐ LỖI]" : "[ỔN ĐỊNH]") << endl;
}

// Lệnh mở cửa cuốn
void GarageDoor::openDoor() {
    if (isError) return;
    isOpened = true;
    isOn = true;
    cout << "[GARAGE] " << name << " đã được mở lên chủ động." << endl;
}

// Lệnh đóng cửa cuốn
void GarageDoor::closeDoor() {
    if (isError) return;
    isOpened = false;
    isOn = false;
    cout << "[GARAGE] " << name << " đã được kéo xuống đóng kín chủ động." << endl;
}
