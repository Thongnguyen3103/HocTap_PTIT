#ifndef WATER_HEATER_H
#define WATER_HEATER_H

#include "Device.h"

// Lớp WaterHeater (Bình nước nóng lạnh) kế thừa từ Device
class WaterHeater : public Device {
private:
    float waterTemp;    // Nhiệt độ nước hiện tại (C)
    float targetTemp;   // Nhiệt độ nước nóng mong muốn (C)
    bool isHeating;     // Trạng thái bình đang đun nóng hay đang tắt

public:
    // Khởi tạo bình nóng lạnh với nhiệt độ mục tiêu mặc định là 45.0 độ C
    WaterHeater(int id, string name, float target = 45.0f);

    // Ghi đè toggle để bật/tắt bình
    void toggle() override;

    // Ghi đè getStatus để in thông tin chi tiết
    void getStatus() override;

    // Đặt nhiệt độ nóng mong muốn
    void setTargetTemp(float temp);

    // Khởi động việc làm nóng chủ động
    void startHeating();
};

#endif
