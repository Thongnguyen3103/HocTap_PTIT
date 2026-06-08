#include "SmartHomeHub.h"
#include <iostream>

SmartHomeHub::SmartHomeHub(const string& name) {
    hubName = name;
}

void SmartHomeHub::addDevice(Device* device) {
    devices.push_back(device);
    cout << "[HUB] " << device->getName() << " đã được thêm vào hệ thống." << endl;
}

void SmartHomeHub::toggleDevice(int id) {
    for (Device* device : devices) {
        if (device->getId() == id) {
            device->toggle();
            return;
        }
    }
    cout << "[HUB] Không tìm thấy thiết bị có ID: " << id << endl;
}

void SmartHomeHub::malfunctionDevice(int id) {
    for (Device* device : devices) {
        if (device->getId() == id) {
            !(*device);
            return;
        }
    }
    cout << "[HUB] Không tìm thấy thiết bị có ID: " << id << endl;
}

void SmartHomeHub::allStatus() {
    cout << string(60, '=') << endl;
    cout << "TRẠNG THÁI HỆ THỐNG: " << hubName << endl;
    for (Device* device : devices) {
        device->getStatus(); 
    }
}

void SmartHomeHub::listDevices() {
    cout << "\n=====================================================================" << endl;
    cout << "                 DANH SÁCH THIẾT BỊ TRONG HỆ THỐNG                   " << endl;
    cout << "=====================================================================" << endl;
    for (size_t i = 0; i < devices.size(); i++) {
        cout << "  ID: ";
        if (devices[i]->getId() < 10) cout << "0";
        cout << devices[i]->getId() << " - " << devices[i]->getName();
        
        // Căn lề cột thứ hai
        if (i % 2 == 0) {
            int len = devices[i]->getName().length() + 10;
            int spaces = 36 - len;
            if (spaces > 0) cout << string(spaces, ' ');
        } else {
            cout << endl;
        }
    }
    if (devices.size() % 2 != 0) cout << endl;
    cout << "=====================================================================" << endl;
}

void SmartHomeHub::triggerDeviceFault(Device* device) {
   cout << "[HUB] Đang quét và kiểm tra phần cứng cho: " 
        << device->getName() << endl;
    
    !(*device); 

    if (device->getIsError()) { 
        cout << "[HUB] Cảnh báo: " 
             << device->getName() << " đang gặp sự cố!" << endl;
        
        cout << "[HUB] Hệ thống tự động kích hoạt lệnh RESET để khắc phục..." << endl;
        !(*device); 

        cout << "[HUB] Hoàn thành quét! Hệ thống trung tâm đã ổn định." << endl;
    }
}