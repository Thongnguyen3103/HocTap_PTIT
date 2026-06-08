#include <iostream>
#include "SecurityCamera.h"
#include "SmartHomeExceptions.h"

using namespace std;

SecurityCamera::SecurityCamera(int id, const string& name, const string& loc)
    : Device(id, name), isAuthenticated(false), isRecording(false), location(loc) {}

void SecurityCamera::authenticate(const string& password) {
    if (password == "admin321") {
        isAuthenticated = true;
        cout << "[CAM] " << "Xác thực thành công!" << endl;
    }else{
        isAuthenticated = false;
        cout << "[CAM] " << "Xác thực thất bại!" << endl;
    }

}

void SecurityCamera::toggle() {
    if (isError) {
        cout << "[!] " << name << " lỗi không thể mở!" << endl;
        return;
    }

   if (!isAuthenticated) {
            throw UnauthorizedAccessException(name + " tại " + location);
    }
    isRecording = !isRecording;
    isOn = isRecording;
    cout << "[CAM] " << name << " - " << location << " - "
         << (isRecording ? "BẮT ĐẦU GHI HÌNH" : "DỪNG GHI HÌNH") << endl;
}

void SecurityCamera::startRecording() {
        if (!isAuthenticated)
            throw UnauthorizedAccessException(name + " tại " + location);
        isRecording = true;
        isOn = true;
        cout << "  [CAM] '" << name << "' bắt đầu ghi hình." << endl;
    }

void SecurityCamera::getStatus(){
    cout << "[CAM] ID: " << id << ", Tên: " << name
         << ", Vị trí: " << location 
         << ", Xác thực: " << (isAuthenticated ? "ĐÃ XÁC THỰC" : "CHƯA XÁC THỰC")
         << ", Trạng thái: " << (isRecording ? "Đang ghi hình, " : "Không ghi hình, ")
         << (isError ? "[TRỤC TRẶC]" : "[ỔN ĐỊNH]") << endl;  
}