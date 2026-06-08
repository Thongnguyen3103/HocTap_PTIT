#ifndef SOUND_SYSTEM_H
#define SOUND_SYSTEM_H

#include "Device.h"

// Lớp SoundSystem (Hệ thống âm thanh đa vùng) kế thừa từ Device
class SoundSystem : public Device {
private:
    int volume;         // Âm lượng loa (0 - 100)
    bool isPlaying;     // Trạng thái đang phát nhạc hay dừng phát
    string genre;       // Thể loại nhạc phát (Pop, Rock, Classical, Jazz)

public:
    // Khởi tạo hệ thống loa thông minh
    SoundSystem(int id, string name);

    // Ghi đè toggle để bật/tắt nguồn loa
    void toggle() override;

    // Ghi đè getStatus để in thông tin loa ra màn hình
    void getStatus() override;

    // Điều chỉnh âm lượng loa
    void setVolume(int vol);

    // Đặt phát thể loại nhạc cụ thể
    void setGenre(const string& g);

    // Lệnh phát nhạc chủ động
    void playMusic();

    // Lệnh dừng phát nhạc chủ động
    void stopMusic();
};

#endif
