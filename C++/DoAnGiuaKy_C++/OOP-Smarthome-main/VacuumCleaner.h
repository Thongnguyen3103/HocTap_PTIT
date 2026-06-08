#ifndef VACUUM_CLEANER_H
#define VACUUM_CLEANER_H

#include "Device.h"

// Lớp VacuumCleaner (Robot hút bụi) kế thừa từ Device
class VacuumCleaner : public Device {
private:
    int batteryLevel;   // Phần trăm pin hiện tại (0 - 100)
    string workMode;    // Chế độ làm việc (Auto, Spot, Edge, Charge)
    bool isCleaning;    // Trạng thái đang dọn dẹp hay không

public:
    // Khởi tạo robot hút bụi với thông số pin mặc định 100%
    VacuumCleaner(int id, string name, int battery = 100);

    // Ghi đè toggle: Bật/tắt robot tương đương bắt đầu/tạm dừng dọn dẹp
    void toggle() override;

    // Ghi đè getStatus: hiển thị trạng thái robot
    void getStatus() override;

    // Đặt chế độ dọn dẹp cụ thể
    void setWorkMode(const string& mode);

    // Bắt đầu dọn dẹp
    void startCleaning();

    // Tạm dừng dọn dẹp
    void stopCleaning();

    // Đưa robot về đốc sạc
    void dockAndCharge();
};

#endif
