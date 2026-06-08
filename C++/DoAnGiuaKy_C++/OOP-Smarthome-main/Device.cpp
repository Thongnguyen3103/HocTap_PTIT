#include "Device.h"

Device::Device(){}

Device::Device(int id, string name)
:id(id), name(name), isOn(false), isError(false){}

Device::~Device(){}

bool Device::getIsError() const {
    return isError;
}

void Device::operator!() {
    isError = !isError;
    if (isError) {
        isOn = false;
        cout << "[!] " << name << " GẶP SỰ CỐ - Cần khởi động lại!" << endl;    
    } else {
        cout << "[OK] " << name << " Đã khởi động lại thành công!" << endl;
    }
}