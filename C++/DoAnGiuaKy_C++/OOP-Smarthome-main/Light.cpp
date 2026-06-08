#include "Light.h"

Light::Light(int id, string name, int brightness)
    : Device(id, name), brightness(brightness) {}

void Light::toggle() {
    if (isError) {
        cout << "[!] " << name << " lỗi không thể mở!" << endl;
        return;
    }

    isOn = !isOn;
    cout << "[ĐÈN] " << name << (isOn ? " BẬT" : " TẮT") 
         << ", độ sáng " << brightness << "%" << endl;
}

void Light::getStatus() {
    cout << "[ĐÈN] " << name << " ID: " << id << " - " << (isOn ? "BẬT" : "TẮT") 
         << ", độ sáng " << brightness << "%" << endl;
}

void Light::setBrightness(int b) {
    brightness = max(0, min(100, b));
    cout << "[ĐÈN] " << name << " độ sáng là " << brightness << "%" << endl;
}

void Light::turnOff() {
    if (isOn) {
        toggle();
    }
}