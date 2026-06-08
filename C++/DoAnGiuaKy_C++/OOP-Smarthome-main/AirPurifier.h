#ifndef AIR_PURIFIER_H
#define AIR_PURIFIER_H

#include "Device.h"

// Lớp AirPurifier (Máy lọc không khí) kế thừa từ Device
class AirPurifier : public Device {
private:
    int fanSpeed;     // Tốc độ quạt gió (1, 2, 3)
    int aqiLevel;     // Chỉ số chất lượng không khí hiện tại (AQI)
    int filterLife;   // Phần trăm tuổi thọ còn lại của màng lọc (0 - 100)

public:
    // Khởi tạo máy lọc không khí
    AirPurifier(int id, string name);

    // Ghi đè toggle để bật/tắt máy lọc
    void toggle() override;

    // Ghi đè getStatus để in trạng thái của máy lọc
    void getStatus() override;

    // Thiết lập tốc độ gió (1, 2, hoặc 3)
    void setFanSpeed(int speed);

    // Cập nhật chỉ số AQI từ cảm biến (giả lập)
    void updateAQI(int aqi);
};

#endif
