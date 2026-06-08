#ifndef DRYER_H
#define DRYER_H

#include "Device.h"

// Lớp Dryer (Máy sấy quần áo) kế thừa từ Device
class Dryer : public Device {
private:
    int dryTime;       // Thời gian sấy (phút)
    string dryMode;     // Chế độ sấy (Eco, Iron, Cupboard)
    bool isRunning;     // Trạng thái máy sấy đang chạy hay dừng

public:
    // Khởi tạo máy sấy
    Dryer(int id, string name);

    // Ghi đè toggle để bắt đầu/tạm dừng sấy
    void toggle() override;

    // Ghi đè getStatus để in trạng thái của máy sấy
    void getStatus() override;

    // Chọn chế độ sấy thích hợp
    void setDryMode(const string& mode);

    // Thiết lập thời gian sấy bằng phút
    void setDryTime(int minutes);

    // Bắt đầu chạy máy sấy chủ động
    void startDry();
};

#endif
