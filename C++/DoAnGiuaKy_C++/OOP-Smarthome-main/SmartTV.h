#ifndef SMART_TV_H
#define SMART_TV_H

#include "Device.h"

// Lớp SmartTV (Tivi thông minh) kế thừa từ Device
class SmartTV : public Device {
private:
    int channel;        // Kênh tivi hiện tại (số hiệu)
    int volume;         // Âm lượng tivi (0 - 100)
    string inputSource; // Nguồn đầu vào (HDMI1, HDMI2, YouTube, Netflix)

public:
    // Khởi tạo tivi thông minh
    SmartTV(int id, string name);

    // Ghi đè toggle để bật/tắt tivi
    void toggle() override;

    // Ghi đè getStatus để in trạng thái tivi
    void getStatus() override;

    // Thiết lập kênh tivi
    void setChannel(int ch);

    // Thiết lập âm lượng tivi
    void setVolume(int vol);

    // Thiết lập nguồn tín hiệu đầu vào
    void setInputSource(const string& source);
};

#endif
