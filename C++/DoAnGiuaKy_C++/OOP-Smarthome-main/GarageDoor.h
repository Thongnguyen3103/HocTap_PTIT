#ifndef GARAGE_DOOR_H
#define GARAGE_DOOR_H

#include "Device.h"

// Lớp GarageDoor (Cửa cuốn Garage) kế thừa từ Device
class GarageDoor : public Device {
private:
    bool isOpened; // Trạng thái cửa cuốn đang mở (true) hay đóng (false)

public:
    // Khởi tạo cửa cuốn garage với trạng thái mặc định ban đầu là đóng
    GarageDoor(int id, string name);

    // Ghi đè toggle để đảo trạng thái đóng/mở cửa cuốn
    void toggle() override;

    // Ghi đè getStatus để in trạng thái của cửa cuốn
    void getStatus() override;

    // Mở cửa cuốn chủ động
    void openDoor();

    // Đóng cửa cuốn chủ động
    void closeDoor();
};

#endif
