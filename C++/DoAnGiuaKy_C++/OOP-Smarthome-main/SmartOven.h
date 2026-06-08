#ifndef SMART_OVEN_H
#define SMART_OVEN_H

#include "Device.h"

// Lớp SmartOven (Lò nướng thông minh) kế thừa từ Device
class SmartOven : public Device {
private:
    int ovenTemp;        // Nhiệt độ lò nướng (C)
    int timerMinutes;    // Hẹn giờ nướng (phút)
    string cookingMode;  // Chế độ nướng (Bake, Grill, Defrost)

public:
    // Khởi tạo lò nướng thông minh
    SmartOven(int id, string name);

    // Ghi đè toggle để bật/tắt lò nướng
    void toggle() override;

    // Ghi đè getStatus để in trạng thái của lò nướng
    void getStatus() override;

    // Thiết lập nhiệt độ, thời gian nướng và chế độ nấu
    void setOven(int temp, int minutes, const string& mode);

    // Kích hoạt lò nướng nấu chủ động
    void startCooking();
};

#endif
