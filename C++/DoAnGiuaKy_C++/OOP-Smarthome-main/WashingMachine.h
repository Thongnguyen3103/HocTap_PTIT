#ifndef WASHING_MACHINE_H
#define WASHING_MACHINE_H

#include "Device.h"

// Lớp WashingMachine (Máy giặt) kế thừa từ Device
class WashingMachine : public Device {
private:
    string washCycle;   // Chu trình giặt (Quick, Cotton, Wool, Spin)
    int waterTemp;      // Nhiệt độ nước giặt (C)
    bool isRunning;     // Trạng thái máy giặt đang chạy hay tạm dừng

public:
    // Khởi tạo máy giặt với các thông số mặc định ban đầu
    WashingMachine(int id, string name);

    // Ghi đè toggle để bắt đầu hoặc tạm dừng hoạt động
    void toggle() override;

    // Ghi đè getStatus để xuất trạng thái hiện tại
    void getStatus() override;

    // Chọn chu trình giặt mong muốn
    void setCycle(const string& cycle);

    // Đặt nhiệt độ nước giặt
    void setWaterTemp(int temp);

    // Khởi động chu trình giặt chủ động
    void startWash();
};

#endif
