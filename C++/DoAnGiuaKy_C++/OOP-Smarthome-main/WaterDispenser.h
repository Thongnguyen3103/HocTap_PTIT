#ifndef WATER_DISPENSER_H
#define WATER_DISPENSER_H

#include "Device.h"

// Lớp WaterDispenser (Máy lọc nước nóng lạnh) kế thừa từ Device
class WaterDispenser : public Device {
private:
    float hotWaterTemp;   // Nhiệt độ ngăn nước nóng (C)
    float coldWaterTemp;  // Nhiệt độ ngăn nước lạnh (C)
    bool uvSterilizing;   // Chế độ diệt khuẩn bằng tia cực tím UV

public:
    // Khởi tạo máy lọc nước nóng lạnh
    WaterDispenser(int id, string name);

    // Ghi đè toggle để bật/tắt toàn bộ hệ thống lọc nước
    void toggle() override;

    // Ghi đè getStatus để in trạng thái của máy lọc nước
    void getStatus() override;

    // Điều chỉnh nhiệt độ bên ngăn nóng (40.0 - 95.0 C)
    void setHotTemp(float temp);

    // Điều chỉnh nhiệt độ bên ngăn lạnh (4.0 - 15.0 C)
    void setColdTemp(float temp);

    // Bật/tắt chế độ diệt khuẩn tự động UV
    void toggleUV(bool active);
};

#endif
