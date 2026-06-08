#ifndef SPRINKLER_H
#define SPRINKLER_H

#include "Device.h"

// Lớp Sprinkler (Hệ thống tưới cây tự động) kế thừa từ Device
class Sprinkler : public Device {
private:
    int waterFlow;          // Lưu lượng nước (L/phút)
    int durationMinutes;    // Thời gian hẹn giờ tưới (phút)
    bool isWatering;        // Trạng thái đang tưới nước hay không

public:
    // Khởi tạo vòi tưới sân vườn
    Sprinkler(int id, string name);

    // Ghi đè toggle để bật/tắt tưới
    void toggle() override;

    // Ghi đè getStatus để in trạng thái
    void getStatus() override;

    // Kích hoạt chu kỳ tưới với thời gian và lưu lượng nước chỉ định
    void startWatering(int minutes, int flow = 10);

    // Tắt vòi tưới chủ động
    void stopWatering();
};

#endif
