#include "SoundSystem.h"
#include <iostream>

using namespace std;

// Constructor định nghĩa loa thông minh
SoundSystem::SoundSystem(int id, string name)
    : Device(id, name), volume(30), isPlaying(false), genre("Pop") {}

// Hàm toggle nguồn phát của loa
void SoundSystem::toggle() {
    if (isError) {
        cout << "[!] " << name << " gặp sự cố truyền tải âm thanh!" << endl;
        return;
    }
    isOn = !isOn;
    if (!isOn) {
        isPlaying = false; // Ngắt nguồn thì ngưng phát nhạc luôn
    }
    cout << "[ÂM THANH] " << name << (isOn ? " đã BẬT nguồn loa." : " đã TẮT nguồn loa.") << endl;
}

// In trạng thái hệ thống âm thanh ra console
void SoundSystem::getStatus() {
    cout << "[ÂM THANH] ID: " << id << " - Tên: " << name
         << " - Trạng thái: " << (isOn ? "BẬT" : "TẮT")
         << " | Đang phát: " << (isPlaying ? "CÓ" : "KHÔNG")
         << " | Thể loại: " << genre
         << " | Âm lượng: " << volume << "%"
         << " | " << (isError ? "[SỰ CỐ LỖI]" : "[ỔN ĐỊNH]") << endl;
}

// Thiết lập âm lượng loa
void SoundSystem::setVolume(int vol) {
    if (!isOn || isError) return;
    volume = vol;
    if (volume < 0) volume = 0;
    if (volume > 100) volume = 100;
    cout << "[ÂM THANH] " << name << " điều chỉnh âm lượng: " << volume << "%" << endl;
}

// Thiết lập thể loại nhạc
void SoundSystem::setGenre(const string& g) {
    if (!isOn || isError) return;
    genre = g;
    cout << "[ÂM THANH] " << name << " chọn thể loại nhạc: " << genre << endl;
}

// Phát nhạc chủ động
void SoundSystem::playMusic() {
    if (!isOn || isError) return;
    isPlaying = true;
    cout << "[ÂM THANH] " << name << " bắt đầu phát nhạc chu trình: " << genre << "." << endl;
}

// Dừng phát nhạc chủ động
void SoundSystem::stopMusic() {
    if (!isOn || isError) return;
    isPlaying = false;
    cout << "[ÂM THANH] " << name << " tạm dừng phát nhạc." << endl;
}
