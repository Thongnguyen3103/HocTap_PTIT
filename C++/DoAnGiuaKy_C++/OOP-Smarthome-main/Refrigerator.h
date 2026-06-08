#ifndef REFRIGERATOR_H
#define REFRIGERATOR_H

#include "Device.h"

// Lớp Refrigerator (Tủ lạnh) kế thừa từ lớp cơ sở Device
class Refrigerator : public Device {
private:
    float fridgeTemp;   // Nhiệt độ ngăn mát (độ C)
    float freezerTemp;  // Nhiệt độ ngăn đông (độ C)
    bool superCool;     // Trạng thái chế độ làm lạnh nhanh

public:
    // Constructor khởi tạo thông số tủ lạnh
    Refrigerator(int id, string name, float fridgeTemp, float freezerTemp);

    // Ghi đè phương thức toggle của lớp cơ sở để bật/tắt tủ lạnh
    void toggle() override;

    // Ghi đè phương thức getStatus để in trạng thái chi tiết của tủ lạnh
    void getStatus() override;

    // Thiết lập nhiệt độ ngăn mát
    void setFridgeTemp(float t);

    // Thiết lập nhiệt độ ngăn đông
    void setFreezerTemp(float t);

    // Bật/tắt chế độ làm lạnh nhanh
    void setSuperCool(bool active);
};

#endif
