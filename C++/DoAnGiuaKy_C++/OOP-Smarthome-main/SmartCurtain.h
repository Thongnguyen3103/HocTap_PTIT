#ifndef SMART_CURTAIN_H
#define SMART_CURTAIN_H

#include "Device.h"

// Lớp SmartCurtain (Rèm cửa thông minh) kế thừa từ Device
class SmartCurtain : public Device {
private:
    int openPercent; // Phần trăm mở rèm (0%: Đóng hoàn toàn - 100%: Mở hoàn toàn)

public:
    // Khởi tạo rèm cửa với độ mở mặc định ban đầu là 0% (Đóng)
    SmartCurtain(int id, string name);

    // Ghi đè toggle để đóng/mở rèm nhanh (mở 100% hoặc đóng 0%)
    void toggle() override;

    // Ghi đè getStatus để in trạng thái rèm cửa
    void getStatus() override;

    // Thiết lập độ mở cụ thể cho rèm (0 đến 100)
    void setOpenPercent(int percent);
};

#endif
