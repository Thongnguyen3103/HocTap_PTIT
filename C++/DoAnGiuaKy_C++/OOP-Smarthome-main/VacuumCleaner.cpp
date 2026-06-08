#include "VacuumCleaner.h"
#include <iostream>

using namespace std;

// Constructor khởi tạo Robot hút bụi
VacuumCleaner::VacuumCleaner(int id, string name, int battery)
    : Device(id, name), batteryLevel(battery), workMode("Charge"), isCleaning(false) {}

// Hàm đảo ngược trạng thái hoạt động (bắt đầu/tạm dừng dọn dẹp)
void VacuumCleaner::toggle() {
    if (isError) {
        cout << "[!] " << name << " đang báo lỗi, không thể làm việc!" << endl;
        return;
    }
    isCleaning = !isCleaning;
    isOn = isCleaning;
    if (isCleaning) {
        workMode = "Auto";
        cout << "[ROBOT] " << name << " bắt đầu tự động dọn dẹp (Auto Mode)." << endl;
    } else {
        workMode = "Standby";
        cout << "[ROBOT] " << name << " đã tạm dừng dọn dẹp." << endl;
    }
}

// Lấy thông tin trạng thái hoạt động của Robot hút bụi
void VacuumCleaner::getStatus() {
    cout << "[ROBOT] ID: " << id << " - Tên: " << name
         << " - Trạng thái: " << (isCleaning ? "Đang dọn dẹp" : "Đang chờ/Sạc")
         << " | Chế độ: " << workMode
         << " | Dung lượng pin: " << batteryLevel << "%"
         << " | " << (isError ? "[SỰ CỐ LỖI]" : "[ỔN ĐỊNH]") << endl;
}

// Thay đổi chế độ hút bụi
void VacuumCleaner::setWorkMode(const string& mode) {
    if (isError) return;
    workMode = mode;
    cout << "[ROBOT] " << name << " chuyển chế độ dọn dẹp sang: " << workMode << endl;
}

// Lệnh bắt đầu dọn dẹp chủ động
void VacuumCleaner::startCleaning() {
    if (isError) return;
    isCleaning = true;
    isOn = true;
    workMode = "Auto";
    cout << "[ROBOT] " << name << " đã được kích hoạt dọn dẹp." << endl;
}

// Lệnh dừng dọn dẹp chủ động
void VacuumCleaner::stopCleaning() {
    isCleaning = false;
    isOn = false;
    workMode = "Standby";
    cout << "[ROBOT] " << name << " đã ngừng dọn dẹp chủ động." << endl;
}

// Yêu cầu robot quay về đốc để sạc pin
void VacuumCleaner::dockAndCharge() {
    isCleaning = false;
    isOn = false;
    workMode = "Charge";
    cout << "[ROBOT] " << name << " đang quay về đốc để sạc pin." << endl;
}
